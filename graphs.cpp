#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>

/* Graph implimentation with basic search functionality 
   Uses a map of <T, set<T>> to store an adjacency list */

template <class T>
class Graph
{
  public:
   void add_node (const T data);
   void add_edge(const T first, const T second);
   void remove_node (const T data); 
   void remove_edge(const T first, const T second);
   void dfs(const T node, const T value);
   void bfs(const T node, const T value);
   void print_list() const;
    
  private:
   std::map<T, std::set<T>> graph;
   std::vector<bool> discovered;
   std::stack<T> path;
   std::queue<T> dfs_order;
   void bfs_path();
   void find_next_node_dfs(const T node, const T value);
   void find_next_node_bfs(const T node, const T value);
   void initialize_discovered();
};

template <class T>
void Graph<T>::add_node(const T data)
{
  std::set<T> s;
  graph.insert(std::make_pair(data, s));
}

template<class T>
void Graph<T>::bfs_path()
{
  std::cout<<"Route: "<<std::endl;
  for (; !path.empty(); path.pop())
    std::cout<<path.top()<<" ";
  std::cout<<std::endl;
  
  discovered.clear(); 
}

template <class T>
void Graph<T>::initialize_discovered()
{
  for (auto i : graph)
    discovered.push_back(false);
}

template <class T>
void Graph<T>::bfs(const T node, const T value)
{
  if (discovered.empty()) 
    initialize_discovered();

  if (graph.find(node) == graph.end()) 
  {
    std::cout<<"Node not found (BFS)"<<std::endl; 
    return;
  }
  find_next_node_bfs(node, value); 
}

template <class T>
void Graph<T>::find_next_node_bfs(const T node, const T value)
{
  auto node_it = graph[node].begin(), node_it_end = graph[node].end();
  for (;node_it != node_it_end; node_it++)
    if (!discovered[(*node_it)-1]) 
    {
      dfs_order.push(*node_it); 
      discovered[(*node_it)-1] = true;
      if (*node_it == value) 
      { 
        std::cout<<"Found node"<<std::endl; 
        while (!dfs_order.empty()) dfs_order.pop(); 
        discovered.clear();
       return;
      }
    }
 
  T tmp = dfs_order.front();
  dfs_order.pop();
  if (dfs_order.empty()){std::cout<<"Node Not Found (BFS)"<<std::endl; return;}
  
  bfs(tmp, value);
}

template <class T>
void Graph<T>::dfs(const T node, const T value)
{
  if (discovered.empty()) 
    initialize_discovered();
 
  if (path.empty() || path.top()!= node)
    path.push(node);

  if (node == value) 
    return bfs_path();
  
  if (graph.find(node) == graph.end()) 
  {
    std::cout<<"Node not found (DFS)"<<std::endl; 
    return;
  }
 
  discovered[std::distance(graph.begin(), graph.find(node))] = true;
   
  find_next_node_dfs(node, value);
}

template <class T>
void Graph<T>::find_next_node_dfs(const T node, const T value)
{
  auto node_it = graph[node].begin(), node_it_end = graph[node].end();

  for (;node_it != node_it_end; node_it++)
    if (!discovered[(*node_it)-1]) 
      return dfs(*node_it, value);
  
  path.pop();
  if (path.empty())
  {
    std::cout<<"Node Not found (DFS)"<<std::endl;
    discovered.clear();
    return;
  } 
  return dfs(path.top(), value);
} 

template <class T>
void Graph<T>::add_edge(const T first, const T second)
{
  graph[first].insert(second);
}

template <class T>
void Graph<T>::remove_edge(const T first, const T second)
{
  graph[first].erase(second);
}

template <class T>
void Graph<T>::remove_node(const T data)
{
  graph.erase(data);
}

template <class T>
void Graph<T>:: print_list() const
{
  for (auto i : graph)
  {
    std::cout<<i.first<<" ";
    for (auto it = i.second.begin(); 
         it!=i.second.end(); ++it) 
    {
      std::cout<<*it<<" ";
    }
   std::cout<<std::endl;
  }
}
int main()
{
  Graph<int> example; 
  
  for (int i = 1; i<=6; i++)
   example.add_node(i);

  example.add_edge(1,2);
  example.add_edge(1,4);
  example.add_edge(2,1);
  example.add_edge(2,4);
  example.add_edge(2,5);
  example.add_edge(3,4);
  example.add_edge(4,2);
  example.add_edge(4,3);
  example.add_edge(4,1);
  example.add_edge(4,2);
  example.add_edge(5,2);
  example.add_edge(5,3); //going to remove this edge
  example.add_edge(6,1); //going to remove node 6
  example.add_edge(6,3);

  example.remove_node(6);
  example.remove_edge(5,3);

  example.print_list();
  //x,y  = start at x and look for y
  example.dfs(1,5);
  example.dfs(1,3);
  example.dfs(5,3);
  example.dfs(2,5);
  example.dfs(4,5);
  //examples of nodes not found:
  example.dfs(1,9);
  example.dfs(9,1);
  

  example.bfs(1,5);
  example.bfs(1,4);
  example.bfs(2,1);
  example.bfs(2,4);
  
  example.bfs(1,9);
  example.bfs(9,1); 
  return 0;
}

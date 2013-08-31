#include <iostream>

/* basic linked list implimentation in C++ using templates
   this linked list can use any datatype -rs */

template <class T>
class linkedList
{
  public:
    linkedList(); //constructor
    ~linkedList(); //destructor
    void push_back(const T &value);
    void deleteNodes(const T &value);
    void printList();
    void reverseList();
    void deleteList();
  private:
    struct _node
    {
      T val;
      linkedList *next;
    };
    struct _node node ;
    linkedList *root = NULL;

  
};
template<class T>
linkedList<T>::linkedList(){};

template<class T>
linkedList<T>::~linkedList(){};

template<class T>
void linkedList<T>::deleteList()
{
  linkedList *t = root;
  while (t)
  {
    t = root->node.next;
    delete root;
    root = t;
  }
  delete t;
}

template<class T>
void linkedList<T>::printList()
{
  if(!root) std::cout<<"List is empty"<<std::endl;
  else
  {
    linkedList *t = root;
    while (t)
    {
      std::cout<<t->node.val<<std::endl;
      t = t->node.next;
    }
  }

}
template <class T>
void linkedList<T>::reverseList()
{

  linkedList *temp = NULL, *prev = NULL, *current = root;
  while (current != NULL)
  {
    temp = current->node.next;
    current->node.next = prev;
    prev = current;
    current = temp;
  }
  root = prev;
}
template <class T>
void linkedList<T>::deleteNodes(const T &value)
{
  linkedList *prev = NULL, *active = NULL;

  if(!root) std::cout<<"List is empty"<<std::endl;
  else
  {
    if (root&& root->node.val == value)
    {
      linkedList *t = root;
      root = t->node.next;
      delete t;
    }
  } 
  prev = root;
  active = root->node.next;
  while (active)
  {
    if (active->node.val == value)
    {
      prev->node.next = active->node.next;
      delete active;
      active = prev->node.next;
    }
    else
    {
      prev = active;
      active = active->node.next;
    }
  }
}
template<class T>
void linkedList<T>::push_back(const T &value)
{
  if (!root)
  {
    root = new linkedList<T>();
    root->node.val = value;
  }
  else
  {
    linkedList *ptr = root;
    while (ptr->node.next)
    {
      ptr = ptr->node.next;
    }
 
    ptr->node.next = new linkedList<T>(); 
    ptr = ptr->node.next;
    ptr->node.val = value;
  }
}

int main()
{
  linkedList <int> example;

  for (int i = 1; i<=20; i++)
    example.push_back(i);

  example.deleteNodes(20);
  example.deleteNodes(1);
  example.deleteNodes(10);
  example.reverseList();

  example.printList();
  example.deleteList();
  return 0;
}

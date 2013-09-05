#include <iostream>

/* basic linked list implimentation in C++ using templates
   this linked list can use any datatype -rs */

template <class T>
class linkedList
{
  public:
    ~linkedList(); //destructor
    void push_back(const T &value);
    void delete_nodes(const T &value);
    void print_list() const;
    void reverse_list();
    void clear();
    void erase(size_t pos);
  private:
    struct _node
    {
      T val;
      _node *next;
    };
    _node *root = NULL;
};

template <class T>
linkedList<T>::~linkedList<T>()
{
  clear();
}


template <class T>
void linkedList<T>::clear()
{
  struct _node *t =NULL;
  while (t)
  {
    t = root->next;
    delete root;
    root = t; 
  }
}

template <class T>
void linkedList<T>::erase(size_t pos)
{
  struct _node *current = root;
  struct _node *prev = NULL;
  
  size_t i = 0;
  while (current != NULL)
  {
    if (pos == i)
    {
      struct _node *t = current->next;
      prev->next = t;
      delete current;
    }
   ++i;
   prev = current;
   current=current->next;
  }
}

template <class T>
void linkedList<T>::reverse_list()
{
  struct _node *t = NULL, *prev = NULL, *current = root;
  while (current != NULL)
  {
    t = current->next;
    current->next = prev;
    prev = current;
    current = t;
  }
  root = prev;
}

template <class T>
void linkedList<T>::delete_nodes(const T &value)
{
  struct _node *prev = NULL;
  struct _node *active = NULL;

  if (root == NULL) return; //list is empty
  else 
  {
    if (root != NULL && root->val == value)
    {
      struct _node *t = root;
      root = t->next;
      delete t;
    }
  }

  prev = root;
  active = root->next;

  while (active)
  {
    if(active->val == value)
    {
      prev->next = active->next;
      delete active;
      active = prev->next;
    }
    else
    {
      prev = active;
      active = active->next;
    }
  }
}

template <class T>
void linkedList<T>::push_back(const T &value)
{

  if (root == NULL)
  {
    root = new _node;
    root->val = value;
  }
  else
  {
    struct _node *ptr = root;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    //now ptr is at the last spot in the list
    ptr->next = new _node; 
    ptr = ptr->next;
    ptr->val = value; 
    ptr->next = NULL; 
  }
}

template <class T>
void linkedList<T>::print_list() const
{
  struct _node *t = root;
  while (t)
  {
    std::cout<<t->val<<std::endl;
    t = t->next;
  }
}

int main()
{
  linkedList <int> example;

  for (int i = 1; i<=20; i++)
    example.push_back(i);

  example.delete_nodes(1);
  example.delete_nodes(10);
  example.delete_nodes(20);
  example.erase(2);

  example.reverse_list();

  example.print_list();

  return 0;
}

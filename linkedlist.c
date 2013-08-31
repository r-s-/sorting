#include <stdio.h>
#include <stdlib.h>
//very basic linked list implimentation in C. 
//basic node structure. No typedef.
struct node
{
  int val;
  struct node *next;
};

void deleteList(struct node *first)
{
  struct node *tmp;
  while (first != NULL)
  {
    tmp = first->next;
    free(first);
    first = tmp;
  }
  free(tmp);
}

struct node *deleteNodes (struct node *first, int num)
{
  struct node *prev = NULL, *active = NULL;
  
  if (!first) return NULL;

  while (first && first->val == num)
  {
    struct node *temp = first;
    first = first->next;
    free(temp);
  }

  prev = first;
  active = first->next;

  while (active)
  {
    if (active->val == num)
    {
      prev->next = active->next;
      free(active);
      active = prev->next;
    }
    else
    {
      prev = active;
      active = active ->next;
    }
  }

return first;
  

}

struct node *reverseList(struct node *root)
{
  struct node *temp= NULL;
  struct node *prev= NULL;

  while (root!= NULL)
  {
    temp = root->next;
    root->next = prev;
    prev = root;
    root = temp;
  }
  return prev;
}

void printList(struct node *root)
{
  struct node *temp = root;
 while (temp!= NULL)
 {
   printf("Value: %d\n", temp-> val);
   temp= temp-> next;
 }
}
int main()
{
 struct node *root = NULL, *tail = NULL;

 int i=1;
 for (;i<=20; ++i)
 {
     struct node *current =(struct node*) malloc(sizeof(struct node));
     current -> val = i;
     current -> next = NULL;
     
     if (root==NULL) root = current;
     else tail -> next = current;

     tail = current;
 }

 //delete first,last and middle element 
 root = deleteNodes(root, 20);
 root = deleteNodes(root, 1);
 root = deleteNodes(root, 10);
 //reverse list
 root = reverseList(root);
 //print list
 printList(root);

 //delete list
 deleteList(root);
 return 0;
}

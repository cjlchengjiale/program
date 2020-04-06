#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int data;
  struct node* next;
  struct node* prev;
}noed;
typedef struct List
{
  node* head;
}list;
node* creatNode(int data)
{
  node* Node = (node*)malloc(sizeof(node));
	Node->prev = Node->next = NULL;
	Node->data = data;
	return Node;
}
void litinit(list *ls)
{
  ls->head = creatNode(0);
  ls->head->next = ls->head;
  ls->head->prev = ls->head;
}
void listPushBack(list* ls, int data)
{
  node* Node = creatNode(data);
  node* p = ls->head->prev;
  Node->next = p->next;
  p->next = Node;
  ls->head->prev = Node;
  Node->prev = p;
}
void listPopFront(list* ls)
{
  if(ls->head->next == ls->head)
  return ;
  node* f = ls->head->next;
  node* n = f->next;
  ls->head->next = n;
  n->prev = ls->head;
  free(f);
}
void listInsert(node* pos, int data)
{
  node* p = pos->prev;
  node* Node = creatNode(data);
  Node->next = pos;
  Node->prev = p;
  p->next = Node;
  pos->prev = Node;
}
void listPopBack(list* ls)
{
  node* last,*p;
  last = ls->head->prev;
  p = last->prev;
  p->next = ls->head;
  ls->head->prev = p;
  free(last);
}
void listPushFront(list* ls, int data)
{
  node* f = ls->head->next;
  node* Node = creatNode(data);
  Node->next = f;
  f->prev = Node;
  Node->prev = ls->head;
  ls->head->next = Node;
}
void listErase(node* pos)
{
  if(pos->next = pos)
  return ;
  node* f = pos->prev;
  node* n = pos->next;
  f->next = n;
  n->prev = f;
  free(pos);
}
void printList(list* ls)
{
  node* n = ls->head->next;
  while(n!=ls->head)
  {
    printf("%d ",n->data);
    n = n->next;
  }
  printf("\n");
}
void listDesroy(list* ls)
{
  node* c = ls->head->next;
  while(c!=ls->head)
  {
    node* p =c->next;;
    free(c);
    c = p;
  }
  free(ls->head);
  ls->head = NULL;
}
int main(int argc, char const *argv[])
{
  list ls;
  return 0;
}

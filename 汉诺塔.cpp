#include<stdio.h>
#include<math.h>
void hanio(int a,char x,char y,char z);
int main()
{
	int n;
	scanf("%d",&n);
	hanio(n,'1','2','3');
	int num;
	num=pow(2,n)-1;
	printf("%d",num);
	return 0;
 }
void hanio(int a,char x,char y,char z)
{
	if(a==1)
	{
		printf("%c->%c\n",x,z);
	}
	else
	{
		hanio(a-1,x,z,y);
		printf("%c->%c\n",x,z);
		hanio(a-1,y,x,z);
	}
}

class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
				struct ListNode* N = New1 = New2 =New3 = (struct ListNode*)malloc(sizeof(	struct ListNode));
				N =New1->next = NULL;
				while(pHead)
				{
					if(pHead->val<=x){
						New1->next = pHead;
						New1 = New1->next;
					}
					else{
						New2->next = pHead;
						New2 = New2->next;
					}
					pHead = pHead->next;
				}
				New2->next = NULL;
				New1->next = New3 - >next;
				free(New3);
				return N;
    }
};

struct ListNode* s,*f,*p,*c,*n;
			 if(A==NULL||A->next == NULL){
					 return true;
			 }
			 f = s =A;
			 while(f&&f->next){
					 s = s->next;
					 f = f->next->next;
			 }
			 p =NULL;
			 c = s;
			 while(c)
			 {
					 n = c->next;
					 c->next = p;
					 p = c;
					 c = n;
			 }
			 c = p;
			 while(A&&c)
			 {
					 if(A->val != c->val){
							 return false;
					 }
					 A = A->next;
					 c = c->next;
			 }
			 return true;


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(!headA||!headB)
		{
			return NULL;
		}
		struct ListNode *A = headA;
		struct ListNode *B = headB;
		int Alen = Blen = 0;
		while(heaaA){
			Alen++;
			headA = headA->next;
		}
		while(heaaB){
			Blen++;
			headB = headB->next;
		}
		if(Alen>Blen){
			Alen = Alen - Blen;
			while(Alen--){
				A = A->next
			}
			while(A!=B){
				A = A->next;
				B = B->next;
				if(A==B){
					return A
				}
			}
			return NULL;
		}
		else{
			Blen = Blen-Alen;
			while(Blen--){
				B = B->next
			}
			while(A!=B){
				A = A->next;
				B = B->next;
				if(A==B){
					return B
				}
			}
			return NULL;
		}
}

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode *A ,*B ;
    A = B = head;
    A = head->next;
    while(A!=B){
        if(A==NULL||A->next==NULL){
            return false;
        }
        A = A->next->next;
        B = B->next;
    }
    return true;
}


struct Node* copyRandomList(struct Node* head) {
	struct Node* cur,*copy,*next,*n;
    if(head==NULL)
        return NULL;
    cur = head;
    while(cur)
    {
        next = cur->next;
        copy =(struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;
        cur->next = copy;
        copy->next = next;
        cur = next;
    }
    cur = head;
    while(cur)
    {
        copy = cur->next;
        next = copy->next;
        if(cur->random)
            copy->random = cur->random->next;
        else
            copy->random = NULL;
        cur = next;
    }
    cur = head;
    n = cur->next;
    while(cur)
    {
        copy = cur->next;
        next = copy->next;
        cur->next = next;
        if(next)
            copy->next = next->next;
        cur = next;
    }
    return n;
}

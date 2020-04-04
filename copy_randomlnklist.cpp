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

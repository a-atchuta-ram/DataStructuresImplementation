#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node NODE;
struct dlist{
    NODE *head;
    //int num_nodes;
};
typedef struct dlist DLIST;
NODE *getnode(int ele){
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=ele;
    temp->llink=NULL;
    temp->rlink=NULL;

    return temp;
}
void init(DLIST *p){
    p->head=NULL;
}
void insertf(DLIST *p,int ele){
    NODE *temp;
    temp=getnode(ele);
    if(p->head==NULL){
        p->head=temp;
    }
    else{
        // temp->rlink=p->head;
        // p->head=temp;
        p->head->llink=temp;
        temp->rlink=p->head;
        p->head=temp;
    }
}
void insertr(DLIST *p,int ele){
    NODE *newnode,*curr=p->head;
    newnode=getnode(ele);
    if(p->head==NULL){
        p->head=newnode;
    }
    else{
        while(curr->rlink!=NULL){
            curr=curr->rlink;
        }
        curr->rlink=newnode;
        newnode->llink=curr;

    }
}
void insertap(DLIST *p,int ele,int pos){  // indexing begins from 1 to n
    NODE *temp;
    NODE *prev=NULL,*cur=p->head,*newnode;
    int count=1;
    newnode=getnode(ele);
    //temp=p->head;
    if(pos==1){
        insertf(p,ele);
    }
    else{
        while(cur->rlink!=NULL && count!=pos){
            prev=cur;
            cur=cur->rlink;
            count++;
        }
       prev->rlink=newnode;
       newnode->llink=prev;
       newnode->rlink=cur;
       cur->llink=newnode;

    }
}
void disp(DLIST *r){
    NODE *temp;
    temp=r->head;
    if(r->head ==NULL){
        printf("\nList is empty");
        return;
    }
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->rlink;
    }

}
void del_f(DLIST *p){
    //code here
    NODE* temp;
    if(p->head==NULL){
        printf("Cannot delete empty list(from del fun)");
    }
    else if(p->head->rlink==NULL){
        //printf("\nInside else if of del_f"); this else if is to delete last node that is present before list 
        // becomes empty
        free(p->head);
        p->head=NULL;
    }
    else{
        temp=p->head;
        p->head->rlink->llink=NULL;
        //p->head=(p->head)->rlink;
        (p->head)=(p->head)->rlink;
        free(temp);

    }
}
void del_r(DLIST *p) {
     NODE* temp,*cur=p->head;
     //temp=p->head;
    if(p->head==NULL){
        printf("Cannot delete empty list(from del fun-rear)");
    }
     else if(p->head->rlink==NULL){
        free(p->head);
        p->head=NULL;
    }
    else{
        while(cur->rlink!=NULL){
            cur=cur->rlink;
        }
        cur->llink->rlink=NULL;
        free(cur);
    }
}
void del_ap(DLIST *p,int pos){
    NODE *temp;
    NODE *prev=NULL,*cur=p->head,*newnode;
    int count=1;
    //newnode=getnode(ele);
    //temp=p->head;
    if(p->head==NULL){
        printf("Cannot delete empty list(from del ap fun)");
    }
    else if(pos==1){
        del_f(p);   
    }
     else{
        while(cur->rlink!=NULL && count!=pos){
            prev=cur;
            cur=cur->rlink;
            count++;
        }
       //statements after it reaches specified node
       cur->llink->rlink=cur->rlink;
       cur->rlink->llink=cur->llink;
       free(cur);


    }
     
    
}



int main(){
    DLIST l1;
    init(&l1); //Initalize the list
    insertf(&l1,10);
    insertf(&l1,20);
    insertf(&l1,500);
    //insertr(&l1,111);
    //insertap(&l1,100,1); //
    del_f(&l1); 
    del_f(&l1);
  
    //del_ap(&l1,2);
    //disp(&l1);

    disp(&l1);
}
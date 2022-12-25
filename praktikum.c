#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_QUEUE 10


int current_queue=0;
struct buku{
    int id_peminjam;
    char nama_peminjam[50];
    char judul_buku[50];
    char genre_buku[15];
    struct buku *next;
};
struct buku *queuehead;
struct buku *queuetail;
struct buku *new_data(int id, char peminjam[], char judul[], char genre[]){
    struct buku *new = (struct buku*)malloc(sizeof(struct buku));
    new->id_peminjam=id;
    strcpy(new->nama_peminjam, peminjam);
    strcpy(new->judul_buku, judul);
    strcpy(new->genre_buku, genre);
    new->next=NULL;
    return new;
}

void enqueue(int id, char peminjam[], char judul[], char genre[]){
    if(current_queue<MAX_QUEUE){
    struct queue *new = new_data(id,peminjam, judul, genre);
    if(queuehead==NULL){
        queuehead=new;
        queuetail=new;
        current_queue++;
        return;
    }
    else{
        struct buku *walker=queuehead;
        while(walker->next!=NULL){
            walker=walker->next;
        }
        walker->next=new;
        queuetail=new;
        current_queue++;
        return;
    }}
    else{
        printf("Queue sudah penuh\n");
    }
}

void dequeue(){
    if(current_queue!=0){
    struct buku* temp=queuehead;
    queuehead=temp->next;
    current_queue--;
    free(temp);
    return;
    }else{
        printf("Tidak ada Queue\n");
    }    
}

void show_queuehead(){
   printf("Queue terdepan adalah : \nId Peminjam : %i\nNama Peminjam : %s\nJudul Buku : %s\nGenre Buku : %s\n\n", queuehead->id_peminjam, queuehead->nama_peminjam, queuehead->judul_buku, queuehead->genre_buku);
   return;
 }

int queueCount(){
	if(queuetail==NULL){
		return 0;
	}else{
		int banyak=0;
		while(queuehead!=NULL){
			queuehead=queuehead->next;
			banyak++;
		}
		return banyak;
	}
}

void isEmpty(){
	if(queuetail==NULL){
		printf("\n Queue masih kosong");
	}else{
		printf("\n Queue tidak kosong");
	}
}

void isFull(){
	if(current_queue==MAX_QUEUE){
		printf("\n Queue Penuh");
	}else{
		printf("\n Queue Masih Bisa Diisi");
	}
}

void traverse(){
    if(current_queue!=0){

	struct buku *pWalker;

    system("cls");
	pWalker = queuehead;
	while (pWalker != NULL){
   	printf("Id Peminjam : %i\nNama Peminjam : %s\nJudul Buku : %s\nGenre Buku : %s\n", pWalker->id_peminjam,pWalker->nama_peminjam,pWalker->judul_buku,pWalker->genre_buku);
   	pWalker = pWalker -> next;
	}
   printf("NULL\n");
    return;
    }else{
        printf("Tidak ada Queue\n");
        return;
    }
   }
   
/* structure of a stack node */
struct sNode {
    char *data;
    struct sNode* next;
};
 
/* Function to push an item to stack*/
void push(struct sNode** top_ref, char *judul);
 
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref);
 
/* structure of queue having two stacks */
struct queue {
    struct sNode* stack1;
    struct sNode* stack2;
};
 
/* Function to enqueue an item to queue */
void enQueue(struct queue* q, char *judul)
{
    push(&q->stack1, judul);
}
 
/* Function to deQueue an item from queue */
int deQueue(struct queue* q)
{
    char *judul;
 
    /* If both stacks are empty then error */
    if (q->stack1 == NULL && q->stack2 == NULL) {
        printf("Q is empty");
        getchar();
        exit(0);
    }
 
    /* Move elements from stack1 to stack 2 only if
       stack2 is empty */
    if (q->stack2 == NULL) {
        while (q->stack1 != NULL) {
            *judul = pop(&q->stack1);
            push(&q->stack2, judul);
        }
    }
 
    *judul = pop(&q->stack2);
    return *judul;
}
 
/* Function to push an item to stack*/
void push(struct sNode** top_ref, char *judul)
{	
	struct sNode* new_node = (struct sNode*)malloc(sizeof(struct sNode));
    if (new_node == NULL) {
        printf("Stack overflow \n");
        getchar();
        exit(0);
    }
 
    /* put in the data */
    new_node->data = strcpy(judul);
 
    /* link the old list of the new node */
    new_node->next = (*top_ref);
 
    /* move the head to point to the new node */
    (*top_ref) = new_node;
}
 
/* Function to pop an item from stack*/
int pop(struct sNode** top_ref)
{
    int res;
    struct sNode* top;
 
    /*If stack is empty then error */
    if (*top_ref == NULL) {
        printf("Stack underflow \n");
        getchar();
        exit(0);
    }
    else {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

int main(){
    enqueue(0,"Abdurrahman", "1001 Malam", "Fiksi");
    enqueue(1,"Rizki", "1002 Malam", "Fiksi");
    enqueue(3,"Abu", "1003 Malam", "Fiksi");
    enqueue(4,"Hanoman", "1004 Malam", "Fiksi");
    enqueue(5,"Fathur", "1005 Malam", "Fiksi");
    traverse();
    //show_queuehead();
    isEmpty();
    isFull();
    dequeue();
    frontQueue();
    printf("/nStack : ");
    struct queue* q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enQueue(q, "1001 Malam");
    enQueue(q, "1002 Malam");
    enQueue(q, "1003 Malam");
 
    //Dequeue items
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
 
    return 0;
}

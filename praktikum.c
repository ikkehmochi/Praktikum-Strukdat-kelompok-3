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
    struct buku *new= (struct buku*)malloc(sizeof(struct buku));
    new->id_peminjam=id;
    strcpy(new->nama_peminjam, peminjam);
    strcpy(new->judul_buku, judul);
    strcpy(new->genre_buku, genre);
    new->next=NULL;
    return new;
}

void enqueue(int id, char peminjam[], char judul[], char genre[]){
    if(current_queue<MAX_QUEUE){
    struct queue *new= new_data(id,peminjam, judul, genre);
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
int main(){
    enqueue(0,"Abdurrahman", "1001 Malam", "Fiksi");
    enqueue(1,"Rizki", "1002 Malam", "Fiksi");
    enqueue(3,"Abu", "1003 Malam", "Fiksi");
    enqueue(4,"Hanoman", "1004 Malam", "Fiksi");
    enqueue(5,"Fathur", "1005 Malam", "Fiksi");
    traverse();
}
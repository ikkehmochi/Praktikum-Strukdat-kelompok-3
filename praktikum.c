#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <math.h>

#define MAX_QUEUE 10
#define MAX_STACK 10

int current_queue=0;
int current_stack=0;

struct buku{
    int id_peminjam;
    char nama_peminjam[50];
    char judul_buku[50];
    char genre_buku[15];
    struct buku *next;
};

struct stack{
	int data;
	struct stack *next;
};

struct stack *top;
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

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void garis(int x) {
	int z;
	for(z = 0; z < x; z++) {
		printf("=");
	}
	printf("\n");
}

void delay() {
	int delay;
	delay=1;
	while(delay<1000000000) {
		delay++;
	}
}

void load()
{	
  	char load[] = {'S','T','A','R','T','>'};
	for(int i=0; i<6; i++) {
		printf("%c\t", load[i]);
		delay();
	}
	Sleep(2);
}

void header()
{
	garis(120);
	printf("\t\t\t\t\t     Final Project Struktur Data A081\n");
	printf("\t\t\t\t\t  Program Pengembalian Buku Perpustakaan\n");
	garis(120);
}

void enqueue(int id, char peminjam[], char judul[], char genre[]){
    system("cls");
	int j;
	if(current_queue<MAX_QUEUE){
        struct buku *new = new_data(id,peminjam, judul, genre);
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
					printf(" \n Data Telah Ditambahkan.\n");
					printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
				}
	}else{
	printf("\n Queue sudah penuh\n");
	printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}
}

int inputCount(){
    int count;
    printf("\n Masukkan jumlah data yang akan dimasukkan: ");
    scanf("%d", &count);
    return count;
}

void insert(){
	system("cls");
	header();
	int j;
	int count = inputCount();
    for(int i=0; i<count; i++){
		printf(" \n Data Pengembalian Buku Ke - %i\n",j+1);
		printf(" ------------------------------------\n");
	int id;
		printf("\n Masukkan Id Peminjam: ");
		scanf("%d", &id);
		
		getchar();
	char peminjam[50];	
		printf(" Masukkan Nama Peminjam: ");
		fgets(peminjam, 50, stdin);
		peminjam[strlen(peminjam)-1] = '\0';
	
	char judul[50];	
		printf(" Masukkan Judul Buku   : ");
		fgets(judul, 50, stdin);
		judul[strlen(judul)-1] = '\0';
		
	char genre[15];	
		printf(" Masukkan Genre Buku   : ");
		fgets(genre, 15, stdin);
		genre[strlen(genre)-1] = '\0';
		enqueue(id, peminjam, judul, genre);
		j++;
	}
}

void dequeue(){
	system("cls");
	header();
	if(current_queue!=0){
	struct buku* temp=queuehead;
	queuehead=temp->next;
	current_queue--;
	printf(" \n Data teratas telah dihapus.\n");
	printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	free(temp);
	}
	else{
		printf(" \n Tidak ada Queue\n");
		printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}
}

void checkQueue(){
	system("cls");
	header();
    if(queuetail==NULL){
        printf("\n Queue masih kosong");
        printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    }else{
        if(current_queue==MAX_QUEUE){
            printf("\n Queue Penuh");
            printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
        }else{
            printf("\n Queue tidak kosong dan masih bisa diisi");
            printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
        }
    }
}

void show_queuehead(){
	system("cls");
	header();
	if(current_queue == NULL){
		printf(" \n Tidak ada Queue\n");
		printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}
	else{
		printf(" \n Queue terdepan adalah : \n Id Peminjam : %i\n Nama Peminjam : %s\n Judul Buku : %s\n Genre Buku : %s\n\n", queuehead->id_peminjam, queuehead->nama_peminjam, queuehead->judul_buku, queuehead->genre_buku);
		printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	}
	return;
}

void traverse(){
	system("cls");
	header();
	int j;
	if(current_queue!=0){
	struct buku *pWalker;
	    system("cls");
	    pWalker = queuehead;
    		while (pWalker != NULL){
    			printf(" \n Data Pengembalian Buku Ke - %i\n",j+1);
		        printf(" \n Id Peminjam : %i\n Nama Peminjam : %s\n Judul Buku : %s\n Genre Buku : %s\n", pWalker->id_peminjam,pWalker->nama_peminjam,pWalker->judul_buku,pWalker->genre_buku);
		        pWalker = pWalker -> next;
		        j++;
    		}
    		printf(" NULL\n");
    		printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    		return;
			}else{
    		printf(" \n Tidak ada Queue\n");
    		printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
			}
}

void convert_queue_to_stack(){
	system("cls");
	header();
	if(queuehead == NULL){
	printf(" \n Queue kosong, tidak bisa dikonversi ke stack\n");
	printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
	return;
	}
		struct buku *temp = queuehead;
		while(temp != NULL){
		    push(temp->id_peminjam);
		    temp = temp->next;
			}
			while(queuehead != NULL){
    		dequeue();
		}
		printf(" \n\n Data Telah Dikonversi Ke Stack\n");
		printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
}

void push(int data){
	system("cls");
	header();
    if(current_stack < MAX_STACK){
        struct stack *new = malloc(sizeof(struct stack));
        new->data = data;
        new->next = top;
        top = new;
        current_stack++;
        printf(" \n Data Telah Ditambahkan.\n");
		printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    }else{
        printf("\n Stack Penuh\n");
        printf("\n Data Tidak Bisa Ditambahkan\n");
        printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    }
}

void pop(){
	system("cls");
	header();
    if(top != NULL){
        struct stack *temp = top;
        top = top->next;
        free(temp);
        printf("\n Data teratas telah dihapus\n");
        printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    }else{
        printf("\n Stack kosong\n");
        printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    }
}

void checkStack(){
	system("cls");
	header();
    if(top == NULL){
        printf("\n Stack masih kosong");
        printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    }else{
		if(current_stack == MAX_STACK){
        	printf("\n Stack penuh");
        	printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    	}else{
        	printf("\n Stack tidak kosong dan masih bisa diisi");
        	printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
    	}
 	}
}

void show_stack(){
	system("cls");
	header();
    if(top == NULL){
        printf(" \n Stack kosong, tidak ada data yang ditampilkan\n");
        printf(" \n Tekan ENTER Untuk Kembali Ke Menu Sebelumnya.\n");
        return;
    }

    printf(" \n Isi stack:\n");
    struct stack *temp = top;
    while(temp != NULL){
        printf(" %d\n", temp->data);
        temp = temp->next;
    }
}

void menu(){
		system("cls");
		header();
		printf("\t\t\t\t\t\t\tMENU UTAMA\n");
	    puts("\n Pilih Menu dibawah ini untuk menjalankan aplikasi");
	    puts("  1.  Tambah Queue");
	    puts("  2.  Hapus Queue");
	    puts("  3.  Tampilkan Queue Terdepan");
	    puts("  4.  Check Full/Empety Queue");
	    puts("  5.  Tampilkan Queue");
	    puts("  6.  Konversi Queue ke Stack");
	    puts("  7.  Tambah Data ke Stack");
	    puts("  8.  Hapus Data dari Stack");
	    puts("  9.  Tampilkan Stack Terdepan");
	    puts(" 10.  Check Full/Empety Stack");
	    puts(" 11.  Tampilkan Data Stack");
	    puts(" Esc. Exit\n");
}

int main(){
	int pilihan;
	system("color 70");
	gotoxy(32,13); 
	load();
	system("cls");
		do{	system("cls");
			menu();
			printf(" Masukkan pilihan Anda: ");
			scanf("%d", &pilihan);
			switch(pilihan){
				case  1:// Tambahkan data
						insert();
						break;
				case  2: // Hapus data terdepan dari queue
						dequeue();
						break;
				case  3: // Tampilkan data terdepan pada queue
						show_queuehead();
						break;
				case  4://Cek queue kosong/full
						checkQueue();
						break;		
				case  5:// Tampilkan seluruh data pada queue
						traverse();
						break;
				case  6:// Konversi queue ke stack
						convert_queue_to_stack();
						break;
				case  7:// Tambah data ke stack
						printf(" Masukkan data yang ingin ditambahkan: ");
						int data;
						scanf(" %d", &data);
						push(data);
						break;
				case  8:// Hapus data terdepan pada stack
						pop();
						break;
				case  9:// Tampilkan data terdepan pada stack
						break;
				case 10://Cek queue kosong/full
						checkStack();
						break;
				case 11:// Tampilkan seluruh data pada stack
						show_stack();
						break;
				case 15: // Keluar dari program
						printf("Terima kasih telah menggunakan program ini!\n");
						break;
				default:
						printf("Pilihan tidak valid. Silakan masukkan pilihan kembali.\n");
						break;
			}
		}while (pilihan != 15);
		return 0;
}

#include<stdio.h>
#include<string.h>

typedef struct Node{
	char Name[50];
	int is_directory;
	int child_count;
	struct Node *parent;
	struct Node *children[50];
}node;

Node *createNode(char name[], int is_directory){
	Node *new_node=(Node *)malloc(sizeof(Node));
	strcpy(new_node->name, name);
	new_node->is_directory = is_directory;
	new_node->parent = NULL;
	new_node->child_count = 0;
	return new_node;
}

Node * createDirectory(Node *parent, char name[]){
	Node *directory=createNode(name,1);
	directory->parent=parent;
	parent->children[parent->child_count]=directory;
	parent->child_count++;
	return directory;
}

Node * createFile(Node * directory, char name[]){
	Node * file = createNode(name, 0);
	file->parent=directory;
	directory->children[directory->child_count]
}

void singlelevel(){
	struct file{
		int index;      
		char fname[20];
	};
	struct file files[100];
	int ch, ptr=0, searchFlag=0;
	char tempname[20];
	do{
		printf("\n1.Create file \n2.Delete file \n3.Search file \n4.Exit \nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1:
				printf("Enter file name: ");
				scanf("%s", files[ptr].fname);
				files[ptr].index=ptr;
				ptr++;
				printf("\n----File added succesfully----\n");
				break;
			case 2:
				printf("\nEnter filename to be deleted: ");
				scanf("%s", tempname);
				for(int i=0; i<ptr; i++){
					if(strcmp(tempname, files[i].fname)==0){
						strcpy(files[i].fname, "");
						printf("\n----File deleted successfully----\n");
						break;
					}
				}
				break;
			case 3:
				printf("\nEnter filename to be searched: ");
				scanf("%s", tempname);
				for(int i=0; i<ptr; i++){
					if(strcmp(tempname, files[i].fname)==0){
						searchFlag=1;
						break;
					}
					else{
						searchFlag=0;
					}
				}
				if(searchFlag==0)
					printf("\n----File not found----\n");
				else
					printf("\n----File found----\n");
				break;
		}
	}while(ch!=4);
	
}

void twolevel(){
	struct file{
		int index;
		char fname[20];
	};
	struct userfiledirectory{
		char ufdname[20];
		int ptr;
		struct file files[50];
	};
	char mfd[20], tempfile[20];
	int ufdno, choice, flag=0;
	printf("Enter Master File Directory Name : ");
	scanf("%s", mfd);
	printf("Enter no of User File Directory: ");
	scanf("%d", &ufdno);
	struct userfiledirectory ufd[ufdno];
	for(int i=0; i<ufdno; i++){
		ufd[i].ptr=0;
	}
	do{
		x: printf("1.Create File \n2.Delete File \n3.Search File  \n4.Exit \nEnter choice: ");
		scanf("%d", &choice);
		int tempufdno;
		switch(choice){
			case 1:
				printf("Enter UFD number to which file to be added: ");
				scanf("%d", &tempufdno);
				printf("Enter file name: ");
				scanf("%s", ufd[tempufdno].files[ufd[tempufdno].ptr].fname);
				printf("\n----File %s added successfully----\n\n",ufd[tempufdno].files[ufd[tempufdno].ptr].fname);
				ufd[tempufdno].ptr++;
				break;
			case 2:
				printf("Enter UFD number from which file be deleted: ");
				scanf("%d", &tempufdno);
				printf("Enter file name: ");
				scanf("%s", tempfile);
				for(int j=0; j<ufd[tempufdno].ptr; j++){
					if(strcmp(tempfile, ufd[tempufdno].files[j].fname)==0){
						strcpy(ufd[tempufdno].files[j].fname, "");
						printf("\n----File deleted successfully----\n");
						break;
					}
				}
				break;
			case 3:
				printf("Enter UFD number from which file be deleted: ");
				scanf("%d", &tempufdno);
				printf("Enter file name to be searched: ");
				scanf("%s", tempfile);
				for(int j=0; j<ufd[tempufdno].ptr; j++){ 
					if(strcmp(tempfile, ufd[tempufdno].files[j].fname)==0){
						flag=1;
						printf("\n----File found in UFD %d----\n", tempufdno);
						goto x;
						break;
					}
					else{
						flag=0;
					}
				}
				
				if(flag==0)
						printf("\n----File not found----\n");
		}
	
	}while(choice!=4);
}

void main(){
	int choice;
	printf("---File Organization techniques---\n");	
	printf("1.Single level \n2.Two-level \n3.Hierarchial \nEnter choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			singlelevel();
			break;
		case 2:
			twolevel();
			break;
		case 3:
			printf("Not implemented yet ");
			break;
		default:
			printf("Invalid choice");
	}
}

//Prajwal PP B21CS1242
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct File{
	char name[20];
	int start, length;
}filesInfo[50];

void contiguous(int harddisklength, int totalnooffiles, struct File files[]){
	int array[harddisklength];
	for(int i=0; i<harddisklength; i++){
		array[i]=0;  //available
	}
	for(int i=0; i<totalnooffiles; i++)
	{	int flag=0;
		for(int j=files[i].start ; j<files[i].length+files[i].start ; j++){
				if(array[j]!=0){
					flag=1;
					break;
				}
		}
		if(flag==1){
			printf("File %s Failed to allocate\n", filesInfo[i].name);
		}
		else{
			for(int j=files[i].start ; j<files[i].length+files[i].start ; j++){
					array[j]=1;
			}
			printf("File %s Allocated from %d to %d \n", filesInfo[i].name, filesInfo[i].start, filesInfo[i].length);
		}
		
	}
	
}

void linkedalloc(){
	struct linkedfile{
		int address;
		struct linkedfile *next;
	};
	int temp[50], arrptr=0, fl=0;
	struct File{
		char name[50];
		int blocks;
		struct linkedfile *start, *end;
	}files[100];
	int fileIndex=0, choice=1, i, fileNo;
	while(choice!=3){
		printf("\n1.Add Files \n2.Display \n3.Exit");
		printf("Enter choice: ");
		scanf("%d", &choice);
		if(choice==1){
			printf("Enter number of files: ");
			scanf("%d", &fileNo);
			for(i=fileIndex ; i< fileIndex+fileNo; i++){
				printf("Enter file name: ");
				scanf("%s", files[i].name);
				printf("Enter number of blocks of file: ");
				scanf("%d", &files[i].blocks);
				printf("Enter block address of file: ");
				struct linkedfile *prevptr;
				for(int j=0; j<files[i].blocks; j++){
					struct linkedfile *ptr=(struct linkedfile *)malloc(sizeof(struct linkedfile));
					scanf("%d", &ptr->address);
					for(int i=0; i<arrptr; i++){
						if(ptr->address==temp[i]){
							fl=1;
							break;
						}
						else{
							temp[arrptr]=ptr->address;
							arrptr++;
						}
					}
					if(fl==0){
						if(j==0){
							files[i].start=ptr;
							prevptr=ptr;
						}
						else{
							prevptr->next=ptr;
							prevptr=ptr;
						}
						ptr->next=NULL;
					}
					else{
						printf("\nCannot be allocated");
					}
					
				}
				files[i].end=prevptr;
			}
			fileIndex+=fileNo;
		}
		else if(choice==2){
			char searchKey[40];
			scanf("%s", searchKey);
			for(int i=0; i<fileIndex; i++){
				struct File file=files[i];
				printf("\n\n%s", file.name);
				printf("\nStarting address is %d ", file.start->address);
				printf("\nEnd address is %d ", file.end->address);
				printf("\nNo of blocks is %d ", file.blocks);
				printf("\nBlocks \n");
				for(struct linkedfile *j=file.start; j!=NULL; j=j->next){
					printf("%d->", j->address);
				}
			}
		}
		else{
			break;
		}
	}
}

void indexed(){
	struct File{
		char name[50];
		int blocks;
		int indexAddress;
		int address[100];
	}files[100];
	int fileIndex=0, choice=1, i;
	char searchKey[40];
	while(choice!=3){
		printf("1.Add files  \n2.Display \n3.Exit");
		scanf("%d", &choice);
		if(choice==1){
			int fileNo;
			printf("Enter no of files: ");
			scanf("%d", &fileNo);
			for(int i=fileIndex; i<fileIndex + fileNo; i++){
				printf("Enter file name: ");
				scanf("%s", files[i].name);
				printf("Enter index block address: ");
				scanf("%d", &files[i].indexAddress);
				printf("Enter no of blocks of file: ");
				scanf("%d", &files[i].blocks);
				printf("Enter blocks addresses of file: ");
				for(int j=0; j<files[i].blocks; j++){
					scanf("%d", &files[i].address[j]);
				}
			}
			fileIndex+=fileNo;
		}
		else if(choice==2){
			for(int i=0; i<fileIndex; i++){
				struct File file=files[i];
				printf("\nIndex block address: %d", file.indexAddress);
				printf("\nNo of blocks: %d", file.blocks);
				printf("\nBlocks\n");
				for(int j=0; j<file.blocks; j++){
					printf("%d -> %d\n", file.indexAddress, file.address[j]);
				}
				
			}
		}
		else if(choice==3){
			break;
		}
		
	}
}

void main(){
	int choice, hdBlocks, noOfFiles;
	printf("File allocation techniques\n");
	printf("Press \n1.Contiguous allocation \n2.Linked allocation \n3.Indexed allocation \n4.Exit");
	printf("Enter choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1:
			printf("Enter total number of blocks in the harddisk: ");
			scanf("%d", &hdBlocks);
			printf("Enter number of files: ");
			scanf("%d", &noOfFiles);
			for(int i=0; i<noOfFiles; i++){
				printf("Enter file %d name: ", i+1);
				scanf("%s", filesInfo[i].name);
				printf("Enter starting block of file %d: ", i+1);
				scanf("%d", &filesInfo[i].start);
				printf("Enter the length of file %d: ", i+1);
				scanf("%d", &filesInfo[i].length); 
			}
			contiguous(hdBlocks, noOfFiles, filesInfo);
			break;
		case 2:
			linkedalloc();
			break;
		case 3:
			indexed();
			break;
	}
	
}
/*OUTPUT
File allocation techniques
Press 
1.Contiguous allocation 
2.Linked allocation 
3.Indexed allocation 
4.Exit  Enter choice: 1
Enter total number of blocks in the harddisk: 50
Enter number of files: 5
Enter file 1 name: connt
Enter starting block of file 1: 0
Enter the length of file 1: 2
Enter file 2 name: tr
Enter starting block of file 2: 14
Enter the length of file 2: 3
Enter file 3 name: mail
Enter starting block of file 3: 19
Enter the length of file 3: 6
Enter file 4 name: list
Enter starting block of file 4: 28
Enter the length of file 4: 4
Enter file 5 name: sample
Enter starting block of file 5: 26
Enter the length of file 5: 3
File connt Allocated from 0 to 2 
File tr Allocated from 14 to 3 
File mail Allocated from 19 to 6 
File list Allocated from 28 to 4 
File sample Failed to allocate

File allocation techniques
Press 
1.Contiguous allocation 
2.Linked allocation 
3.Indexed allocation 
4.Exit  Enter choice: 2

1.Add Files 
2.Display 
3.ExitEnter choice: 1
Enter number of files: 3
Enter file name: aaa
Enter number of blocks of file: 3
Enter block address of file: 10 9 7
Enter file name: bbb
Enter number of blocks of file: 3
Enter block address of file: 1 2 4
Enter file name: ccc
Enter number of blocks of file: 4
Enter block address of file: 5 20 21 30

1.Add Files 
2.Display 
3.Exit  Enter choice: 2

aaa
Starting address is 10 
End address is 7 
No of blocks is 3 
Blocks 
10->9->7->

bbb
Starting address is 1 
End address is 4 
No of blocks is 3 
Blocks 
1->2->4->

ccc
Starting address is 5 
End address is 30 
No of blocks is 4 
Blocks 
5->20->21->30->

File allocation techniques
Press 
1.Contiguous allocation 
2.Linked allocation 
3.Indexed allocation 
4.Exit  Enter choice: 3
1.Add files  
2.Display 
3.Exit 1
Enter no of files: 3
Enter file name: abc
Enter index block address: 5 
Enter no of blocks of file: 3
Enter blocks addresses of file: 1 2 6
Enter file name: cde
Enter index block address: 7
Enter no of blocks of file: 3
Enter blocks addresses of file: 21 12 10
Enter file name: fgh
Enter index block address: 13
Enter no of blocks of file: 3
Enter blocks addresses of file: 4 8 31
1.Add files  
2.Display 
3.Exit2

Index block address: 5
No of blocks: 3
Blocks
5 -> 1
5 -> 2
5 -> 6

Index block address: 7
No of blocks: 3
Blocks
7 -> 21
7 -> 12
7 -> 10

Index block address: 13
No of blocks: 3
Blocks
13 -> 4
13 -> 8
13 -> 31
*/

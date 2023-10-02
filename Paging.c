//Prajwal PP B21CS1242
#include<stdio.h>
#include<string.h>
void main(){
	int s,size,p,f,i,n,pa,choice;
	struct pgindex{
		int page;
		int frame;	
	};
	printf("Enter page size: ");
	scanf("%d", &size);
	printf("Enter no of pages: ");
	scanf("%d", &n);
	struct pgindex pagetable[n];
	for(i=0; i<n; i++){
		pagetable[i].page=i;
		printf("Page no %d Enter frame no: ", i);
		scanf("%d", &pagetable[i].frame);
	}
	printf("Page No    Frame\n");
	for(i=0; i<n; i++){
		printf("  %d \t    %d \n", pagetable[i].page, pagetable[i].frame);
	}
	x: printf("Enter page no and offset: ");
	   scanf("%d %d", &p, &s);
	if(s>size-1){
		printf("Offset greater than page size\n");
		goto x;
	}
	if(p>n-1){
		printf("Page not found\n");
		goto x;
	}
	else{
		f=pagetable[p].frame; 
		pa=(f*size)+s;
		printf("Physical address is: %d \n", pa); 
	}
	printf("1.Generate new physical address    2.Exit \nEnter choice: ");
	scanf("%d", &choice);
	if(choice==1){
		goto x;
	}
}
/*Enter page size: 4
Enter no of pages: 5
Page no 0 Enter frame no: 2     
Page no 1 Enter frame no: 3
Page no 2 Enter frame no: 0
Page no 3 Enter frame no: 4
Page no 4 Enter frame no: 6
Page No    Frame
  0 	    2 
  1 	    3 
  2 	    0 
  3 	    4 
  4 	    6 
Enter page no and offset: 4 2
Physical address is: 26 
1.Generate new physical address    2.Exit 
*/

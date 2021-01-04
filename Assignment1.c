#include <stdio.h>
#include<stdlib.h>
#include<time.h>

void makeBox(int l,int w,int b,int p){
	srand(time(NULL));
	int medium;
	int small;

	//Randomizes the amount of boxes made
	int large =(int)((rand()/(double)RAND_MAX)*(p+1));
	if(large!=p){
		medium =(int)((rand()/(double)RAND_MAX)*(p-large));
	}
	if(large+medium!=p){
		small =p-large-medium;
	}

	//Initializes each boxes with 'e' inside for empty
	char box[b][l][w];
	for(int i=0;i<b;i++){
		for(int j=0;j<l;j++){
			for(int k=0;k<w;k++){
				box[i][j][k]='e';
			}
		}
	}
	//Temporary Value holders that are subtracted to 0 in each sized package loop down below
	int tempLarge=large;
	int tempMed=medium;
	int tempSmall=small;
	int counter=0;

	//Adds the large packages into the boxes
	for(int i=0;i<b;i++){
		for(int j=0;j<l;j++){
			for(int k=0;k<w;k++){
				if(tempLarge!=0){
					if(box[i][j][k]=='e' && box[i][j][k+1]=='e' && box[i][j+1][k]=='e' && box[i][j+1][k+1]=='e'){
						box[i][j][k]='L';
						box[i][j][k+1]='L';
						box[i][j+1][k]='L';
						box[i][j+1][k+1]='L';
						tempLarge-=1;
						counter+=1;
					}
					if(counter==4){break;}
				}
				if(counter==4){break;}
			}
			if(counter==4){
				counter=0;
				break;
			}
		}
	}
	
	//Adds the medium packages into the boxes
	for(int i=0;i<b;i++){
		for(int j=0;j<l;j++){
			for(int k=0;k<w;k++){
				if(tempMed!=0){
					if(box[i][j][k]=='e' && box[i][j][k+1]=='e'){
						box[i][j][k]='M';
						box[i][j][k+1]='M';
						tempMed-=1;
					}else if(box[i][j][k]=='e' && box[i][j+1][k]=='e'){
						box[i][j][k]='M';
						box[i][j+1][k]='M';
						tempMed-=1;
					}
				}
			}
		}
	}
	
	//Adds the small packages into the boxes
	for(int i=0;i<b;i++){
		for(int j=0;j<l;j++){
			for(int k=0;k<w;k++){
				if(tempSmall!=0){
					if(box[i][j][k]=='e'){
						box[i][j][k]='S';
						tempSmall-=1;
					}
				}
			}
		}
	}
	
	//Counts the amount of boxes used
	char Value;
	int boxCount=0;
	for(int i=0;i<b;i++){
		Value=box[i][1][1];
		if(Value!='e'){
			boxCount+=1;
		}
	}

	float total=(small*5.99)+(medium*10.99)+(large*19.99);
	printf("\nOrder:  Large=%.2d Medium=%.2d Small=%.2d\n", large,medium,small);
	printf("\nSmall   (%d units)		$%6.2f",small,  (small*5.99));
	printf("\nMedium  (%d units)		$%6.2f",medium, (medium*10.99));
	printf("\nLarge   (%d units)		$%6.2f",large,  (large*19.99));
	printf("\n------------------------------------------");
	printf("\nTotal	  			$%6.2f",total);
	printf("\nShipping (%d boxes)       	$%6.2f",boxCount,(boxCount*1.49));
	printf("\nHST  (13%%)			$%6.2f",(total*0.13));
	printf("\n------------------------------------------");
	printf("\nAmount Charge			$%6.2f\n",((total*1.13)+(boxCount*1.49)));

	//Prints the boxes
	printf("\nIndividual boxes are packed as follows:\n\n");
	for(int i=0;i<boxCount;i++){
		for(int j=0;j<l;j++){
			for(int k=0;k<w;k++){
				if(box[i][j][k]!='e'){
					printf("%c",box[i][j][k]);
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}

void main(){
	//parameter settings makeBox(length,width,Amount_Of_Boxes,Amount_Of_Packages);
	makeBox(5,4,6,24);
}
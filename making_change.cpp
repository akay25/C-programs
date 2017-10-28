#include <bits/stdc++.h>

using namespace std;

int total_amt, avl_change[100], avl_c_size;

int result[100][100];

int min(int x, int y){
	return (x<y)?x:y;
}

void print_results(){
	int i, j;
	printf("\n-------------------------------------------------------------------------------\n");
	printf("\t||");
	for(j=0;j<=total_amt;j++)
		printf("%d\t|", j);
	printf("\n");
	printf("-------------------------------------------------------------------------------\n");
	for(i=0;i<avl_c_size;i++){
		printf("%d\t||", avl_change[i]);
		for(j=0;j<=total_amt;j++){
			if(!result[i][j] && j!=0)
				printf(" \t|");
			else
				printf("%d\t|", result[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------------------------------------------------------\n");
}

int main(int argc, char * argv[]){

	int i, j, k;

	printf("Enter total number of changes:");
	cin>>avl_c_size;
	printf("\n");
	for(i=0;i<avl_c_size;i++){
		printf("Enter %d change amount:", i+1);
		cin>>avl_change[i];
	}

	printf("\nEnter the total amount to be calculated:");
	cin>>total_amt;

	for(i=0;i<avl_c_size;i++)
		result[i][0] = 0;
	k = 1;
	
	for(j=1;j<=total_amt;j++){
		for(i=0;i<avl_c_size;i++){
			printf("step %d:", k++);

			printf("\n\ti = %d", i + 1);
			printf("\n\tj = %d", j);
			printf("\n\td[%d] = %d",i+1, avl_change[i]);
			printf("\n\t--------");
			printf("\n\tc[%d, %d] = ",i+1, j);
 
			if(i == 0 && j < avl_change[0]){
				result[i][j] = 1000;
			}else if(i == 0){
				result[i][j] = 1 + result[i][j - avl_change[0]];
				printf("1 + c[1, %d]\t(Case I used)", j - avl_change[0]);
				printf("\n\tc[1, %d] = 1 + %d", j, result[i][j - avl_change[0]]);
				printf("\n\tc[1, %d] = %d\n",j, result[i][j]);
			}else if(j < avl_change[i]){
				result[i][j] = result[i-1][j];
				printf("c[%d, %d]\t(Case II used)",i, j);
				printf("\n\tc[%d, %d] = %d\n",i+1, j, result[i][j]);
			}else{

				printf("min(c[%d, %d] , 1 + c[%d, %d])\t(Case III used)",i, j, i+1, j - avl_change[i]);
				
				if(j - avl_change[i] >= 0){
					result[i][j] = min(result[i-1][j], 1 + result[i][j - avl_change[i]]);
					printf("\n\tc[%d, %d] = min(%d, %d)", i+1, j, result[i-1][j], 1 + result[i][j - avl_change[i]]);
				}else{
					result[i][j] = min(result[i-1][j], 1 + 1000);
					printf("\n\tc[%d, %d] = min(%d, inf)", i+1, j, result[i-1][j]);
				}
				printf("\n\tc[%d, %d] = %d\n",i+1, j, result[i][j]);
			}
			print_results();
		}
	}

	return 0;
}

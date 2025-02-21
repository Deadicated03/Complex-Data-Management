#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//konstantinos chatziioannou AM: 5389
typedef struct{
	
	int primary_key;
	int c_data;
	int e_data;
	int sum;
		
}keys;

int main(){
	
	keys db_r[1000];
	keys db_s[1000];
	char buffer_r[1000];
	char buffer_s[1000];
	char *data_r;
	char *data_s;
	FILE *infile_r;
	FILE *infile_s;
	FILE *outfile_s = fopen("O3.csv", "w");
	int temp_1[100];
	
	

	infile_r = fopen("R.csv","r");//*		//if you want different input file changes here*
	if(infile_r == NULL){
		printf("cant open file");
		exit(-1);	
	}
	
	infile_s = fopen("S.csv","r");//*
	if(infile_s == NULL){
		printf("cant open file");
		exit(-1);	
	}
	int j = 0;
	int len1;
	int len2;
	int i = 0;
	
											//same logic with cq file
	
	while(1){
		
	
			fgets(buffer_r,sizeof(buffer_r),infile_r);
			fgets(buffer_s,sizeof(buffer_s),infile_s);
			
			if (feof(infile_s)){
				break;
			}
			
			data_r = strtok(buffer_r,",");				
			db_r[j].primary_key = atoi(data_r);
			
			data_s = strtok(buffer_s,",");			
			
			data_s = strtok(NULL,",");			
			db_s[j].primary_key = atoi(data_s); //foreign key just named it like this	
			

			if((db_r[j].c_data == 7) && (db_r[j].primary_key != db_s[j].primary_key)) {
				fprintf(outfile_s,"%d,%d\n",db_r[j].primary_key,db_s[j].sum);							//prints data here because it needs db_r[j].primary_key
			}
				
		
			data_s = strtok(NULL,",");
			db_s[j].e_data = atoi(data_s);
			
			
			data_r = strtok(buffer_r,",");	
			while(db_r[j].primary_key < db_s[j].primary_key){
				len1 = ftell(infile_r);	
				fgets(buffer_r,sizeof(buffer_r),infile_r);
				db_r[j].primary_key = atoi(data_r);
				len2 = ftell(infile_r);
				i = 1;
			}	
			
			if(i == 1){
			db_r[j].c_data = 0;		//first time set c_data == 0
			db_s[j].sum = 0;			//first time set sum == 0
			data_r = strtok(buffer_r,",");	
			data_r = strtok(NULL,",");	
			data_r = strtok(NULL,",");	
			db_r[j].c_data = atoi(data_r);
			i = 0;
			}
			
				if(db_r[j].c_data == 7){		
					db_s[j].sum += db_s[j].e_data;			//for sumation
				}
			
		
			fseek(infile_r,-(len2-len1),SEEK_CUR);
			
				
	}
	
	fclose(infile_r);
	fclose(infile_s);
	fclose(outfile_s);

	return 0;
}
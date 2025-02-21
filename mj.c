#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//konstantinos chatziioannou AM: 5389
typedef struct{
	
	int primary_key;
	int first_data;
		
}keys;

int main(){

	keys db_r[1000];
	keys db_s[1000];
	char buffer_r[1000];
	char buffer_s[1000];
	char *data_r;
	char *data_s;
	int temp_1[100];
	int temp_2[100];
	int temp_3[100];
	FILE *infile_r;
	FILE *infile_s;
	FILE *outfile_s = fopen("O2.csv", "w");


	infile_r = fopen("R.csv","r");//*			//if you want different input file changes here*
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
	int i = 0;
	int len1;
	int len2;
	
	while(1){
	
			
			
			fgets(buffer_r,sizeof(buffer_r),infile_r);		//reads file one line at a time(take the cursor one line down)
			fgets(buffer_s,sizeof(buffer_s),infile_s);

			if (feof(infile_s)){
				printf("mpes");
				break;
			}			
					
			
			
			data_r = strtok(buffer_r,",");
			db_r[j].primary_key = atoi(data_r);				//take info of keys
			printf("%d\n",db_r[j].primary_key);
			
			data_s = strtok(buffer_s,",");			
			db_s[j].first_data = atoi(data_s);	
					
			data_s = strtok(NULL,",");			
			db_s[j].primary_key = atoi(data_s);				//foreign key just named it like this	
			
			
				
			
			data_s = strtok(NULL,",");			
			temp_3[j] = atoi(data_s);
		
			while(db_r[j].primary_key < db_s[j].primary_key){	//checks if the primary key is smaller what the foreign key
				len1 = ftell(infile_r);						//where it is before changing line
				fgets(buffer_r,sizeof(buffer_r),infile_r);	//changes line until it finds primary key == foreign key
				db_r[j].primary_key = atoi(data_r);									
				len2 = ftell(infile_r);						//where it is after changing line
				i = 1;
				
			}
			
			
			if(i == 1){										//gets in if only on first time
				data_r = strtok(buffer_r,",");
				data_r = strtok(NULL,",");			
				temp_1[j] = atoi(data_r);					//temp arrays get info of R file
				data_r = strtok(NULL,",");
				temp_2[j] = atoi(data_r);
				i = 0;
				
			}
			
			
			
			fseek(infile_r,-(len2-len1),SEEK_CUR);			//take back the cursor one line	
			fprintf(outfile_s,"%d,%d,%d,%d,%d\n", db_r[j].primary_key, temp_1[j],temp_2[j],db_s[j].first_data,temp_3[j]);

	}

		fclose(infile_r);
		fclose(infile_s);
		fclose(outfile_s);
		
	return 0;
}
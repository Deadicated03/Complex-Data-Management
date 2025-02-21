#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//konstantinos chatziioannou AM: 5389

typedef struct{
	
	int key;	
	int value;	
		
}array_element;


void merge_arrays(array_element array[],int l,int m,int r,int func_to_use){
	
	int left_len = m - l + 1; 				//len of left array
	int right_len = r - m;					//len of right array
	FILE *out = fopen("O1.csv", "w");
	
	
	array_element temp_left[left_len]; 		//temporary arrays
	array_element temp_right[right_len];
	int i,j,k;								//indexes i,j, and k is the index for our merged array
	
	for(i = 0; i < left_len; i++){		
		temp_left[i].key = array[l+i].key;	//fill temp array
		temp_left[i].value = array[l+i].value;
		
	}
		
	for(i = 0; i < right_len; i++){		
		temp_right[i].key = array[m+1+i].key;
		temp_right[i].value = array[m+1+i].value;
		
	}
	for(i = 0,j = 0,k = l; k <= r; k++){		
		
		
		if((i < left_len) && ((j >= right_len) || temp_left[i].key <= temp_right[j].key)) { 
			
			array[k].key = temp_left[i].key;
			array[k].value = temp_left[i].value;	//merges the two arrays
			i++;
			
		}
		else
		{
			array[k].key = temp_right[j].key;
			array[k].value = temp_right[j].value;	//merges the two arrays
			j++;
			
		}	
	}
	
	
	int array_key = array[1].key;
	int array_val = array[1].value;
	
	
	
	 for (int i = l; i <= r ; i++){				//takes out the duplicates
				
		 if (array[i].key != array_key){		//compares it with the next element
            fprintf(out, "%d, %d\n", array_key, array_val);   //prints in file the elements
            array_key = array[i].key;
            array_val = array[i].value;

        } 
		else{					
			if(func_to_use == 0){
				if(array[i].value > array_val){
					array_val = array[i].value;
				}
			}
			else if(func_to_use == 1){					//checks what func_to_use we have
				if(array[i].value < array_val){
					array_val = array[i].value;
				}
			}
			else if(func_to_use == 2){
				array_val += array[i].value;		
			}
		}
		}
		
	fprintf(out, "%d, %d\n", array_key, array_val);		//prints in file the elements
	
	fclose(out);
}


void recursion(array_element array[],int l,int r,int func_to_use){
	
	if(l < r){
		int m = (l + r)/2;		//splits array in half from the left side first until it finds m = 0;
		recursion(array,l,m,func_to_use);	
		recursion(array,m+1,r,func_to_use);
		merge_arrays(array,l,m,r,func_to_use);
	}
}
void merge_sort(array_element array[], int length,int func_to_use){
	
	recursion(array,0,length-1,func_to_use); //merge sort algorithm
	
}

int main(int agrc,char *argv[]){
	
	FILE *infile;
	char teamAttribute[10]; //attribute
	char calcAttribute[10]; //where is applied
	char calcFunction[10]; //sum max min
	char buffer[1000];
	char *data;
	int func_to_use;
	array_element db_0[5000];	//different columns
	array_element db_1[5000];
	array_element db_2[5000];
	array_element *array_attribute;
	array_element *array_calc;
	int array_len;

	
	
	strcpy(teamAttribute,argv[2]);
	strcpy(calcAttribute,argv[3]);
	strcpy(calcFunction,argv[4]);

	infile = fopen(argv[1],"r");
	if(infile == NULL){
		printf("cant open file");
		exit(-1);	
	}
	if(calcAttribute == teamAttribute){
		printf("cant be the same");
		exit(-1);
	}
	
	
	int j = 0;
	while(fgets(buffer,sizeof(buffer),infile)!= NULL){			
			data = strtok(buffer,",");				
			db_0[j].key = atoi(data);		
			data = strtok(NULL,",");
			db_1[j].key = atoi(data);
			data = strtok(NULL,",");
			db_2[j].key = atoi(data);
			j++;		

	}
	

	
	if(!strcmp(teamAttribute ,"0")){	
		array_attribute = db_0;
	
	}
	if(!strcmp(teamAttribute ,"1")){	//checks the teamAttribute and sets a pointer to the column
		array_attribute = db_1;
		
	}
	if(!strcmp(teamAttribute ,"2")){
		array_attribute = db_2;	
	}
	
	
	
	if(!strcmp(calcAttribute ,"0")){	
		array_calc = db_0;
	
	}
	if(!strcmp(calcAttribute ,"1")){	//checks the calcAttribute and sets a pointer to the column
		array_calc = db_1;
		
	}
	if(!strcmp(calcAttribute ,"2")){
		array_calc = db_2;	
	}
	
	
	
	if(!strcmp(calcFunction ,"max")){	
		func_to_use = 0;
	
	}
	if(!strcmp(calcFunction ,"min")){	//checks the calcFunc and sets func_to_use
		func_to_use = 1;
		
	}
	if(!strcmp(calcFunction ,"sum")){
		func_to_use = 2;	
	}
	
	array_len = j; //finds the len of the file

	for(int i = 0; i < array_len; i++){		
		array_attribute[i].value = array_calc[i].key; //sets the value of my attribute column to array_calc key
	}
	merge_sort(array_attribute,array_len,func_to_use);	
	fclose(infile);
	

	
}
	

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "random.h"
#include "vector.h"

void insert_erase_random(size_t init_size, size_t n);
void insert_erase_head(size_t init_size, size_t n);
void insert_erase_tail(size_t init_size, size_t n); 
void read_write_random(size_t init_size, size_t n); 
void read_write_sequential(size_t init_size, size_t n); 
void bubble_sort(size_t init_size, size_t n);

int main(int argc, char*argv[]){
	srand(time(NULL));
	
	if(argc != 4){
		printf("Aide : %s test_type init_size n\n", argv[0]);
		printf("\ttest_type :\n\t\tinsert_erase_random \n\t\tinsert_erase_head \n\t\tinsert_erase_tail \n\t\tread_write_random \n\t\tread_write_sequential \n\t\tbubble_sort \n");
		return 0;
	}

	return 0;
}

void insert_erase_random(size_t init_size, size_t n){

}

void insert_erase_head(size_t init_size, size_t n){

}

void insert_erase_tail(size_t init_size, size_t n){

}

void read_write_random(size_t init_size, size_t n){

}

void read_write_sequential(size_t init_size, size_t n){

}

void bubble_sort(size_t init_size, size_t n){

}

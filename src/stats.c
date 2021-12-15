/**
 * @file <stats.c> 
 * @brief <Implementation file for statistical analysis on an array dataset>
 *
 * <This implementation file takes an unsigned dataset, sorts it, then derives statistics such as maximum, minimum, median, mean from the sorted array.>
 *
 * @author <Daniel Isaac Kemajou Njamen>
 * @date <10/11/2020>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

/*void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};*/

  
  /* Other Variable Declarations Go Here */
  
  /*unsigned char max;
  unsigned char min;
  unsigned char med;
  unsigned char avg;
  
  avg = find_mean(test,SIZE);
  med = find_median(test,SIZE);
  max = find_maximum(test,SIZE);
  min = find_minimum(test,SIZE);
  
  print_statistics(avg,med,max,min);
  print_array(test,SIZE);
  
}*/
  /* Statistics and Printing Functions Go Here */
  
void sort_array(unsigned char *array, unsigned int arr_size){
  unsigned char i,j,tmp;
  for ( i=0; i<arr_size; i++){
      for (j = i+1;j<arr_size;j++){
           if(*(array+j)>*(array+i)){
              tmp = *(array+i);
              *(array+i) = *(array+j);
              *(array+j) = tmp;
              }
            }
       }  
   
  }

 unsigned char find_mean(unsigned char *array,unsigned int arr_size){
  unsigned char i;
  unsigned int average;
  unsigned char mean;
  for(i=0; i<arr_size;i++){
     average += *array;
     array++;
     }
  mean= (average/arr_size);
  return mean;  
  }

unsigned char find_median(unsigned char *array,unsigned int arr_size){
  unsigned char med;
  unsigned char i,j;
  
  sort_array(array,arr_size);
  
  i = array[arr_size/2];
  j = array[(arr_size/2)-1];
  med = (i+j)/2.0;
  return (unsigned int) med;
   
  }

unsigned char find_maximum(unsigned char *arr,unsigned int arr_size){
  unsigned char max;
  
  sort_array(arr,arr_size);
  max = arr[0];
  
  return max;
  }

unsigned char find_minimum(unsigned char *array,unsigned int arr_size ){
  unsigned char min;
  
  sort_array(array,arr_size);
  
  min =array[arr_size-1];
  return min;
  }  

void print_statistics(unsigned char mean,unsigned char median,unsigned char maximum,unsigned char minimum){
  printf("The mean is %u \n",(unsigned int) mean);
  printf("The median is %u \n", (unsigned int) median);
  printf("The maximum is %u \n",(unsigned int) maximum);
  printf("The minimum is %u \n",(unsigned int) minimum);
  }

void print_array(unsigned char *array,unsigned int size){
  #ifdef VERBOSE
		PRINTF("{");
		for (int i=0; i < size; i++){
			PRINTF("%i ", array[i]);
		}
		PRINTF("}\n\n");
  #endif
  }

/* Add other Implementation File Code Here */

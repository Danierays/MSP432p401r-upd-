/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <stats.h> 
 * @brief <Header file with function declarations for stats.c >
 *
 * <In this header file, I'll declare all the functions used for the analytics namely finding the median, maximum, minimum, sorting the array, as well as printing the array and the statistics>
 *
 * @author <Daniel Isaac Kemajou Njamen>
 * @date <10/11/2020>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void print_statistics(unsigned char mean,unsigned char median,unsigned char maximum,unsigned char minimum);
/**
 * @brief <A function that prints the statistics of an array>
 *
 * <Takes as input the maximum, minimum, mean and median of the array and prints these statistics.>
 *
 * @param <minimum> <minimum value in the array>
 * @param <maximum> <maximum value in the array>
 * @param <mean> <average value in the array>
 * @param <median> <middle value in a (largest to smallest) sorted array>
 *
 * @return <void>
 */

/* Add Your Declarations and Function Comments here */ 
void print_array(unsigned char *array,unsigned int size);
/**
 * @brief <A function that prints array>
 *
 * <Prints an array>
 *
 * @param <array> <array to be displayed>
 * @param <array_size> <size of array to be displayed>
 *
 * @return <void>
 */
 
 /* Add Your Declarations and Function Comments here */ 
unsigned char find_median(unsigned char *array,unsigned int size);
/**
 * @brief <A function that gets the median value of data array>
 *
 * <finds the median of an array by picking the middle value from a sorted array>
 *
 * @param <*array[]> <pointer to an n-element of sorted array>
 * @param <array_size> <Array-size of the dataset>
 *
 * @return <The median value>
 */

/* Add Your Declarations and Function Comments here */ 
unsigned char find_mean(unsigned char *array,unsigned int size);
/**
 * @brief <A function that gets the mean value of data array>
 *
 * <finds the mean of an array by summing all its n-element entries and dividing by its array size>
 *
 * @param <*array[]> <pointer to an n-element data array value>
 * @param <array_size> <Array-size of the dataset>
 *
 * @return <The mean value>
 */
 
 /* Add Your Declarations and Function Comments here */ 
unsigned char find_maximum(unsigned char *arr,unsigned int arr_size);
/**
 * @brief <A function that gets the maximum value of a dataset>
 *
 * <finds the maximum value of data array by taking the first entry element of the sorted array>
 *
 * @param <*array> <pointer to an array value>
 * @param <array_size> <Array-size of the dataset>
 *
 * @return <The maximum value>
 */
 
 /* Add Your Declarations and Function Comments here */ 
unsigned char find_minimum(unsigned char *array,unsigned int size);
/**
 * @brief <A function that gets the minimum value of data array>
 *
 * <finds the minimum value of a data array by taking the (n-1)element of the sorted array>
 *
 * @param <*array[]> <pointer to an (n-1)element of the data array>
 * @param <array_size> <Array-size of the dataset>
 *
 * @return <The minimum value>
 */
 
/* Add Your Declarations and Function Comments here */ 
void sort_array(unsigned char *array,unsigned int size);
/**
 * @brief <A function that sorts an array from largest to smallest.>
 *
 * <Takes as input the maximum, minimum, mean and median of the array and prints them as output>
 *
 * @param <*array> <pointer to an array value>
 * @param <array_size> <Array-size of the dataset>
 *
 * @return <void>
 */
#endif /* __STATS_H__ */

/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

bool searchhalf(int key,int arr[],int start,int end,int mid);
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int key, int arr[], int size)
{
    // TODO: implement a searching algorithm
    if(size < 0){
        return false;
    }
    
    int start = 0,end = size-1,mid = (start+end)/2;
    
    if( start <= end ){
        
        if(arr[mid] == key ){
        return true;
        }
         else if(arr[mid] > key){
            end = mid - 1;
            bool p;
            p = searchhalf(key,arr,start,end,mid);
            return p;
        }else{
            start = mid + 1;
            bool p;
            p = searchhalf(key,arr,start,end,mid);
            return p;
         }
    }
    
    return false;
}

bool searchhalf(int key,int arr[],int start,int end,int mid){
    
    mid = (start + end)/2;
    
    if( start <= end ){
        
        if(arr[mid] == key ){
            return true;
        }
        else if(arr[mid] > key){
            end = mid - 1;
            bool p;
            p = searchhalf(key,arr,start,end,mid);
            return p;
        }
        else{
            start = mid + 1;
            bool p;
            p = searchhalf(key,arr,start,end,mid);
            return p;
        }  
    }
    
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    int i=0;
    int j=0;int temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            temp = values[j];
            if(values[j] > values[j+1]){
                values[j] = values[j+1];
                values[j+1] = temp;
            }
        }
    }
    
   
    return;
}
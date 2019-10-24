#include<stdio.h>

void mergeSort(int [], int, int, int);
void partition(int [],int, int);
void quicksort(int [], int, int);
int largest(int [], int );
void RadixSort(int [], int );
void counting_sort(int [], int, int);
int main(){
    int list[10000];
    int i, size, op, max = 0;
    printf("Enter total number of elements:");
    scanf("%d", &size);
    printf("Enter the elements:\n");
    for(i = 0; i < size; i++){
      scanf("%d", &list[i]);
      if(list[i] > max){
        max = list[i];
      }
    }
    printf("Which sorting algorithm you want to use? \n1.Merge Sort \n2.Quick Sort \n3.Radix Sort \n4.Counting Sort \n");
    scanf("%d", &op);

    switch(op){
       case 1: {	       
          partition(list, 0, size - 1);
          printf("After merge sort:\n");
          for(i = 0;i < size; i++){
          printf("%d\n",list[i]);
          }
       }
       break;
       case 2: {
          quicksort(list, 0, size - 1);
	  printf("After quick sort: \n");
	  for(i = 0; i < size; i++){
	    printf("%d\n", list[i]);
	  }
       }
       break;
       case 3:{
          RadixSort(list, size);         	      
	  printf("After radix sort: \n");
	  for(i = 0; i < size; i++){
	    printf("%d\n", list[i]);
	  }
       }
       break;
       case 4:{
         counting_sort(list, size, max);
       }
   }
	       
}
void partition(int list[],int low,int high){
    int mid;
    if(low < high){
        mid = (low + high) / 2;
        partition(list, low, mid);
        partition(list, mid + 1, high);
        mergeSort(list, low, mid, high);
    }
}
void mergeSort(int list[],int low,int mid,int high){
    int i, mi, k, lo, temp[50];
    lo = low;
    i = low;
    mi = mid + 1;
    while ((lo <= mid) && (mi <= high)){
        if (list[lo] <= list[mi]){
            temp[i] = list[lo];
            lo++;
        }else{
            temp[i] = list[mi];
            mi++;
        }
        i++;
    }
    if (lo > mid){
        for (k = mi; k <= high; k++){
            temp[i] = list[k];
            i++;
        }
    } else{
        for (k = lo; k <= mid; k++){
             temp[i] = list[k];
             i++;
        }
    }
    for (k = low; k <= high; k++){
        list[k] = temp[k];
    }
}

void quicksort(int list[25],int first,int last){
   int i, j, pivot, temp;

   if(first < last){
      pivot = first;
      i = first;
      j = last;

      while(i < j){
         while(list[i] <= list[pivot] && i < last)
            i++;
         while(list[j] > list[pivot])
            j--;
         if(i < j){
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
         }
      }

      temp = list[pivot];
      list[pivot] = list[j];
      list[j] = temp;
      quicksort(list, first, j - 1);
      quicksort(list, j + 1, last);

   }
}
int largest(int a[], int n){
    int large = a[0], i;
    for(i = 1; i < n; i++){
        if(large < a[i])
            large = a[i];
    }
    return large;
}
void RadixSort(int a[], int n){
    int bucket[10][10], bucket_count[10];
    int i, j, k, remainder, NOP=0, divisor=1, large, pass;

    large = largest(a, n);
    while(large > 0){
        NOP++;
        large/=10;
    }
    for(pass = 0; pass < NOP; pass++){
        for(i = 0; i < 10; i++){
            bucket_count[i] = 0;
        }
        for(i = 0; i < n; i++){ 
            remainder = (a[i] / divisor) % 10;
            bucket[remainder][bucket_count[remainder]] = a[i];
            bucket_count[remainder] += 1;
        } 
        i = 0;
        for(k = 0; k < 10; k++){
            for(j = 0; j < bucket_count[k]; j++){
                a[i] = bucket[k][j];
                i++;
            }
        }
        divisor *= 10;
    }
}
void counting_sort(int a[],int n,int max){
  int count[50]={0},i,j;

  for(i=0;i<n;++i){
      count[a[i]]=count[a[i]]+1;
  }
  printf("Sorted elements are:\n");

  for(i=0;i<=max;++i){
    for(j=1;j<=count[i];++j){
      printf("%d\n",i);
    }
  }
}


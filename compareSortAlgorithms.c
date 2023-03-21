#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int extraMemoryAllocated;
	
// implement merge sort
// extraMemoryAllocated counts bytes of extra memory allocated
void merge(int pData[], int l, int m, int r) {
    int a;
    int b;
    int c;
    
    int num1 = m - l + 1;
    int num2 = r - m;
 
    int L[num1];
	int R[num2];
 
    for (a = 0; a < num1; a++) {
        L[a] = pData[l + a];
        
    }
        
        
    for (b = 0; b < num2; b++) {
        R[b] = pData[m + 1 + b];
    }
 
    a = 0;
    b = 0;
    c = l;
    
    
    while (a < num1 && b < num2) {
        if (L[a] <= R[b]) {
            pData[c] = L[a];
            a++;
        }
        
        
        else {
            pData[c] = R[b];
            b++;
        }
        c++;
    }
 
    while (a < num1) {
        pData[b] = L[a];
        a++;
        c++;
    }
 
    while (b < num2) {
        pData[c] = R[b];
        b++;
        c++;
    }
}
 
void mergeSort(int pData[], int l, int r) {
    if (l < r) {
        int middle = l + (r - l) / 2;
        
        
        mergeSort(pData, l, middle);
        mergeSort(pData, middle + 1, r);
        merge(pData, l, middle, r);
    }
}

// implement insertion sort
// extraMemoryAllocated counts bytes of memory allocated
void insertionSort(int* pData, int n)
{
	int a;
	int data;
	int c;
	
	for (a = 0; a < n; a++) {
		data = pData[a];
		c = a - 1;
	}
	
	while (c > 0 && pData[c] > data) {
		pData[c + 1] = pData[c];
		
		c -= 1;
	}
	
	pData[c + 1] = data;
	}
	



// implement bubble sort
// extraMemoryAllocated counts bytes of extra memory allocated
void bubbleSort(int* pData, int n)
{
	int a;
	int b;
	
	for (a = 0; a < n - 1; a++) {
		for (b = 0; b < n - 1; b++) {
			
			if (pData[b] > pData[b + 1]) {
				int t = pData[b];
				pData[b] = pData[b + 1];
				pData[b + 1] = t;
			}
		}
	}
	}


// implement selection sort
// extraMemoryAllocated counts bytes of extra memory allocated
void selectionSort(int* pData, int n) {
    int a; 
	int b; 
	int min;
    
    
    for (a = 0; a < n - 1; a++) {
        min = a;
    
        for (b = a + 1; b < n; b++) {
        	
            if (pData[b] < pData[min]) {
            	
                min = b;
                
        int t = pData[min];
        
        pData[min] = pData[a];
        
        pData[a] = t;
    }
    }
}
    }

// parses input file to an integer array
int parseData(char *inputFileName, int **ppData)
{
	FILE* inFile = fopen(inputFileName,"r");
	int dataSz = 0;
	*ppData = NULL;
	
	if (inFile)
	{
		fscanf(inFile,"%d\n", &dataSz);
		*ppData = (int *)malloc(sizeof(int) * dataSz);
		// Implement parse data block
		
		if (*ppData) {
			
			for (int i = 0; i < dataSz; i++) {
				fscanf(inFile, "%d\n", &((*ppData)[i]));
			}
		}
		
	}
	
	fclose(inFile);
	return dataSz;
}

// prints first and last 100 items in the data array
void printArray(int pData[], int dataSz)
{
	int i, sz = dataSz - 100;
	printf("\tData:\n\t");
	for (i=0;i<100;++i)
	{
		printf("%d ",pData[i]);
	}
	printf("\n\t");
	
	for (i=sz;i<dataSz;++i)
	{
		printf("%d ",pData[i]);
	}
	printf("\n\n");
}

int main(void)
{
	clock_t start, end;
	int i;
    double cpu_time_used;
	char* fileNames[] = {"input1.txt", "input2.txt", "input3.txt"};
	
	for (i=0;i<3;++i)
	{
		int *pDataSrc, *pDataCopy;
		int dataSz = parseData(fileNames[i], &pDataSrc);
		
		if (dataSz <= 0)
			continue;
		
		pDataCopy = (int *)malloc(sizeof(int)*dataSz);
	
		printf("---------------------------\n");
		printf("Dataset Size : %d\n",dataSz);
		printf("---------------------------\n");
		
		printf("Selection Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz*sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		selectionSort(pDataCopy, dataSz);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n",cpu_time_used);
		printf("\textra memory allocated\t: %d\n",extraMemoryAllocated);
		printArray(pDataCopy, dataSz);
		
		printf("Insertion Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz*sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		insertionSort(pDataCopy, dataSz);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n",cpu_time_used);
		printf("\textra memory allocated\t: %d\n",extraMemoryAllocated);
		printArray(pDataCopy, dataSz);

		printf("Bubble Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz*sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		bubbleSort(pDataCopy, dataSz);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n",cpu_time_used);
		printf("\textra memory allocated\t: %d\n",extraMemoryAllocated);
		printArray(pDataCopy, dataSz);
		
		printf("Merge Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz*sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		mergeSort(pDataCopy, 0, dataSz - 1);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n",cpu_time_used);
		printf("\textra memory allocated\t: %d\n",extraMemoryAllocated);
		printArray(pDataCopy, dataSz);
		
		free(pDataCopy);
		free(pDataSrc);
	}
	
}

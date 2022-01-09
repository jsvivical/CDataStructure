#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define SIZE 100
#define COMPARE(x,y) (((x) < (y))? -1 : ((x) == (y)) ? 0 : 1)

int iter_binsearch(int list[], int searchnum, int left, int right)
{
	int middle;
	while(left <= right)
	{
		middle = (left + right) / 2;
		if(list[middle] == searchnum) return middle;
		else if(list[middle] < searchnum) 
		{
			left = middle + 1;
		}
		else right = right -1;
	}
	return -1;
}

int search(int list[], int searchnum, int size)
{
	int i= 0;
	for(i = 0; i < size; i++)
	{
		if(list[i] == searchnum) return i;
	}
	return -1;
}

int main()
{
	FILE *fp = NULL;
	int list[100];
	int start = 0;
	int index = 0;
	int i, searchnum;
	 fp = fopen("in.txt","r");
	if(fp == NULL)
	{
		printf("���� ���⿡ �����߽��ϴ�.\n");
		exit(1);
	}

	while(!feof(fp))
	{
		fscanf(fp, "%d" , &list[index]);
		index++;
	}

	/*for(i = 0; i< index; i++)
	{
		printf("%d ", list[i]);
	}*/

	printf("ã������ ���� : ");
	scanf("%d", &searchnum);
	i = iter_binsearch(list, searchnum, start, index);
	if(i == -1) printf("ã�⿡ �����߽��ϴ�.\n");
	else printf("iterative binary search�� ��� : %d\n\n", i);
	

	printf("ã������ ���� : ");
	scanf("%d", &searchnum);
	

	i = search(list, searchnum,index);
	if(i == -1) printf("ã�⿡ �����߽��ϴ�.\n");
	else printf("sequential search�� ��� : %d\n\n", i);
	


	return 0;

}
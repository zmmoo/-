#include <stdio.h>
void selection_sort(int *dat,int n)
{
	for(int i=0; i<n-1; i++)
	{
		int min = i;
		int temp;
		for(int j=i+1; j<n; j++)
			if(dat[j] < dat[min])
				min = j;
		if (min != i)
		{
		temp = dat[min];
		dat[min] = dat[i];
		dat[i] = temp;	
		}
	}
}

void insertion_sort(int *dat, int n)
{
	for(int i=1; i<n; i++)
	{
		int t = dat[i];
		int j;
		for(j=i; j>0 && dat[j-1]>t; j--)
		{
			dat[j] = dat[j-1];
		}
		dat[j] = t;
	}
}

void shell_sort(int *dat, int n)
{
	for(int inc = n/3; inc>=1; inc/=3)
	{
		for(int i=inc; i<n; i++)
		{
			int t = dat[i];
			int j;
			for(j=i; j>=inc && dat[j-inc]>t; j-=inc)
			{
				dat[j] = dat[j-inc];
			}
			dat[j] = t;
		}
	}

}

void bubble_sort(int *dat,int n)
{
	for(int i=0; i<n-1; i++)
	{
		int temp;
		for(int j=i+1; j<n; j++)
			if(dat[j] < dat[i])
			{
				temp = dat[j];
				dat[j] = dat[i];
				dat[i] = temp;	
			}
	}
}

void swap(int *dat,int l, int m)
{
	int temp;
	temp = dat[l];
	dat[l] = dat[m];
	dat[m] = temp;
}


void quick_sort(int *x,int l, int u)
{
    if (l >= u)
	return;
    int m = l;
    for (int i = l+1; i<= u; i++)
    {
       	if(x[i] < x[l])
    		swap(x, ++m, i);
    }
    swap(x, l, m);
    quick_sort(x, l, m-1);
    quick_sort(x, m+1, u);
}


int main()
{
	int a[] = {2,4,9,3,8,1,0,5,10};
	//selection_sort(a, 8);
//	insertion_sort(a, 8);
//	shell_sort(a, 9);
	quick_sort(a,0,9);
//	bubble_sort(a, 9);
	for(int i=0; i<9; i++)
		printf("%d",a[i]);
	return 0;
}

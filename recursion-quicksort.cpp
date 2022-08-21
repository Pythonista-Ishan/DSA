#include <iostream>

using namespace std;

int partition (int arr[],int s,int e)
{
  int pivot = arr[s];
  int cnt = 0;
  for (int i = s + 1; i <= e; i++)
    {
      if (arr[i] <= pivot)
	{
	  cnt++;
	}
    }
  //place pivot at right position
  int pivotindex = s + cnt;
  swap (arr[pivotindex], arr[s]);

  int i = s, j = e;
  while (i < pivotindex && j > pivotindex)
    {
      while (arr[i] < pivot)
	{
	  i++;
	}
      while (arr[j] > pivot)
	{
	  j--;
	}
      if (i < pivotindex && j > pivotindex)
	{
	  swap (arr[i], arr[j]);
	  i++;
	  j--;
	}
    }
}

void
quickSort (int arr[], int s, int e)
{ //base case
  if (s >= e)
    {
      return;
    }
  int p = partition (arr, s, e);
//leftsort
  quickSort (arr, s, p - 1);
  
//rightsort  
  quickSort (arr, p + 1, e);
}

int
main ()
{
  int arr[10] = { 45,69,15,78,24,69,54,24,88,125 };
  int n = 10;

  quickSort (arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    {
      cout << arr[i] << " ";
    } cout << endl;


  return 0;
}

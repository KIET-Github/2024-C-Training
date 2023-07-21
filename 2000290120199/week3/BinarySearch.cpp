//Given a sorted array you need to find the index where the given element is present if element not found then return -1.

//Simple iterative approach
int binarySearch(vector<int>&arr , target)
{
  int l=0;
  int n=arr.size();
  int h=n-1;
  while(l<=h)
    {
      int mid = (l+h)/2;
      if(arr[mid]==target)
        return mid; // target present at mid.
      else if(arr[mid]<target)
        low=mid+1; // target present somewhere in right of mid.
      else
        high=mid-1; // target present in the left of mid.
    }
  return -1;
}

//Recursive approach
int binarySearch(vector<int>&arr , target , low , high)
{
  int low=0;
  int n=arr.size();
  int high=n-1;

  if(low>high)
   return -1;  
  int mid = (low+high)/2;
      
  if(arr[mid]==target)
   return mid; // target present at mid.
  else if(arr[mid]<target)
   return binarySearch(arr, target, mid+1, high); // target present somewhere in right of mid.
  return binarySearch(arr , target, low, mid-1); // target present in the left of mid.
    }
  
}

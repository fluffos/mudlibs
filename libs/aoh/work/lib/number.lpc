/*
** A collection of functions to handle integers
** Author: Thragor@Nightfall, 20dec94
** Update: Thragor@Nightfall, 07jul95
*/

public int round(float f)
{
  if (f>0.0) return to_int(f+0.5);
  else if (f<0.0) return to_int(f-0.5);
  else return 0;
}
public int abs(int i)
// Return the absolute value of i
{
  return i<0?-i:i;
}

public int sign(int i)
// Return -1, 0 or 1 when i is negative, 0 or positive
{
  return i<0?-1:i>0?1:0;
}

public int max(int *arr)
// Return the maximum of all numbers
{
  return sort_array(arr,#'<)[0];
}

public int min(int *arr)
// Return the minimum of all numbers
{
  return sort_array(arr,#'>)[0];
}

public int sum(int *arr)
// Return the sum of all values.
{
  int res;
  while(sizeof(arr))
    {
      res+=arr[0];
      arr=arr[1..];
    }
  return res;
}

public int val(string v)
// Converts a number contained in a string into the value
{
  return to_int(v);
}

public float a_avarage(int *arr)
// Arythmetic avarage: (a1+...+an)/n
{
 int i,s;
 float result;

 s = i = sizeof(arr);
 result = 0.0;
 while(i--) result+=to_float(arr[i]);
 return result/to_float(s);
}

public float g_avarage(int *arr)
// Geometric avarage: (a1*...*an)*(1/n)
{
 int i,s;
 float result;

 s = i = sizeof(arr);
 result = 1.0;
 while(i--) result*=to_float(arr[i]);
 return result/to_float(s);
}

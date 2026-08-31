/*
// File: exclude_array.c
// A simul_efun module.
// Thanks to the folks at Portals for this one.
// Author: either Huthar or Wayfarer, I presume.
// Now a part of the TMI distribution mudlib.
// Purpose: to remove a range from an array
*/

varargs mixed *exclude_array(mixed *arr, int fro, int t)
{
   mixed *bottom,*top;
   
   bottom = ({ });
   top = ({ });
   
   if(!t) t = fro;
   if(fro > 0)
      bottom = arr[0 .. fro - 1];
   if(t < sizeof(arr) - 1)
      top = arr[t + 1 .. sizeof(arr) - 1];
   return bottom + top;
}


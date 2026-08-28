/*
// File: exclude_array.c
// A simul_efun module.
// Thanks to the folks at Portals for this one.
// Author: either Huthar or Wayfarer, I presume.
// Now a part of the TMI distribution mudlib.
// Purpose: to remove a range from an array
// Parnell --- changed mixed name from array to aray... invalid name
*/
varargs mixed *exclude_array(mixed *aray,int from, int to)
{
   mixed *bottom,*top;
   
   bottom = ({ });
   top = ({ });
   
   if(!to) to = from;
   if(from > 0)
      bottom = aray[0 .. from - 1];
   if(to < sizeof(aray) - 1)
      top = aray[to + 1 .. sizeof(aray) - 1];
   return bottom + top;
}

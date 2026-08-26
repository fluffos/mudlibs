/*
// writef.c - Oct25/91 by Jubal
// This file is a part of the TMI distribution mudlib.
// Please retain the header if you use it.
*/

#include <writef.h>

string
writef( string str, int n, int flags )
{
   int len, i;
   
   if( ! str ) str = "";
   len = strlen( str );
   if( len < n )
      {
      if( flags & JFY_RIGHT )
         {
         str = extract( PAD, 0, n - len - 1 ) + str;
      }
      else
         {
         str += extract( PAD, 0, n - len - 1 );
      }
   }
   else if( len > n )
      {
      if( ! ( flags & TRUNCATE ) )
         {
         str = extract( ERR, 0, n-1 );
         }
      else if( flags & TRUNC_RIGHT )
         {
         if( flags & TRUNC_ELL )
            str = extract( str, 0, n - 4 ) + "...";
         else
            str = extract( str, 0, n - 1 );
           }
      else
         {
         if( flags & TRUNC_ELL )
            str = "..." + extract( str, len - n + 3, len - 1 );
         else
            str = extract( str, len - n, len - 1 );
           }
   }
   if( ! ( flags & QUIET ) ) write( str );
   return str;
}

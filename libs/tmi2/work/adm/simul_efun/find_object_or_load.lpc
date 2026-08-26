/*
// file: find_object_or_load.c
// Author either Huthar or Wayfarer
// Thanks to the folks at Portals for this one.
// Now a part of the distribution mudlib.
// Purpose: To either find the object with the matching file,
// and return it, or to load it, then return it.
*/
#include <config.h>

object find_object_or_load (string str)
{
   object ob;
   
   ob = find_object(str);
   if (ob != 0)
      return ob;
   seteuid(geteuid(previous_object()));
   catch( call_other( str, "???" ) );
   seteuid(0);
   ob = find_object(str);
   return ob;
}

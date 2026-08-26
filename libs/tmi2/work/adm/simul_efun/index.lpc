/*
// Index.c written by Sulam@TMI
// Yet another handy little simul_efun for you!
// Happily sliced into a module by Buddha(2-18-92)
// A part of the TMI distribution mudlib... keep the header...
*/

int
index(mixed target, mixed *array, int offset)
{
   int i;
   
   if( !pointerp(array) || !intp(offset) ) return -1;
   array = array[offset..<1];
   if( (i = member_array(target, array)) < 0 ) return -1;
   else return i+offset;
}

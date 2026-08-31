
/* break_string (new) shall be even faster */

varargs string break_string(string what,int when)
{
   int sz, i, j;
   string ret;

   sz = strlen(what);

   if (!when || when >= sz)
       return what;

   j = when;  
   i = 0;
   ret = "";

   while(i < j && j < sz) 
   {
      if (what[j]==32) 
      {
          ret = ret + what[i..j]+"\n";
          i = j + 1;
          j = j + when;
      }
      j--; 
   }
   return (ret + what[i..sz]);
}

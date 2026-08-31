#include <daemons.h>

string *alpha = ({ "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
                   "l", "m", "n","o","p","q","r","s","t","u","v","w","x",
                  "y", "z" });
int is_alphanum(string str)
{
 int i;
 string s; 
 i = strlen(str);
 while(i--)
  {
   s = sprintf("%c", str[i]);
   if (member_array(s, alpha)) return 1;
  }
 return 0;
}


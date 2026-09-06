/*     
   Show the talents of a player

   [Softbyte] 12mar98 Creation
*/

#include <properties.h>
#include <daemons.h>
#include <msgclass.h>

#define TP this_player()
#define SLIB "/lib/string"

string GetTString(string s)
{
  int value;
  string m;

  if (!s) return "";
  value=({int})TP->QueryTalent(s);
  switch(value)
  {
    case 0..150:   m="very low";
    break;
    case 151..250:   m="low";
    break;
    case 251..500: m="medium";
    break;
    case 501..750: m="good";
    break;
    case 751..900: m="very good";
    break;
    case 901..1000: m="excellent";
    break;
    default:  m="unknown";
  }
  return capitalize(s)+" ("+m+")";
}

public int main( string arg ) {
  string s;
  int i;
  string *idx;

  seteuid(getuid());
  idx=({string *})TP->QueryTalents()||({});

  if (!idx || !sizeof(idx))
  {
    s="Seems, you have no talents.\n";
  }
  else 
  {
    s=({string})SLIB->cadjust(" "+({string})TP->QueryShort()+"'s talents ",75,"-=")+"\n";  }

  for (i=0;i<sizeof(idx);i+=3)
  {
      if (i+2<sizeof(idx))
          s+=sprintf("   %-24.24s %-24.24s %-24.24s\n",
             GetTString(idx[i]),
             GetTString(idx[i+1]),
             GetTString(idx[i+2]));
      else if (i+1<sizeof(idx))
          s+=sprintf("   %-24.24s %-24.24s\n",
             GetTString(idx[i]),
             GetTString(idx[i+1]));
      else  
          s+=sprintf("   %-24.24s\n",GetTString(idx[i]));
  }

  s+=({string})SLIB->mkstr(75,"-=")+"\n";  msg_write( CMSG_GENERIC|MMSG_MORE,s);  seteuid(0);
  return 1;
}





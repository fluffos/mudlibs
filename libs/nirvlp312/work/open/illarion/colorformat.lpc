inherit "obj/clean";
#include "/players/illarion/esc.h"
#define NORM ESC+"[2;37;0m"

varargs string colorformat(string str,int wid) {
  string *ansi;
  int *place;
  int prev,count,size;
  string str1,str2,str3;
  ansi=({}); place=({});
  if(!str) return 0;
  /* strip out the ansi, and keep it in an array */
  while((sscanf(str,"%s"+ESC+"%sm%s",str1,str2,str3) >=1) && str2) {
    str=(str1?str1:"")+(str3?str3:"");
    ansi+=({ESC+str2+"m"});
    place+=({(str1?strlen(str1)-1:0)});
    prev=place[count];
    str1=0; str2=0; str3=0;
    count++;
  }
  str=(wid?format(str,wid):format(str));
  size=sizeof(place);
  if(!size)
    return str+NORM;
  /* stick the ansi back in in the right places */
  else {
    string final;
    final="";
    prev=0;
    for(count=0;count<size;count++) {
      if(place[count]-prev>=1)
        final+=(extract(str,prev,place[count])+(ansi[count]));
      else
        final+=ansi[count];
      prev=(place[count]+1);
    }
    final+=extract(str,prev);
    return final+NORM;
  }
}

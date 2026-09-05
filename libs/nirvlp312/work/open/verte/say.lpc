#define color HIW
#include "../std.h"
status main(string str) 
{
   string verb;
   if(!str) 
   {
      FAIL("Say what?\n");
      return 0; 
   }
   if(strlen(str) > 1)
   {
     if(str[strlen(str)-2..strlen(str)-1] == ":)")
       verb = "smile";
     else if(str[strlen(str)-2..strlen(str)-1] == ":(")
       verb = "frown";
     else if(str[strlen(str)-2..strlen(str)-1] == ";)")
       verb = "wink";
     else if(str[strlen(str)-2..strlen(str)-1] == ";(")
       verb = "sadly wink";
     else if(str[strlen(str)-1] == '?')
       verb = "ask";
     else if(str[strlen(str)-1] == '!')
       verb = "exclaim";
     else
       verb = "say";
   }
   else verb = "say";
    write(color+"You "+verb+":"+NORM+" "+str+"\n");
    say(color+CAP((string)TPRN) + " "+verb+"s:"+NORM+" " + str + "\n");
   return 1; 
}

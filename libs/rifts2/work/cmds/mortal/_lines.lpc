 
//_lines.c
//A utility to help wizards keep track of what lines they're
//on, and to them turn all off and on with one command.
//by Gregon@nightmare
//
//Zortek 960321 Modifed the display to be easier to read
//at a glance. 
 
#include <std.h>
inherit DAEMON;
 
int cmd_lines(string str) {
 
string *ob, col, wibble;
int i;
 
ob = (string *)this_player()->query_channels();
  if(!str) {
  wibble = "";
  write("%^BLUE%^+-------------------------------------------------------------+%^RESET%^");
    for(i=0; i<sizeof(ob); i++) {
      switch(ob[i]) {
        case "newbie":      col = "%^BOLD%^MAGENTA%^"; break;
        case "darke":       col = "%^BOLD%^"; break;
        case "cre":         col = "%^BOLD%^BLUE%^"; break;
        case "intercre":    col = "%^BOLD%^CYAN%^"; break;
        case "admin":       col = "%^YELLOW%^"; break;
        case "arena":       col = "%^BOLD%^RED%^"; break;
        case "high-mortal": col = "%^B_BLUE%^YELLOW%^"; break;
        case "council":     col = "%^B_RED%^YELLOW%^"; break;
        case "bid":      col = "%^B_GREEN%^WHITE%^"; break;
        case "arch":      col = "%^B_MAGENTA%^WHITE%^"; break;
        default:            col = "%^GREEN%^";
      }
      if(this_player()->query_blocked(ob[i]))
        wibble += col+sprintf("[ ]  %-17s  ",ob[i])+"%^RESET%^";
      else
        wibble += col+sprintf("[X]  %-17s  ",ob[i])+"%^RESET%^";
      if(i%3 == 2) {
        write(wibble);
        wibble = "";
      }
    }
  write("\n%^RESET%^BLUE%^+-------------------------------------------------------------+");
  write("%^BLUE%^|%^RESET%^         [X]  On Channel            [ ]  Off Channel         %^BLUE%^|%^RESET%^");
  write("%^BLUE%^+-------------------------------------------------------------+%^RESET%^");

  return 1;
}
 
  if(str=="on"){
      for(i=0; i<sizeof(ob);i++){
      if(this_player()->query_blocked(ob[i]))
        this_player()->set_blocked(ob[i]);
     }
     return 1;
}
 
  if(str=="off"){
      for(i=0; i<sizeof(ob);i++){
      if(!this_player()->query_blocked(ob[i]))
        this_player()->set_blocked(ob[i]);
     }
     return 1;
}
 
}		
 
void help(){
     write(@HELP
Syntax: lines -or- lines [on|off]
 
With no argument this command will display the status of the
lines/channels to which you have access.  With the argument
on|off it will turn all of the lines on or off.
HELP
);
}

// Written by Chronos (6/4/96) 
// (04-05-98) Chronos removed all traces of %^BOLD%^ references and their like.
//            This command is designed to allow wizards to change their titles
//            quickly and easily.
// April 21st 1998 Nightmask stole the file and changed a few things.
#include <mudlib.h>


inherit DAEMON ;

int cmd_title(string title) {
  string temp;
  if (TP->query_level() < 30) {
     write("You must be 30th level to change your title.\n");
  return 1;
  }  
  if (!title) {
  write("Your title is currently set to:\n"+TP->query("short") +
   "\n");
     return 1;
  } 
  if (sscanf(title, "%s$N%s", temp, temp)!=2)
   TP->setenv("TITLE", "$N "+title+" ($A)");
  else TP->setenv("TITLE", title + " ($A)");
  write("Your title is now set to:\n"+TP->query("short")+"\n");
  return 1 ;
}

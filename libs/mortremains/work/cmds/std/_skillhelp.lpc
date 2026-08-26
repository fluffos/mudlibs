// Made to work right by Chronos.
// (06-10-00) Chronos adds a header.

#include <mudlib.h>

inherit DAEMON ;
#define HELP "/doc/"

int cmd_skillhelp(string str) {
  string work, work2;
  if (!str) str = "index";

// Chronos had to use this since substr is not here.. ????
  if (sscanf(str, "%s %s", work, work2) == 2) {
       str = work+"_"+work2; }
  if (TP->more(HELP+"skills/"+str) != 1) {
    write("[SkillHelp] Could not find help on that skill.\n") ;
    return 1;
  }
return 1;
}

string help() {
   return @ENDHELP
Usage: skillhelp [<skill>]

This command gives you info about a particular skill.  All the
available skills will be listed if you do not include an argument.
ENDHELP
  ;
}

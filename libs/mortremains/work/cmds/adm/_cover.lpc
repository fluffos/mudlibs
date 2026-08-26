#include <mudlib.h>

inherit DAEMON;

int cmd_cover() {
  int cover ;
  cover = TP->query("prevent_scry") ;
  switch(cover) {
    case 1: write("You are no longer covered from scrying.\n") ;
    TP->delete("prevent_scry") ;
            break ;
   default: write("You are now covered from scrying.\n") ;
       TP->set("prevent_scry", 1) ;
    break ;
  }
  return 1;
}

string help() {
   return @ENDHELP
Usage: cover

This command toggles your scry-covering ability.  This prevents people
from seeing where you are, either with a scry command or with the
people command.
ENDHELP
   ;
}

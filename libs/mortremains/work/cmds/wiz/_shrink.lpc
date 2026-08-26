// A command to allow a wizard to shrink at will.
// (08-27-96) Written by Chronos.
// (04-10-98) Ported to new lib, Chronos@NK.

#include <mudlib.h>

inherit DAEMON;

int cmd_shrink(string str) {
  int i;
  if (!str) {
    write("You are currently at size "+TP->query("size")+".\n");
    return 1;
  }
  if (sscanf(str, "%d",i)!= 1) {
    write("You must supply an integer by which to shrink.\n");
    return 1;
  }
  if (i<1) {
    write("If you want to be larger, you need to GROW.\n");
    return 1;
  }
  TP->add("size", -1 * i);
  write("You shrink by a factor of "+i+", bringing you to a size "+
     TP->query("size")+".\n");
  say(TPN+" suddenly shrinks!\n");
  return 1;
}

string help() {
  return @ENDHELP
Usage: shrink [size_factor]

This command allows you to shrink your size how ever much you want.
The effort is temporary, and only lasts until you log out.

With no arguments, this command will tell you your current size.
ENDHELP
  ;
  }
  

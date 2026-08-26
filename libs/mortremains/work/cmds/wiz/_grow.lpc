// A command to allow a wizard to grow at will.
// (08-27-96) Written by Chronos.
// (04-10-98) Ported to new lib, Chronos@NK.

#include <mudlib.h>

inherit DAEMON;

int cmd_grow(string str) {
  int i;
  if (!str) {
    write("You are currently at size "+TP->query("size")+".\n");
    return 1;
  }
  if (sscanf(str, "%d",i)!= 1) {
    write("You must supply an integer by which to grow.\n");
    return 1;
  }
  if (i<1) {
    write("If you want to be smaller, you need to SHRINK.\n");
    return 1;
  }
  TP->add("size", i);
  write("You grow larger by a factor of "+i+", bringing you to a size "+
     TP->query("size")+".\n");
  say(TPN+" suddenly grows larger!\n");
  return 1;
}

string help() {
  return @ENDHELP
Usage: grow [size_factor]

This command allows to you grow larger at will.  This effort is temporary.

With no arguments, this command will tell you your current size.
ENDHELP
;
  }
  

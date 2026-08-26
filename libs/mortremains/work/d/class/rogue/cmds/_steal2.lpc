/* File: _steal.c   (so thieves can rip you off)
** Purpose: A thief is only as good as your shit.
** Date: August 2nd, 1997
** Original Design: Cyanide
** Hacked By: Nightmask
*/


#include <rogues.h>
#include <mudlib.h>

object ob, targ;
string str2;

int cmd_steal(string str) {
  if (TP->query_level() < 10) {
     write("You must be hidden to use this ability.\n");
  return 1;
 }
  if (!TP->query("invisible")) {
     write("You need to be hidden for this ability.\n");
  return 1;
  }

  if (sscanf(str, "%s from %s", str, str2) != 2) {
    write ("Steal what from who?\n");
    return 1;
  }

   targ = present(str2, environment(this_player()) );
  if (!targ) {
     write("There is no "+capitalize(str2)+" here.\n");
    return 1;
  }

  ob = present(str, targ);
  if (!ob) {
     write(capitalize(str2)+" dosen't have a "+str+".\n");
    return 1;
  }
  ob->move(this_player());
     write("You lift "+str+" from "+capitalize(str2)+" with ease.\n");
  return 1;
}

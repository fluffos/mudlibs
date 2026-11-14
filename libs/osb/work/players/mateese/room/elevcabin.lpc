/* Elevator Cabin */

#include "/players/mateese/mydefs.h"

#include <properties.h>
#include <rooms.h>
#include <moving.h>

inherit "/std/room";

int direction; /* 0: down, 1: up */
int count;
string plname;
object pl;

create() {
  room::create();
  SetIntShort("Globe of light");
  SetIntLong(
"You are floating in a globe of light.\n"+
"You feel a fast @@_long@@ movement.\n"
             );
  SetIntLight(1);
  Set(P_INDOORS, 1);
}

QueryIntLong(arg) {
  if (arg) return ::QueryIntLong(arg);
  return
"You are floating in a globe of light.\n"+
"You feel a fast "+(direction ? "upward" : "downward")+" movement.\n";
}

move (dir) {
  direction = dir;
  if (!(plname = PL_RNAME)) plname = lower_case(PL_NAME);
  if (PL_WLEVEL) call_out ("arrived", 1);
  else {
    count = 4;
    call_out ("moving", 3);
  }
}

moving () {
  write ("You still move ");
  if (direction) write ("upwards.\n"); else write ("downwards.\n");
  count--;
  if (count) call_out ("moving", 3);
  else call_out ("arrived", 3);
}

arrived() {
  object dst, *ob;
  int i;
  string mmsgin;
  pl = find_player(plname);
  if (!pl) pl = find_living(plname);
  if (pl && environment(pl) == ME) {
/*
    mmsgin = pl->query_mmsgin();
    pl->setmmin ("arrives in a globe of light");
*/
    mmsgin = "in a globe of light";
    write ("The light vanishes.\n");
/*
    if (direction) pl->move(MR+"elevtop", M_TELEPORT);
    else pl->move(MR+"elevbot", M_TELEPORT);
    pl->setmmin (mmsgin);
*/
    if (direction) pl->move(MR+"elevtop", M_TELEPORT,({mmsgin}));
    else pl->move(MR+"elevbot", M_TELEPORT, ({mmsgin}));
  } else {
    if(dst = find_object(MR+"elevtop"))
      tell_room(dst, "Far below is a silent explosion of light.\n");
    if(dst = find_object(MR+"elevbot"))
      tell_room(dst, "Far above is a silent explosion of light.\n");
  }
  if(dst = find_object(MR+"elevbot")) {
    ob = all_inventory(ME);
    if (sizeof(ob))
      tell_room(dst, "Some things hit the ground with heavy impact.\n");
    for (i = 0; i < sizeof(ob); i++) ob[i]->move(dst, M_NOCHECK); 
  }
  destruct (ME);
}

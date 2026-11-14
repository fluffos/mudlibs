/* This room overwrites quit but has two other exits to leave it. I hope
   it will be ok in this case. This room already has had these commands
   when I ported it from old code to new one. Cadra 1-12-94 */

#include <combat.h>
#include <moving.h>
#include <properties.h>
#include <rooms.h>
#include "path.h"
#include <magic.h>

inherit "/lib/money";
inherit "std/room";


int inf(string str) {
  write("No more shouts from this cell ...\n");
  return 1;
}

int xxx(string str) {
  int amt,pamt;

  if (!this_player())
  notify_fail("Pay what?\n");
  if (lower_case(str||"")=="money") {
      amt = QuerySomeonesValue(this_player());
      if ((!(pamt = amt/2))&&amt)
        pamt = amt;
      PayValue(this_player(),pamt);
      write("Your money begins to feel warm .. and suddenly it's much lighter.\n");
      return this_player()->move(CITY("shop"),M_SPECIAL,
                      ({"vanishes before your eyes",
                      "materializes in front of your eyes",
                      "feel a bit dizzy and suddenly you're somewhere else"}));
      }
  return 0;
}

int qui() {
  write("*smile* You have to get out first ...\n");
  return 1;
}

int pus(string str) {
  write("No ...\n");
  return 1;
}

int tel(string str) {
  write("From this cell no one can hear you ...\n");
  return 1;
}

int ent(string str) {
  if (!str) return (int) notify_fail("Enter what?\n") && 0;
  if ((lower_case(str)=="outlet")) {
    write("You manage to execute 'compress -f "+this_player()->QueryRealName()+"'.\n"
"You enter the hole.\n"
"You pass through a magic force field.\n");
    if (!this_player()) return 0;
    this_player()->move(PIRATE("way1"),M_GO,"into an outlet");
    return 1;
    }
}

create() {
  ::create();
  SetIntShort("A lonely but lovely prison cell");
  SetIntLong(
"You're in a comfortable prison cell. "
"A well furnished bed stands in the corner, a chair and a table in the "
"other.\n"
"A sign on the wall reads:\n"
"    This is the right place for the (saintly, good, nice,\n"
"    neutral, nasty, evil and demonic) players.\n"
"    Don't try to shout or it will be stopped.\n");
  AddReadMsg(({"sign"}),
"    This is the right place for the (saintly, good, nice,\n"
"    neutral, nasty, evil and demonic) players.\n"
"    Don't try to shut or it will be stopped.\n");
  SetTPort(TPORT_NO);
  SetMaxWeight(1073741824);
  AddDetail(({"chair","standard chair","wooden chair","standard wooden chair"}),
"You see a standard wooden chair.\n");
  AddDetail(({"bed","ordinary bed","lovely bed","furnished bed",
  "lovely furnished bed","wooden bed","lovely furnished wooden bed",
  "ordinary wooden bed"}),
"An ordinary, but lovely furnished wooden bed. "
"A small sign is fixed above it.\n");
  AddDetail(({"wood","old wood"}),"It looks old.\n");
  AddDetail(({"table","wooden table","empty table","empty wooden table"}),
"An empty wooden table. But what's that ...\n"
"You discover a small outlet under the table.\n");
  AddDetail("sign","Try to read it.\n");
  AddDetail(({"outlet","small outlet"}),
"It's too dark to see anything in it.\n");
  AddDetail(({"cell","lonely cell","comfortable cell","prison cell",
  "comfortable prison cell"}),QueryIntLong());
  AddDetail(({"corner","corners"}),"There is some furniture in the corners.\n");
  AddDetail(({"furniture","some furniture"}),
"There is a table, a bed and a chair.\n");
  AddRoomCmd("shout",#'inf);
  AddRoomCmd("tell",#'tel);
  AddRoomCmd("quit",#'qui);
  AddRoomCmd(({"use","push","press"}),#'pus);
  AddRoomCmd("enter",#'ent);
  AddRoomCmd("pay",#'xxx);
  AddItem("/std/weapon",REFRESH_REMOVE,
    ([P_SHORT:"a morningstar",
      P_LONG:
"This is a heavy morningstar. The strong iron chain connects the iron "
"ball at the one end to the thick stick at the other one. The weapon "
"looks mighty.\n",
      P_IDS:({"morningstar","weapon"}),
      P_ADS:({"heavy"}),
      P_DAM_TYPE:DT_BLUDGEON,
      P_WEAPON_TYPE:WT_CHAIN,
      P_NUMBER_HANDS:1,
      P_WEIGHT:8000,
      P_WC:13,
      P_VALUE:350]));
}

#include "path.h"
#include <combat.h>
#include <properties.h>
#include <rooms.h>
#include <moving.h>

inherit "/std/room";

int za,zb;

int appear() {
  object ob;
  ob=clone_object("/std/thing");
  ob->SetShort("small figurine of Thor");
  ob->SetLong("This is a nice small figurine. Must be handwork.\n");
  ob->SetValue(30);
  ob->SetWeight(100);
  ob->SetIds(({"figurine","pirfigur"}));
  ob->SetAds(({"small","a"}));
  write("A small figurine appears on the ground.\n");
  ob->move(this_object(),M_SILENT);
  za=zb=0;
  return 1;
}

read() {
  if (present("skeleton",this_object())) {
    return "Not as long as the skeleton disturbs you.\n";
    }
  return "Do me this two favours:\n'answer' me: "
"Who was this great nordic god with a hammer?\n"
"Feed me with some decayed brain.\n";
}

int down() {
  if (!this_player()) return 0;
  if (present("skeleton",this_object())) {
    write("Not as long as the skeleton bars your way.\n");
    return 1;
    }
  this_player()->move(PIRATE("rroom1"),M_GO,"down");
  return 1;
}

int put(string str) {
  string what,where;
  object ob;
  if (!this_player()) return 0;
  if (present("skeleton",this_object())) return (int) notify_fail(
    "Not now.\n") && 0;
  if (!str) return 0;
  if (sscanf(str,"%s into %s",what,where)!=2) return (int)
    notify_fail("Put what into what?\n") && 0;
  if ((what!="skull") || (!ob=present("skull",this_player())))
    return (int) notify_fail(
    "You cannot do that.\n") && 0;
  if (where!="mouth") return (int) notify_fail(
    "Perhaps better put it into the mouth?\n") && 0;
  write("You put the skull into the mouth.\n");
  ob->remove();
  if (ob) destruct(ob);
  za=1;
  if ((za==1) && (zb==1)) appear();
  return 1;
}

int feed(string str) {
  if (present("skeleton",this_object())) return (int)
    notify_fail("Not now.\n") && 0;
  if (!str) return 0;
  if ((str!="face with skull") && (str!="mouth with skull")) return
    (int) notify_fail("Feed what?\n") && 0;
  return put("skull into mouth");
}

int answer(string str) {
  if (present("skeleton",this_object())) return (int) notify_fail(
    "Not now.\n") && 0;
  if (!str) return notify_fail(
    "What do you want to answer?\n"),0;
  if (lower_case(str)!="thor") return (int)
    notify_fail("WRONG!\n") && 0;
  write("The face speaks: 'right' "
"The correct answer has been given.\n");
  zb=1;
  if ((zb==1) && (za==1)) appear();
  return 1;
}

create() {
  ::create();
  SetIntShort("a chamber");
  SetIntLong(
"You're in a large chamber. A big face is built into the southern "
"wall. A sign is beneath it. A staircase leads down.\n");
  AddDetail(({"stairs","stairway"}),"You see another chamber down below.\n");
  AddDetail(({"huge mouth","toothless mouth","deep mouth","mouth"}),
  "Huge, deep, monumental, toothless.\n");
  AddDetail(({"chamber","large chamber"}),QueryIntLong());
  AddDetail(({"another chamber"}),
  (PIRATE("rroom1"))->QueryIntLong()+(PIRATE("rroom1"))->Content());
  AddDetail(({"south wall","southern wall"}),"There is a big face in it.\n");
  AddDetail("sign","There is something written on it.\n");
  AddDetail(({"big face","face"}),"It has a huge mouth.\n");
  AddDetail(({"walls","wall"}),"There is a huge face in the southern wall.\n");
  AddDetail(({"floor","ground"}),"A stairway leads down.\n");
  AddDetail("ceiling","You see nothing special.\n");
  AddReadMsg("sign",#'read);
  AddRoomCmd("put",#'put);
  AddRoomCmd("answer",#'answer);
  AddRoomCmd("feed",#'feed);
  AddExit("south","./m5");
  AddExit("down",#'down);
  AddItem("/std/npc",REFRESH_HOME,({
    ([P_NAME:"skeleton",
      P_SHORT:"skeleton warrior",
      P_LEVEL:14,
      P_HP:250,
      P_ALIGN:-400,
      P_RACE:"undead",
      P_LONG:"This is a huge living skeleton.\n",
      P_HANDS:({ ({"left hand",0,15}),({"right hand",0,20}) }),
      P_AC:7,
      P_IDS: ({"skeleton","warrior","undead"}),
      P_ADS:({"huge","living"})]),
    ([P_ITEMS_REFRESH:({
        ({"/std/weapon",REFRESH_REMOVE|REFRESH_FUNC,
          ([P_SHORT:"a morningstar",
            P_LONG:
"A large spiked ball of steel connected by a chain to a sturdy stick.\n",
            P_WC:15,
            P_NUMBER_HANDS:2,
            P_WEAPON_TYPE:WT_CLUB,
            P_DAM_TYPE:DT_BLUDGEON,
            P_VALUE:600,
            P_WEIGHT:15000,
            P_IDS:({"morningstar"}),
            P_ADS:({"heavy","spiked"})]),"wieldme",0})})])}));
  za = zb = 0;
}

reset() {
  ::reset();
  za=zb=0;
}

#include "path.h"
#include <rooms.h>
#include <properties.h>
#include <moving.h>

inherit "/std/room";

int dig;

int enter (string str) {
  write("You enter the water and begin to swim ... "
"After half an hour you reenter the beach. You feel great.\n");
  return 1;
}

int dig() {
  object ob;
  if (!this_player()) return 0;
  if (!present("shovel",this_player())) return (int) notify_fail(
    "You cannot dig with that at this place. You need a shovel.\n")
      && 0;
  if (dig) return (int) notify_fail(
    "You find nothing.\n") && 0;
  write("You start to dig ...\n... and find a bullet.\n");
  if (!this_player()) return 0;
  show(this_player()->QueryName()+" digs in the sand.\n",this_player());
  /* Another bullet for the Western miniquest. 
   * See also .../lair.c and .../mx.c 
   */
  ob=clone_object("/std/thing");
  ob->SetShort("a bullet");
  ob->SetLong("A deadly looking bullet. There is an inscription on it.\n");
  ob->SetValue(2);
  ob->AddId("bullet");
  ob->SetReadMsg("1879\n");
  ob->SetWeight(10);
  if (ob->move(this_player(),M_GET)!=ME_OK) {
    write("You cannot carry the bullet you found.\n");
    ob->move(this_object(),M_DROP);
  }
  return dig=1;
}

create() {
  ::create();
  SetIntShort("on a beach");
  SetIntLong(
"You're standing near the ocean on a rocky part of the beach. Behind "
"you the cliff raises high into the sky. To the north lies another "
"cliff. Small waves on the ocean shimmer in the sun.\n");
  AddDetail(({"water","sea","ocean"}),"It looks inviting.\n");
  AddDetail(({"cliff","cliffs"}),
"It looks high and steep.\n");
  AddDetail(({"waves","wave"}),
"Waves splash agains the shore.\n");
  AddDetail("sun","The ocean always shimmers like in sunshine.\n");
  AddDetail(({"shore","beach"}),"Nothing special.\n");
  AddDetail(({"rocks","rock","sand","small rock","small rocks"}),
"Instead of sand you see small rocks all over the beach.\n");
  AddRoomCmd("dig",#'dig);
  AddRoomCmd("swim",#'enter);
  SetIndoors(0);
  AddExit("up","./cliffn");
  AddExit("north",PORT("nf_port"));
  AddExit("enter",#'enter);
  HideExit("enter",1);
  AddItem("/obj/bag",REFRESH_REMOVE);
  AddItem("/std/npc",REFRESH_HOME,
    ([P_NAME:"frog",
      P_IDS: ({"frog","animal"}),
      P_ADS:({"green","little","greenish"}),
      P_SHORT:"a little greenish frog",
      P_LONG:"Wow! It's kind of green animal, isn't it?\n",
      P_AC:3,
      P_HANDS:({ ({"tongue",0,6}),({"legs",0,5}) }),
      P_LEVEL:3,
      P_FROG:1,
      P_ITEMS_REFRESH:({
        ({"/std/thing",REFRESH_REMOVE,
          ([P_SHORT:"a green crown",
            P_LONG:"Wow! It's kind of green metal, isn't it?\n",
            P_IDS:({"crown"}),
            P_ADS:({"green","a","metal"}),
            P_VALUE:20,
            P_WEIGHT:40]),0}) }) ]));
  reset();
}

reset() {
  ::reset();
  dig=0;
}

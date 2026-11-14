#include <combat.h>
#include <properties.h>
#include <moving.h>
#include "path.h"

#define I_AM_SMALL "is_very_small"

inherit "/std/room";

int digger;

reset() {
  ::reset();
  digger=0;
}

int swim() {
  write("You don't really want to do that, do you?\n"
"You would not survive these sharks.\n");
  return 1;
}

int enter(string str) {
  if (!str) return (int) notify_fail(
"What do you want to enter?\n") && 0;
  if ((lower_case(str)=="ocean") || (lower_case(str)=="sea")) {
    swim();
    return 1;
    }
  if ((lower_case(str)=="hole") || (lower_case(str)=="opening")) {
    if (!this_player()) return 0;
  if ((this_player()->QueryFrog())||(this_player()->Query(I_AM_SMALL))) {
      write("You hop into the hole..\n");
      this_player()->move(PIRATE("inhole"),M_GO,"into the hole");
      return 1;
      }
    return (int) notify_fail("You're way too big for that small hole.\n"
"Think of a way to become smaller.\n") && 0;
    }
}

int dig() { 
  object ob;
  if (!this_player()) return 0;
  if ((present("pickaxe",this_player())) || (present("shovel",this_player()))) {
    if (digger!=0) return (int) notify_fail(
"All the sand is removed from this part of the beach.\n") && 0;
    write("You start to dig a hole.\n");
    digger=1;
    write("After some digging work you hit some rocks... "
"You found something!\n");
    show(this_player()->QueryName()+
    " digs. "+this_player()->QueryPronoun()+" found something!\n");
    ob=clone_object("std/armour");
    ob->SetShort("a rusty ankh");
    ob->SetLong(
"This is a small rusty iron anchor. You get an evil feeling "
"when you look at it. It looks like some sort of cross with a "
"hole at the top.\n");
    ob->SetValue(20);
    ob->SetWeight(100);
    ob->SetAC(-2);
    ob->SetArmourType(AT_AMULET);
    ob->SetSize(PSIZE_NORMAL);
    ob->SetQuality(66);
    ob->SetIds(({"amulet","ankh","anchor"}));
    ob->SetAds(({"rusty","small","a","an","old","iron"}));
    ob->move(this_object(),M_SILENT);
    return 1;
    }
  return (int) notify_fail("You don't have the right equipment to do that.\n") && 0;
}

create(){
  ::create();
  SetIntShort("a small part of a beach");
  SetIntLong(
"You are on a small sandy part of the beach. To the north and southwest "
"huge masses of stones block the way. On the Sea you see the fins of "
"some sharks. A small hole leads into the cliff.\n");
  AddDetail(({"small sandy part","small sandy part of the beach",
  "part of the beach"}),QueryIntLong());
  AddDetail(({"stones","stone","huge masses of stones"}),
"The stones block the ways to the north and southwest.\n");
  AddDetail(({"sea","ocean","blue sea","blue ocean","wide sea","wide ocean",
  "wide blue sea","wide blue ocean"}),
"It is the wide blue Sea.\n");
  AddDetail(({"fin","fins","sharks","shark"}),
"Some sharks seem to be in the sea.\n");
  AddDetail(({"beach","view"}),"Nice view.\n");
  AddDetail(({"hole","opening","small hole","small opening"}),
"It is a small and dark opening in the cliff.\n");
  AddDetail(({"sand","yellow sand"}),"Nice yellow corny small particles.\n");
  SetIndoors(0);
  AddExit("enter",#'enter);
  HideExit("enter",1);
  AddRoomCmd("dig",#'dig);
  AddExit("swim",#'swim);
  HideExit("swim",1);
AddExit("up","./downcliff");
  reset();
}

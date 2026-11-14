#include <moving.h>
#include "path.h"

inherit "/std/room";

int kd;

int dig() {
  write("Digging will lead you to no success. The rocks must be removed !\n");
  return 1;
}

int pick(string str) {
  object ob;
  if (!this_player()) return 0;
  if (!str) return (int) notify_fail("Pick what?\n") && 0;
  if ((str!="rocks") && (str!="rock") && (str!="at rocks") && (str!="pick")) 
    return (int) notify_fail(
      "You feel sure that this is not what you should pick.\n") && 0;
  if (!present("pickaxe",this_player())) return (int)
    notify_fail("You don't have the right equipment for this.\n") && 0;
  if (kd==0) {
    see("You start with your work. "
"After some minutes you have removed dozens of rocks and ...\n"
"... found a key.\n");
    show(this_player()->QueryName()+" hacks at the rocks.\n"
"After a while a key appears.\n",this_player());
    kd=1;
    ob=clone_object("/obj/key");
    ob->SetShort("a normal looking key");
    ob->SetLong("This is a strangely shaped key.\n");
    ob->SetValue(10);
    ob->SetWeight(20);
    ob->AddKeyId("pirkey");
    ob->SetAds(({"a","normal","normal looking"}));
    if (ob->move(this_player(),M_GET)!=ME_OK) {
      write("You cannot carry the key.\n");
      ob->move(this_object(),M_DROP);
      }
    return 1;
    }
  write("You work for a while but find nothing.\n");
  return 1;
}

int search(string str) {
  if (!this_player()) return 0;
  if (!str) return (int) notify_fail("Search what?\n") && 0;
  if (str=="rocks with shovel") return (int) notify_fail(
"You remove some rocks with the shovel, but you find nothing. Perhaps "
"a pickaxe would serve you better here?\n") && 0;
  if (str!="rocks") return (int) notify_fail(
    "Search what?\n") && 0;
  see("You remove some rocks with your hands. You find nothing. If you "
"continue this way it will take days to finish your work. "
"You should try to find something suitable to pick such large rocks.\n");
  show(this_player()->QueryName()+" tries to move the rocks but fails.\n",
    this_player());
  return 1;
}

create() {
  ::create();
  SetIntShort("a dead end");
  SetIntLong(
"You're at a dead end. Many rocks are piled up here. It seems that there "
"once has been an exit to the west.\n");
  AddDetail(({"old exit","exit","broken exit"}),
"The exit is no more. You just can still see that there once has been "
"one.\n");
  AddDetail(({"rocks","rock","pile","pile of rocks"}),"These are huge masses of rock.\n");
  AddDetail(({"end","dead end","cave"}),QueryIntLong());
  AddDetail(({"wall","walls","ceiling"}),"There is nothing special to be seen.\n");
  AddDetail(({"floor","ground"}),"There is a pile of rocks on the floor.\n");
  AddRoomCmd(({"search","move","remove"}),#'search);
  AddRoomCmd(({"pick","hack","use","mine"}),#'pick);
  AddRoomCmd("dig",#'dig);
  AddExit("south","./doorx");
  reset();
}

reset() {
  kd=0;
  ::reset();
}

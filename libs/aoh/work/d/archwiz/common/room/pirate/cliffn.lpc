#include "path.h"
#include <rooms.h>
#include <moving.h>
#include <combat.h>

inherit "/std/room";

int broken;
int ropeyes;

reset() {
  object ob;
  ::reset();
  broken=0;
  if (ob=present("rope",this_object())) {
    tell_room(this_object(),
"The rope loses its hold and falls down to the Sea vanishing in the waves.\n");
    ob->remove();
    if (ob) destruct(ob);
    }
  ropeyes=0;
}

int tie(string str) {
  string what,towhat;
  object ob;
  if (!this_player()) return 0;
  if (sscanf(lower_case(str||""),"%s to %s",what,towhat)!=2) return (int)
    notify_fail("Tie what to what?\n") && 0;
  if (what!="rope") return (int)
    notify_fail("How do you wanna do that?\n") && 0;
  if (!present("rope",this_player())) return (int)
    notify_fail("You don't have one.\n") && 0;
  if (towhat!="tree") return (int) notify_fail(
    "Are you sure that this could be possible?\n") && 0;
  if (broken) return (int) notify_fail(
    "You don't manage to tie the rope to the remains of the tree.\n") && 0;
  if (ropeyes) return (int) notify_fail(
    "There is already a rope tied to the tree.\n") && 0;
  write("You tie the rope to the tree.\n");
  show(this_player()->QueryName()+" ties a rope to the old tree.\n",
    this_player());
  ob=present("rope",this_player());
  ob->remove();
  if (ob) destruct(ob);
  return  ropeyes=1;
}

int untie(string str) {
  object ob;
  if (!this_player()) return 0;
  if (str!="rope") return (int) notify_fail(
    "You cannot do that here.\n") && 0;
  if (!ropeyes) return (int) notify_fail(
    "But there is no rope.\n") && 0;
  write("You untie the rope.\n");
  ob=clone_object("/obj/rope");
  if (ob->move(this_player(),M_GET)!=ME_OK) {
    write("As you cannot carry the rope, you drop it.\n");
    ob->move(this_object(),M_DROP);
    }
  ropeyes=0;
  return 1;
}

int climb(string str) {
  object ob;
  if ((str!="tree") && (str!="down") && (str!="rope")) return (int) notify_fail(
    "You should try that elsewhere.\n") &&0;
  if (broken) return (int) notify_fail(
    "You cannot climb it. It's collapsed.\n") && 0;
  if (str=="tree") {
    write("You climb the tree ... "
"After arriving in the highest branches, the tree suddenly starts to "
"collapse ! You fall down ... Ouch ! Thats hurts ...\n"
"An object which was high above in the tree has also made its way to the "
"ground.\n");
    ob=clone_object("std/weapon");
    ob->SetShort("a very large knife");
    ob->SetLong("This knife is huge! It's as long as your arm!\n");
    ob->SetIds(({"knife","weapon"}));
    ob->SetAds(({"a","large","very","huge","long"}));
    ob->SetWC(4);
    ob->SetWeaponType(WT_KNIFE);
    ob->SetDamType(DT_SLASH);
    ob->SetNumberHands(1);
    ob->SetWeight(2000);
    ob->SetValue(30);
    ob->move(this_object(),M_SILENT);
    return broken=1;
    }
  if (!this_player()) return 0;
  if ((str=="down") || (str=="rope")) {
    if (!ropeyes) return (int) notify_fail(
      "You would break you neck if you try that.\n") && 0;
    write("You grab the rope and begin to climb down.\n");
    this_player()->move(PIRATE("drope"),M_GO,"climbing down");
    return 1;
    }
}

string tree() {
  string str;
  if (broken==0) {
    str="It's just a standard dead tree.\n";
  if (ropeyes==1)
    str=str+"A rope is connected to it's base.\n";
  }
  if (broken==1)
    str="These are the remains of an old collapsed tree.\n";
  return str;
}

string QueryIntLong() {
    return broken?
"You are on the top of a high cliff. To the east you see the ocean below "
"and a small sandy beach. To the north the cliff softly falls down to the "
"shore. An old tree without any green leaves is here.\n":
"You are on the top of a high cliff. To the east you see the ocean below "
"and a small sandy beach. To the north the cliff softly falls down to the "
"shore. A broken tree lies on the ground.\n";
}

create() {
  ::create();
  SetIntShort("On a cliff");
  AddDetail(({"old tree","tree"}),#'tree);
  AddDetail(({"top","top of a high cliff","top of a cliff"}),
#'IntLong);
  AddDetail(({"cliff","high cliff"}),
"The cliff is very steep and looks dangerous. Maybe you could climb down "
"here if you would have something to secure yourself?\n");
  AddDetail(({"ocean","blue ocean","wide ocean","wide blue ocean",
  "sea","blue sea","wide sea","wide blue sea"}),
"It is just the wide blue Sea you see below.\n");
  AddDetail(({"waves","wave"}),
"The waves roll the Sea.\n");
  AddDetail(({"beach","sandy beach","small beach","small sandy beach"}),
(PIRATE("beach2"))->QueryIntLong()+(PIRATE("beach2"))->Content());
  AddDetail(({"letter","letters"}),
"The letters are too far away to see them clearly.\n");
  AddDetail(({"cave","cave entrance","entrance"}),
"You see it far below.\n");
  AddReadMsg(({"letters","letter"}),
"You cannot read letters that are that far away.\n");
  SetIndoors(0);
  AddRoomCmd("tie",#'tie);
  AddRoomCmd("untie",#'untie);
  AddExit("south","./cliff");
  AddExit("down","./nearsea");
  HideExit("down",1);
  AddExit("north","./nearsea");
  HideExit("north",1);
  AddExit("climb",#'climb);
  HideExit("climb",1);
  reset();
}

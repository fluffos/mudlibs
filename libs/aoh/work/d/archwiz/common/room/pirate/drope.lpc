#include "path.h"
#include <moving.h>
#include <money.h>

inherit "/std/room";

int ropeyes,found;

int do_drop(string str) {
  object ob;
  if (!this_player()) return 0;
  if (!str) return 0;
  if (!this_player()->CanSee()) {
    write("You cannot see anything.\n");
    return 1;
    }
  if (!ob=present(str,this_player())) {
    write("You don't have a "+str+".\n");
    return 1;
    }
  write(
    "You drop "+str+" which immediately falls down.\n");
  show_room(this_object(),
this_player()->QueryName()+" drops "+str+" which immediately falls down.\n",
    ({this_player()}));
  ob->move(PIRATE("beach2"),M_SILENT);
  show_room(PIRATE("beach2"),
    capitalize(str)+" suddenly falls in from above.\n");
  return 1;
}

int tie(string str) {
  object ob;
  string what,where;
  if (!str) return (int) notify_fail(
    "Tie what to what?\n") && 0;
  if (sscanf(lower_case(str),"%s to %s",what,where)!=2) return (int)
    notify_fail("Tie what to what?\n") && 0;
  if (what!="rope") return (int) notify_fail(
    "What do you want to tie to "+where+"?\n") && 0;
  if (!ob=present("rope",this_player())) return (int) notify_fail(
    "You don't have a rope!\n") && 0;
  if ((where!="ring") && (where!="iron ring")) return (int)
    notify_fail("Tie it to what?\n") && 0;
  if (!this_player()) return 0;
  write("You tie your rope to the ring.\n");
  show(this_player()->QueryName()+" ties a rope to the ring.\n",this_player());
  ob->remove();
  if (ob) destruct(ob);
  return ropeyes=1;
}

int untie(string str) {
  object ob;
  if (!str) return (int) notify_fail("Untie what?\n") && 0;
  if (!ropeyes) return (int) notify_fail(
    "There is no rope.\n") && 0;
  write("You untie the rope from the ring.\n");
  if (!this_player()) return 0;
  if(!this_object()) return 0;
  show(this_player()->QueryName()+" unties the rope from the ring.\n",
    this_player());
  ropeyes=0;
  ob=clone_object("/obj/rope");
  if (ob->move(this_player(),M_GET)!=ME_OK) {
    write("You cannot carry the rope so you drop it.\n");
    show(this_player()->QueryName()+" suddenly drops the rope.\n",
      this_player());
    tell_room(this_object(),"The rope falls down.\n");
    ob->move(PIRATE("beach2"),M_DROP);
    tell_room(PIRATE("beach2"),"Suddenly a rope falls down the cliff.\n");
    }
  return 1;
}

rope() {
  if (ropeyes) return "The rope is tied to the iron ring. You may climb further down.\n";
  return "You don't see a rope at this place.\n";
}

int down() {
  if (!ropeyes) return (int) notify_fail(
    "Do you want to commit suicide?\n") && 0;
  if (!this_player()) return 0;
  write("You continue climbing down.\n");
  this_player()->move(PIRATE("beach2"),M_GO,"down");
  return 1;
}

int climb(string str) {
  if (!this_player()) return 0;
  if ((!str) || ((str!="down") && (str!="up"))) return (int)
    notify_fail("If you wanna climb  up or down, do it.\n") && 0;
  if (str=="down") return down();
  if (str=="up") {
    write("You climb up the rope.\n");
    show(this_player()->QueryName()+" climbs up.\n",this_player());
    this_player()->move(PIRATE("cliffn"),M_SILENT);
    return 1;
    }
}

cliff() {
  object ob;
  write("You look at the cliff and discover a nest of some bird.\n");
  if (!this_player()) return 0;
  if (!found) {
    write("You discover some coins in the nest.\n");
    ob=clone_object("/obj/money");
    ob->SetMoney(MONEY_DEMON->CreateMoney((random(4)+1),({"copper"})));
    if (ob->move(this_player(),M_GET)!=ME_OK) {
      write("As you cannot carry it, you drop the money. "
"Unfortunately the money falls far down.\n");
      ob->move(PIRATE("beach2"),M_DROP);
      found=1;
      }
    return "";
    }
  write(
"Suddenly a big bird erupts from the sky, catches you, circles down and drops "
"you in the air 5 metres above the ground of the beach.\n\OUCH!!!\n");
  this_player()->DoDamage(random(20));
  show(this_player()->QueryName()+" is catched by a huge bird who drops "
    +this_player()->QueryObjective()+" about 5 metres above the ground.\n"
    "You see "+this_player()->QueryName()+" falling down.\n",this_player());
  this_player()->move(PIRATE("beach2"),M_SILENT);
  tell_room(PIRATE("beach2"),"You see a huge bird flying in the air that "
"suddenly drops "+this_player()->QueryName()+".\n",({this_player()}));
  return "";
}

test() {
  if (ropeyes) return "There is an iron ring with a rope tied to it "
"fastened into the cliff.\n";
  return "There is an iron ring fastened into the cliff.\n";
}

QueryIntLong() {
  return
"You're hanging high in the air on a rope. The beach is more than 30 metres "
"below. That is obviously too high to jump. Far in the distance you see some "
"isles in the sea. "+test();
}

create() {
  ::create();
  SetIntShort("hanging on a rope");
  SetIndoors(0);
  AddDetail(({"ring","iron ring"}),#'test);
  AddDetail("cliff",#'cliff);
  AddDetail("rope",#'rope);
  AddDetail(({"beach","shore"}),
(PIRATE("beach2"))->QueryIntLong()+(PIRATE("beach2"))->Content());
  AddDetail(({"air","salty air"}),"The air smells salty.\n");
  AddSmell(({"air","salty air","salt"}),"It smells salty.\n");
  AddDetail(({"sea","blue sea","blue ocean","wide sea","wide ocean",
  "wide blue sea","wide blue ocean"}),
"It is just the wide blue Sea.\n");
  AddDetail(({"isle","isles"}),
"They are far away.\n");
  AddRoomCmd("drop",#'do_drop);
  AddRoomCmd("untie",#'untie);
  AddRoomCmd("tie",#'tie);
  AddRoomCmd("climb",#'climb);
  AddRoomCmd("down",#'down);
  reset();
}

reset() {
  ::reset();
  ropeyes=found=0;
  if (!this_object()) return 0;
  tell_room(this_object(),"The rope gets loose and falls down.\n");
}

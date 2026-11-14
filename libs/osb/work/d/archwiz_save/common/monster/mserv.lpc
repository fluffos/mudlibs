/* Cadra 20-12-94 for the 'free_turanu' quest */

#include "path.h"
#include <combat.h>
#include <moving.h>

inherit "/std/npc";

create() {
  if (::create()) return 1;
  SetName("master servant");
  SetShort("the master servant");
  SetLong(
"He looks strong. Better don't mess with him.\n");
  SetLevel(30);
  SetDex(60);
  SetHP(1000);
  SetHands(({({"left hand",0,15}),({"right hand",0,17})}));
  SetAC(7);
  AddDefence(DT_FIRE,45);
  AddDefence(DT_MAGIC,40);
  AddDefence(DT_BLUDGEON,30);
  SetAttribute("MagicDefence",77);
  InitChats( ({
"The servant says: Where did I put this ring to?\n",
"The servant asks: Could you help me?\n",
"The servant whispers: Noone is allowed to enter the throneroom without\n\
permision, but you would bring me the ring back...\n",
"The servant sighs deeply.\n",}));
  SetChatChance(20);
  SetMale();
  SetIds(({"servant","masterservant"}));
  SetAds(({"the","master"}));
}

init() {
  ::init();
  add_action("do_give","give");
  add_action("do_give","offer");
  add_action("go_south","south");
}

int do_give(string str) {
  string what,whom;
  object ob;
  if (!this_player()) return 0;
  if (!str) return (int) notify_fail("Give what to whom?\n") && 0;
  if (sscanf(str,"%s to %s",what,whom)!=2) return (int) notify_fail(
"Give what to whom?\n") && 0;
  if (!id(whom)) return (int) notify_fail(
"You see no sense in this as you think it over.\n") && 0;
  if (!ob=present(what,this_player())) return (int) notify_fail(
"You don't have it.\n") && 0;
  if ((!ob->id("goldquest")) || (ob->QueryCreator()!=PALACE("fount1"))) return
    (int) notify_fail(
"The servant says: This is not mine. Where did you get this???\n") && 0;
  ob->remove();
  if (ob) destruct(ob);
  write("The servant thanks you wholeheartedly and let's you pass.\n");
  this_player()->move(PALACE("throne"),M_GO,"south");
  return 1;
}

int go_south() {
  write("The servant barrs your way.\n");
  return 1;
}

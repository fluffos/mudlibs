//      /bin/users/_gut.c
//      by Nightshade

#include <std.h>
#include <move.h>
inherit DAEMON;
int abil();

string type() { return "other"; }

int cmd_gut(string str) {
  object corpse;
  object ob, *all, mon;
  string *curr;
  int i, b, amount, ammount;

  if (!abil()) {
    notify_fail("What?\n");
    return 0;
  }
  if(!str) {
    notify_fail("Gut what?\n");
    return 0;
  }
  corpse = present(str, environment(this_player()));
  if (!corpse)
    return notify_fail("Gut what?\n");
  if (!corpse->query_corpse())
    return notify_fail("You can only gut corpses.\n");
  if (corpse->id("ashes"))
    return notify_fail("There is no sinew left among the ashes.\n");

  write("You gut the corpse, taking the sinew.");
  say(this_player()->query_cap_name()+" deftly guts the corpse.");
  for (int j=this_player()->query_skill("nature")/90+1; j > 0; j--) {
    ob = new(OBJECT);
    ob->set_short("a piece of sinew");
    ob->set_long("This piece of sinew seems to have come from "+indefinite_article(corpse->query_race())+".");
    ob->set_name("sinew");
    ob->set_id(({"gut_sinew_ob","sinew"}));
    ob->set_weight(1);
    ob->move(this_player());
    ob=0;
  }
  this_player()->set_disable();
   corpse->loot(this_player());
  corpse->remove();
  return 1;
}

void help() { 
  write("Syntax: <gut corpse>\n\n"+
   "Rangers are able to gut corpses, taking the necessary\n"+
   "parts for use in making things.\n");
}

int abil() {
  object tp = this_player();
  if (tp->query_level() >= 3 && tp->query_subclass() == "ranger") return 1;
  return 0;
}

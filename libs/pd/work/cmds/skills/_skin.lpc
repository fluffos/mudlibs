//      /bin/users/_skin.c
//      by Nightshade

#include <std.h>
inherit DAEMON;
int abil();

string type() { return "other"; }

int cmd_skin(string str) {
  object ob, *stuff;
  string *curr;
  int i;

  if (!abil()) {
    notify_fail("What?\n");
    return 0;
  }
  if(!str) {
    notify_fail("Skin what?\n");
    return 0;
  }
  if(str != "corpse") {
    notify_fail("You can only skin corpses.\n");
    return 0;
  }
  if(!present("remains", environment(this_player()))) {
    notify_fail("No corpse here!\n");
    return 0;
  }
  if(this_player()->query_current_attacker()) {
    notify_fail("You cannot take the time to do that now.");
    return 0;
  }
  if(present("remains", environment(this_player()))->id("skinned")) {
    notify_fail("This corpse has already been skinned.\n");
    return 0;
  }
  if (present("remains", environment(this_player()))->id("ashes"))
    return notify_fail("There is no skin left among the ashes.\n");

  write("You carefully remove the skin from the corpse.");
  say(this_player()->query_cap_name()+" carefully removes the skin from the corpse.");
  ob = new(SKIN);
  ob->set_short(present("remains", environment(this_player()))->query_old_race()+" skin");
  ob->set_name(ob->query_short());
  ob->set_long("A raw bit of skin taken from "+indefinite_article(present("remains", environment(this_player()))->query_old_race())+".");
  ob->set_id(({"skin","skin_skin_ob",present("remains", environment(this_player()))->query_old_race()+"skin"}));
  ob->set("skin_race", present("remains", environment(this_player()))->query_old_race() );
  ob->set_race( present("remains", environment(this_player()))->query_old_race() );
  ob->set_weight(1);
  ob->set_curr_value("silver", 3+random(this_player()->query_skill("nature")/10));
  ob->move(this_player());
  this_player()->set_disable();
  if(random(40)+100 > this_player()->query_skill("nature")) {
    ob = present("remains", environment(this_player()));
    ob->loot(this_player());
    present("remains", environment(this_player()))->remove();
  }
  else
    present("remains", environment(this_player()))->set_id(present("remains", environment(this_player()))->query_id()+({"skinned"}));
  return 1;
}

void help() { 
  write("Syntax: <skin corpse>\n\n"+
   "Rangers can remove the skin from corpses for\n"
   "making armour or selling.\n");
}

int abil() {
  object tp = this_player();
  if (tp->query_level() >= 3 && tp->query_subclass() == "ranger") return 1;
  return 0;
}

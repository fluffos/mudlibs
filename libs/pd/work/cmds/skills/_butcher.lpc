//      /bin/users/_butcher.c
//      by Nightshade
//      Small fixed by Whit
//      update for coin bug and autobag by Nightshade

#include <std.h>
#include <move.h>
inherit DAEMON;
int abil();

string type() { return "other"; }

int cmd_butcher(string str) {
  object corpse;
  object ob, *all, mon;
  string *curr;
  int i, ammount, b;

  if (!abil()) {
    notify_fail("What?\n");
    return 0;
  }
  if(!str) {
    notify_fail("Butcher what?\n");
    return 0;
  }
  if(this_player()->query_current_attacker()) {
    notify_fail("You have more pressing matters to attend to.\n");
    return 0;
  }
  if(this_player()->query_ghost())
  {
    write("You have no body to butcher with!");
    return 1;
  }
  corpse = present(str, environment(this_player()));
  if (!corpse) {
    notify_fail("No corpse here!\n");
    return 0;
  }
  if (!corpse->query_corpse()) {
    notify_fail("You can only butcher corpses.\n");
    return 0;
  }
  if (corpse->id("ash"))
    return notify_fail("The remains of the undead are not suitable for eating!");

  write("You slice up the meat for food.");
  say(this_player()->query_cap_name()+" slices up the corpse for food.");
  ob = new(FOOD);
  if(!present("remains", environment(this_player()))->query_old_race()) {
    ob->set_short("A bit of unknown meat");
    ob->set_long("This slice of unknown meat would be good for eating.");
    ob->set_name("unknown meat");
  } else {
    ob->set_name(present("remains", 
      environment(this_player()))->query_old_race()+" meat");
    ob->set_short("A bit of "+present("remains",
      environment(this_player()))->query_old_race()+" meat");
    ob->set_long("This slice of "+present("remains",
      environment(this_player()))->query_old_race()+" meat would be good "
     "for eating.");
  }
  ob->set_id(({"meat","bit of meat", "food"}));
  ob->set_weight(2);
  ob->set_dis(1);
  ob->set_my_mess("You eat the slice of meat.");
  ob->set_your_mess("eats a slice of meat.");
  ob->set_strength(random(10)+10);
  ob->set_servings(1 + random(1+this_player()->query_level()/25));
  ob->move(this_player());
  ob = present("remains", environment(this_player()));
  ob->loot(this_player());
  ob->remove();
  if(ob)
    destruct(ob);
  this_player()->set_disable();
  return 1;
}

void help() { 
  write("Syntax: <butcher corpse>\n\n"+
   "Those with strong enough stomachs can cut up the corpse\n"+
   "for food.\n");
}

int abil() {
  object tp = this_player();
  if (tp->query_level() >= 3 && tp->query_class() == "fighter") return 1;
  return 0;
}

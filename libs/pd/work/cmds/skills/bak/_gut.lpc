//      /bin/users/_gut.c
//      by Nightshade

#include <std.h>
#include <move.h>
inherit DAEMON;
int abil();

string type() { return "other"; }

int cmd_gut(string str) {
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
  if(str != "corpse") {
    notify_fail("You can only gut corpses.\n");
    return 0;
  }
  if(!present("remains", environment(this_player()))) {
    notify_fail("No corpse here!\n");
    return 0;
  }
  if (present("remains", environment(this_player()))->id("ashes"))
    return notify_fail("There is no sinew left among the ashes.\n");

  write("You gut the corpse, taking the sinew.");
  say(this_player()->query_cap_name()+" deftly guts the corpse.");
  for (int j=this_player()->query_skill("nature")/90+1; j > 0; j--) {
    ob = new(OBJECT);
    ob->set_short("a piece of sinew");
    ob->set_long("This piece of sinew seems to have come from a "+present("remains", environment(this_player()))->query_old_race()+".");
    ob->set_name("sinew");
    ob->set_id(({"gut_sinew_ob","sinew"}));
    ob->set_weight(1);
    ob->move(this_player());
    ob=0;
  }
  this_player()->set_disable();
  ob = present("remains", environment(this_player()));
   ob->loot(this_player());
   /*
  all = all_inventory(ob);
  i = sizeof(all);
  while(i--)
  {
    if(all[i]->is_money_pile()) {
      mon = all[i];
      b = sizeof( curr = mon->query_currencies() );
      while(b--) {
	write("You find "+(ammount=mon->query_money(curr[b]))+" "+curr[b]+" "+
	 (ammount>1?"coins":"coin")+" on the body.");
	this_player()->add_money(curr[b], ammount);
      }
      mon->remove();
      if(mon)
	destruct(mon);
    }
    else {
      if(all[i]->move(this_player()) == MOVE_NO_ROOM)
	write("You are too overburdened to take "+all[i]->query_short()+".");
      else {
	write("You get "+all[i]->query_short()+" from the corpse.");
	if(this_player()->query_property("autobag"))
	  this_player()->force_me("put "+all[i]->query_id()[0]+" in "+this_player()->query_property("autobag"));
      }
    }
  }
  */
  present("remains", environment(this_player()))->remove();
  return 1;
}

void help() { 
  write("Syntax: <gut corpse>\n\n"+
   "Rangers are able to gut corpses, taking the necessary\n"+
   "parts for use in making things.\n");
}

int abil() {
  if (this_player()->query_subclass() != "ranger") return 0;
  return 1;
}

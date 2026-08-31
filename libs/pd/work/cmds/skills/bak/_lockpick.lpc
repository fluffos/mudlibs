//	_lockpick.c
//	from the Nightmare mudlib
//	Rogue ability
//	created by Descartes of Borg 211092
//	You will be assimilated.

#include <std.h>
inherit DAEMON;
int abil();

string type() { return "other"; }

int cmd_lockpick(string str) {
    int i, locks, tool;
    int resist;
    object ob;
    object *inv;


   if (!abil()) {
      write("What?\n");
      return 1;
   }
    if(!str) {
        notify_fail("Lockpick what?\n");
	return 0;
    }
    if (this_player()->query_hp() <= 6) return notify_fail("You are about to die!\n");
    ob = present(str, this_player());
    if(!ob) ob = present(str, environment(this_player()));
    if(!ob) ob = environment(this_player());
    if(!ob->id(str)) {
	notify_fail("You cannot lockpick that.\n");
	return 0;
    }
    ob->set_disable();
    if(!ob->query_locked(str)) {
	notify_fail("The "+str+" is not locked!\n");
	return 0;
    }
    locks = (int)this_player()->query_skill("locks");
    inv = all_inventory(this_player());
    tool = 0;
    for(i=0; i<sizeof(inv); i++) {
       if (inv[i]->query_property("lockpicking tool") > tool)
	tool = inv[i]->query_property("lockpicking tool");
    }
    locks += tool;
    resist = (int)ob->query_property("magic hold");
    if(locks < (random(101) + resist)) {
	this_player()->add_hp(-5);
	write("You fail to pick the lock.\n");
	if((int)this_player()->query_stats("dexterity") < random(101)) {
	    write("You cut yourself on the lock!\n");
	    this_player()->do_damage((string)this_player()->return_limb(), random(10));
	    say(this_player()->query_cap_name()+" gets cut picking the lock.\n");
	    this_player()->add_skill_points("locks", random(5));
	    return 1;
  	}
        this_player()->add_skill_points("locks", random(7));
	say(this_player()->query_cap_name()+" fails to pick the lock.\n", this_player());
	return 1;
    }
    if(!ob->pick_lock(str)) {
	this_player()->add_hp(-5);
	write("A magic force prevents you from picking the lock.\n");
	say("A magic force prevents "+this_player()->query_cap_name()+" from the picking the lock.\n");
	this_player()->add_skill_points("locks", random(resist));
	return 1;
    }
    write("You pick the lock.\n");
    say(this_player()->query_name()+" successfully picks the lock.\n", this_player());
    this_player()->add_skill_points("locks", 10 + resist);
    return 1;
}

void help() {
    write("Syntax: <lockpick [(item)]>\n\n"+
	"This command is an attempt to pick the lock on an item if an item\n"+
	"is specified, or a lock in the room if no item is specified.\n");
}

int abil() {
   object l;
   l = this_player();
   if (!l);
   if (l->query_class() != "rogue") return 0;
   if (l->query_skill("locks") < 15) return 0;
   if (l->query_level() < 3) return 0;
   return 1;
}

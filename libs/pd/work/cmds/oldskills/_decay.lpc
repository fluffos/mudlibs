#include <move.h>
#include <std.h> 
inherit DAEMON;
int spell();

int cmd_decay(string str) {
    int amount, ammount, i, b;
    string Class, *curr;
    object ob, *all, mon;

    if (!spell()) {
	write("What?\n");
	return 1;
    }
    if(str!="corpse") {
	notify_fail("Decay what?\n");
	return 0;
    }
    if(!present("remains", environment(this_player()))) {
	notify_fail("No corpse here!\n");
	return 0;
    }
    if(this_player()->query_current_attacker()) {
	notify_fail("You cannot do that in battle!\n");
	return 0;
    }
    Class = (string)this_player()->query_subclass();
    if(Class != "necromancer") {
	notify_fail("There is no way.\n");
	return 0;
    }
    if(this_player()->query_ghost())
    {
	write("You have no body to decay with!");
	return 1;
    }
    write("You decay this corpse feeding off the putrid energies it creates.");
    say(this_player()->query_cap_name()+" makes the corpse turn to dust.", this_player());
    amount = random((int)this_player()->query_skill("faith")/7 + 6);
    this_player()->heal(amount);
    this_player()->add_alignment(-(amount*5));
    ob = present("remains", environment(this_player()));
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
		write("You are too overburdened to take "+all[i]->query_short()+"%^RESET%^.");
	    else {
		write("You get "+all[i]->query_short()+" from the corpse.");
		if(this_player()->query_property("autobag"))
		    this_player()->force_me("put "+all[i]->query_id()[0]+" in "+this_player()->query_property("autobag"));
	    }
	}
    }
    ob->remove();
    if(ob)
	destruct(ob);
    return 1;
}

void help() { 
    write("Syntax: <decay corpse>\n\n"+
      "Allows a necromancer to decay a corpse and feed off the energies of death.\n");
}

int spell() { if (this_player()->query_subclass() == "necromancer") return 1; }

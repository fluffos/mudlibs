// a dungeonware.net producion 28-Nov-00
// based upon firebomb.c
#include <std.h>
#include <daemons.h>
inherit DAEMON;
int spell();
int cmd_chaoswave(string str)
{
    int i, x;
    string party;
    object *per=({});
    if(str) return 0;
    if (!spell()) {
	write("What?\n");
	return 1;
    }
    if (this_player()->query_disable())
	return notify_fail("You are busy.\n");
    if (this_player()->query_mp() < 70)
	return notify_fail("Your spell fails, due to lack of magic.\n");
    if (environment(this_player())->query_property("no attack") || environment(this_player())->query_property("no magic") )
    {
	write("Greater powers prevent your malice.");
	return 1;
    }
    i = this_player()->query_skill("necromancy");
    i += this_player() ->query_skill("magic attack")* 3/2;
    i += this_player()->query_stats("wisdom")*3/5;
    write("%^BOLD%^%^BLUE%^You flood the area with waves of chaos!\n%^RESET%^");
    say("%^BOLD%^%^BLUE%^"+this_player()->query_cap_name()+" floods the area with the negative energies of chaos!%^RESET%^\n");
    this_player()->add_mp(-(random(25)));
    per = all_inventory(environment(this_player()));
    x = sizeof(per);
    if (this_player()->query_party())
	party = this_player()->query_party();
    else party = "AdkIl898-FL00Jn-neInfe_ron";
    this_player()->set_paralyzed(1+random(2), "You are concentrating on creating waves of chaos.");
    while(x--) {
	if (!per[x]->is_living()) continue;
	if (this_player()->query_mp() < 70) {
	    write ("%^BOLD%^%^BLUE%^The energy dissipates into nothingness.%^RESET%^");
	    break;
	}
	if (per[x]->query_party() == party) continue;
	if (!per[x]->query_ghost() && per[x] != this_player() && !wizardp(per[x])) {
	    if(per[x]->query_skill("magic defense") + per[x]->query_stats("wisdom") > i) {
		write("%^BOLD%^%^BLUE%^The waves of chaos flow around "+per[x]->query_cap_name()+" doing no harm.\n%^RESET%^");
		say("%^BOLD%^%^BLUE%^Waves of chaos flow around "+per[x]->query_cap_name()+" doing no harm.\n%^RESET%^");
		tell_object(per[x], "%^BOLD%^%^BLUE%^The waves of chaos flow around you doing no harm!\n%^RESET%^");
		continue;
	    }
	    if(!this_player()->kill_ob(per[x])) {
		write(per[x]->query_cap_name()+" can't be attacked by you yet.");
		return 1;
	    }
	    per[x]->damage(i+(random(i)/3) - per[x]->query_skill("magic defense")*2/3 - per[x]->query_stats("wisdom") , "physical");
	    this_player()->kill_ob(per[x]);
	    tell_object(per[x], "%^BOLD%^%^BLUE%^The waves of chaos cause you great pain!\n%^RESET%^");
	    tell_room(environment(per[x]), "%^BLUE%^The waves greatly wound "+per[x]->query_cap_name()+" with negative energy!\n%^RESET%^", ({ per[x] }));
	    this_player()->add_mp(-i/14)*x;
	    this_player()->set_disable();
	}
    }
    return 1;
}

void help() {
    message("help", "Syntax: <chaoswave>\n"
      "\n"
      "A necromancer spell that sends waves of negative energy known\n"
      "as chaos towards everything in the immediate area.\n",
      this_player());
}
int spell() {
    object tp;
    tp = this_player();
    if (tp->query_subclass() != "necromancer")
	return 0;
    if (tp->query_level() < 30) return 0;
    return 1;
}

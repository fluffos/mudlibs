//	/std/fish_room.c
//	from the Nightmare mudlib
//	an inheritable fishing room originally created for IgorMud
//	created and written by Descartes of Borg 03 september 1992
//	modified significantly 10 february 1993
//      minor changes 5 november 1993

#define FISH ([ "mackeral":3, "blue fish":5, "flounder":12, "marlin":20, "swordfish":30 ])

#include <std.h>

inherit ROOM;

mapping fishing, fish;
int max_catch, chance, caught, max_fishing;

int stop_fishing(string str);
void catch_anything(string who);
void still_fishing(string who);
void caught_something(string who);
void give_player_a_fish(string who, string fish_name, int strength);
int pole_breaks(int wt, string who);
void snap(string who);

void init() {
    ::init();
    add_action("go_fish", "fish");
    add_action("dropped_the_pole", "drop");
    add_action("stop_fishing", "stop");
}

int go_fish() {
    object ob;

    if(!fishing) fishing = ([]);
    ob = present("fishing pole", this_player());
    if(!ob) {
	notify_fail("You really need something to fish with!\n");
	return 0;
    }
    if(ob->query_broken()) {
	notify_fail("You cannot fish while your "+(string)ob->query_name()+
	    " is broken!\n");
	return 0;
    }

    if(this_player()->query_current_attacker()) {
      notify_fail("You are too busy to fish right now.\n");
      return 0;
    }

    if(fishing[(string)this_player()->query_name()]) {
	notify_fail("You are already fishing!\n");
	return 0;
    }
    if(max_fishing <= sizeof(fishing)) {
	write("The area is simply too crowded with people fishing right now.");
	say(this_player()->query_cap_name()+" is unable to find a spot to fish.", this_player());
	return 1;
    }
    write("You cast your "+(string)ob->query_name()+" into the water and start fishing.");
    say(this_player()->query_cap_name()+" casts "+(string)this_player()->query_possessive()+
	" "+(string)ob->query_name()+" into the water.", this_player());
    fishing[(string)this_player()->query_name()] = ob;
    call_out("catch_anything", 10, (string)this_player()->query_name());
    return 1;
}

int dropped_the_pole(string str) {
    if(!fishing) return 0;
    if(!fishing[(string)this_player()->query_name()]) return 0;
    if(!fishing[(string)this_player()->query_name()]->id(str)) return 0;
    if(stop_fishing("fishing")) return 0;
    else {
	write("You cannot drop it!");
	return 1;                /* Why would this happen? */
    }
}

int stop_fishing(string str) {
    if(!str || str != "fishing") return 0;
    if(!fishing) {
	notify_fail("You are not fishing!\n");
	return 0;
    }
    if(!fishing[(string)this_player()->query_name()]) {
	notify_fail("You are not fishing!\n");
	return 0;
    }
    map_delete(fishing, (string)this_player()->query_name());
    write("You stand up and pull in your line.");
    say(this_player()->query_cap_name()+" gives up on fishing for now.", this_player());
    return 1;
}

void catch_anything(string who) {
    int bait, str_class;

    if(!who) return;        /* how in hell did this happen? */
    if(!present(who)) map_delete(fishing, who);
    if(!fishing[who]) return;
    bait = (int)fishing[who]->query_bait();
    str_class = (int)fishing[who]->query_pole_class();
    if( (caught == max_catch) || (random(101) > chance+str_class+bait) ) 
	still_fishing(who);
    else caught_something(who);
}

void still_fishing(string who) {
    tell_object(present(who), "You pull in your line and cast again, hoping for better luck this time.");
    tell_room(this_object(), this_player()->query_cap_name()+" pulls in "+(string)this_player()->query_possessive()+
	" line and then casts again.", ({ present(who) }));
    call_out("catch_anything", 10, who);
}

void caught_something(string who) {
    string fish_name;

    if(!fish) fish = FISH;
    fish_name = keys(fish)[random(sizeof(fish))];
    tell_object(present(who), "Suddenly you feel something tug at your "+
	(string)fishing[who]->query_name()+"!");
    tell_object(present(who), "You see a "+fish_name+" fighting on your hook!");
    tell_room(this_object(), "Something tugs at "+present(who)->query_cap_name()+"'s line!",
	({ present(who) }) );
    tell_room(this_object(), present(who)->query_cap_name()+" has hooked a "+
	fish_name+"!", ({ present(who) }) );
    give_player_a_fish(who, fish_name, fish[fish_name]);
}

void give_player_a_fish(string who, string fish_name, int strength) {
    object this_catch;

    if(!pole_breaks(strength, who)) {
	this_catch = new("std/food");
	this_catch->set_name(fish_name);
	this_catch->set_id( ({ "fish", fish_name }) );
 	this_catch->set_short(capitalize(fish_name));
	this_catch->set_long("A fish caught by a fisher of Nightmare!\n");
        this_catch->set_strength(strength);
	this_catch->set_value(0);
	this_catch->set_destroy();
        this_catch->set_weight(50);
	if(this_catch->move(present(who))) this_catch->move(this_object());
    }
    else snap(who);
    fishing[who]->unbait();
    caught ++;
    map_delete(fishing, who);
}

int pole_breaks(int wt, string who) {
    int max_wt, str_class;

    str_class = (int)fishing[who]->query_pole_class();
    max_wt = (str_class - 1) * (str_class - 1);
    if(max_wt < wt) return 1;
    else return 0;
}

void snap(string who) {
    fishing[who]->break_pole();
    tell_object(present(who), "The fish is so big, it breaks your "+
	(string)fishing[who]->query_name()+"!");
    tell_room(this_object(), present(who)->query_cap_name()+" catches a fish "+
	"so big that it breaks "+(string)present(who)->query_possessive()+
	" "+(string)fishing[who]->query_name()+"!", ({present(who)}));
}

void set_max_fishing(int x) {
    if(x>10) x=10;
    max_fishing = x;
}

int query_max_fishing() { return max_fishing; }

void set_chance(int x) { 
    if(x > 20) x=20;
    chance = x;
}

int query_chance() { return chance; }

void set_max_catch(int x) { max_catch = x; }

int query_max_catch() { return max_catch; }

void set_fish(mapping borg) { fish = borg; }

mapping query_fish() { return fish; }

void add_fish(string nom, int x) {
    if(!fish) fish = ([]);
    fish[nom] = x;
}

//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit OBJECT;
int i;
void add_bees(string who);

void create() {
    ::create();
    set_name("bee hive");
    set_short("a bee hive");
    set_long("This is the home of many of thousands of bees.  They swarm "
      "around quietly going about there business.");
    set_prevent_get("You cannot take that.");
    set_id(({"hive", "bee hive"}));
}

void reset() {
    ::reset();
    i = 0;
}

void init() {
    ::init();
    add_action("search", "search");
    add_action("enter", "enter");
}

int search(string str) {
    if(str != "hive" && str != "bee hive") return 0;
    if(i==1) {
	write("There is nothing in the hive.  You may be able to fit into "
	  "the hole though.");
	return 1;
    }
    write("Ohh No!  You pissed off the bees.  Bees start swarming out of the "
      "hive.");
    add_bees(this_player()->query_name());
    i = 1;
    return 1;
}

void add_bees(string who) {
    int x;
    object bee;
    x = random(20);
    if(x < 5) x = 10;
    while(x--) {
	bee = new(MON"bee");
	bee->move(environment(this_object()));
	bee->force(who);
    }
}

int enter() {
    if(!i) {
	write("Its not a good idea while there are bees inside.\n");
	return 1; 
    }
    if(present("angry bee")) {
	write("Its not a good idea while there are bees around.\n");
	return 1;
    }
    //    "/d/citrin/gemote"->start();
    this_player()->move_player(ROOMS"hive/1");
    return 1;
}


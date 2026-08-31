//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

int dead() {
    "/d/citrin/mon/army/guardian"->start();
    return 1;
}

void create() {
    ::create();
    set_name("alverest");
    set_long("The man is dressed in old, tathered rags.  A deep "
      "frown is on his face.  He seems like he may be in deep "
      "concentration.");
    set_short("Alverest, the gnome");
    set_id(({"alverest","gnome", "alverest the gnome"}));
    set_race("gnome");
    set_body_type("gnome");
    set_level(70);
    set_gender("male");
    set_die((: dead() :));
}

void catch_tell(string str) {
    string tmp, a, b;
    int i;
    object *all;

    if(sscanf(str, "%suest", tmp)==1) {
	this_object()->force_me("say So you have heard about my biddings.");
	this_object()->force_me("emote grins.");
	call_out("b", 5);
    }
    if(sscanf(str, "%s gives you %s.", a, b) == 2) {
	if(b == "gemmed necklace") {
	    if(present("gemmed necklace", this_object())) {
		this_object()->force_me("say Thank you so much for returning my "
		  "necklace.");
		this_object()->force_me("emote smiles.");
		message("", "You are rewarded for helping Alverest.",
		  this_player());
		message("", this_player()->query_cap_name()+" is rewarded for "
		  "helping "
		  "Alverest.", environment(this_player()), ({ this_player() }));
		if(this_player()->set_mini_quest("alverest", 100, "You returned "
		    "Alverest's lost necklace.")) {
		    this_player()->add_exp(800+random(200));
    		    this_player()->add_money("gold", 10000);
            }
		i = sizeof(all = all_inventory(this_object()));
		while(i--) {
		    if(member_array("gemmed necklace", all[i]->query_id()) != -1)
			all[i]->remove();
		}
		return;
	    }
	}
	this_object()->force_me("say That is not what my heart desires.");
	this_object()->force_me("give "+b+" to "+lower_case(a));
	return;
    }
}

void b() {
    this_object()->force_me("say I was walking through the forest one day.  "
      "A monster jumped out from the bushes and attacked.  As he attacked "
      "my necklace my son, \"The lonely Traveller\" gave me, fell off onto "
      "some bushes.  Every since,  a monster has been guarding it and "
      "wont let me get it.  It would be very kind if you would get my "
      "necklace.  You will not go empty handed.");
}


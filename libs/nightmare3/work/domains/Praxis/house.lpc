#include <std.h>

inherit VAULT;

void create() {
    ::create();
    set_properties( ([ "no castle" : 1,"light" : 2, "indoors" : 1]) );
       set_short("a house with a thatched roof");
 set_long(
	"The small thatch covered house has been standing for many years. "
        "It is the dwelling of an old, dishonored knight. The house "
"is very sparse, devoid of any decorations or furnishings. The knight "
"is quite poor and cannot afford any more than a few meager belongings. "
	"A rough wooden  door leads into a room to the south, "
"and north leads back to Sun Alley.");
    set_items(
	(["thatch" : "It is beginning to suffer from the weather "
	    "and ill-keeping.",
	  "house" : "It is very unimpressive.",
	  "furnishing" : "Nothing.",
	  "decoration" : "Absolutely nothing.",
	  "door" : (: this_object(), "look_at_door" :) ]) );
    set_exits( 
	      (["south" : "/domains/Praxis/locked",
		"north"	: "/domains/Praxis/sun1"]) );
    set_door("door", "/domains/Praxis/locked", "south", "honor key");
    present("knight")->force_me("close door");
    present("knight")->force_me("lock door with key");
}

void reset() {
    object mon, key;

    ::reset();
    if(!present("knight")) {
	mon = new("/domains/Praxis/obj/mon/knight");
 	mon->move(this_object());
	new("/domains/Praxis/obj/armour/helm")->move(mon);
	mon->command("wear helm");
        key = new(OBJECT);
	key->set_name("key");
  	key->set_id( ({ "key", "honor key" }) );
	key->set("short", "a wooden key");
	key->set("long", "The wooden key is very coarse, and rough. "
		 "It doesn't look like it would lead to anything of "
		 "importance.");
	key->set_value(15);
	key->set_weight(40);
	key->move(mon);
    }
    if(query_reset_number() != 1) {
        present("knight")->force_me("close door");
        present("knight")->force_me("lock door with key");
    }
}

void look_at_door() {
    if(query_open("door")) write("It is open.");
    else write("It is closed.");
}


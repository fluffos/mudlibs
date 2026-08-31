#include <std.h>
#include <daemons.h>
#include <tirun.h>
inherit ROOM;
#define COST    money/bonus
void init() {
    ::init();
    add_action("new_body", "renew");
    add_action("clean_poison", "clean");
    add_action("regenerate", "regenerate");
    add_action("read", "read");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no bump", 1);
    set("short", "Hospital of Tirun");
    set("long",
      "%^GREEN%^The Tirun Hospital%^RESET%^\n"
      "The local Tirunian hospital is a clean white-walled building. Just "
      "about everything here is a dull white color. The Tirun hospital is "
      "known for it's specialties in limb regeneration. "
      "A list of all services that can be performed is posted on the wall.");
    set_items(([
	"list" : "You can read all the services by typing <read list>.",
	"hospital" : "The clerics here specialize in regenerating "
	"lost limbs.",
	"clerics" : "They are mending the wounds of patients."]));
    set_exits(([ "out" : ROOMS"ehonin3",
	"up" : ROOMS"clergy/cleric/cleric_join" ]) );
    set_property("no teleport", 1);
    set_property("no attack", 1);
    set_property("no steal", 1);
new("/d/nopk/tirun/obj/misc/thingy")->move(this_object());
}
void reset() {
    ::reset();
    if (!present("kaldir"))
	new(MOB "kaldir")->move(this_object());
}
int new_body(string str) {
    object *inv;
    int i;
    if( (int)this_player()->query_level() > 5) {
	return notify_fail("The clerics only perform this service for the inexperienced.\n");
    }
    inv = all_inventory(this_player());
    for(i=0; i<sizeof(inv); i++) {
	inv[i]->unequip();
    }
    write("Kaldir comes over to you and mutters a small prayer.");
    write("You again have all the limbs you were born with!");
    say("Kaldir mutters a small prayer for the novice "+this_player()->query_cap_name()+".", this_player());
    this_player()->new_body();
    return 1;
}
int read(string str) {
    if(!str) {
	return notify_fail("Read what?\n");
    }
    if(str != "list") {
	return notify_fail("That is not here for reading.\n");
    }
    message("info", "Welcome to the Hospital of Tirun!",this_player());
    message("Ninfo",
      "The clerics perform the following services:\n"
      "------------------------------------------------------------------\n"
      "<renew body>: This is a charity service the clerics perform for\n"
      "       novice adventurers who have lost limbs while adventuring.\n"
      "       All limbs are replaced.\n"
      "<regenerate [limb]>: This service is for the experienced adventurer\n"
      "       who has lost limbs.  The limb is replaced and acts like new.\n"
      "       Tithe schedule for regeneration:\n"
      "         from 320 gold for minor limbs (non-clerics)\n"
      "         to 800 gold for major limbs (non-clerics)\n"
      "         240 to 600 gold for clerics\n"
      "<clean poison>: Helps remove some of the poison from your body.\n"
      "       Tithe: 50 gold\n"
      "<buy '#' ointment>: This is a magical blend of curative salve the\n"
      "       clerics have blessed to heal minor body damage. (20 uses)\n"
      "       Tithe: 200 gold per vial\n"
      "------------------------------------------------------------------\n"
      "Half off all regenerations with the severed limb!\n"
      "Your tithe is used only toward good causes.\n", this_player());
    return 1;
}
int clean_poison(string str) {
    object tp;
    if(!str) return 0;
    if(str != "poison") return 0;
    tp = this_player();
    if((int)tp->query_poisoning()<1) {
	write("%^BOLD%^CYAN%^Kaldir whispers to you:%^RESET%^ But you are not poisoned!\n");
	return 1;;
    }
    if((int)tp->query_money("gold") < 50) {
	write("%^BOLD%^CYAN%^Kaldir whispers to you:%^RESET%^ You do not have enough gold for the tithe.\n");
	return 1;
    }
    tp->add_money("gold", -50);
    tp->add_poisoning(-10);
    write("Kaldir casts a spell of healing upon you.\n");
    say("Kaldir casts a spell of healing on "+tp->query_cap_name()+".", tp);
    return 1;
}
int regenerate(string limb) {
    int money, bonus;
    mapping limb_info;
    object tp;
    string *there, *missing;
    if (!limb) {
      write("%^BOLD%^%^CYAN%^Kaldir whispers to you:%^RESET%^ Regenerate what?\n");
      return 1;
    }
    tp = this_player();
    if(present(limb, this_player())) bonus = 2;
    else bonus = 1;
    there = (string *)tp->query_limbs();
    missing = (string *)this_player()->query_severed_limbs() +
    (string *)RACE_D->query_limbs((string)this_player()->query("race"));
    /*
       checking with the race_d is allowing compatibility with old
       versions of the mudlib
    */
    if(!missing) {
	write("%^BOLD%^CYAN%^Kaldir whispers to you:%^RESET%^ You are not missing any limbs.\n");
	return 1;
    }
    if(member_array(limb, missing) == -1) {
	write("%^BOLD%^CYAN%^Kaldir whispers to you:%^RESET%^ You are not missing that limb.\n");
	return 1;
    }
    if(member_array(limb, there) != -1) {
	write("%^BOLD%^CYAN%^Kaldir whispers to you:%^RESET%^ You already have that one back.\n");
	return 1;
    }
    limb_info= (mapping)RACE_D->query_limb_info(limb,(string)tp->query("race"));
    if(!limb_info) {
	write("%^BOLD%^CYAN%^Kaldir whispers to you:%^RESET%^ That limb cannot be replaced.\n");
	return 1;
    }
    if(limb_info["attach"] != "0") {
	if(member_array(limb_info["attach"], there) == -1) {
	    notify_fail("You would need a "+limb_info["attach"]+" for that!\n");
	    return 0;
	}
    }
    if((string)this_player()->query_class() == "cleric") money = 1200;
    else money = 1600;
    money = money / limb_info["max"];
    if((int)tp->query_money("gold") < COST) {
	write("%^BOLD%^CYAN%^Kaldir whispers to you:%^RESET%^ You do not have enough gold.\n");
	return 1;
    }
    tp->add_limb(limb, limb_info["ref"], (int)tp->query_max_hp()/limb_info["max"], 0, 0);
    if(member_array(limb, (string *)RACE_D->query_wielding_limbs((string)tp->query("race"))) != -1) 
	tp->add_wielding_limb(limb);
    this_player()->add_money("gold", -COST);
    say(sprintf("%s asks the clerics for some help with %s missing %s.",
	this_player()->query_cap_name(), possessive(this_player()), limb));
    write("Kaldir restores your "+limb+"!");
    return 1;
}

#include <std.h>
#include <daemons.h>
#include <purgatory.h>

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
    set_property("no castle", 1);
    set("short", "Purgatory Hospital");
    set("long",
      "%^BOLD%^%^RED%^The Purgatory Hospital.%^RESET%^\n"
        "%^BOLD%^%^BLACK%^Bodies lay strewn across the floor, rats and other pests "
"%^BOLD%^%^BLACK%^crawl around on the decaying flesh. Lepers and other hooded "
"%^BOLD%^%^BLACK%^figures move around the bodies, chanting incantations to "
"%^BOLD%^%^BLACK%^those that still live. A list of incantations can be seen on "
"%^BOLD%^%^BLACK%^the wall.");
    set_items(([
        "list" : "You can read all the services by typing <read list>.",
          "hospital" : "The lepers scurry around the hospital.",
          "bodies" : "Some travelers lay wounded and dead along the walls.",
          "rats" : "Large rats make their meals on the toes, ears and fingers of the people lying injured on the floor",
          "pests" : "Cockroaches, fleas, and other pests make their homes in and around the bodies.",
          "clerics" : "They are dragging out the dead and helping the sick."]));
    set_exits(([ "north" : ROOMS"purgatory10" ]) );
    set_property("no teleport", 1);
}

int new_body(string str) {
    object *inv;
    int i;

    if( (int)this_player()->query_level() > 5) {
        notify_fail("The lepers only perform this service for the inexperienced.\n");
        return 0;
    }
    inv = all_inventory(this_player());
    for(i=0; i<sizeof(inv); i++) {
        inv[i]->unequip();
    }
    write("A leper hobbles over to you and chants an incantation.");
    write("You again have all the limbs you were born with!");
    say("A leper mutters an incantation over "+this_player()->query_cap_name()+".", this_player());
    this_player()->new_body();
    return 1;
}

int read(string str) {
    if(!str) {
        notify_fail("Read what?\n");
        return 0;
    }
    if(str != "list") {
        notify_fail("You moron! You cant read that!\n");
        return 0;
    }
    message("info", "Welcome to the Purgatory Hospital!",this_player());
    message("Ninfo",
        "The lepers might preform any of this:\n"
        "------------------------------------------------------------------\n"
        "<renew body>: The lepers might take pity on any small\n"
        "       travelers who have lost their limbs and renew\n"
        "       their bodies.\n"
        "<regenerate [limb]>: If the lepers feel like it they might\n"
        "       replace the limbs for the more experienced travelers\n"
        "       This is a costly commission though and will require:\n"
        "            from 500 gold for minor limbs (non-clerics)\n"
        "            to 1500 gold for major limbs (non-clerics)\n"
        "            300 to 800 gold for clerics\n"
        "<clean poison>: Helps remove some of the poison from your body.\n"
        "Cost: 150 gold\n"
        "------------------------------------------------------------------\n"
        "Half off all regenerations with the severed limb!\n"
        "Your gold is used to further corrupt the fair people of this town.\n", this_player());
    return 1;
}

int clean_poison(string str) {
    object tp;

    if(!str) return 0;
    if(str != "poison") return 0;
    tp = this_player();
    if((int)tp->query_poisoning()<1) {
        notify_fail("%^BOLD%^%^RED%^A leper yells into your face:%^RESET%^ You arent poisoned, out of my hospital!\n");
        return 0;
    }
    if((int)tp->query_money("gold") < 150) {
        notify_fail("You do not have enough gold to be cleaned.\n");
        return 0;
    }
    tp->add_money("gold", -150);
    tp->add_poisoning(-10);
    tp->add_alignment(-random(300));
    write("A leper runs its diseased hands across your skin.\n");
    say("A leper runs its diseased hands across "+tp->query_cap_name()+"'s skin.", tp);
    return 1;
}

int regenerate(string limb) {
    int money, bonus;
    mapping limb_info;
    object tp;
    string *there, *missing;

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
        notify_fail("%^BOLD%^%^RED%^The leper tells you:%^RESET%^ You arent missing limbs! Out of my hospital!\n");
        return 0;
    }
    if(member_array(limb, missing) == -1) {
        notify_fail("%^BOLD%^%^RED%^The leper tells you:%^RESET%^ You already have one of those!\n");
        return 0;
    }
    if(member_array(limb, there) != -1) {
        notify_fail("%^BOLD%^%^RED%^The leper tells you:%^RESET%^ Who are you trying to fool, you just got that one!\n");
        return 0;
    }
    limb_info=(mapping)RACE_D->query_limb_info(limb,(string)tp->query("race"));
    if(!limb_info) {
        notify_fail("That limb cannot be replaced!\n");
        return 0;
    }
    if(limb_info["attach"] != "0") {
        if(member_array(limb_info["attach"], there) == -1) {
            notify_fail("%^BOLD%^%^RED%^The leper tells you:%^RESET%^ I need "+limb_info["attach"]+" for that!\n");
            return 0;
        }
    }
    if((string)this_player()->query_class() == "cleric") money = 2200;
    else money = 2600;
    money = money / limb_info["max"];
    if((int)tp->query_money("gold") < COST) {
        notify_fail("The leper tells you:  You do not have enough gold.\n");
        return 0;
    }
    tp->add_limb(limb, limb_info["ref"],
(int)tp->query_max_hp()/limb_info["max"], 0, 0);
    if(member_array(limb, (string
*)RACE_D->query_wielding_limbs((string)tp->query("race"))) != -1) 
        tp->add_wielding_limb(limb);
    this_player()->add_money("gold", -COST);
    say(sprintf("%s asks the clerics for some help with %s missing %s.",
      this_player()->query_cap_name(), possessive(this_player()), limb));
    write("The clerics restore your "+limb+"!");
    return 1;
}

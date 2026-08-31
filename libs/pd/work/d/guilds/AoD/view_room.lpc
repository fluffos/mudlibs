#include <guild.h>
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Aod Scry Room");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );

    set_exits((["up" : AoD"hall"]));
    set_long("%^BOLD%^%^BLACK%^This cavernous room seems "
      "to hum with power.  Six gigantic pillars stand in "
      "a circle in the middle.  Soft blue lines of energy "
      "coil around them and flicker in between them.  "
      "Dead center lies a sphere of jet black obsidian.  "
      "Red lightning can be seen flashing from within.  "
      "A compelling voice calls out, drawing those who "
      "enter into this chamber of power.  The urge to "
      "touch the sphere and peer into its depths is "
      "overwhelming.");
    set_items( ([ 
	"sphere" : "Light pulses from within, vague scenes "
	"from distant lands flicker rapidly.",
	({ "pillar", "pillars" }) : "Strange runes cover "
	"these pillars, glowing with a faint, red aura."
      ]) );
}

void init() {
    ::init();
    add_action("view", "view");
}

int view(string str) {
    object ob, env;

    if(!str) return notify_fail("View whom?\n");
    if(!ob = find_player(str)) return notify_fail("You place your "
	  "hands upon the sphere and energy crackles but nothing "
	  "enters your mind.\n");
    if(wizardp(ob)) return notify_fail("You place your "
	  "hands upon the sphere and energy crackles but nothing "
	  "enters your mind.\n");
    env = environment(ob);
    if(env->query_property("no scry") || env->query_property("no teleport")) return notify_fail("You place your "
	  "hands upon the sphere and energy crackles but nothing "
	  "enters your mind.\n");
    message("scry", "%^BLACK%^%^BOLD%^You place your hands upon the sphere and energy "
      "crackles as your mind is sucked into the vortex!%^RESET%^\nYou see "+
      ob->query_cap_name()+" at "+env->query_short()+".", this_player());
    message("scry", "Energy crackles as "+this_player()->query_cap_name()+" places "+
      possessive(this_player())+" hands on the sphere.", 
      environment(this_player()), ({ this_player() }) );
    return 1;
}


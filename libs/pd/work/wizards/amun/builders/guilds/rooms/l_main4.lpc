#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set("short", "Guild Town");
    set("long","%^BOLD%^%^BLACK%^The path becomes a circle that leads off into halls for travelers to use. Completly void of life, the area is covered in %^WHITE%^snow%^BLACK%^. No warmth can be found in the area, just the absence of anything breathing light. The %^WHITE%^snow %^BLACK%^blows down hard causing the already cold area to freeze.%^RESET%^");
    set_items((["path" : "%^BOLD%^%^BLACK%^The path breaks at the end and forms a circle with paths leading towards the %^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^mon%^WHITE%^, %^BLACK%^dr%^RED%^ag%^BLUE%^on%^WHITE%^, %^BLACK%^rogue%^WHITE%^, and %^RED%^fighter %^WHITE%^halls.%^RESET%^", "halls" : "%^BOLD%^%^WHITE%^The path breaks at the end and forms a circle with paths leading towards the %^BLACK%^d%^RESET%^e%^BOLD%^%^BLACK%^mon%^WHITE%^, %^BLACK%^dr%^RED%^ag%^BLUE%^on%^WHITE%^, %^BLACK%^rogue%^WHITE%^, and %^RED%^fighter %^WHITE%^halls.%^RESET%^", "snow" : "%^BOLD%^%^WHITE%^The snow comes down hard in the area.%^RESET%^"]));
    set_exits( ([ "enter dragon" : GROOM "draghall", "enter demon" : GROOM "demhall", "enter rogue" : GROOM "roghall", "enter fighter" : GROOM "fighthall", "east" : GROOM "l_main3", "north" : GROOM "g5" ]) );
    add_pre_exit_function("enter dragon", "go_dragon");
    add_pre_exit_function("enter demon", "go_demon");
    add_pre_exit_function("enter rogue", "go_rogue");
    add_pre_exit_function("enter fighter", "go_fighter");
}
void init() {
    ::init();
    add_action("lookin", "peer");
    add_action("say_breath", "say");
}
int go_dragon() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_race() != "dragon") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "Dragon's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_demon() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_race() != "demon") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "Demon's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_fighter() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "fighter") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "Fighter's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_rogue() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "rogue") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "Rogue's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int lookin(string str) {
    string *disallow;
    disallow = ({ "dragon", "demon", "fighter", "rogue" });
    if(member_array(str, disallow) == -1)
	return 0;
    else {
	message("info", "This hall is closed off from view.", this_player(),);
	return 1;
    }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );
    return 1;
}
int say_breath(string str) {
    write("As you speak, your breath shows up in the air.");
    say("As "+this_player()->query_cap_name()+" speaks, their breath becomes visible.");
    return 0;
}

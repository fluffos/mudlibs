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
    set("long","%^BOLD%^%^WHITE%^The path becomes a circle that leads off into halls for travelers to use. Large %^MAGENTA%^c%^WHITE%^h%^MAGENTA%^erry b%^WHITE%^l%^MAGENTA%^ossum %^WHITE%^trees stand tall around the circled path. As the wind picks up, %^MAGENTA%^f%^WHITE%^l%^MAGENTA%^o%^WHITE%^w%^MAGENTA%^e%^WHITE%^r%^MAGENTA%^s %^WHITE%^from the %^MAGENTA%^c%^WHITE%^h%^MAGENTA%^erry b%^WHITE%^l%^MAGENTA%^ossums %^WHITE%^float down like %^MAGENTA%^pink rain%^WHITE%^. The area is serene and quiet.%^RESET%^");
    set_items((["path" : "%^BOLD%^%^WHITE%^The path breaks at the end and forms a circle with paths leading towards the %^YELLOW%^a%^WHITE%^n%^YELLOW%^gel%^WHITE%^, %^CYAN%^mage%^WHITE%^, %^BLUE%^wanderer%^WHITE%^, and clergy halls.%^RESET%^", "halls" : "%^BOLD%^%^WHITE%^The path breaks at the end and forms a circle with paths leading towards the %^YELLOW%^a%^WHITE%^n%^YELLOW%^gel%^WHITE%^, %^CYAN%^mage%^WHITE%^, %^BLUE%^wanderer%^WHITE%^, and clergy halls.%^RESET%^", "cherry blossums" : "%^BOLD%^%^WHITE%^The %^MAGENTA%^c%^WHITE%^h%^MAGENTA%^erry b%^WHITE%^l%^MAGENTA%^ossums %^WHITE%^stand tall and full along the path.%^RESET%^", "trees" : "%^BOLD%^%^WHITE%^The %^MAGENTA%^c%^WHITE%^h%^MAGENTA%^erry b%^WHITE%^l%^MAGENTA%^ossums %^WHITE%^stand tall and full along the path.%^RESET%^", "flowers" : "%^BOLD%^%^MAGENTA%^The flowers from the %^MAGENTA%^c%^WHITE%^h%^MAGENTA%^erry b%^WHITE%^l%^MAGENTA%^ossums float down softly like a gentle rain.%^RESET%^"]));
    set_exits( ([ "enter mage" : GROOM "magehall", "enter angel" : GROOM "anghall", "enter clergy" : GROOM "clerghall", "enter wanderer" : GROOM "wandhall", "west" : GROOM "r_main3", "north" : GROOM "g6" ]) );
    add_pre_exit_function("enter mage", "go_mage");
    add_pre_exit_function("enter angel", "go_angel");
    add_pre_exit_function("enter wanderer", "go_wanderer");
    add_pre_exit_function("enter clergy", "go_clergy");
}
void init() {
    ::init();
    add_action("lookin", "peer");
}
int go_mage() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "mage") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "Mage's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_angel() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_race() != "archangel") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "Angel's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_wanderer() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "wanderer") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "Wanderer's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int go_clergy() {
    if(wizardp(this_player())){
	write("Mighty immortals are always welcome into the hall.");
	return 1;
    }
    if((string)this_player()->query_class() != "clergy") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	  "Clergy's sanctuary, but fails.", this_player());
	return 0;
    }
    return 1;
}
int lookin(string str) {
    string *disallow;
    disallow = ({ "wanderer", "angel", "clergy", "mage" });
    if(member_array(str, disallow) == -1)
	return 0;
    else {
	message("info", "This hall is closed off from view.", this_player(),);
	return 1;
    }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );
    return 1;
}

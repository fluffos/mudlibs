#include <std.h>
#include <ether.h>
inherit ETHERARM;
void create() {
::create();
set_name("scorpion tattoo");
set("id",({"scorpion", "tattoo"}));
set("short","%^BOLD%^%^BLACK%^a tattoo of a %^MAGENTA%^scorpion%^RESET%^");
set("long", "A huge %^BLUE%^tattoo%^RESET%^ of a menacing scorpion. Maybe you should make it glow: <scorpionglow>");
set_type("shield");
//Don't know how to set it as a wearable non-armour type.
set_ac(0);
set_limbs(({"torso"}));
set_weight(0);
set("value",0);
set_element("earth",2);
set_element("fire",2);
set_element("ice",2);
}

int query_auto_load() {
  if (this_player()->query_name()=="tahngarth" || this_player()->query_name() == "aethar") return 1;
}

int tahngarthonly(string str) {
     if (!str || present(str, this_player()) != this_object()) return 0;
     if (this_player()->query_name()=="tahngarth" || this_player()->query_name() == "aethar") return 0;
     write("This is not your tattoo! You're %^RED%^sin%^YELLOW%^ged%^RESET%^ "
	"by a %^GREEN%^mystical %^RESET%^%^B_RED%^%^YELLOW%^fire.%^RESET%^"
     );
     this_player()->do_elemental("fire",200);
     return 1;
}

void special() {
if (!this_object()->query_worn()) return notify_fail("You need to have the tattoo worn first.\n");
write(
	"%^BLUE%^Your tattoo glows for a while, the scorpion seems to be animated...%^RESET%^\n"
);
say(
	"%^GREEN%^You notice the scorpion %^BOLD%^%^BLACK%^tattoo%^RESET%^%^GREEN%^ on "
	"%^RED%^"+this_player()->query_cap_name()+"%^GREEN%^ to be moving. %^MAGENTA%^"+this_player()->query_cap_name()+" gives you a "		   			        "%^B_YELLOW%^%^RED%^w%^RESET%^i%^B_YELLOW%^%^RED%^c%^RESET%^k%^B_YELLOW%^%^RED%^e%^RESET%^d"
	" grin.%^RESET%^\n"
);
return 1;
}
void init() {
  ::init();
    add_action("tahngarthonly", "wear");
    add_action("special","scorpionglow");
}

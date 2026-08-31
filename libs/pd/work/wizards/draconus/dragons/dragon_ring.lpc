#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_property("no steal", 1);
    set_id(({"ring","dragon ring","ring of draconus"}));
    set_name("dragon ring");
    set_short("Ring of Draconus");
    set_long("It is a ring with a figure of a dragon roaring ferociously mounted on it.");
    set_mass(0);
    set_value(0);
    set_type("ring");
    set_ac(15);
    set_limbs(({"head","torso","right horn","left horn","right wing","left wing","front right leg","front left leg","back right leg","back left leg","front right claw","front left claw","back right claw","back left claw","tail"}));
}

void init() {
    ::init();
    add_action("prevent_put","put");
    add_action("prevent_drop","drop");
}

int prevent_put(string str) {
    string *strs;

    strs = explode(str, " ");
    if (id(strs[0])) {
        write("You can't remove your ring!");
	return 1;
    }
    return 0;
}

int prevent_drop(string str) {
    string *strs;

    strs = explode(str, " ");
    if (id(strs[0])) {
	write("You can't remove your ring!");
	return 1;
    }
    return 0;
}

string extra_look() {
   string res;
   mapping d_types = ([
"fire" : "%^BOLD%^RED%^red%^RESET%^",
"ice" : "%^BOLD%^%^CYAN%^bright cyan%^RESET%^",
"shadow" : "%^BOLD%^BLACK%^black%^RESET%^",
"sonic" : "%^BLUE%^blue%^RESET%^",
"lightning" : "%^YELLOW%^bright yellow%^RESET%^",
"water" : "%^CYAN%^cyan%^RESET%^",
"air" : "%^BOLD%^white%^RESET%^",
"faerie" : "%^BOLD%^MAGENTA%^bright pink%^RESET%^",
"earth" : "%^ORANGE%^brown%^RESET%^",
"forest" : "%^BOLD%^GREEN%^bright green%^RESET%^",
"cloud" : "%^BOLD%^bright white%^RESET%^",
"sand" : "%^ORANGE%^tan%^RESET%^",
"storm" : "%^BOLD%^BLUE%^deep blue%^RESET%^",
"mist" : "%^BOLD%^BLACK%^grey%^RESET%^",
"wind" : "%^BOLD%^CYAN%^turquoise%^RESET%^",
]);

   res = capitalize(environment()->query_subjective())+" has the mark of Draconus on "+environment()->query_possessive()+" forehead.\n";

   res += capitalize(environment()->query_possessive())+" scales are "+d_types[environment()->query_subclass()]+".\n";
   return res;
}

int query_invis() { return 1; }

int query_auto_load() { return 1; }

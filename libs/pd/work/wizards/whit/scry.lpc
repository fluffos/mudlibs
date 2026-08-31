#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_name("Forsaken Scry Room");
    set_long("The atmosphere of this small room is somewhat "
      "%^BOLD%^%^BLACK%^darker %^RESET%^than that of the rest "
      "of the guild. The walls seem to %^YELLOW%^glow %^RESET%^"
      "%^WHITE%^multiple %^BLUE%^s%^RED%^h%^BLUE%^a%^RED%^d"
      "%^BLUE%^e%^RED%^s%^WHITE%^ of %^BOLD%^%^BLACK%^black"
      "%^RESET%^ and %^RED%^red %^WHITE%^simultaneously, and "
      "are accompanied by the %^BOLD%^%^BLUE%^oth%^RESET%^"
      "%^CYAN%^erwor%^BOLD%^%^BLUE%^ldly %^RESET%^%^WHITE%^light "
      "of a large %^BOLD%^%^WHITE%^intense%^RESET%^ %^BOLD%^"
      "%^BLACK%^black%^RESET%^ fire in the center of the room. "
      "The fire is surrounded by a circle of %^YELLOW%^glowing%^ "
      "%^RED%^ar%^YELLOW%^ca%^RED%^ne%^RESET%^%^WHITE%^ runes, and "
      "emits a %^BOLD%^%^WHITE%^s%^RESET%^w%^BOLD%^%^WHITE%^i"
      "%^RESET%^r%^BOLD%^%^WHITE%^l%^RESET%^i%^BOLD%^%^WHITE%^n"
      "%^RESET%^g, almost %^BOLD%^%^RED%^living %^RESET%^%^BOLD%^"
      "%^BLUE%^azhure %^RESET%^%^WHITE%^smoke.");
    set_short("Forsaken Scry Room");
    set_exits(([ "out":"/d/tirun/square" ]));
}

void init() {
    ::init();
    add_action("fview", "view");
}

int fview(string str) {
    object ob, env;
    if(!str) return notify_fail("View whom?\n");
    if(!ob = find_player(str)) return notify_fail("There is no one "
	  "in the realms by that name.\n");
    if(ob->query_invis() || !interactive(ob)) return notify_fail("There is no one "
	  "in the realms by that name.\n");
    env = environment(ob);
    if(env->query_property("no scry")) return notify_fail("Mist blocks your view\n");
    write(env->query_short());
    return 1;
}


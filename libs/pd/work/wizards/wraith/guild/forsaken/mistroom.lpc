#include <std.h>
inherit ROOM;
void create() {
    ::create();
     set_name("Forsaken Mist Room");
     set_short("Forsaken Mist Room");
     set_long("The atmosphere of this small room is somewhat %^BOLD%^%^BLACK%^darker%^RESET%^ than "
"that of the rest of the guild. The walls seem to %^BOLD%^%^YELLOW%^glow%^RESET%^ "
"multiple %^RESET%^%^BLUE%^s%^RED%^h%^BLUE%^a%^RED%^d%^BLUE%^e%^RED%^s%^RESET%^ of %^BOLD%^%^BLACK%^black%^RESET%^ and %^RED%^red%^RESET%^ simultaneously, and are "
"accompanied by the %^BOLD%^%^BLUE%^oth%^RESET%^%^CYAN%^erwor%^BOLD%^%^BLUE%^ldly%^RESET%^ light of a large %^BOLD%^%^WHITE%^intense%^RESET%^ "
"%^BOLD%^%^BLACK%^black%^RESET%^ fire in the center of the room. The fire is surrounded "
"by a circle of %^BOLD%^%^YELLOW%^glowing %^RED%^ar%^YELLOW%^ca%^RED%^ne%^RESET%^ runes, and emits a %^BOLD%^%^WHITE%^s%^RESET%^w%^BOLD%^%^WHITE%^i%^RESET%^r%^BOLD%^%^WHITE%^l%^RESET%^i%^BOLD%^%^WHITE%^n%^RESET%^g, almost %^BOLD%^%^RED%^living %^BLUE%^azure%^RESET%^ "
"smoke.");
     set_properties(([
        "light"       : 2,
        "no bump"     : 1,
        "indoors"     : 1,
        "no steal"    : 1,
        "no scry"     : 1,
        "no gate"     : 1,
]));

    set_items( ([
        "wall"  : "Empty eyed skulls streaked with blood stare back at you and
fleshless hands wave to you from their places in the walls.",
        "ceiling" : "Streaked with blood the bones of the dead seem to cave
inward twards you.",
        "blood" : "Running rivers of blood flow from the walls and ceiling to
form a huge pool in the middle of the room."
      ]) );
}

void init() {
    ::init();
add_action("view", "view");
}
int view(string str) {
mixed strr;
    object env;
    if(!str) return notify_fail("View who?\n");
    if(!find_player(str)) return notify_fail("No such person.\n");
    strr = find_player(str);
    env = environment(strr);
    if(env->query_property("no scry") || env->query_property("no teleport"))
        return notify_fail("The blood ripples and reveals nothing.\n");
    if(wizardp(strr)) { notify_fail("The blood ripples and reveals
nothing.\n");
        return 0;
    }
write("The blood ripples revealing "+capitalize(str)+" is in
"+env->query_short()+"\n");
    return 1;
}

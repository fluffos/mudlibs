// Chernobog (6/25/22)
// Disgusting Oozeling

inherit "/d/common/obj/pets/loot_pets/generic_pet";

void create(){
    ::create();
    set_name("disgusting oozeling");
    set_short("%^RESET%^%^CRST%^%^C130%^a %^C106%^di%^C112%^sg%^C118%^us%^C112%^ti%^C106%^ng %^C106%^o%^C112%^o%^C118%^zeli%^C112%^n%^C106%^g %^RESET%^%^C130%^awash with %^C137%^f%^C143%^ilt%^C137%^h%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C130%^Seemingly comprised of %^C131%^a%^C137%^n%^C143%^imat%^C137%^e%^C131%^d pu%^C137%^tr%^C143%^esc%^C137%^en%^C131%^ce%^RESET%^%^C130%^, this %^C112%^o%^C118%^o%^C112%^z%^C106%^e %^C130%^rises up into a small bulbous heap. It %^C101%^quivers %^C130%^and %^C100%^glides %^C130%^about on a trail of sticky %^C137%^offal%^C130%^, driven by some alien motive. The reek is palpable, offering a hideous, stinging warmth to those nearby.%^CRST%^");
    set_race("elemental");
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 40; }
string query_DC_type(){ return "survival"; }


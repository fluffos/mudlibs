// Chernobog (7/13/22)
// Shroomling

inherit "/d/common/obj/pets/loot_pets/generic_pet";

void create(){
    ::create();
    set_name("shroomling");
    set_short("%^RESET%^%^CRST%^%^C126%^a %^C196%^b%^C160%^rig%^C196%^h%^C160%^t r%^C196%^e%^C160%^d %^C126%^and %^C255%^spotted %^C144%^shroomling%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C126%^Sporting a broad %^C196%^r%^C160%^e%^C196%^d c%^C160%^a%^C196%^p %^C126%^with stark %^C255%^white spots%^C126%^, this creature ambles about on a divided %^C144%^stalk %^C126%^that serves as its legs. For the most part, these creatures are almost identical to %^C196%^mu%^C255%^s%^C196%^hro%^C255%^o%^C196%^ms %^C126%^and %^C144%^fungi%^RESET%^%^C126%^, especially when at rest.%^CRST%^");
    set_race("myconid");
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 40; }
string query_DC_type(){ return "survival"; }


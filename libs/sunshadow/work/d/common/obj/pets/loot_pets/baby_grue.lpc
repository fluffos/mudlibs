// Chernobog (6/25/22)
// Baby Grue

inherit "/d/common/obj/pets/loot_pets/generic_pet";

void create(){
    ::create();
    set_name("baby grue");
    set_short("%^RESET%^%^CRST%^%^C024%^a tiny %^C059%^sw%^C244%^i%^C059%^rli%^C244%^n%^C059%^g %^C024%^patch of %^C059%^da%^C244%^r%^C059%^kne%^C244%^s%^C059%^s%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C024%^It is hard to discern what you are looking at, as the %^C059%^da%^C244%^r%^C059%^kne%^C244%^s%^C059%^s %^C024%^writhing about this creature seeks to %^C030%^obfuscate %^C024%^and interrupt any inspection. All you can tell is it seems diminutive, and you occasionally catch a glimpse of tiny %^C255%^cla%^C250%^w%^C255%^s%^C024%^.%^CRST%^");
    set_race("grue");
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 40; }
string query_DC_type(){ return "spellcraft"; }


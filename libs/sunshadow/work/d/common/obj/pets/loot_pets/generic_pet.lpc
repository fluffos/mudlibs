// Chernobog (6/25/22)
// Generic Base for Tamable Pets

#include <std.h>

inherit WEAPONLESS;

void create(){
    ::create();
    set_name("wild monster");
    set_id(({"wild monster", "monster"}));
    set_short("A generic monster for capture");
    set_hd(4,1);
    set_max_hp(40);
    set_hp(query_max_hp());
    set_exp(1);
    set_size(1);
    set_gender("neuter");
    set_property("no fight", 1);
    set_property("no animate", 1);
    set_property("no random treasure", 1);
}

// Taming DCs: Low - 10, Mid - 25, High - 40, Epic - 55
// Types of DCs: "survival" for wild creatures (snakes, rats, stags, spiders, etc...)
//               "spellcraft" for magical creatures (elementals, sprites, will o wisp, etc...)
//               "dungeoneering" for constructs (clockwork creatures, golems, etc...)
int is_tamable(){ return 1; }
int query_tame_DC(){ return 10; }
string query_DC_type(){ return "survival"; }


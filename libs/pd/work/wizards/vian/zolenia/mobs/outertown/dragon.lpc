#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("dragon");
    set_short("%^RESET%^%^BOLD%^a %^GREEN%^magical %^WHITE%^baby dragon%^RESET%^");
    set_long("The green baby dragon has taken refuge in the outertown of Zolenia.  She has marks on her legs from too-tight chains.");
    set_id(({"dragon", "magical dragon"}));
    set_level(56);
    set_race("dragon");
    set_body_type("dragon");
    set_gender("female");

    add_money("gold", 2000);    
    add_money("platinum", 100);
    set_spell_chance(20);    
    set_spells(({"jab", "rush", "bite"}));  
}

void catch_tell(string str) {
string a, b;
    if(!str) return;
    str=lower_case(strip_colours(str));
    if(sscanf(str, "%s says: %s", a, b)!=2) return;
    if(sscanf(b, "%szolenia%s", a, str)==2) {
      force_me("say I come from the dungeons of Zolenia... I am one of the few who have ever escaped.");
      return;
    }
}

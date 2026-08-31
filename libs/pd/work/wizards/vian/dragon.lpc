#include <std.h>
inherit MONSTER;

void create() {
::create();
    set_name("dragon");
    set_short("%^RESET%^%^BOLD%^a %^RED%^m%^RESET%^%^ORANGE%^a%^BOLD%^%^YELLOW%^g%^%^BLUE%^i%^GREEN%^c%^MAGENTA%^a%^CYAN%^l%^RESET%^%^BOLD%^ baby dragon%^RESET%^");
    set_long("%^BOLD%^The %^GREEN%^green%^WHITE%^ baby dragon has taken refuge in Vian's workroom.  She is stronger than she looks.");
    set_id(({"dragon", "magical dragon"}));
    set_level(100);
    set_race("dragon");
    set_body_type("dragon");
    set_gender("female");

    add_money("gold", 50000);    
    add_money("platinum", 10000);

    set_skill("attack", 400); 
    set_stats("stregnth", 125);  

    set_spell_chance(20);    
    set_spells(({"jab", "rush", "bite"}));  
}

void catch_tell(string str) {
string a, b;
    if(!str) return;
    str=lower_case(strip_colours(str));
    if(sscanf(str, "%s says: %s", a, b)!=2) return;
    if(sscanf(b, "%szolenia%s", a, str)==2) {
      force_me("say I come from the dungeons of Zolenia... I entered a magical portal.");
      return;
    }
    if(sscanf(b, "%sportal%s", a, str)==2) {
      force_me("say The portals are quite amazing.. they took me to this safe land.  I don't recommend going back...");
      return;
    }
    if(sscanf(b, "%svian%s", a, str)==2) {
      force_me("say Vian has allowed me to stay here... I will protect him if I must.");
      return;
    }
}

#include <std.h>
inherit MOUNT;

void create() {
::create();
    set_name("dragon");
    set_short("%^RESET%^%^BOLD%^a %^RED%^bloodied %^BLUE%^escapee %^WHITE%^baby dragon%^RESET%^");
    set_long("The blue baby dragon has many bloodied wounds and scars.  He is very powerful looking for his size.  He has a saddle on his back.  He looks determined to solve some sort of quest.");
    set_id(({"dragon", "bloodied dragon"}));
    set_level(51+random(6));
    set_race("dragon");
    set_body_type("dragon");
    set_gender("male");
    set_class("dragon");
    set_subclass("green");
    add_money("gold", 2000);    
    add_money("platinum", 100);
    set_spell_chance(20);    
//    set_max_riders(1);
    set_spells(({"jab", "swoop", "bite"}));  
}

void catch_tell(string str) {
string a, b;
    if(!str) return;
    str=lower_case(strip_colours(str));
    if(sscanf(str, "%s says: %s", a, b)!=2) return;
    if(sscanf(b, "%squest%s", a, str)==2) {
      force_me("say You'd like a quest?  How about you rescue me.");
      return;
}
    if(sscanf(b, "%srescue%s", a, str)==2) {
      force_me("say I think the best way for you to rescue me is to ride me and get a move on out of here!");
      return;

    
    }
}
void init() {
    ::init();
    add_action("cmd_dismount", "dismount");
}
int cmd_dismount(string str)
{
        write("You can't stop now!  Help me escape!");
    return 1;
}

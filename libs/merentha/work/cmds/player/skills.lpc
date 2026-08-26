// Petrarch
// Merentha Lib 1.0
// <skills>

#include <skills.h>
#include <std.h>
#include <daemons.h>

#define SKILL_DISPLAY "\n %^GREEN%^"+list[i]+" %^ORANGE%^"+this_player()->query_skill_level(list[i])+" ("+(this_player()->query_skill_points(list[i])*100/SKILL_D->formula(this_player(),list[i]))+"%)"

#define OLD_SKILL_DISPLAY "\n %^GREEN%^"+list[i]+" %^ORANGE%^"+this_player()->query_skill_level(list[i])+"/"+SKILL_D->overall_skill_adjustment(this_player(), list[i])+"/"+SKILL_D->formula(this_player(), list[i])+"/"+SKILL_D->adj_formula(this_player(), list[i])

inherit DAEMON;

mapping skills=([
  "combat": COMBAT_SKILLS,
  "weapons": WEAPON_SKILLS,
  "magic": MAGIC_SKILLS,
  "nature": NATURE_SKILLS,
  "deception": DECEPTION_SKILLS,
  "science": SCIENCE_SKILLS,
]);

int command() {
    string *list, *lcombat, *lweapons, *lnature;
    string combat, weapons, magic, nature, deception, science, ret="";
    int i,max,w,x;
    combat="%^RED%^Combat";
    i=sizeof(list=skills["combat"]);
    while(i--) 
        combat+=SKILL_DISPLAY;
    weapons="%^RED%^Weapons";
    i=sizeof(list=skills["weapons"]);
    while(i--) 
        weapons+=SKILL_DISPLAY;
    magic="%^RED%^Magic";
    i=sizeof(list=skills["magic"]);
    while(i--) 
        magic+=SKILL_DISPLAY;
    nature="%^RED%^Nature";
    i=sizeof(list=skills["nature"]);
    while(i--) 
        nature+=SKILL_DISPLAY;
    deception="%^RED%^Deception";
    i=sizeof(list=skills["deception"]);
    while(i--) 
        deception+=SKILL_DISPLAY;
    i=sizeof(list=skills["science"]);
    science="%^RED%^Science";
    while(i--) 
        science+=SKILL_DISPLAY;
    combat+="\n \n"+magic+"\n \n";
    weapons+="\n \n"+deception;
    nature+="\n \n"+science;
    max=sizeof(lcombat=explode(combat,"\n"));
    if(max<i=sizeof(lweapons=explode(weapons,"\n"))) max=i;
    if(max<i=sizeof(lnature=explode(nature,"\n"))) max=i;
    i=0;
    x=this_player()->getenv("SCREEN");
    if(!x) x=75;
    w=x-4;
    w=to_int(w/3);
    while(i<max) {
        if(i>=sizeof(lcombat)) ret+=arrange_string(" ",w+3);
        else ret+=arrange_string(lcombat[i],w+3);
        if(i>=sizeof(lweapons)) ret+=arrange_string(" ",w-1);
        else ret+=arrange_string(lweapons[i],w-1);
        if(i>=sizeof(lnature)) ret+=arrange_string(" ",w-2);
        else ret+=arrange_string(lnature[i],w-2);
        ret+="\n";
        i++;
    }
    message("command",border(ret,"skills",x),this_player());
    return 1;
}

string help() {
    return "\
Syntax: skills\n\n\
This command displays your current skill levels.\n\
Skills determine how good you are in a given field of combat, magic, nature or other area. The higher your skill level the better you are in that area.  Skills improve with incresed use.\n\
\n\
See also: stats, classes, races";
}

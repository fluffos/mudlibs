// Chernobog (7/28/22)
// Monster Summoning Base

#include <std.h>

inherit MONSTER;

int create(){
    ::create();
	set_name("defender");
    set_id(({"monster", "defender", "summoned monster"}));
	set_short("%^RESET%^%^CRST%^%^C030%^generic summoned monster%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C030%^This looks like some kind of place holder.%^CRST%^");
    set_race("construct");
	set_gender("neuter");
	set_body_type("human");
    set("aggressive",18);
    set_hd(6,1);
    set_alignment(5);
    set_size(2);
    set_stats("intelligence",10);
    set_stats("wisdom",12);
    set_stats("strength",16);
    set_stats("charisma",10);
    set_stats("dexterity",16);
    set_stats("constitution",10);
    set_hp(50);
    set_max_hp(query_hp());
    set_exp(500);
}

int die(){
    object monster, room;
    string mon_name;
    monster = this_object();
    room = environment(monster);
    mon_name = monster->query_race();
    
    message("info", "%^RESET%^%^CRST%^%^CYAN%^A "+mon_name+"%^RESET%^%^CRST%^%^CYAN%^ collapses, fading away and disappearing.%^CRST%^", room);
    monster->remove();

    ::die();
    return 1;
}


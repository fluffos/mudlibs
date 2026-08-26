// Chernobog (10/25/22)
// Hound

#include <std.h>

inherit MONSTER;

void create(){
    ::create();
    set_name("hound");
    set_id(({"hound", "defender", "summoned monster"}));
    set_short("%^RESET%^%^CRST%^%^C030%^generic summoned hound%^CRST%^");
    set_long("%^RESET%^%^CRST%^%^C030%^This looks like some kind of place holder.%^CRST%^");
    set_gender(random(2) ? "male" : "female");
    set_race("hound");
    set_body_type("quadruped");
    set_hd(10, 1);
    set_stats("strength", 16);
    set_stats("dexterity", 20);
    set_stats("constitution", 10);
    set_stats("intelligence",10);
    set_stats("wisdom", 12);
    set_stats("charisma", 10);
    set_hp(1);
    set_attacks_num(1);
    set_size(1);
    set_property("no random treasure", 1);
}

void die(object ob){
    tell_room(environment(this_object()), "%^RESET%^%^CRST%^%^C030%^A "+this_object()->query_name()+"%^RESET%^%^CRST%^%^C030%^ returns from whence it came.%^CRST%^");
    remove();
    return;
}


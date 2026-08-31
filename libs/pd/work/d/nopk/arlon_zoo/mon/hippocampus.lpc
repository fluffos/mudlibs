#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("hippocampus");
    set_id( ({ "hippocampus", "seahorse", "horse" }) );
    set_short("a hippocampus");
    set_long("This hippocampus, also known as a giant sea horse, has a shiny white "+
      "coat and body the tail of a fish as well as fins for hooves.\n");
    set_level(12);
    set("race", "hippocampus");
    set_body_type("merperson");
    set_gender("male");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(1,({ "The hippocampus seems to prance about in the water." }),0);
    money = new("/std/obj/coins");
    money->set_money("gold", 3*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}

void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string pc = this_player()->query_cap_name();
    string monster_action = "The hippocampus swishes its tail and tries to pet "+pc+" with a fin.\n";

    string no_monster = "Pet what?\n";
    string wrong_monster = "Pet who?\n";
    string petted_monster, petted_number;

    if(petted==0) return notify_fail(no_monster);

    sscanf(petted, "%s %s", petted_monster, petted_number);
    if(petted_monster == 0){petted_monster=petted;}

    if(!present(lower_case(petted))) return notify_fail(wrong_monster);

    if(member_array(petted_monster,this_object()->query_id()) == -1)
	return notify_fail(wrong_monster);

    tell_room(environment(this_object()),monster_action,this_object());
    return 1;
}

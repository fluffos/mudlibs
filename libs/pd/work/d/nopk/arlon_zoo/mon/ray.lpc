#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("manta ray");
    set_id( ({ "ray", "manta" , "giant" }) );
    set_short("a giant manta ray");
    set_long("You see a giant manta ray.  Its simply huge!\n");
    set_level(11);
    set("race", "manta ray");
    set_body_type("snakewgd");
    set_gender("male");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(1,({ "The manta ray glides through the water." }),0);
    money = new("/std/obj/coins");
    money->set_money("gold", 2*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}

void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string pc = this_player()->query_cap_name();
    string monster_action = "The manta ray swims around happily as "+pc+
    "'s hand slides smoothly down its dorsal side.\n";
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

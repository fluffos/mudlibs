#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("dolphin");
    set_id( ({ "dolphin" }) );
    set_short("a friendly dolphin");
    set_long("You see a dolphin swiming about.  It has an elongated beak-like snout.\n");
    set_level(10);
    set("race", "dolphin");
    set_body_type("fish");
    set_gender("male");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(1,({ "The dolphin surfaces to take a breath." }),0);
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
    string monster_action = "The dolphin chitters and squeaks excitedly.\n";
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

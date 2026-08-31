#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("piglet");
    set_id( ({ "piglet", "pig", "baby" }) );
    set_short("A little piglet");
    set_long("This little piglet is a dusty pink in color.\n");
    set_level(8);
    set("race", "pig");
    set_body_type("hog");
    set_gender("male");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(2,({ "The piglet grunts."}),0);
    money = new("/std/obj/coins");
    money->set_money("gold", (1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}

void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string monster_action = "The piglet squeals happily.\n";

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

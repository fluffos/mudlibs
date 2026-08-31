#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("baby goat");
    set_id( ({ "goat", "baby" }) );
    set_short("a baby goat");
    set_long("This goat has a bushy tail and has begun growing small horns.\n");
    set_level(8);
    set("race", "goat");
    set_body_type("cow");
    set_gender("male");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(1,({ "The goat nibbles on your clothes."}),0);
    money = new("/std/obj/coins");
    money->set_money("gold", 2*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}
void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string monster_action = "The goat nips at your hand, "+
    "prompting a handler to come over and offer a bandage.\n";

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

#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("baby mouse");
    set_id( ({ "mouse", "baby" "little"}) );
    set_short("A cute little mouse");
    set_long("This mouse is a pretty shade of pink and has a curly little tail.\n");
    set_level(4);
    set("race", "mouse");
    set_body_type("rodent");
    set_gender("female");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(2,({ "The mouse squeeks."}),0);
    money = new("/std/obj/coins");
    money->set_money("gold", (1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}
void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string monster_action = "The mouse wiggles its whiskers happily.\n";

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

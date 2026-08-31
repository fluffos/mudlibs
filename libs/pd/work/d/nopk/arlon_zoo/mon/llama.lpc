#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("llama");
    set_id( ({ "llama", "baby"}) );
    set_short("a baby llama");
    set_long("This baby llama is actually quite tall, and has a surprisingly soft fleece.\n");
    set_level(10);
    set("race", "llama");
    set_body_type("deer");
    set_gender("female");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(1,({ "The baby llama stretches its neck to look about."}),0);
    money = new("/std/obj/coins");
    money->set_money("gold", 2*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}
void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){

    string monster_action = "The llama nuzzles its head in your hands.\n";

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

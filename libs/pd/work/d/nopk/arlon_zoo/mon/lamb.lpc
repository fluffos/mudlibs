#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("lamb");
    set_id( ({ "lamb", "sheep", "baby" }) );
    set_short("a baby lamb");
    set_long("This docile lamb idly stands by as visitors pet its woolen coat.\n");
    set_level(6);
    set("race", "sheep");
    set_body_type("cow");
    set_gender("female");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(5,({ "The lamb baaas quietly." }),0);
    money = new("/std/obj/coins");
    money->set_money("gold", 1+random(BASE_GOLD));
    money->move(this_object());
}

void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string monster_action = "The lamb turns its head slightly as it's petted.\n";

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

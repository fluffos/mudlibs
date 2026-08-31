#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("puppy");
    set_id( ({ "puppy", "dog", "baby","dalmation" }) );
    set_short("a cute little puppy");
    set_long("This baby dalmation has quite a few black spots on his shiny white coat.\n");
    set_level(6);
    set("race", "dog");
    set_body_type("dog");
    set_gender("male");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(10,({ "The puppy licks your face.", "The puppy rolls around on the floor."}),0);
    money = new("/std/obj/coins");
    money->set_money("gold", (1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}

void init() {
    ::init();
    add_action("pet_monster","pet");
    add_action("rub_belly","rub");
}

int pet_monster(string petted){
    string monster_action = "The puppy rolls over, wanting his belly rubbed.\n";

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



int rub_belly(string rubbed){
    string monster_action = "The puppy's legs twitch as he clearly enjoyed the rub.\n";

    string no_monster = "Rub where?\n";
    string wrong_object = "Rub who?\n";
    string rubbed_object, rubbed_number;

    if(rubbed==0) return notify_fail(no_monster);

    sscanf(rubbed, "%s %s", rubbed_object, rubbed_number);
    if(rubbed_object == 0){rubbed_object=rubbed;}

    if(rubbed_object != "belly")
        return notify_fail(wrong_object);

    tell_room(environment(this_object()),monster_action,this_object());
    return 1;
}

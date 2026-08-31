#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("diver");
    set_id( ({ "diver", "man", "swimmer" }) );
    set_short("a diver");
    set_long("You see someone in a diving suit tending to the aquarium and the"+
      " creatures living within.\n");
    set_level(13);
    set("race", "human");
    set_body_type("human");
    set_gender("female");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(1,({ "The diver inspects the coral for damage.", 
	"The diver studies the sea life as it swims by."}),0);
    money = new("/std/obj/coins");
    money->set_money("gold", 6*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());

}

void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string monster_action = "The diver looks irritated and tries to shoo you away.\n";

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

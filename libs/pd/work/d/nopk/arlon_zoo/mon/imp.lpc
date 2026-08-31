#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("imp");
    set_id( ({ "imp", "thief" }) );
    set_short("A tiny imp");
    set_long("This tiny imp doesn't initially see you.  "+
      "He seems preoccupied with something shiny.\n");
    set_level(12);
    set("race", "imp");
    set_body_type("imp");
    set_gender("male");
    set("aggressive", 0);
    set_alignment(-100);
    set_emotes(1,({ "The imp looks for a shadow to hide in."}),0);
    new(OBJ"zookey")->move(this_object());
    money = new("/std/obj/coins");
    money->set_money("platinum", (random(BASE_GOLD)));
    money->set_money("gold", 4*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->set_money("electrum", 3*(1+random(BASE_GOLD)));
    money->set_money("silver", 6*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->set_money("copper", 7*(1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}

void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string monster_action = "Hey!  What are you doing here!  Quit that!\n";
    string no_monster = "Pet what?\n";
    string wrong_monster = "Pet who?\n";
    string petted_monster, petted_number;

    if(petted==0) return notify_fail(no_monster);

    sscanf(petted, "%s %s", petted_monster, petted_number);
    if(petted_monster == 0){petted_monster=petted;}

    if(!present(lower_case(petted))) return notify_fail(wrong_monster);

    if(member_array(petted_monster,this_object()->query_id()) == -1)
	return notify_fail(wrong_monster);
    this_object()->force_me("say "+monster_action);
    this_object()->force_me("kill "+this_player()->query_name());
    return 1;
}

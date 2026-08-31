#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
    object money;
    ::create();
    set_name("kitten");
    set_id( ({ "kitten", "cat", "tabby", "baby" }) );
    set_short("a cute little kitten");
    set_long("Awww, how cute!  This little %^ORANGE%^tabby%^RESET%^ has "+
      "the cutest little white spot on its left front paw.\n");
    set_level(5);
    set("race", "cat");
    set_body_type("cat");
    set_gender("female");
    set("aggressive", 0);
    set_alignment(0);
    set_emotes(10,({ "The kitten mews.", 
	"The kitten jumps around playfully as something new catches its attention.",
	"The kitten purrs contentedly.", 
	"The kitten rubs up against you."  }),0);
    money = new("/std/obj/coins");
    money->set_money("gold", (1+random(BASE_GOLD))+(random(BASE_GOLD)));
    money->move(this_object());
}
void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){

    string monster_action = "The kitten purrs loudly.\n";

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

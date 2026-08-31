#include <std.h>
#include <petzoo.h>
inherit MONSTER;

void create() {
   object money;
   ::create();
   set_name("baby raccoon");
   set_id( ({ "raccoon", "baby" }) );
   set_short("A baby raccoon");
   set_long("He has a sharp snout and a bushy %^BOLD%^%^BLACK%^black%^RESET%^ and %^BOLD%^silver%^RESET%^ tail .\n");
   set_level(7);
   set("race", "raccoon");
   set_body_type("dog");
   set_gender("male");
   set("aggressive", 0);
   set_alignment(0);
   set_emotes(1,({ "The raccoon briefly forages about." }),0);
   money = new("/std/obj/coins");
   money->set_money("gold", (1+random(BASE_GOLD))+(random(BASE_GOLD)));
   money->move(this_object());
}
void init() {
    ::init();
    add_action("pet_monster","pet");
}

int pet_monster(string petted){
    string monster_action = "The raccoon sits up and begs for food.\n";

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

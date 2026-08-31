#include <std.h>
inherit MONSTER;
void create() {
::create();
    set_name("troll");
    set_short("%^RESET%^%^BLACK%^A Black Troll");
    set_long("%^BOLD%^%^BLACK%^This is a dirty black troll that seems to have "
      "lived his whole life in these caverns.");
    set_id(({"troll", "a dirty black troll"}));
    set_invis();
    set_level(44);
    set("aggressive", 25);
    set_race("troll");
    set_body_type("human");
    set_gender("male");
    set_moving(1);
    set_speed(7);
    set_spell_chance(35);
    set_spells( ({ "parry" }) );
    new("/wizards/detach/darkmouth/obj/s_armour")->move(this_object());
    new("/wizards/detach/darkmouth/obj/sword")->move(this_object());   
    new("/wizards/detach/darkmouth/obj/gloves")->move(this_object());   
    this_object()->force_me("wield cutlass");
    this_object()->force_me("wear armour");
    this_object()->force_me("wear gloves");   
    if(sizeof(children(base_name(this_object()))) > 50) this_object()->remove();
}                                       


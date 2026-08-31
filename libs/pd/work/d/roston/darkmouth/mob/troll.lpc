#include <std.h>
#include <roston.h>
#include <rooms.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("troll");
    set_short("%^BOLD%^%^BLACK%^A Black Troll%^RESET%^");
    set_long("This is a dirty black troll that seems to have "
      "lived his whole life in these caverns.");
    set_id(({"troll", "a dirty black troll"}));
    set_invis();
    set_level(44);
    set("aggressive", 37);
    set_race("troll");
    set_body_type("human");
    set_gender("male");
    set_moving(1);
    set_speed(7);
    set_spell_chance(35);
    set_spells( ({ "parry" }) );
    set_alignment(-200);
    new(DMOBJ "s_armour")->move(this_object());
    new(DMOBJ "sword")->move(this_object());   
    new(DMOBJ "gloves")->move(this_object());   
    force_me("wear armour");
    force_me("wear gloves");
    force_me("wield sword");

    if(sizeof(children(base_name(this_object()))) > 150)
	call_out("remove_me", 1);
}                                       
void init()
{ 
    ::init();
}


void remove_me() {
    this_object()->move(ROOM_VOID);
    all_inventory(this_object())->remove();
    this_object()->remove();
}

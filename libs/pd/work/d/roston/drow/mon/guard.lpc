#include <std.h>
#include <roston.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Guard");
    set_short("Camp Guard");
    set_long("This guard is here to stop anyone who trys to get into the "
            "camp that doesnt have permision to get in. He looks very "
            "very buff, and would probably kill you.");
    set_id(({"guard", "camp guard"}));
    set_race("drow");
    set_class("rogue");
    set_subclass("assassin");
    set_spell_chance(40);
    set_spells( ({"stab"}) );
    set("aggressive", 35);
    set_level(60);

    set_body_type("human");
    set_gender("male");
    set_alignment(-500);
    new(DROWOBJ"knife")->move(this_object());
    new(DROWOBJ"knife")->move(this_object());
    new(DROWOBJ"cloak")->move(this_object()); 


    set_heart_beat(1);
}                                             
void init()   
{
 ::init();
}

void heart_beat()
{
 ::heart_beat();
 if (!wielded_sword)
   {
    this_object()->force_me("wear cloak");
    this_object()->force_me("wield knife");
    this_object()->force_me("wield knife 2");
    wielded_sword = 1;
   }
}



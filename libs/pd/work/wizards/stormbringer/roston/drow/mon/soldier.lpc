#include <std.h>
#include <roston.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Soldier");
    set_short("Drow Soldier");
    set_long("This soldier, is the buffest member of the drow "
       "army, the soldiers of the army is where the drow army "
         "got there respect for the being the best army in "
        "the lands of Primal Darkness.");
    set_id(({"soldier", "drow soldier"}));
    set_race("drow");
    set("aggressive", 35);
    set_class("fighter");
    set_subclass("soldier");
    set_spell_chance(35);
    set_spells( ({"rush","slash"}) );
    set_skill("riding", 1000);
    set_level(68);

    set_body_type("human");
    set_gender("male");
    add_alignment(-500);
    new(DROWOBJ"drag")->move(this_object());
    new(DROWOBJ"sword")->move(this_object());
    new(DROWOBJ"sword")->move(this_object()); 


    set_heart_beat(1);
   set_exp(210000);
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
    this_object()->force_me("wear armour");

    this_object()->force_me("wield sword");
    this_object()->force_me("wield sword 2");
    wielded_sword = 1;
   }
}



#include <std.h>
#include <roston.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("a member of the Cavalry");
    set_short("A member of the Cavalry");
    set_long("This is a member of the drow cavalry. He is the bravest "
             "member, simply because he charges into battle. He has "
             "half a drow body and half a spiders' from lack of faith "
             "in his God.");
    set_id(({"drow", "cavalry","member"}));
    set_race("drider");
    set("aggressive", 35);
    set_class("fighter");
    set_subclass("paladin");
    set_spell_chance(35);
    set_spells(({"whirl"}));
    set_level(65);

    set_body_type("artrell");
    set_gender("male");
    add_alignment(-500);
    new(DROWOBJ"staff")->move(this_object());
    new(DROWOBJ"staff")->move(this_object());
    new(DROWOBJ"gloves")->move(this_object());
    new(DROWOBJ"plate")->move(this_object()); 


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
    this_object()->force_me("wear gloves");
    this_object()->force_me("wield staff");
    this_object()->force_me("wield staff 2");
    wielded_sword =1;
    } 

}

#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("War Priest");
    set_short("%^BOLD%^%^YELLOW%^War Priest%^RESET%^");
    set_long("This Priest is one of the legendary, War Priest's "
"of the great Sacron war. He stands 8 foot tall and has 6 arms. "
"A great yellow glow surrounds him.");
    set_id(({"priest", "war priest"}));
    set_race("sacron");
    set("aggressive", 50);
    set_class("monk");
    set_subclass("light");
    set_spell_chance(40);
    set_spells(({"faithbomb","vestment me","denmak"}));
    set_skill("axe", 220);
    set_skill("magic defense", 300);
    set_skill("healing", 300);  
    set_skill("faith", 300); 
    set_level(52);
    set_exp(210000);
    set_body_type("sacron");
    set_gender("male");
    new("/wizards/detach/azeria/obj/3")->move(this_object());
    new("/wizards/detach/azeria/obj/3")->move(this_object());
    new("/wizards/detach/azeria/obj/3")->move(this_object());
    new("/wizards/detach/azeria/obj/3")->move(this_object());
    new("/wizards/detach/azeria/obj/3")->move(this_object());
    new("/wizards/detach/azeria/obj/3")->move(this_object());
    new("/wizards/detach/azeria/obj/a2")->move(this_object());
    new("/wizards/detach/azeria/obj/a3")->move(this_object()); 


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
    this_object()->force_me("wear plate");
    this_object()->force_me("wear boots");
    this_object()->force_me("wield axe");
    this_object()->force_me("wield axe 2");
    this_object()->force_me("wield axe 3");
    this_object()->force_me("wield axe 4");
    this_object()->force_me("wield axe 5");
    this_object()->force_me("wield axe 6");
    wielded_sword = 1;
   }
}

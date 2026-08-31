#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Light Monk");
    set_short("%^BOLD%^%^YELLOW%^Light Monk%^RESET%^");
    set_long("This Monk travels through the lands of azeria. "
"seekin peace through out the lands. He is a giant male Sacron.");
    set_id(({"monk", "light monk"}));
    set_race("sacron");
    set("aggressive", 50);
    set_class("monk");
    set_subclass("light");
    set_spell_chance(40);
    set_spells(({"denmak"}));
    set_skill("blunt", 220);
    set_skill("magic defense", 300);
    set_skill("healing", 300);  
    set_skill("faith", 300); 
    set_level(52);
    set_exp(210000);
    set_body_type("sacron");
    set_gender("male");
    new("/wizards/detach/azeria/obj/9")->move(this_object());
    new("/wizards/detach/azeria/obj/9")->move(this_object());
    new("/wizards/detach/azeria/obj/9")->move(this_object());
    new("/wizards/detach/azeria/obj/9")->move(this_object());
    new("/wizards/detach/azeria/obj/9")->move(this_object());
    new("/wizards/detach/azeria/obj/9")->move(this_object());
    new("/wizards/detach/azeria/obj/a8")->move(this_object());
    new("/wizards/detach/azeria/obj/a9")->move(this_object()); 


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
    this_object()->force_me("wear boots");
    this_object()->force_me("wield staff");
    this_object()->force_me("wield staff 2");
    this_object()->force_me("wield staff 3");
    this_object()->force_me("wield staff 4");
    this_object()->force_me("wield staff 5");
    this_object()->force_me("wield staff 6");
    wielded_sword = 1;
   }
}

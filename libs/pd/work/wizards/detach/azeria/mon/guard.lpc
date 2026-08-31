#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Azeria Guard");
    set_short("%^BOLD%^%^YELLOW%^Az%^BLUE%^er%^YELLOW%^ia Gu%^BLUE%^a%^YELLOW%^rd");
    set_long("%^BOLD%^%^WHITE%^This Guard stands 8 foot tall, he has 6 arms. He will protect his city with his life.");
    set_id(({"guard", "azeria guard"}));
    set_race("sacron");
    set("aggressive", 50);
    set_class("fighter");
    set_subclass("ranger");
    set_spell_chance(40);
    set_spells(({"rush","slash","whirl"}));
    set_skill("axe", 220);
    set_skill("magic defense", 300);
    set_skill("riding", 400);  
    set_skill("blade", 400); 
    set_level(50);
    set_body_type("sacron");
    set_gender("male");
    new("/wizards/detach/azeria/obj/blade")->move(this_object());
    new("/wizards/detach/azeria/obj/blade")->move(this_object());
    new("/wizards/detach/azeria/obj/blade")->move(this_object());
    new("/wizards/detach/azeria/obj/blade")->move(this_object());
    new("/wizards/detach/azeria/obj/blade")->move(this_object());
    new("/wizards/detach/azeria/obj/blade")->move(this_object());
    new("/wizards/detach/azeria/obj/a4")->move(this_object());
    new("/wizards/detach/azeria/obj/a13")->move(this_object()); 


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
    this_object()->force_me("wear claok");
    this_object()->force_me("wear boots");
    this_object()->force_me("wield blade");
    this_object()->force_me("wield blade 2");
    this_object()->force_me("wield blade 3");
    this_object()->force_me("wield blade 4");
    this_object()->force_me("wield blade 5");
    this_object()->force_me("wield blade 6");
    wielded_sword = 1;
   }
}

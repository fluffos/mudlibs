#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Satanic Warlord");
    set_short("Satanic Warlord");
    set_long("This Warlord was sent to this world to destory all Arch-Angels.");
    set_id(({"Satanic warlord", "warlord"}));
    set_race("sacron");
    set("aggressive", 50);
    set_spell_chance(70);
    set_spells(({"cure me","rush","whirl"}));
    set_skill("magic defense", 300);
    set_level(169);
    set_stats("constitution", 1000);
    set_stats("dexterity", 1000);
    set_stats("wisdom", 1000);
    set_stats("strength", 1000);
    set_stats("intelligence", 1000);
    set_stats("charisma", 1000);
    set_class("fighter");
    set_subclass("paladin");
    set_body_type("sacron");
    set_gender("male");
    set_skill("attack", 1014); 
    set_skill("healing", 507); 
    set_skill("axe", 845); 
    set_skill("blade", 845); 
    set_skill("blunt", 845); 
    set_skill("flail", 845); 
    set_skill("knife", 845); 
    set_skill("projectile", 845); 
    set_skill("ranged", 676); 
    set_skill("faith", 676); 
    set_skill("magic attack", 676); 
    set_skill("magic defense", 676); 
    set_skill("defense", 845); 
    set_skill("double wielding", 845); 
    set_skill("melee", 845); 

    new("/wizards/detach/azeria/obj/armour")->move(this_object());
    new("/wizards/detach/azeria/obj/boots")->move(this_object());
    new("/wizards/detach/azeria/obj/knife")->move(this_object());
    new("/wizards/detach/azeria/obj/cutlass")->move(this_object());
    new("/wizards/detach/azeria/obj/pike")->move(this_object());
    new("/wizards/detach/azeria/obj/staff")->move(this_object());
    new("/wizards/detach/azeria/obj/whip")->move(this_object());
    new("/wizards/detach/azeria/obj/axe")->move(this_object()); 


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
    this_object()->force_me("wear armour");
    this_object()->force_me("wear boots");
    this_object()->force_me("wield axe");
    this_object()->force_me("wield staff");
    this_object()->force_me("wield pike");
    this_object()->force_me("wield knife");
    this_object()->force_me("wield cutlass");
    this_object()->force_me("wield whip");
    wielded_sword = 1;
   }
}

#include <std.h>
inherit MONSTER;

int wielded_sword=0;
void create() {
::create();
    set_name("Satanic Warlord");
    set_short("%^BOLD%^%^BLACK%^Sat%^RESET%^%^RED%^an%^BOLD%^%^BLACK%^ic War%^RESET%^%^RED%^lo%^BOLD%^%^BLACK%^rd");
    set_long("%^BOLD%^%^BLACK%^This Warlord was sent to this world to destory all %^BOLD%^%^WHITE%^Arch-Angels.");
    set_id(({"Satanic warlord", "warlord"}));
    set_race("sacron");
    set("aggressive", 50);
    set_spell_chance(70);
    set_spells(({"cure me""rush","whirl"}));
    set_skill("magic defense", 300);
    set_level(169);
    set_class("fighter");
    set_subclass("paladin");
    set_body_type("sacron");
    set_gender("male");
    set_skill("attack", 1500); 
    set_skill("healing",600); 
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

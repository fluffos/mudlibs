#include <std.h>
inherit MONSTER;
void create() {
::create();
    set_name("keeper");
    set_short("Caverns Keeper");
    set_long("%^BOLD%^%^BLACK%^This Demon stands guard over the Caverns, hes "
      "not to be trusted.");
    set_id(({"keeper", "caverns keeper"}));
    set_level(58);
    set("aggressive", 25);
    set_race("Demon");
    set_body_type("demon");
    set_gender("male");
    set_class("clergy");
    set_subclass("kataan");
    set_spell_chance(35);
    set_spells( ({ "hellfire","impale" }) );
    new("/wizards/detach/darkmouth/obj/armour3")->move(this_object());
    new("/wizards/detach/darkmouth/obj/pike")->move(this_object());   
    new("/wizards/detach/darkmouth/obj/pike")->move(this_object());   
    new("/wizards/detach/darkmouth/obj/robes")->move(this_object());
    new("/wizards/detach/darkmouth/obj/tunic")->move(this_object());
    new("/wizards/detach/darkmouth/obj/mask")->move(this_object());
    new("/wizards/detach/darkmouth/obj/helmet")->move(this_object());
    new("/wizards/detach/darkmouth/obj/helm")->move(this_object());
    this_object()->force_me("wield pike");
    this_object()->force_me("wield pike 2");
    this_object()->force_me("wear tunic");   
    this_object()->force_me("wear mask");     
    this_object()->force_me("wear mask 2");  
    this_object()->force_me("wear armour");  
    this_object()->force_me("wear robes");  
    this_object()->force_me("wear helmet");  
   set_exp(180000);
}                                       


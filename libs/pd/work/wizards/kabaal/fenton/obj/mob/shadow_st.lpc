#include <std.h>;
#include <fenton.h>;
inherit MONSTER;

void create() {
::create();
    set_name("stalker");
    set_short("%^BOLD%^%^BLACK%^Shadow Stalker%^RESET%^");
    set_long("You can barely make out your hunter.  All you can see are "
    "his %^RED%^bloodshot eyes%^RESET%^ that pierce the night.  "
    "He is sly and full of hatred.");
    set_id(({"stalker", "shadow", "shadow stalker"}));
    set_race("unknown");
    set_body_type("human");
    set_gender("male");
    add_money("gold", 100);
   new("/wizards/kabaal/fenton/obj/wep/deathdagger")->move(this_object());
   this_object()->force_me("wield dagger");
    set_skill("attack", 125); 
    set_stats("stregnth", 50);
    set_stats("dexterity", 80);
  set("aggressive",100);
  set_class("rogue");
  set_subclass("assassin");
    set_level(35);
    set_spell_chance(55);    
    set_spells(({"stab", "backstab"}));
    }

#include <std.h>;
#include <fenton.h>;
inherit MONSTER;

void create() {
::create();
    set_name("guardian");
    set_short("Guardian of the Tower");
    set_long("Guardians of the Tower don't take their job lightly.  They have "
"been trained in the skill of unarmed combat and are deadly beings.");
    set_id(({"guardian", "guardian of the tower"}));
    set_race("artrell");
    set_body_type("artrell");
    set_gender("male");
    add_money("gold", 33);
    add_money("platinum", 40);
    set_skill("attack", 150); 
    set_skill("melee", 250); 
    set_stats("stregnth", 55);
    set_stats("dexterity", 90);
    set_stats("constitution", 40);

  set("aggressive",1);
  set_class("fighter");
  set_subclass("warrior");
    set_level(45);
    set_spell_chance(50);    
    set_spells(({"headbutt", "jab"}));
new("/wizards/kabaal/fenton/obj/arm/ashield")->move(this_object());
new("/wizards/kabaal/fenton/obj/arm/artrell")->move(this_object());
this_object()->force_me("wear armour");
this_object()->force_me("wear shield");
    }

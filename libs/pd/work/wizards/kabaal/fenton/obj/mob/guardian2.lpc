#include <std.h>;
#include <fenton.h>;
inherit MONSTER;

void create() {
::create();
    set_name("guardian");
    set_short("Stately Guardian of the Tower");
    set_long("This is the head guard.  He grunts as you look him over. "
" He guards his master, Protelus with his life.  Anyone he sees, dies.");
    set_id(({"guardian", "stately guardian"}));
    set_race("ogre");
    set_body_type("human");
    set_gender("male");
    add_money("gold", 450);
    add_money("platinum", 50);
    set_skill("attack", 300); 
    set_stats("stregnth", 80);
    set_stats("dexterity", 35);
    set_stats("constitution", 70);

  set("aggressive",500);
  set_class("fighter");
  set_subclass("warrior");
    set_level(50);
    set_spell_chance(10);    
    set_spells(({"slash"}));
new("/wizards/kabaal/fenton/obj/wep/gsword")->move(this_object());
this_object()->force_me("wield sword");
    }

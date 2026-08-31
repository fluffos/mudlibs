#include <std.h>;
#include <fenton.h>;
inherit MONSTER;

void create() {
::create();
    set_name("skeleton");
    set_short("Skeleton Warrior");
    set_long("This skeleton used to be a warrior when he was alive.  He was strong "
"and well taught.  He is controlled by the evil necromancer.");
    set_id(({"skeleton", "warrior", "skeleton warrior"}));
    set_race("skeleton");
    set_body_type("human");
    set_gender("male");
    add_money("gold", 100);
    set_skill("attack", 125); 
    set_stats("stregnth", 45);
    set_stats("dexterity", 35);
    set_stats("constitution", 45);

  set("aggressive",500);
  set_class("fighter");
  set_subclass("warrior");
    set_level(42);
    set_spell_chance(35);    
    set_spells(({"whirl", "slash"}));
new("/wizards/kabaal/fenton/obj/wep/sksword")->move(this_object());
new("/wizards/kabaal/fenton/obj/wep/sksword")->move(this_object());
this_object()->force_me("wield sword");
this_object()->force_me("wield sword 2");
    }

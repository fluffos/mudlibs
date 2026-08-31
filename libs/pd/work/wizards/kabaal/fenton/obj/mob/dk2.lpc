
#include <std.h>;
#include <fenton.h>;
inherit MONSTER;

void create() {
::create();
    set_name("deathknight");
    set_short("DeathKnight");
    set_long("This is one of the legendary DeathKnights.  They have "
"been known to take down a dozen men at a time.");
    set_id(({"deathknight", "knight"}));
    set_race("undead");
    set_body_type("human");
    set_gender("male");
    add_money("gold", 450);
    add_money("platinum", 100);
    set_skill("attack", 0); 
    set_skill("defense", 0);
    set_stats("stregnth", 0);
    set_stats("dexterity", 0);
    set_stats("constitution", 0);
  set("aggressive",1);
  set_class("fighter");
  set_subclass("warrior");
    set_level(55);
    set_spell_chance(0);    
new("/wizards/kabaal/fenton/obj/wep/chaos_sword")->move(this_object());
new("/wizards/kabaal/fenton/obj/wep/chaos_sword")->move(this_object());
this_object()->force_me("wield sword");
this_object()->force_me("wield sword 2");
    }

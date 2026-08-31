#include <std.h>;
#include <fenton.h>;
inherit MONSTER;

void create() {
::create();
    set_name("vampire");
    set_short("Vampire");
set_long("He looks at you and snarls his %^BOLD%^%^WHITE%^white%^RESET%^ with %^BOLD%^%^RED%^blood%^RESET%^ dripping "
"off the sharp tips.  He doesn't appear to be too pleased that you're disturbing him.");
    set_id(({"vampire", "male"}));
    set_race("undead elf");
    set_body_type("human");
    set_gender("male");
    add_money("gold", 50);
    add_money("silver", 100);
    set_skill("attack", 100); 
    set_stats("stregnth", 45);
    set_stats("dexterity", 70);
    set_stats("constitution", 50);

  set("aggressive",25);
  set_class("fighter");
  set_subclass("soldier");
    set_level(50);
new("/wizards/kabaal/fenton/obj/arm/cloak")->move(this_object());
this_object()->force_me("wear cloak");
    }

#include <std.h>;
#include <fenton.h>;
inherit MONSTER;

void create() {
::create();
    set_name("angel");
    set_short("%^BOLD%^%^WHITE%^Angeline the Defender%^RESET%^");
    set_long("Angeline glances at you with big, %^BOLD%^%^BLUE%^blue%^RESET%^ eyes. "
"The look on her face brings peace upon your soul..");
    set_id(({"angeline", "Angeline the Defender"}));
    set_race("angel");
    set_body_type("human");
    set_gender("female");
    set_skill("melee", 135); 
    set_stats("stregnth", 15);
    set_stats("dexterity", 35);
    set_stats("constitution", 500);

  set("aggressive",0);
  set_class("monk");
  set_subclass("light");
    set_level(42);
    set_spell_chance(65);    
    set_spells(({"paralyze"}));
new("/wizards/kabaal/fenton/obj/arm/boots")->move(this_object());
this_object()->force_me("wear boots");
    }


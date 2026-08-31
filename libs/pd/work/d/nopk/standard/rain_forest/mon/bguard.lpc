#include <std.h>
#include <rain.h>
inherit MONSTER;

void create(){
   ::create();
   set_name("guard");
   set_short("elven guard");
   set_id(({"elf", "guard", "elven guard"}));
   set_long("This guard honorably protects the elven nation with pride.");
   set_level(10);
   set_class("fighter");
   set_gender("male");
   set_race("elf");
   set_body_type("human");
   set_spells(({"whirl", "slash"}));
   set_spell_chance(10);
   new(ARM"gchain")->move(this_object());
   new(WEA"gsword")->move(this_object());
   force_me("wear chainmail");
   force_me("wield sword");
 }

#include <std.h>
#include <metallicana.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("nomad");
   set_id(({"nomad", "Nomad"}));
   set_short("A Nomad");
   set_long("He sits still in the water hunting the animals for food and uses
their skin for armour.");
   set_gender("male");
   set_race("kobold");
   set_body_type("human");
   set_level(45);
   new(ARM "water_cape")->move(this_object());
   force_me("wear cape");
   new(ARM "water_belt")->move(this_object());
   force_me("wear belt");
   new(WEP "butterfly_knife")->move(this_object());
   force_me("wield knife");
}

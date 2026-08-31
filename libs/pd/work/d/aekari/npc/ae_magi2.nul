

#include <std.h>
#include <aekari.h>
inherit MONSTER;


void create() {
   ::create();
   set_name("yellow magi-guard");
   set_id( ({ "guard","magi","faerie","aekari","yellow guard" }) );
   set_short("Lesser Aekari Magi-Guard");
   set_long(
     "Her features are calm and angled. The flames around her body roar quietly and pulsing, with the shine in her eyes. She is one of the tortured students of magic, used to serve her people. The tattoo on her forehead is a symbol of power and pain. "
   );
   set_class("mage");
   set_subclass("druid");
   set_level(17);
   set_stats("intelligence",35);
   set_stats("wisdom",35);
   set_stats("dexterity",35);
   set_max_mp(700);
   set_mp(700);
   set("aggressive", 999);
   set_gender("female");
   set_body_type("faerie");
   set_race("Aekari");
   set_spell_chance(20);
   set_spells( ({ "bolt" }) );
   new(ARM"yrobe.c")->move(this_object());
   force_me("wear robe");
}




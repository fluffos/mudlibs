#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_level(35);
  set_stats("constitution", 1000);
  set_short("%^RESET%^%^RED%^The Dragon Rendor%^RESET%^");
  set_name("Rendor");
  set_long("Rendor's massive wingspan blocks out the majority of the sky as he hovers a few feet above the ground.  The sweep of his wings nearly knocks you over as he lets out a ferocious roar.  The light dances and shimmers across his deep red scales.  As he swings his head past you, the red glow of anger can be seen lighting up his eyes.");
  set_race("dragon");
  set_class("dragon");
  set_subclass("red");
  add_money("gold", 1000 + random(100));
  set_body_type("dragon");
  set_id( ({ "dragon", "dragon rendor", "rendor" }) );
  set_max_hp( 15000000 );
  set_skill( "defense", 300 );
  set( "aggressive", 500 );
  set_hp( query_max_hp() );
  set_skill("breath", 500 );
  set_gender("male");
  set_spells( ({ "roar", "dragonfury", "shout Infidels!  You will all pay!" }) );
  set_spell_chance( 30 );
}

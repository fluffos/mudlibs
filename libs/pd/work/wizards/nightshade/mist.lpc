#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_level(25);
  set_stats("constitution", this_object()->query_stats("constitution")*2);
  set_short("%^CYAN%^A strange mist%^RESET%^");
  set_name("mist");
  set_long("This strange mist seems to just hover and occasionally move about aimlessly.");
  set_race("mistform");
  set_body_type("blob");
  set_id( ({ "mist", "mistform", "strange mist" }) );
  set_hp( query_max_hp() );
  if( random(5) == 0 )
    new("/wizards/nightshade/iceshard")->move(this_object());
}

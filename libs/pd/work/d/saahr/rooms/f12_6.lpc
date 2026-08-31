#include <std.h>
#include <damage.h>
#include <damage_types.h>
#include <saahr.h>

inherit VIRTUALROOM;

int thorns_hurt();

void create() {
  set_server(VFSERVER);
  ::create();

  set_day_long(load_object(VFSERVER)->query_random_long(0)+
    "\nLong bushes spread out across the south."
  );
  set_night_long(load_object(VFSERVER)->query_random_long(1)+
    "\nLong bushes spread out across the south."
  );

  set_listen("default", "The sounds of civilization come from the south.");
  set_listen( ({ "south", "civilization" }),
    "The faint sounds of people talking and walking about.");

  set_items( (query_items() || ([])) + ([
    "bushes" : "Easily eight feet tall, and very thick and thorny.",
  ]) );
  
  set_exits(([
    "south" : VPROOMS "town12_7",
    "west" : VPROOMS "f11_6"
  ]));
  add_invis_exit("south");
  add_pre_exit_function("south", "thorns_hurt" );
}

int thorns_hurt() {
  object tp=this_player();
  int d;
  if (!tp) return 0;
  d = tp->do_damage("none", 15+random(20), DAMAGE_PHYSICAL | DAMAGE_PIERCE,
                    DAMAGE_BYPASS_ARMOUR | DAMAGE_NONLETHAL, "thorns");
  if (d) {
    message("move", "%^GREEN%^Thorns %^RED%^cut you%^GREEN%^ "
                    "as you pass through the bushes.", tp);
  }
  return 1;
}


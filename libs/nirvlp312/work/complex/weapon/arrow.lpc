#include <combat.h>
#include <message.h>
#include <persistence.h>

inherit WEAPON;

void configure() {
  WEAPON::configure();
  set_persistence(__FILE__,PER_KEEP_VARS);
  set_type("arrow");
  set_name("arrow");
  set_short("arrow");
  set_long("This is a simple arrow.\n");
  set_pointiness(700+random(300));
  set_sharpness(400+random(300));
}


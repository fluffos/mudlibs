//Cracked by Roath
#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("Å£¹Ç°ô", ({ "niugu bang", "bang", "staff" }) );
  init_staff(25);
  set("unit", "¸ù");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 70);
    set("material", "bone");
  }
  setup();
}


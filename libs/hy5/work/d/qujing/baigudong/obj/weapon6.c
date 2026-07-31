#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("Çå¹Ç°Ò", ({ "zhushan pa", "pa", "staff" }) );
  init_staff(35);
  set("unit", "¸ù");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 320);
    set("material", "iron");
  }
  setup();
}


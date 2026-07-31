// cracked by vikee 2/09/2002   vikee@263.net
#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("戒刀", ({ "jie dao", "dao", "blade" }) );
  init_blade(35);
  set("unit", "把");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "metal");
  }
  setup();
}


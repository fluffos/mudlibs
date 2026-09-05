//newmap Zine Nov 11 2010
#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
  set_name( "李保长的一双鞋" , ({"shoes"}));
  set_weight(500);

  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "双");
    set("value", 0);
    set("long","这是李保长的一双鞋。\n");
    set("unit", "双");
    set("material", "cloth");
    set("armor_prop/armor", 1);
  }
  setup();
}


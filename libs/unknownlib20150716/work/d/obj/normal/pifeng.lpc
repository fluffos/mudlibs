// by snowcat oct 15 1997
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIG"披风"NOR, ({"pifeng", "cloth"}));
  set("level",1);
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("unit", "件");
    set("value", 700);
    set("armor_prop/armor", 55);
	set("no_sell",1);
  }
  setup();
}



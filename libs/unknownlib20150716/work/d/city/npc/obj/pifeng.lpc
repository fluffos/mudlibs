// by snowcat oct 15 1997
#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIG"新手披风"NOR, ({"pifeng", "cloth"}));
  set("level",1);
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "leather");
    set("unit", "件");
    set("value", 700);
    set("armor_prop/armor", 35);
	set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
				set("no_give","总管发的装备，可不能乱送人哟！\n");
				set("no_get","想拿总管一叶知秋发的装备？做梦吧!\n");
  }
  setup();
}



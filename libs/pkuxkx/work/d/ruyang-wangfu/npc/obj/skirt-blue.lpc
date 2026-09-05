//skirt-blue.c -- 汝阳王府美貌女郎服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( HIB"天蓝绸裙"NOR, ({ "blue skirt", "blue", "skirt" }) );
	set("long", HIB"一条天蓝色的丝绸长裙，是由上等的湖丝制作的。\n"NOR);
	set_weight(1000);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 0);
  }
  setup();
}

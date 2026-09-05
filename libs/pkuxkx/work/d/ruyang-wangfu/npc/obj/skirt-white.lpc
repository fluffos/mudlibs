//skirt-white.c -- 汝阳王府花季少女服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( HIW"薄纱白裙"NOR, ({ "yellow skirt", "yellow", "skirt" }) );
	set("long", HIW"一条薄纱白裙，是由上等的湖丝制作的。\n"NOR);
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

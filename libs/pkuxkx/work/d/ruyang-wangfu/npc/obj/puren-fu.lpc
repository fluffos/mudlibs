//zihong-jiasha.c -- 汝阳王府仆人服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-2

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name( WHT"仆人服"NOR, ({ "puren fu", "purenfu", "fu"}) );
  set("long", WHT"这是一件定制的长袍，一般汝阳王府的侍从仆役所穿的就是它。\n"NOR);
  
  set_weight(2000);
  if( clonep() )
  	set_default_object(__FILE__);
  else 
  {
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 80);
  }
  setup();
}


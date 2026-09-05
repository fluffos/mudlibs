//bosi-changku.c -- 汝阳王府胡姬服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-4

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIW"宽褶长裤"NOR, ({ "bosi changku", "changku", "ku" }) );
  set("long", HIW"这是一条雪白的宽褶长裤，一看就知道是西域样式的。\n"NOR);
  
  set_weight(1500);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "条");
    set("material", "cloth");
    set("armor_prop/armor", 1);
    set("value", 1000);
   }
   setup();
}

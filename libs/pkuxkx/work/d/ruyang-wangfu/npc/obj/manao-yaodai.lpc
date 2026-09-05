//manao-yaodai.c -- 汝阳王府胡姬首饰
//Zone: 汝阳王府
//Create by ddid
//2009-6-4

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(YEL"玛瑙腰带"NOR, ({ "manao yaodai", "yaodai", "band" }) );
  set("long", YEL"一条镶嵌着多颗玛瑙的黄褐色腰带。\n"NOR);
  
  set_weight(1200);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "条");
    set("material", "leather");
    set("armor_prop/armor", 1);
    set("value", 30000);
   }
   setup();
}
//baoshi-xianglian.c -- 汝阳王府胡姬首饰
//Zone: 汝阳王府
//Create by ddid
//2009-6-4

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name(BLU"宝石项链"NOR, ({ "baoshi xianglian", "xianglian", "necklace" }) );
  set("long", "一条由多颗宝石串连而成的项链，特别是胸前的三颗，都是鹅卵般大小的蓝宝石。\n");
  
  set_weight(1800);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "条");
    set("material", "GOLD");
    set("armor_prop/armor", 1);
    set("value", 60000);
   }
   setup();
}
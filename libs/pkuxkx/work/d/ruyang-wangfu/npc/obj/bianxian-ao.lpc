//bianxian-ao.c -- 汝阳王府卫士服装
//Zone: 汝阳王府
//Create by ddid
//2009-6-3

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(RED"辫线袄"NOR, ({ "bianxian ao", "ao", "cloth" }) );
  set("long", "这是一件辫线袄，蒙古武士一般都爱穿它。\n");
  
  set_weight(2500);
  if( clonep() )
  	set_default_object(__FILE__);
  else
  {
  	set("unit", "件");
    set("material", "cloth");
    set("armor_prop/armor", 50);
    set("value", 200);
   }
   setup();
}

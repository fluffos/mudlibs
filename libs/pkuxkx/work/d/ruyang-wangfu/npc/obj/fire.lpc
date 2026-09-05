//fire.c -- 汝阳王府波斯火种
//Zone: 汝阳王府
//Create by ddid
//2009-6-4

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name( HIY"火种"NOR, ({ "huo zhong", "huozhong", "fire" }));
 	set("long", HIY"这是一支波斯火种，可以用来点燃(burn)东西。\n"NOR);
 	
  set_weight(120);
  if (clonep())
  	set_default_object(__FILE__);
  else
  {
    set("unit", "支");
    set("value", 100);
   }
}

void init()
{
	add_action("do_burn", "dian");
  add_action("do_burn", "burn");
}

int do_burn(string arg)
{
	
	return 1;
}
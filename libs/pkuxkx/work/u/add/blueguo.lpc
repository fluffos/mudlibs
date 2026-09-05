// blueguo.c 紫果
// hongdou 98.10.04

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
   set_name(MAG"紫果"NOR,({"blue guo","blueguo", "guo"}));
   set_weight(50);
   if(clonep() )
     set_default_object(__FILE__);
   else{
   	set("long","一枚紫靛靛的野果，散发出的浓重的香甜气味，使你不禁想上去咬一口。\n");
	set("unit","枚");
   	set("value",1000);
       }
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg)) return notify_fail("你要吃什么？\n");
	message_vision(MAG "$N吃下一枚紫果，甜蜜的汁液流入腹中，说不出的舒服。\n" NOR, this_player());
	if (((int)me->query_condition("xx_poison") > 0) ||
		((int)me->query_condition("snake_poison") > 0))
	{
	      message_vision(HIC"由于以毒攻毒，将你身上所中的毒解掉了！\n"NOR,this_player());
	      me->apply_condition("xx_poison", 0);
	      me->apply_condition("snake_poison",0);
	      destruct(this_object());
	      return 1;
	}	
	else {
	  message_vision(HIC "\n忽然之间，$N感到眼前出现了幻觉，模模糊糊地。\n\n"NOR,this_player());
	  me->unconcious();
           me->add("eff_jing", -((int)(me->query("eff_jing"))/2));
           me->add("eff_qi", -((int)(me->query("eff_qi"))/2));
          destruct(this_object());
          return 1;
	}
}

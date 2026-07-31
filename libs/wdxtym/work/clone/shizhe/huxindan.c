// huxin-dan.c 天王护心丹

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_eat", "fuyong");
}

void create()
{
	set_name(HIR"天王护心丹"NOR, ({"huxin dan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","一颗"+name()+"，地狱家族秘制的"ZJURL("cmds:fuyong huxin dan")+ZJSIZE(20)+"疗伤"NOR"圣药，功能起死回生。\n");
		set("value", 2000);
		set("unit", "颗");
		set("numb", 99);
		set("no_put", 1);
		set("no_get", 1);
		set("no_drop", 1);
		set("no_give", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
	  }
   	setup();
}

int do_eat(string arg)
{
       int q, j;
	string *enemy;

       object me, ob;      
       me=this_player();
       ob=this_object();

	if (!arg || arg!="huxin dan")
		return notify_fail("你要服什么?\n");

	if(me->is_busy())
		return notify_fail("你正忙着呢。\n");

	//enemy = me->query_enemy();
	//enemy -=({0});
	enemy = filter_array(me->query_enemy(), (: userp($1) :));	
	
	if (sizeof(enemy) >0)	
		return notify_fail("正在和玩家对手战斗，不能使用"+ name() +"。\n");

	if(me->query("combat_exp", 1) > 2000000) 
		return notify_fail("你已经是武林高手了，此丹药已经对你失去了作用！\n");

	if(me->query_condition("medicine") > 0 )
		  return notify_fail("你上次的药劲儿还没过呢，等会再吃吧。\n");

	if (me->query("eff_qi") >= (me->query("max_qi")+me->query_gain_qi()) 
	     && me->query("eff_jing") >= (me->query("max_jing") +me->query_gain_jing())
	     && me->query("neili") >= me->query("max_neili"))
		return notify_fail("你现在不需要吃"+name()+"。\n");

      if( ob->query("numb") > 0){      
		me->set("eff_qi", me->query("max_qi")+me->query_gain_qi());
		me->set("eff_jing", me->query("max_jing")+me->query_gain_jing());

		me->set("neili",me->query("max_neili")*2);
		me->set("jingli",me->query("max_jingli"));
		me->set("food", me->max_food_capacity());
		me->set("water", me->max_water_capacity());
		me->apply_condition("medicine", 5);
		message_vision(HIG"$N服下一些"+name()+HIG"，顿时伤势痊愈气血充盈！"NOR"\n" , me);
		me->start_busy(2);
		ob->add("numb", -1);

	   if(ob->query("numb") < 1){
		write(""+name()+"已经被吃的一丝不剩了。\n");
		destruct(this_object()); 
	     }
	   else write(""+name()+"还能继续使用"+ob->query("numb")+"次。\n");
   
		return 1;
	     }
	
}



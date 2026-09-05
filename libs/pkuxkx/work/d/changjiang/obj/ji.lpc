// Zine 2012,射雕主线quest物品

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("肥鸡", ({ "fei ji","ji","chicken"}));
	set_weight(1500);
	if (clonep())
		set_default_object(__FILE__);
	else 
		{
			set("long", "这是一只肥鸡。\n");
			set("unit", "只");
		}
	set("value",10);
}

void init()
{
	add_action("do_kao","kao");
	add_action("do_bo","bo");
	add_action("do_guo","guo");
	add_action("do_zhao","zhao");
}

int do_bo()
{
	object ob=this_object(),me=this_player();
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (ob->query("bo"))
	{
		tell_object(me,"这只鸡的内脏已经被清理干净了。\n");
		return 1;
	}
	message_vision(HIM"$N开始动手清理"+ob->query("name")+"的内脏。\n"NOR,me);
	ob->set("bo",1);
	ob->set("value",0);
	ob->set_name("剥净的肥鸡", ({ "fei ji","ji","chicken"}));
	set("long", "这是一只被剥净内脏的肥鸡。\n");
	return 1;
}

int do_zhao()
{
	object ob,me=this_player();
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	ob=new(__DIR__"ni");
	ob->move(me);
	message_vision(WHT"$N挖起一团地里的泥巴。\n"NOR,me);
	return 1;
}

int do_guo()
{
	object ob=this_object(),me=this_player(),ni;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (ob->query("guo"))
	{
		tell_object(me,"这只鸡已经被裹上了厚厚的泥巴。\n");
		return 1;
	}
	if (!ob->query("bo"))
	{
		tell_object(me,"这只鸡的内脏还没有被清理干净，做出来可能不能吃。\n");
		return 1;
	}
	if (!ni=present("ni ba",me))
	{
		tell_object(me,"你要把什么裹在鸡上？\n");
		return 1;
	}
	if (!ni->query("is__mud"))
	{
		tell_object(me,"你要把什么裹在鸡上？\n");
		return 1;
	}
	message_vision(WHT"$N开始在"+ob->query("name")+"的外表裹上一层层的"+ni->query("name")+"。\n"NOR,me);
	destruct(ni);
	ob->set("guo",1);
	ob->set_name("裹上泥巴的肥鸡", ({ "fei ji","ji","chicken"}));
	set("long", "这是一只裹上了一层泥巴的肥鸡。\n");
	return 1;
}
int huang_back(object me)
{
	object huang=me->query_temp("shediaoquest/kanglong/huang");
	if (!me||!living(me))
	{
		return 1;
	}
	if (!huang)
	{
		tell_object(me,"黄蓉这时下落不明了。\n");
		return 1;
	}
	huang->move(environment(me));
	huang->hong_appear(me);
	return 1;
}
int finish(object me,object ob)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (!ob->query("kao"))
	{
		message_vision("$N似乎被烤糊了，完全不能吃了。\n",ob);
		destruct(ob);
		return 1;
	}
	ob->set("is__jiaohuaji",1);
	ob->set_name("叫化鸡", ({ "jiaohua ji","ji","chicken"}));
	ob->set("long", "这是一只肥美可口的叫化鸡。\n");
	ob->set("food_remaining", 1);
	ob->set("food_supply", 100);
	message_vision(HIG"$N被烤好了，香气四溢。\n"NOR,ob);
	remove_call_out("check_ji");
	call_out("huang_back",2,me);
	return 1;
}
int check_ji(object me,object ob,object env)
{
	if (env!=environment(me))
	{
		ob->delete("kao");
	}
	remove_call_out("check_ji");
	call_out("check_ji",1,me,ob,env);
	return 1;	
}
int do_kao()
{
	object ob=this_object(),me=this_player(),fire;
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (ob->query("kao"))
	{
		tell_object(me,"你已经在烤制叫化鸡了。\n");
		return 1;
	}
	if (!ob->query("guo"))
	{
		tell_object(me,"这只鸡还没有被裹上了泥巴，叫化鸡不是这么做的。\n");
		return 1;
	}
	if (!ob->query("bo"))
	{
		tell_object(me,"这只鸡的内脏还没有被清理干净，做出来可能不能吃。\n");
		return 1;
	}
	if (!fire=present("huo dui",environment(me)))
	{
		tell_object(me,"没火你怎么烤叫化鸡？\n");
		return 1;
	}
	if (!fire->query("is__fire"))
	{
		tell_object(me,"没火你怎么烤叫化鸡？\n");
		return 1;
	}
	message_vision("$N将$n夹在火上烤了起来。\n",me,ob);
	ob->set("kao",1);
	call_out("finish",5+random(5),me,ob);
	call_out("check_ji",1,me,ob,environment(me));
	return 1;
}
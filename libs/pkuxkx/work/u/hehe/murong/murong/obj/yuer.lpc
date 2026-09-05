//by hehe
//2003.3.21

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("鱼饵", ({"yuer","er"}));
    set_weight(100);
    if( clonep() )
		set_default_object(__FILE__);
    else 
	{
		set("unit", "个");
        set("long","这是个钓鱼用的鱼饵。\n");
		set("value", 10);
        set("material", "steel");
    }
}
void init()
{
	add_action("do_gua","gua");
	add_action("do_diao","diao");
}
int do_gua(string arg)
{
	object me;
	me=this_player();
	if(me->query("age")>=18)
	{
		message_vision("$N老大不小的人了，别在这里耗时间钓鱼了！\n",me);
		return 1;
	}
	if(!(present("yugou",me)))
	{
		tell_object(me,"你没有鱼钩啊，搞什么鬼啊！\n");
		return 1;
	}
	if(!arg)
	{
		message_vision("你要挂什么？\n",me);
		return 1;
	}
	if((string)arg!="yuer")
	{
		tell_object(me,"你要挂什么?\n",me);
		return 1;
	}
	if(me->query_temp("murong/yuer"))
	{
		tell_object(me,"你的鱼钩上已经有了一个鱼饵了，不能再挂了！\n");
		return 1;
	}
	tell_object(me,"你小心的吧鱼饵挂到鱼钩上。");
	me->set_temp("murong/yuer",1);
	return 1;
}
int do_diao(string arg)
{
	object me;
	int t;
	me=this_player();
	if(!arg)
	{
		tell_object(me,"你钓什么啊！\n");
		return 1;
	}
    if (base_name(environment(me))!="/d/murong/tdiaoyu")
	{
		tell_object(me,"钓什么钓，也不看看什么地方？\n");
		return 1;
	}
	if((string)arg!="fish")
	{
		tell_object(me,"你想钓什么你说清楚啊！\n");
		return 1;
	}
	if(!(me->query_temp("murong/yuer")))
	{
		tell_object(me,"你还没把鱼饵挂在鱼钩上哪！\n");
		return 1;
	}
	if((me->query("jing"))<20)
	{
		tell_object(me,"你太累了，歇会再钓吧！\n");
		return 1;
	}
	if(me->is_busy())
	{
		tell_object(me,"你还忙着那，等会再钓吧!\n");
		return 1;
	}
	t=random(40);
	me->start_busy(t);
	tell_object(me,"你把鱼钩扔到湖里去，紧张的看着鱼漂的浮动。\n");
	call_out("end_diaoyu",5,me);
	return 1;
}
int end_diaoyu(object me)
{
	object ob;
	if(me->is_busy())
	{
		tell_object(me,"鱼漂一上一下，你紧张的手心都出汗了！\n");
		call_out("end_diaoyu",5,me);
		return 1;
	}
	else
	{
		tell_object(me,HIW"鱼漂突然一沉，你大吃一惊！\n"NOR);
		tell_object(me,HIC"你猛地一拉鱼线，感到手上一沉....\n"NOR);
		tell_object(me,HIY"你紧拉鱼线，终于钓到一条大鱼\n"NOR);
		tell_object(me,HIM"你把鱼放到身边的鱼篓里\n"NOR);
		me->set_temp("murong/yuer",0);
		ob=new("/d/murong/obj/fish");
		ob->move(me);
		call_out("reward",0,me);
		return 1;
	}
}
int reward(object me)
{
	object ob;
	ob=this_object();
	if((me->query("combat_exp"))<10000)
	{
		int a=20+random(20);
		int b=a/10;
		me->add("combat_exp",a);
		me->add("potential",b);
		me->add("jing",-b);
		me->improve_skill("sword",a);
		printf("你的经验增加了%d点\n",a);
		printf("你的潜能增加了%d点\n",b);
	}
	else if((me->query("combat_exp"))<100000)
	{
		int a=50+random(50);
		int b=a/10;
		me->add("combat_exp",a);
		me->add("potential",b);
		me->add("jing",-10);
		me->improve_skill("sword",a);
		printf("你的经验增加了%d点\n",a);
		printf("你的潜能增加了%d点\n",b);
	}
	else if((me->query("combat_exp"))<500000)
	{
		int a=100+random(100);
		int b=a/10;
		me->add("combat_exp",a);
		me->add("potential",b);
		me->add("jing",-10);
		me->improve_skill("sword",a);
		printf("你的经验增加了%d点\n",a);
		printf("你的潜能增加了%d点\n",b);
	}
	else if((me->query("combat_exp"))<1000000)
	{
		int a=200+random(150);
		int b=a/10;
		me->add("combat_exp",a);
		me->add("potential",b);
		me->add("jing",-10);
		me->improve_skill("sword",a);
		printf("你的经验增加了%d点\n",a);
		printf("你的潜能增加了%d点\n",b);
	}
	else
	{
		tell_object(me,"你已经有足够的资本出去闯荡了，不用再浪费时间在钓鱼上了！\n");
	}

	destruct(ob);
	return 1;
}







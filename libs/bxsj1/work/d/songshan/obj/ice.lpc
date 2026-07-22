// OBJECT:  ice.c 玄冰
// Created by Numa 1999-12-09

#include <ansi.h>
inherit ITEM;

string do_long();

void create()
{
	set_name(HIW"玄冰"NOR,({"ice"}));
	set_weight(2000000);
//        if (clonep())
/*
        	set_default_object(__FILE__);
     	else
     	{
*/
        	set("unit", "块");
        	set("long", (: do_long :));
        	set("value", 500000);
        	set("no_get", 1); 
        	set("unique",1);
        	set("location",1);
        	set_temp("no_return",1);
//        }
     	setup();
}

string do_long()
{
	object me = this_player();
	object ob = this_object();
	
	if (!me->query_temp("ss/zsb_get"))
		return "这是一块寒气森森的玄冰，内中晶莹透亮，闪烁着异样的光芒。\n";
	
    if (me->query("id") == ob->query_temp("find_by"))
	{
		me->delete_temp("ss/zsb_get");
		me->set_temp("ss/zsb_done",1);
		return "这是一块寒气森森的玄冰，内中卷曲着一条长鞭，似乎可以破(po)冰取之。\n";
	}

	me->delete_temp("ss/zsb_get");
	return "这是一块寒气森森的玄冰，内中卷曲一个黑黝黝的东西，似乎取不出来。\n";	
}

void init()
{
	add_action("do_po","po");
}

int do_po(string arg)
{
	object me = this_player();
	object obj = this_object();
	object ob, *clone;
	int i, j;


	if (!arg)
		return notify_fail("你要干什么？\n");
	if (!me->query_temp("ss/zsb_done"))
		return notify_fail("你要干什么？\n");
		
	if (arg == "ice" || arg == "bing")
	{
		if (me->is_busy() || me->is_fighting())
			return notify_fail("你正忙着呢！\n");
        if (me->query_temp("weapon"))
                return notify_fail("要破开这块玄冰，凭你手上那破武器恐怕难以奏效吧！\n");
		if (me->query_skill("hanbing-zhenqi",1) < 150)
		{
			tell_object(me,HIC"你伸出手掌，向着玄冰用力斩去，可是却被寒气所逼，一时间又冷又痛。"NOR);
			me->apply_condition("cold_poison",50-random(me->query("kar")));
			me->unconcious();
			return 1;
		}
		message_vision(HIC"$N伸出手掌，向着玄冰用力斩去，只听「啪」的一声，玄冰立时随开，其中长鞭也掉了出来。\n"NOR,me);
        call_out("dest",1,obj);
		me->delete_temp("ss");
        ob = unew(BINGQI_D("zisong-bian"));
       		if(!clonep(ob))
       		{
       			ob = new(BINGQI_D("whip"));
       			tell_object(me,HIR"你捡起长鞭，发现竟然只是一根普通的长鞭，你失望极了。\n"NOR);
       			ob->move(me);
       			return 1;
       		}
	       	i = ob->query("unique");
       		clone = filter_array(children(base_name(ob)), (: clonep :));
        	j = sizeof(clone);
        	while (j--)
        		if (!clone[j]->query("clone_by_wizard"))
        			i--; 
       		if(clonep(ob) && i < 0)
       		{
        		destruct(ob);
       			ob = new(BINGQI_D("whip"));
       			tell_object(me,HIR"你捡起长鞭，发现竟然只是一根普通的长鞭，你失望极了。\n"NOR);
       			ob->move(me);
       			return 1;
       		}

		tell_object(me,HIR"你捡起长鞭，发现竟然是邓八公当年所使的那条紫松鞭，顿时欣喜若狂。\n"NOR);		
		ob->move(me);
		return 1;
	}
	else
		return notify_fail("你要干什么？\n");
}

void dest(object ob)
{
        destruct(ob);
}

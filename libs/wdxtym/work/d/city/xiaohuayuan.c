// xiaohuayuan.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short","小花园");
	set("long", @LONG
这里是一个小花园，这里的肥沃土壤十分适合各种花的生长，特别
地一些十分名贵的花种，这里也可生长。西边的花房可以买到花的种子，
你可以在这里种花。旁边有一个小门，隐隐传来一些人谈话的声音。
LONG
	);

	set("exits", ([ 
		"west"  : __DIR__"huafang",
		"east" : __DIR__"liaotian",
	]));

	set("action_list", ([ 
		"种花"  : "zhonghua",
		"浇花" : "jiaoshui",
		"培育" : "peiyu",
	]));

	set("no_fight", 1);
	setup();
}

void init()
{
	add_action("do_jiaoshui", "jiaoshui");
	add_action("do_peiyu", "peiyu");
}

int do_peiyu()
{
	object ob,me;
	me = this_player();

	if (! me->query_temp("zhonghua"))
	{
		tell_object(me, HIR "你种子都没有，还想种花？"NOR"\n"); 
		return 1;
	}

	if (me->query_temp("jiaoshui") == 1)
	{
		tell_object(me,HIR "你已经完成了培育这道程序，现在可以浇水(jiaoshui)。"NOR"\n");
		return 1;
	}

	if (me->query("combat_exp") > 150000 || me->query("combat_exp") < 10000)
	{
		tell_object(me,HIR "以你的身份大概不适合在小花园种花吧！"NOR"\n");
		return 1;
	}

	if (me->query("jing") < 70)
	{
		message_vision(HIR "$N一幅气喘吁吁的样子，怎么能种花呢！"NOR"\n",me);
		return 1;
	}

	message_vision("$N把土坑周围好好地修整了一下，使土壤更加适合花的生长。\n", me); 
	me->set_temp("peiyu",1);
	me->set_temp("jiaoshui",1);
	me->start_busy(1 + random(3));
	return 1;
}

int do_jiaoshui()
{
	object me,ob;

	me = this_player();

	if (me->query("jing") < 70)
	{
		tell_object(me,HIR "你气色不好，还是休息休息吧。"NOR"\n"); 
		return 1;
	}

	if (me->is_busy())
	{
		tell_object(me, HIR "你正忙着呢，别着急。"NOR"\n");
		return 1;
	}

	if (! me->query_temp("peiyu") == 1)
	{
		tell_object(me,HIR "你是来捣乱吗？没事干浇什么水啊！"NOR"\n");
		return 1;
	}

	if (me->query_temp("peiyu") == 2)
	{
		if (random(14) == 1)
		{
			switch (random(5))
			{
				case 1 : ob = new("/d/changan/npc/obj/hmeigui"); break;
				case 2 : ob = new("/d/changan/npc/obj/zi-luolan"); break;
				case 3 : ob = new("/d/changan/npc/obj/bai-chahua"); break;
				case 4 : ob = new("/d/changan/npc/obj/huang-meigui"); break;
				case 0 : ob = new("/d/changan/npc/obj/lan-tiane"); break;
			}

			if (random(15) == 1)
			{
				if (random(10000) == 1)
				{
					ob = new("/d/shenlong/obj/hua4");
					CHANNEL_D->do_channel(this_object(), "rumor",me->query("name") + "从小花园种出一朵翡翠兰。");
					message_vision(HIR "$N" HIR "得到了翡翠兰。"NOR"\n",me);
					ob->move(me, 1);
					me->delete_temp("jiaoshui");
					me->delete_temp("zhonghua");
					me->delete_temp("peiyu");
					me->add("combat_exp", 500);
					me->improve_potential(100 + random(100));
					return 1;
				}

				ob = new("/d/shenlong/obj/hua2");
				me->add("combat_exp", 20 + random(10));
				me->improve_potential(20 + random(10));
				CHANNEL_D->do_channel(this_object(), "rumor",me->query("name") + "从小花园种出一朵无名花。");
				return 1;
			}

			message_vision(HIC "$N" HIC "十分小心的给小坑里浇了一些水，突然" + ob->query("long") + "从坑里冒了出来。"NOR"\n",me);   
			message_vision(HIR "$N" HIR "把它摘了下来，拿在手里。"NOR"\n",me);
			ob->move(me, 1);
			me->delete_temp("jiaoshui"); 
			me->delete_temp("peiyu"); 
			me->delete_temp("zhonghua"); 
			me->add("combat_exp", 20 + random(10)); 
			me->improve_potential(10 + random(10));
			return 1; 
		}

		message_vision(HIR "$N" HIR "笨手笨脚的拿起水壶给小坑里浇水，结果水洒的太多把花给毁了。\n",me); 
		me->delete_temp("jiaoshui"); 
		me->delete_temp("zhonghua"); 
		me->delete_temp("peiyu"); 
		me->add("jing", -50);
		me->add("combat_exp", 3);
		me->improve_potential(2); 
		return 1; 
	}

	if (me->query_temp("jiaoshui") == 1)
	{
		message_vision("$N拿起水壶给小坑浇了一些水。\n",me); 
		me->add("jing", -70); 
		me->set_temp("peiyu", 2); 
		me->start_busy(1 + random(2)); 
		return 1;
	}
}

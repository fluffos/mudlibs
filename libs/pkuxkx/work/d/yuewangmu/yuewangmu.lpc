// 岳飞墓
// by male
// 02/9/3
// modified by iszt@pkuxkx, 2007-01-16 and 2007-02-05 and 2007-02-10

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",HIW"岳王冢"NOR);
	set("long", HIY @LONG
这就是当年令金兵闻风丧胆岳武穆的墓室。虽然现在墓室里是如此的安静，
但是你仍然好像隐约的听到当年岳飞驰骋疆场时刀枪剑戟的碰撞之声。岳王的石
棺(coffin)稳稳的放在墓室中央，让人肃然起敬。你燃起蜡烛，环顾四周，发现
墙上还隐约可见岳飞当年写的「满江红」。在满江红的下面，你发现好像记载着
一些枪法。由于百姓自发对岳王冢的保护，岳王冢多年来都没有受到盗墓者的骚
扰，墙上的字迹仍然清晰可见。也许你可以在上面学到些什么。(watch 墙壁)
------------------------------------------------------------------------


                   冢              王              岳


------------------------------------------------------------------------
LONG NOR
	);
	set("bookcount",1);
	set("qiangcount",1);
	set("exits", ([
		"out" : __DIR__"muhou",
	]));
	set("item_desc", ([
		"coffin" : "这是岳飞的石棺，岳王的遗骸就在里面，石棺的棺盖极厚，看来没有一定的内力是推不开的（push)\n",
	]) );
        set("no_task",1);
	setup();
}

void init()
{
	object me;
	me=this_player();
	if(!wizardp(me) && (!me->query_temp("dig1")||!me->query_temp("dig2")
		||!me->query_temp("dig3")||!me->query_temp("dig4")
		||!me->query_temp("dig5")||!me->query_temp("dig6")
		||!me->query_temp("dig7")||!me->query_temp("dig8")))
	{
		message_vision(HIY"$N不是挖地道进来的？那请回罢！嘿嘿！\n赏恶罚善使者突然出现在岳王墓中一声冷笑，将$N一把抓了出去！\n"NOR,me);
		me->move("/d/yuewangmu/muhou");
                if (userp(me)) me->unconcious();
		return ;
	}
	else
	{
		write(HIB"你终于来到了岳王墓中，真是几经波折啊，你马上开始在墓里搜索起来！\n"NOR);
	}
	add_action("do_push", "push");
	add_action("do_watch", "watch");
	return ;
}

int do_push(string arg)
{
	object me;
	object shu,qiang;
	me=this_player();
	if(!arg||arg!="coffin")
	{
		tell_object(me,HIW"你要推什么？\n"NOR);
		return 1;
	}
        if ((int)me->query("marks/open_coffin")+20000 >= me->query("mud_age") )
	{
		tell_object(me,HIR"你前不久才来拿过，怎么又来？不要贪得无厌啊！\n"NOR);
		return 1;
	}
	if(me->query("shen")>0)
	{
		message_vision(HIW"$N想推开石棺，但又想了想，终于$N的良心让$N又把手收缩了回来。\n"NOR,me);
		me->add("shen",-1000);
		return 1;
	}
	if(me->query("max_neili")<3000)
	{
		message_vision(HIR"$N鼓足内力推向石棺，但是无奈，很明显内力不够，石棺纹丝不动。\n"NOR,me);
		me->set("neili",0);
		return 1;
	}
        me->set("marks/open_coffin",me->query("mud_age"));
	message_vision(HIR"沉重的棺盖在$N精纯的内力下轻而易举就推开了。\n"NOR,me);
	if(!(this_object()->query("qiangcount")))
	{
		message_vision(MAG"$N推开了一半棺盖，但是发现除了岳王的白骨什么都没有。\n"NOR,me);
		return 1;
	}
	if(this_object()->query("qiangcount"))
	{
		switch (random(2))
		{
		case 0:
			qiang=new(__DIR__"obj/dpqiang");
			message_vision(HIR"$N发现有一杆枪掉了出来，居然是传说中的夺魄枪，不禁欣喜若狂！\n"NOR,me);
			qiang->move(this_object());
			this_object()->set("qiangcount",0);
			break;
		case 1:
			qiang=new("/d/beijing/npc/obj/danxinjue");
			message_vision(HIR"$N发现有一本书掉了出来，不禁欣喜若狂！\n"NOR,me);
			qiang->move(this_object());
			this_object()->set("qiangcount",0);
			break;
		/*case 2:
			qiang=new("/d/beijing/npc/obj/book_sunzi");
			message_vision(HIR"$N发现有一本书掉了出来，不禁欣喜若狂！\n"NOR,me);
			qiang->move(this_object());
			this_object()->set("qiangcount",0);
			break;*/
		}
	}
	me->add("neili",-3000);
	me->add("shen",-1000);
	return 1;
}
int do_watch(string arg)
{
	object me;
	int max_level;
	int times;

	me=this_player();
	if(me->query_temp("begin_read")!=1)
	{
		me->set_temp("begin_read",1);
		me->apply_condition("begin_read",600);
	}

	if(!arg || (sscanf(arg, "墙壁 %d", times) != 1 && arg != "墙壁"))
		return notify_fail("你四周看了看，墙壁上似乎记载着一些枪法。\n");
	if(!times)
		times = 1;
	if(times > 50)
		return notify_fail("学习次数不能超过五十次。\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢，还想学岳家枪？\n");
	if(me->query("shen")<0)
		return notify_fail("你心术不正，无法领会其中精义。\n");
	if(me->query("neili")<5*times || me->query("jing")<50*times)
		return notify_fail("你已经太累了，先休息一下吧。\n");

	message_vision("$N仔细辨认墓壁上的文字和图画。\n", me);
	if ( me->query_int() < 50 )
	{
		write(HIY"你看了半天却看不懂壁上文字所表达的含义。\n"NOR);
		return 1;
	}
	if( (int)me->query("max_jingli")<100)
	{
		write("你精力不够，无法领悟岳家枪。\n");
		return 1;
	}

//	max_level = (me->query("kar") + me->query("int") + me->query("spi") + 30)*10 / 2;
        max_level = (me->query("con") + me->query_spi() + 80 - me->query("kar"))*10 / 2;

	if (max_level < 250) max_level=250;
	if (max_level > 600) max_level=600;
	if (me->query_skill("yuejia-qiangfa",1) > max_level)
	{
		write("你对着墙上的枪谱看了又看，只觉得过于深奥，无法理解。\n");
		return 1;
	}
	me->receive_damage("jing",50*times);
	me->add("neili",-5*times);
	me->improve_skill("yuejia-qiangfa",(int)(me->query("kar")/2+me->query("int")/2)*times);
	message_vision(HIW"$N学习了墙上的枪谱，对岳家枪有所体会！\n"NOR,me);
	if ((int)me->query_condition("begin_read" ) < 10 )
	{
		message_vision(HIR"$N觉得墓室里缺氧，有些难受！\n"NOR,me);
	}
	if ((int)me->query_condition("begin_read" ) < 2 )
	{
		message_vision(HIW"由于$N在潮湿的墓室里长期缺氧，$N觉得体力不支，爬了出来！\n"NOR,me);
		me->move("/d/yuewangmu/muhou");
		message_vision(HIR"结果$N一爬出来，就晕了过去！\n"NOR,me);
		me->set_temp("begin_read",0);
		me->unconcious();
		me->set("neili",0);
		me->add("max_neili",0-random(10));
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if(dir == "out")
		me->set_temp("begin_read",0);
	return::valid_leave(me,dir);
}

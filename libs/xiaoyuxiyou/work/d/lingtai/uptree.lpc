// Room: some place in 西牛贺洲
// uptree.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set ("short", "大松树顶");
  	set ("long", @LONG
站在大松树的顶端，山风阵阵，空气清新。向山顶仰望，
隐约看到一片房屋在一股淡淡的紫气笼罩之下。
    枝叶之间，挂满了松果(guo)，随风而动。
LONG);
	set("exits", ([
		"down": __DIR__"uphill2"
	]));
	set("objects", ([
		__DIR__"obj/guo": 1,
	]));
	set("item_desc",([
		"guo" : "沉甸甸的松果，散发着清香，试试能不能摘(zhai)到。\n",
	]));	
        set("no_clean_up", 0);
	set("outdoors", 1);
        setup();
}

void init()
{
	add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
	int kar,dodge;
	object obj,me = this_player();
	if( me->is_busy() )
		return err_msg("你现在正忙着呢。\n");
	me->start_busy(1);
	if( !arg 
	|| (arg!="guo" && arg!="松果" && arg!="果" ) )
	{
		EMOTE_D->do_emote(me, "wave",geteuid(me),CYN,0,0,0);
		return 1;
	}
	message_vision("$N站在枝头，探身去摘松果。\n",me);
	dodge = me->query_skill("dodge");
	if( random(dodge/10)<10 )
	{
		message_vision("\n结果$N脚下一滑，“哎呦”一声，从枝头跌落了下去！\n",me);
		me->move(__DIR__"uphill2",2);
		message("vision","\n\n一道身影从大松树顶上跌落了下来！\n\n",environment(me),me);
		tell_object(me,"\n你重重的摔在了地上，只觉屁股刺心的疼。。。。\n");
		me->delete_temp("last_damage_from");
		me->set_temp("death_msg","失足从高处摔死了！");
		me->receive_wound("kee",100+random(50),me);
		return 1;
	}
	kar = me->query_kar();
	kar/= 10;
	if( random(kar)<3 )
	{
		message_vision("\n结果$N累了一身汗，啥也没摘到。\n",me);
		me->start_busy(3);
	}
	else if( random(kar)<6 )
	{
		obj = new(__DIR__"obj/guo");
		if( !obj->move(me) )
		{
			message_vision("\n糟糕！失手了，松果掉落到了树下！\n",me);
			if( !obj->move((__DIR__"uphill2")) )
				destruct(obj);
			else	message("vision","\n\n一个黑色的松果从树顶落了下来。\n",environment(obj));
		}
		else	message_vision("\n结果$N摘到了一个"+obj->name()+"。\n",me);
	}
	else
	{
		obj = new(__DIR__"obj/guo2");
		if( !obj->move(me) )
		{
			message_vision("\n糟糕！失手了，松果掉落到了树下！\n",me);
			if( !obj->move((__DIR__"uphill2")) )
				destruct(obj);
			else	message("vision","\n\n一个黑色的松果从树顶落了下来。\n",environment(obj));
		}
		else	message_vision("\n结果$N摘到了一个"+obj->name()+"。\n",me);
	}
	return 1;
}

		
//yhetang.c
//by hehe
//2003.3.21

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "农舍");
    set("long", @LONG
这是大旁边突向湖面的一个小道，与农舍相连。湖面上的
莲蓬看起来近在咫尺，似乎是垂手可得。
LONG
    );

    set("exits", ([
		"south" : __DIR__"yhouse",
		"east" : __DIR__"yroad3",
    ]));
    
    set("outdoors", "murong");
    setup();

}
void init()
{
	add_action("do_zai","zai");
}
int do_zai(string arg)
{
	object me;
	int t;
	me=this_player();
	if(me->query("age")>=18)
	{
		message_vision("$N年纪这么大了，还玩这种游戏，不害臊啊！\n",me);
		return 1;
	}
	if(!arg)
	{
		message_vision("$N想摘什么！\n",me);
		return 1;
	}
	if((string)arg!="peng")
	{
		message_vision("$N想摘什么你说清楚啊！\n",me);
		return 1;
	}
	if((me->query("jing"))<20)
	{
		message_vision("$N太累了，歇会再摘吧！\n",me);
		return 1;
	}
	if(me->is_busy())
	{
		message_vision("$N还忙着那，等会再摘吧!\n",me);
		return 1;
	}
	t=random(20);
	me->start_busy(t);
	message_vision(HIG "$N向湖面上探身过去，想去摘个莲蓬。\n" NOR ,me);
	call_out("end_zaipeng",5,me);
	return 1;
}
int end_zaipeng(object me)
{
	object ob;
	if(me->is_busy())
	{
		message_vision(HIB "$N的手左右移动，在挑选一个好的莲蓬！\n" NOR,me);
		call_out("end_zaipeng",5,me);
		return 1;
	}
	else
	{
		switch(random(2))
		{
		case 0:
			{
				message_vision(BLU "$N手指准确的指向一个莲蓬\n" NOR,me);
				message_vision(BLU "$N手指一加，把莲蓬抓在手里....\n" NOR,me);
				message_vision(BLU "$N手指一掐，把莲蓬摘了下来\n" NOR,me);
				message_vision(HIC "$N把莲蓬放在身边\n",me);
				ob=new("/d/murong/obj/lianpeng");
				ob->move(me);
				call_out("reward",0,me);
				return 1;
			}
		case 1:
			{
				message_vision(WHT "$N手向水中伸去，一下捞了到了一个臭鞋套\n" NOR,me);
				message_vision(WHT "$N拿起来闻了闻，感觉很臭，又丢到水里去了！\n" NOR,me);
				me->improve_skill(random(20));
				me->add("jing",-10);
				return 1;
			}
		default :
			{
				message_vision("$N看来看去，一个也没看中，白弄了半天,ft!\n");
			}
		}
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
		me->improve_skill("finger",a);
		printf("你的经验增加了%d点\n",a);
		printf("你的潜能增加了%d点\n",b);
		return 1;
	}
	else if((me->query("combat_exp"))<100000)
	{
		int a=50+random(50);
		int b=a/10;
		me->add("combat_exp",a);
		me->add("potential",b);
		me->add("jing",-10);
		me->improve_skill("finger",a);
		printf("你的经验增加了%d点\n",a);
		printf("你的潜能增加了%d点\n",b);
		return 1;
	}
	else if((me->query("combat_exp"))<500000)
	{
		int a=100+random(100);
		int b=a/10;
		me->add("combat_exp",a);
		me->add("potential",b);
		me->add("jing",-10);
		me->improve_skill("finger",a);
		printf("你的经验增加了%d点\n",a);
		printf("你的潜能增加了%d点\n",b);
		return 1;
	}
	else if((me->query("combat_exp"))<1000000)
	{
		int a=200+random(150);
		int b=a/10;
		me->add("combat_exp",a);
		me->add("potential",10);
		me->add("jing",-b);
		me->improve_skill("finger",a);
		printf("你的经验增加了%d点\n",a);
		printf("你的潜能增加了%d点\n",b);
		return 1;
	}
	else
	{
		message_vision("$N已经有足够的资本出去闯荡了！不要在这里瞎忙活了\n",me);
		return 1;
	}

}
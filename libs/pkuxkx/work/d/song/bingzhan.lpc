// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "城北兵站");
	set("long", @LONG
这里是临安城北的兵站，负责招募、训练新兵。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"west" : "/d/hangzhou/beimen",
	]));
	set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
	set("at_hangzhou",1);
	setup();
}

void init()
{
    add_action("do_jianyue","jianyue");
    add_action("do_lianbing","lianbing");
}

int do_jianyue()
{
    object me=this_player();
    int n;
    string xunlian;
    if (me->query_temp("songtasks/bingbu/task")!=1)
	return notify_fail("你没事跑军站来玩了？\n");
	if (me->query_temp("songtasks/bingbu/fail"))
	return notify_fail("兵都给你练光了，还练？\n");
	if (me->query_temp("songtasks/bingbu/jianyue"))
	return notify_fail("没完没了的检阅？没人理你了。\n");
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
	if(ANTIROBOT_D->stopped())
    {
        tell_object(me,"你发现，此刻狂风暴雨，还是过一会再来吧。\n");
        return 1;
    }
    n=50+random(30);
    xunlian=chinese_number(n);
    message_vision("$N来到校场，旗牌官忙拿出令旗，召集众人接受$N的检阅。\n",me);
    tell_object(me,"你扫视了一下场中，大约这队官兵的训练程度是：\n");
    ANTIROBOT_D->mxpantirobot_ex(me,xunlian);
    tell_object(me,"时间紧迫，那就赶紧开始训练吧。\n");
    me->add_busy(1);
    me->set_temp("songtasks/bingbu/jianyue",1);
    me->set_temp("songtasks/bingbu/bing_degree",n);
    return 1;
}

int do_lianbing()
{
    object me=this_player();
    int n;
    if (me->query_temp("songtasks/bingbu/task")!=1)
	return notify_fail("你没事跑军营来玩了？\n");
	if (me->query_temp("songtasks/bingbu/fail"))
	return notify_fail("兵都给你练光了，还练？\n");
	if (me->is_busy() || me->is_fighting())
	return notify_fail("你正忙着哪！\n");
	if (!me->query_temp("songtasks/bingbu/jianyue"))
	return notify_fail("将不知兵还如何训练？先检阅(jianyue)一下吧。\n");
	if (me->query_temp("songtasks/bingbu/bing_degree")>85 && me->query_temp("songtasks/bingbu/bing_degree")<=100)
		me->set_temp("songtasks/bingbu/1/finish",1);
	if (me->query_temp("songtasks/bingbu/bing_degree")>100)
	{
		tell_object(me,"你把人往死里练？官兵大哗，一哄而散，你赶紧会兵部领罪吧。\n");
		me->set_temp("songtasks/bingbu/fail",1);
		me->delete_temp("songtasks/bingbu/1/finish");
		return 1;
	}
	message_vision("大队官兵在$N的监督下操练阵型。\n",me);
	n=1+random(5);
	me->add_temp("songtasks/bingbu/bing_degree",n);
	message_vision("官兵在$N的操练下，训练程度上升"+chinese_number(n)+"点。\n",me);
	me->add_busy(2);
	return 1;
}

//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;
string look_fish();
void create()
{
        set("short", HIG"清溪"NOR);
        set("long", @LONG
这里是一条清澈的小溪，溪中许多游鱼(fish)。
LONG
        );
        set("exits", ([
             "south" : __DIR__"cjb3",
        ]));
        set("couldfish",1);
		set("item_desc",
        ([
        "fish":(:look_fish:),
        ]));
        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );
		set("shediao_place",2);
        set("no_task", 1);
        set("outdoors", "changjiang");

        setup();
}
string look_fish()
{
	return "如果有钓竿肯定能把水里的鱼儿钓上来。\n";
}
int valid_leave(object me,string dir)
{  
	if (dir=="south")
    {
		if (me->query_temp("shediaoquest/kanglong/start")<9)
		{
			return notify_fail("黄蓉在这里还没玩够了，迟些再走吧。\n");
		}
    }
	return ::valid_leave(me, dir);
}
int notice(object me)
{
	object huang;
	if (!huang=present("huang rong",this_object()))
	{
		return 1;
	}
	if (huang->query("owner")!=me)
	{
		return 1;
	}
	huang->sayswim(me);
	return 1;
}
int nextstep(object me)
{
	object huang;
	if (!huang=present("huang rong",this_object()))
	{
		return 1;
	}
	if (huang->query("owner")!=me)
	{
		return 1;
	}
	huang->fish(me);
	return 1;
}
int swim(object me)
{
	if (!me||!living(me))
	{
		return 1;
	}
	if (me->query_temp("shediaoquest/kanglong/start")<7)
	{
		return 1;
	}
	if (environment(me)!=this_object())
	{
		return 1;
	}
	if (random(10)>3)
	{
		message_vision("$N站立不稳，跌入水中，心慌意乱之下，不由喝了几口水。\n",me);
		call_out("swim",2,me);
		return 1;
	}
	else
	{
		message_vision("游泳之道旨在能够控制呼吸，$N于内功习练有素，精通呼吸吐纳的功夫，半日之下，已略识门径。\n",me);
		me->set_temp("shediaoquest/kanglong/start",8);
		me->set("shediaoquest/kanglong/swim",1);
		call_out("nextstep",2,me);
		return 1;
	}
}
int do_swim()
{
	object me=this_player();
	if (me->query_temp("shediaoquest/kanglong/start")<7)
	{
		tell_object(me,"这里水流湍急，你根本不会游泳啊！\n");
		return 1;
	}
	else if (me->query_temp("shediaoquest/kanglong/start")>7)
	{
		tell_object(me,"别闹了，看看其他事情吧。\n");
		return 1;
	}
	else
	{
		message_vision("$N依照黄蓉的指点，开始练习游泳。\n",me);
		call_out("swim",1,me);
		return 1;
	}
}
void init()
{
	object me=this_player();
	add_action("do_swim","swim");
	if (me->query_temp("shediaoquest/kanglong/start")==4)
	{
		tell_object(me,"真是一片美丽的景色啊，美不胜收！\n");
		me->set_temp("shediaoquest/kanglong/start",5);
		call_out("notice",4,me);
	}
	return;
}

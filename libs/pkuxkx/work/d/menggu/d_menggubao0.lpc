// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大帐");
	set("long", @LONG
这里是一顶巨大的蒙古包，札木合、桑坤的帅帐所在，门前站着几个卫士，
盘查进大帐的人。
LONG
	);

	set("exits", ([
		"southeast" : __DIR__"d_menggubao3",
		"southwest" : __DIR__"d_menggubao5",
		"northeast" : __DIR__"d_menggubao2",
        "northwest" : __DIR__"d_menggubao6",
        "north" : __DIR__"d_menggubao1",
        "south" : __DIR__"d_menggubao4",
        "enter" : __DIR__"d_menggubao00",
	]));
    set("valid_startroom", 1);
    set("outdoors", "menggu_m");
	set("no_robber",1);
	set("objects", ([
        	//__DIR__"npc/muyangren" : random(3),
	]));
	setup();
}

void init()
{
    add_action("do_say","say");
    add_action("do_say",",");
}

int do_say(string arg)
{
    object me=this_player();
    if (arg==me->query_temp("shediaoquest/jdfm/kouling")&&me->query_temp("shediaoquest/jdfm/kouling")!="finish")
    {
        message_vision("$N答道：今天的口令是“"+arg+"”！\n",me);
        tell_room(this_object(),"卫士满意地点点头，放"+me->name()+"进去！\n");
        me->set_temp("shediaoquest/jdfm/kouling","finish");
        return 1;
    }
    return 0;
}

int escape(object me)
{
    if (me&&environment(me)==this_object())
    {
        tell_object(me,"未完成大汗所托，你满怀羞愧地回到了大翰耳朵。\n");
        me->move("/d/menggu/dahanerduo_path2");
    }
    return 1;
}

int valid_leave(object me,string dir)
{
    object room=load_object(this_object()->query("exits/enter"));
    if (dir=="enter")
    {
        if (!me->query_temp("shediaoquest/jdfm/gogogo"))
        {
            return notify_fail("此刻，桑坤、札木合正在商量对付铁木真的事宜，不愿见客。\n");
        }
        else if (me->query_temp("shediaoquest/jdfm/check_point")<2)
        {
            call_out("escape",5,me);
            return notify_fail("你并没有按铁木真所言，越过不儿罕山从和林北部杀入，行踪早早被人发现，快撤把。\n");
        }
        else if (me->name()!="十夫长")
        {
            return notify_fail("卫士们嘲讽地看着你：大帐是尔等平民可以随便乱闯的吗？\n");
        }
        else if (!me->query_temp("shediaoquest/jdfm/kouling"))
        {
            message_vision("卫士们看到$N，大喊：“口令？”",me);
            call_out("escape",5,me);
            return notify_fail("很明显，你啥口令都不知道。显然蒙混不过去了。\n");
        }
        else if (!present("sang kun",room))
        {
            return notify_fail("桑坤此刻并不在帐中，刺杀他可能还要稍等。\n");
        }
        else if (me->query_temp("shediaoquest/jdfm/kouling")=="finish")
        {
            return ::valid_leave(me,dir);
        }
        else
        {
            return notify_fail("快把从十夫长那里套来的口令说(say)给他们吧。\n");
        }
    }
    return ::valid_leave(me,dir);
}
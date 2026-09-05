// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY+"金帐"+NOR);
	set("long", @LONG
这是帐篷的里间，铁木真在此处的行辕，大汗正在出征，除了两个女仆，别
的人都不在。
LONG
	);

	set("exits", ([
        
		"out" : __DIR__"menggubao7",
		"north" : __DIR__"jinzhang2",
	]));
	set("no_robber",1);
	set("objects", ([
        	__DIR__"npc/shinv" : 2,
	]));
	setup();
}


int valid_leave(object me,string dir)
{
    if (dir=="north"&&!me->query("shediaoquest/jdfm"))
    {
        return notify_fail("没有大汗的命令，任何人不得进入后帐。\n");
    }
    return ::valid_leave(me,dir);
}

int do_look(string arg)
{
	object me=this_player();
    if (arg=="north")
    {
        tell_object(me,"不要命了？在这里还探头探脑的！\n");
        return 1;
    }
    return 0;
}

int show_up(object me)
{
        object zhebie=new(__DIR__"npc/zhebie2");
        zhebie->move(this_object());
        message_vision("$N从后帐走了出来。\n",zhebie);
        zhebie->hello(me);
        return 1;
}

int intojob(object me)
{
	tell_object(me,"此时帐中的气氛分外凝重，你觉得铁木真似乎有话要说，去问问(ask)他吧。\n");
	return 1;
}

void init()
{
    object room,me=this_player();
    add_action("do_look","look");
    add_action("do_look","l");
    if (!present("zhe bie",this_object())&&me->query("shediaoquest/zhebie")==1&&!me->query_temp("shediaoquest/study_from_zhebie")&&!present("zhe bie",this_object()))
    {
        me->set_temp("shediaoquest/study_from_zhebie",1);
		remove_call_out("show_up");
        call_out("show_up",1,me);
    }
    if (me->query("shediaoquest/zhebie")>=2&&(time()-(int)me->query("shediaoquest/zhebie_endtime"))>60*24&&!me->query_temp("shediaoquest/jdfm/start")&&!me->query("shediaoquest/jdfm"))
    {
        me->set_temp("shediaoquest/jdfm/start",1);
        message_vision("帐后传来了一声雄厚的声音：“"+me->query("name")+"，进来吧！”\n",me);
        tell_object(me,"声音带着不容抗拒的威严，你顺从地走进了帐后。\n");
        room=load_object(__DIR__"jinzhang2");
        tell_room(room,me->name()+"从"+this_object()->query("short")+"走了进来。\n");
        me->move(room);
		call_out("intojob",1,me);
    }
    return;
}


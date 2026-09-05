// Room: /city/beimen.c
// YZC 1995/12/04 
// Zine 2010/10/2 哇塞，整整过了15年才有人动这个文件。

inherit ROOM;
#include <ansi.h>
#include "dating.h"
string look_gaoshi();

void create()
{
	set("short", "北门");
	set("long", @LONG
这是扬州的北城门，因为曾经失火，到现在城墙还是黑乎乎的，因此白纸黑
字的官府告示(gaoshi)就显得特别显眼。北方是一条官道，通往淮北和曲阜。西
北方向有条小路，你可以仔细观察(guancha)一下。
LONG);

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
		"south" : __DIR__"beidajie2",
		"east" : __DIR__"junying",
		"north" : __DIR__"guandaon1",
		
	]));
        set("objects", ([
		__DIR__"npc/wujiang1"+random(2) : 1,
                __DIR__"npc/bing" : 2,
        ]));
    set("gate","北");
	set("outdoors", "city");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n扬州知府\n程药发\n";
}

void init()
{
	add_action("do_watch", ({ "guancha", }));
    add_action("do_dating","dating");
    add_action("do_answer","answer");
}

int close_door()
{
	delete("exits/northwest",);
	return 1;
}

int do_watch(string arg)
{
	object me=this_player();
	object room;
	if (me->query("combat_exp")>=500000)
	{
		if (me->is_busy() || me->is_fighting())
		{
			return notify_fail("你正忙着哪！\n");
        }
	if(!arg)
		{
			return notify_fail("你要往哪里张望？\n");
		}
    if(arg != "northwest" && arg !="西北" && arg !="nw")
		{
            return notify_fail("你要往哪里张望？\n");
		}
    if (query("exits/northwest"))
		{
			return notify_fail("你已经发现一条小路，还不赶紧过去？\n");
		}
    if(!( room = find_object(__DIR__"qingjunying")) )
		{
			room = load_object(__DIR__"qingjunying");
		}
    if(objectp(room))
        {
			set("exits/northwest", __DIR__"qingjunying"); 
			message_vision("$N探头望去，西北面竟是清军大营。\n",me);
			remove_call_out("close_door");
			call_out("close_door",3); 
		}
    return 1;
		
	}
	else
	{
		tell_object(me,RED"清军野蛮凶残，没事还是别去惹麻烦为妙。\n"NOR);
		return 1;
	}
}
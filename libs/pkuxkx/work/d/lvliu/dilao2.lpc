#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;

void create()
{
	set("short", HIG"五行牢狱·木牢"NOR);
	set("long",HIG"一间阴暗的地牢。四周石壁上长着许多样式古怪的花花草草，一股
若有若无的异香弥漫在整个地牢中，稍一闻到便有头晕目眩的感觉，你
急忙捂住了口鼻。\n"NOR);
	set("exits", ([
	  "east" : __DIR__"path2",
	]));
	set("item_desc", ([
		"east" : "前面黑乎乎的，啥也看不见。\n",
	]));
	set("no_sleep_room",1);
	setup();
}

void init()
{
	object me = this_player();
	object npc, here = this_object();

	if (!objectp(me) || !userp(me)) return;
	
	if (!here->query("checking"))
	{
		here->set("checking", 1);
		call_out("do_check", 5);
	}
	
	npc = present("jiguan ren", here);
	if (!objectp(npc) || userp(npc))
	{
		npc=new(__DIR__"npc/jiguanren2");
		if (objectp(npc))
		{
			npc->move(here);
			message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
		}
		return;
	}
	message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
}

void do_check()
{
	int count;
	object *allob = all_inventory(this_object());
	count = 0;
	for (int i=0; i<sizeof(allob); i++)
	{
		if (!objectp(allob[i]) || !userp(allob[i])) continue;
		count++;
		if (!living(allob[i])) continue;
		tell_object(allob[i], HIG"你的鼻中闻到一股异香，顿感头晕脑胀，整个人迷迷糊糊的，几乎就要栽倒在地。\n"NOR);
		if (!wizardp(allob[i])) allob[i]->start_busy(3);
	}
	if (count>0)
		call_out("do_check", 5);
	else
		this_object()->delete("checking");
}

int valid_leave(object me, string dir)
{
    if ( objectp(present("jiguan ren", environment(me))))
        return notify_fail("机关人巨大的身躯挡住了出口，在把它解决掉之前你根本出不去。\n");
    return ::valid_leave(me, dir);
}


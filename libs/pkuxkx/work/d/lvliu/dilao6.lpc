#include <ansi.h>
#include <room.h>
#include "nodie.h"
inherit ROOM;

int do_swim(string arg);

void create()
{
	set("short", HIC"五行牢狱·密室"NOR);
	set("long", HIC"一间阴暗的地牢。四周石壁上沾着一层厚厚的泥土，有些地方干裂
着一个个大口子，露出了下面的青石，显示着整座牢狱坚不可摧。空气
有点浑浊，满是一股腐败的泥土气息。\n"NOR);
	set("exits", ([
	  "west" : __DIR__"path5",
	  "out" : __DIR__"dating",
	]));
	set("item_desc", ([
		"out" : "前面黑乎乎的，啥也看不见。\n",
	]));
	set("no_sleep_room",1);
	setup();
}

void init()
{
	object me = this_player();
	object npc, here = this_object();

	if (!objectp(me) || !userp(me)) return;
	
	npc = present("jiguan ren", here);
	if (!objectp(npc) || userp(npc))
	{
		npc=new(__DIR__"npc/jiguanren6");
		if (objectp(npc))
		{
			npc->move(here);
			message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
		}
		return;
	}
	message_vision(YEL"黑暗中缓缓站起了一个机关人，巨大的身躯挡在了$N的面前。\n"NOR, me);
}

int valid_leave(object me, string dir)
{
    if ( objectp(present("jiguan ren", environment(me))))
        return notify_fail("机关人巨大的身躯挡住了出口，在把它解决掉之前你根本出不去。\n");
	if (dir!="out")
		return notify_fail("已经没有回头路可走了。\n");
    return ::valid_leave(me, dir);
}


// by aiai
 
inherit ROOM;
#include <room.h>

void create ()
{
	set ("short", "青石崖");
	set ("long", @LONG

   岛上风光秀丽，当真是好去处！高崖上视野开阔，远望四周，
把蓬莱景色看的清清楚楚。远处大海如明镜般平整。山崖上长有
无数异草，飘着淡淡香气。
LONG);
	set("exits", ([ /* sizeof() == 3 */
	
]));
	set("objects",([
//                      "/kungfu/class/xiakedao/xianzhi":1,
        __DIR__"npc/baihe":1,
	]));
	set("no_clean_up",1);
	set("outdoors", "xiakedao");
	setup();
}
void init()
{
	add_action("do_down", "d");
        add_action("do_down", "down");
	
}

int do_down(string arg)
{
	object me;
	object room;
	me = this_player();
        message_vision("$N从山窟跳了下去。\n", me);

	me->move(__DIR__"yaxia");
	
	return 1;
}


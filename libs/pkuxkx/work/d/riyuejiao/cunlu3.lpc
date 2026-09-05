//cunlu3.c	村中小路
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","村中小路");
	set("long",@LONG 
这是村子中的小路。路边栽着一些柳树。左边是一座柴房，
右边是日月神教的白虎堂，门口站着几个日月教的弟子，不许人
坐卧停留，连看也不许多看一眼。前面守卫更加严密，仿佛是一
处重要所在。
LONG
	);

	set("exits", ([
		"north" : __DIR__"yaxia",
		"south"	: __DIR__"cunlu2",
		"west"	: __DIR__"chaifang2",
            "east"  : __DIR__"baihutang",
	]));
    set("objects",([
		__DIR__"npc/jiaozhong5"	: 1,
		]));
	set("outdoors", "riyuejiao");
	setup();

}

void init()
{
	object room;

	if(!( room = find_object(__DIR__"chaifang2")) )
        	room = load_object(__DIR__"chaifang2");

	if (room->query("fired"))
		{
			set("exits/west",__DIR__"chaifang3");
		}

}

int valid_leave(object me, string dir)
{
    if (!userp(me)&&me->query("zhulou_dizi")&&dir!="north")
	return notify_fail("连柴刀都偷，你也太没品了吧。\n");
        return ::valid_leave(me, dir);
}


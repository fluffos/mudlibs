// 山脚
// gaoshan0.c
// augx@sj 2/27/2002

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","高山脚下");
	set("long",
"这是做极高的山峰，从半山腰起就云雾缭绕，在山顶的悬崖上生长着不少
奇珍异草，还有不少罕见的动物出没。此山是有名的药材产地，常年都有无数
的采药人忙碌其间。
"); 

	set("objects",([
		__DIR__"npc/xunbu" : 2,
	]));
        
	set("exits",([
		"west"		: "/d/chengdu/road1",
		"northup"	: __DIR__"gaoshan1",
		"southup"	: __DIR__"gaoshan2",
		"eastup"	: __DIR__"gaoshan3",
	]));
	
	set("outdoors", "成都郊外");
	set("incity",1);
	setup();
}

int clean_up()
{
	return 1;
}

// Added by mxzhao 2004/03/06
int valid_leave(object me, string dir)
{
	//if (!wizardp(me) && dir != "west")
	if (dir != "west")
	{
		return notify_fail("此地近有猛兽出没，禁止通行。\n\n\t\t成都知府。\n");
	}

	return ::valid_leave(me, dir);
}
// End

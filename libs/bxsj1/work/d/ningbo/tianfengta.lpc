// Room: /u/beyond/ningbo/tianfengta.c 天封塔
// Beyond make 1997.6.8

#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"天封塔"NOR);
	set("long", @LONG
天封塔是宁波城附近最高的建筑物了，凡是到了宁波的文人、名士和游客
总要登上塔顶，一览全城风光，在塔壁上留下不少题咏。
LONG
	);
        set("objects",([
		__DIR__"npc/you" : 1,
        ]));
	set("outdoors", "宁波");
	set("exits", ([
		"north" : __DIR__"shilu",
		"east" : __DIR__"aywsi",
		"south" : __DIR__"ttcsi",
	]));
	setup();
}

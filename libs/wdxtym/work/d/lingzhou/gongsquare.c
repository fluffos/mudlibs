// Room: /lingzhou/gonggate.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "皇宫广场");
	set("long", @LONG
这里就是西夏皇宫广场，南面是一扇宽阔的朱红大门，上面包着拳头大的
铜钉。门的两边站着两排衣甲鲜明的武士，戒备深严。
LONG );
	set("exits", ([
		"south"  : __DIR__"gonggate",
		"east"  : __DIR__"biangate",
		//"west"  : "/d/fuben/xixia/jiaochang",
	]));
	set("no_fight",1);
	set("objects", ([
		__DIR__"npc/gongweishi" : 2,
	]));
	create_door("south" , "红漆宫门", "north" , DOOR_CLOSED);
	setup();

}



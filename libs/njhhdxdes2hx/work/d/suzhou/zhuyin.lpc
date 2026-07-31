// Room: /d/suzhou/zhuyin.c
//by dwolf
//97.11.4 

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", MAG"主营"NOR);
	set("long", @LONG
	这里是主将大营，两边是武将，居中是大将穆桂英。北边是大帐门，南边是
兵器库，一道铁门挡住去路。
LONG
	);

	set("exits", ([
		"south" : __DIR__"wqku",
		"north" : __DIR__"yinzhang", 
		"east" : __DIR__"mapeng",
	]));       
	create_door("north", "bulian", "south", DOOR_CLOSED);
	create_door("south", "铁门", "north", DOOR_CLOSED);

	set("objects", ([
                 __DIR__"npc/mgying" : 1,
                "/obj/npc/wujiang1"+random(3) : 2,
                "/obj/npc/wujiang1"+random(3) : 2,
	]));

	setup();
}


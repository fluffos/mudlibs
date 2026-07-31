// Room: /yaocan-ting.c
// Created by Numa 1999-11-21
// Modify by Lklv 2001.10.19

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"遥参亭"NOR);
	set("long", @LONG
这是一座古色古香的亭台，由青砖整体铺构而成，亭上横卧一匾，上写着
“遥参亭”三个隶书大字。向北边望去，远远能看见那里有一座琉光璃瓦的大
殿，好不壮观。
LONG);
	set("exits", ([
            "north" : __DIR__"tianzhong-ge",
            "south" : __DIR__"shidao1",
        ]));
	set("objects", ([
		CLASS_D("songshan") + "/bu" : 1,
	]));
	set("outdoors", "嵩山");
	setup();
}

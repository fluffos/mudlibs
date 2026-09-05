// Room: /d/quanzhou/yanyu.c
// Date: May 23, 96   Jay

inherit ROOM;

void create()
{
	set("short", "烟雨楼");
	set("long", @LONG
烟雨楼建在南湖中心的一个小岛上。南湖终年不断的水气把它
笼罩得迷迷蒙蒙的。二楼开了一间宴客厅。
LONG
	);

	set("exits", ([
                "up" : __DIR__"yanyu2",
                "north" : __DIR__ "nanhu1",
	]));

	set("outdoors", "quanzhou");
        set("objects", ([
                __DIR__"npc/zhucong": 1,
                __DIR__"npc/hanbaoju": 1,
                __DIR__"npc/hanxiaoying": 1,
                __DIR__"npc/nanxiren": 1,
            __DIR__"npc/xiaoer" : 1]));

	setup();
}


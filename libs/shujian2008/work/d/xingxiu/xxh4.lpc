// Room: /d/xingxiu/xxhh4.c 星宿海
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
        set("short", "星宿海");
        set("long", @LONG
这里是星宿海。因方圆几百里都是一望无际的湖泊和沼泽，当地牧羊人称
之为“海”。也因阴暗潮湿，毒虫繁殖甚富。星宿弟子常来此捕捉毒虫，以备
练毒之用。这里通向星宿海的深处。
LONG);
	set("outdoors", "星宿");
        set("objects", ([
                __DIR__"npc/xxdizi"  : 1,
        ]));
        set("exits", ([
		"east" : __DIR__"xxh2",
		"south" : __FILE__,
		"west" : __DIR__"xxh3",
		"north" : __DIR__"xxh1",
        ]));
        set("outdoors", "xingxiuhai");
	setup();
}
#include "/d/xingxiu/xxh.h";

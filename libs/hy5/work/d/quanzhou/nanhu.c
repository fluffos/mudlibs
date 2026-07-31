// Room: /d/quanzhou/nanhu.c
// Date: May 21, 96   Jay

inherit ROOM;

void create()
{
	set("short", "南湖南岸");
	set("long", @LONG
这里是江南南湖。节近中秋，荷叶渐残，莲肉饱实。一阵轻柔
婉转的歌声，飘在烟水蒙蒙的湖面上。湖边一个道姑在一排柳树下
悄立已久。
LONG );
	set("exits", ([
            "west"      : __DIR__"jiaxing",
            "east"      : __DIR__"jiaxinggang",
            //"south"     : __DIR__"tieqiang",
            "southeast" : __DIR__ "nanhu1",
	]));
	set("outdoors", "quanzhou");
        set("objects", ([
            //__DIR__"npc/limochou" : 1
        ]));
//        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


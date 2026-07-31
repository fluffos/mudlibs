
// Room: /d/snow/mstreet3.c

#include <room.h>

inherit ROOM;

void create()
{
    set("coor",({-70,4770,10}));
	set("short", "宁远城西街");
	set("long",
"这里是宁远城的大街，西边有一栋陈旧的建□，看起来像是什麽店铺，门口上方挂了一块木\n"
"匾，上面写着“林家铺子”四个大字，往南是是一个小楼亭，大街往东西两个方向延伸。\n"
);

	set("exits", ([
        "south" : __DIR__"tfyard",
        "north" : __DIR__"herbshop",
        "east"  : __DIR__"mstreet2",
        "west"  : __DIR__"mstreet4",
	]));
	set("outdoors", "ny");

	setup();



	replace_program(ROOM);
}

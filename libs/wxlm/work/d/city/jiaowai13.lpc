// Room: /d/city/jiaowai13.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "密林");
    set("long", @LONG
扬州郊外的茂密树林，阴森可怖。抬头不见天日。这里也
是扬州命案发生最多的地方。鸟兽蛇虫游荡不穷。
LONG );
    set("exits", ([
	"south" : __DIR__"jiaowai11",
	"east"  : __DIR__"jiaowai12",
    ]));
    set("objects", ([
	CLASS_D("gaibang")+"/mo-bu" : 1,
	__DIR__"obj/shuzhi": 1,
    ]));
//    set("no_clean_up", 0);
    setup();
    //replace_program(ROOM);
}


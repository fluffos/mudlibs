// Room: /d/city/jiaowai2.c
// Jan. 8.1998 by Venus
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "树林");
    set("long", @LONG
扬州郊外的树林，松枝挺拔，乔木横斜。林间小道，逶迤
随远。林中蝉鸣厮闹，鸟啼宛转，使你顿时烦意尽消。
    地上落了很多树枝石块。
LONG );
    set("exits", ([
	"north" : __DIR__"jiaowai1",
	"south" : __DIR__"jiaowai3",
    ]));
    set("objects", ([
	CLASS_D("gaibang")+"/qiu-wanjia": 1,
	__DIR__"obj/shuzhi": 1,
	__DIR__"obj/shitou": 1,
    ]));
//    set("no_clean_up", 0);
    set("outdoors", "yangzhou");
    setup();
    //replace_program(ROOM);
}

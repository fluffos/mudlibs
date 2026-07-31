// Room: /u/beyond/ningbo/ttcsi.c 天童禅寺
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "天童禅寺");
	set("long", @LONG
天童禅寺有“东南佛国”之称。寺庙依地傍山，规模宏大，气势非凡，
寺周群山环抱，古木参天，景色秀丽多姿。寺庙西面的玲珑岩奇石嶙峋，古
木葱茏，山径曲折，流水淙淙，环境十分幽雅。
LONG
	);
	set("exits", ([
	"north" : __DIR__"tianfengta",
        "east" : __DIR__"ningbocheng",
        "southwest" : __DIR__"qsddao2",
        ]));
	setup();
        replace_program(ROOM);
}

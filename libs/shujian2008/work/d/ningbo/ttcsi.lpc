// Room: /u/beyond/ningbo/ttcsi.c 天童禅寺
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"天童禅寺"NOR);
	set("long", @LONG
天童禅寺有“东南佛国”之称。寺庙依地傍山，规模宏大，气势非凡，寺
周群山环抱，古木参天，景色秀丽多姿。寺庙西面的玲珑岩奇石嶙峋，古木葱
茏，山径曲折，流水淙淙，环境十分幽雅。
LONG
	);
	set("outdoors", "宁波");
        set("objects",([
		__DIR__"npc/you" : 1,
        ]));

	set("exits", ([
		"north" : __DIR__"tianfengta",
        	"east" : __DIR__"ningbo",
        	"southwest" : "/d/fuzhou/road1",
        ]));
	setup();
}

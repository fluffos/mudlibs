//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "营盘水");
	set("long", @LONG
这里是当年蒙恬修长城时驻军的地方，蒙恬治军有方，当年他亲自带人在
驻地挖了好几口甜水井，使士卒们不用喝又苦又涩的咸水，后来此地的百姓们
叫这里为营盘水，称这里的井为“蒙恬井”。
LONG );

	set("resource/water", 1);
	set("drink_msg", "$N从蒙恬井中提出一些甜井水，慢慢喝了下去。\n");
	set("exits", ([
		"southwest" : __DIR__"bingcao",
                "east" : __DIR__"gccheng",
	]));

	set("outdoors", "兰州");
	setup();
}

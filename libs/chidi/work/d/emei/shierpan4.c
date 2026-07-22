// Room: /d/emei/shierpan4.c 峨嵋派 十二盘4

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "十二盘");
	set("long", @LONG
这里石阶陡折多弯，号称「十二盘」。由此西上可达华严顶，东下则到万
年庵。
LONG
	);

	set("exits", ([
                "westdown": __DIR__"shierpan3",
                "eastup" : __DIR__"huayanding",
	]));

	set("outdoors", "emei");
	setup();
}

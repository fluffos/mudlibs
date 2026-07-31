// cundaota2.c 存道塔二层

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "存道塔二层");
	set("long", @LONG
这里是存道塔的二层，塔梯绕着塔内向塔顶延伸。这里空空如
也，经书也许全被全真弟子们借去阅读了。
LONG
	);
	set("exits", ([
		"northup" : __DIR__"cundaota3",
		"southdown" : __DIR__"cundaota1",
	]));
	set("no_clean_up", 0);
	setup();
}

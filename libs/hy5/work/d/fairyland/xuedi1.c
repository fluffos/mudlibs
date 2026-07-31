// Room: /u/qingyun/jyzj/xuedi1.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW"雪地"NOR);
	set("long", @LONG
昆仑山由于僻处北疆，山上经常终年积雪。这里的地上白雪皑皑，反光直
刺你的双目。雪地里一行脚印通向北边，看来那边应该有条山路的。
LONG	);
	set("exits", ([
		"north" : __DIR__"shanlu1",
		"southwest" : __DIR__"xuedi",
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

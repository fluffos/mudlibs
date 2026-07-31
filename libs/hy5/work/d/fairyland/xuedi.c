// Room: /u/qingyun/jyzj/xuedi.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW"雪地"NOR);
	set("long", @LONG
昆仑山由于僻处北疆，山上经常终年积雪。这里是一个悬崖的下方，地上
白雪皑皑，反光直刺你的双目。附近有个雪堆(xuedui)。
LONG	);
	set("exits", ([
		"northeast" : __DIR__"xuedi1",
	]));
        set("item_desc", ([
		"xuedui"  : "你一脚踢向雪堆，但见柴草纷飞，原来是农家积柴的草堆，想来附近必有人家。\n"
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

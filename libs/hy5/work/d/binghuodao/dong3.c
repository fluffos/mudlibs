// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "迷洞");
	set("long", @LONG
又湿又潮的一个石洞,还散发着野兽的腥臭.
LONG );
set("exits", ([
		"north" : __DIR__"dong3",
	         "east" : __DIR__"dong2",
"south" : __DIR__"road7",
	        "west"  : __DIR__"dong3",
	]));

        set("outdoors", "binghuodao");
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

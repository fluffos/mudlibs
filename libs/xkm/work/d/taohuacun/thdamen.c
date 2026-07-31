// Room: /d/taohuacun/taohua1.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"桃花村庄门"NOR);
	set("long", @LONG
这里是号称“水米之乡”的江南，风景秀丽，人们生活富足。
出了大道，你发现风景变的秀丽无比，大路开始渐渐变窄，一条
阡陌在你面前隐隐约约消失在桃花林中。高大的桃花村庄门
树立在你面前，也许你厌烦了仇杀、浪迹天涯，开始希望有
个家，来到这里，你的心情开始变的愉快！
LONG );
	set("outdoors", "city");
//	set("no_clean_up", 0);

	set("exits", ([
                "west" : "/d/village/hsroad2",
               "north" : "/d/taohuacun/taohua1",
	]));
	set("objects", ([
		"/d/wudang/npc/bee" : 1,
	]));
	setup();
	replace_program(ROOM);
}


// Room: geup.c
// Made by:pingpang
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"太湖阁"NOR);
	set("long", @LONG
虽说楼底是雾气很大，这里也够迷茫的，你难以看清楚里面到底有些什么。
下面不时传来一阵阵欢笑声和花拳声，还有卖艺女的歌声。
水老板在此正坐在柜台前认真地算帐，时不时地招呼几声客人。
LONG
	);

	set("exits", ([
                "down" : __DIR__"taihuge",
                ]));

	set("outdoors", "guiyunzhuang");
        set("objects", ([
            __DIR__"npc/shui" : 1,
	]));

	setup();
	replace_program(ROOM);
}


// Room: /hangzhou/dongdajie1.c
// hubo 2008/4/19 

inherit "/d/hangzhou/song_room";
#include <ansi.h>
void create()
{
	set("short", HIG"仙林寺"NOR);
	set("long", @LONG
仙林寺是临安府城北最大的一处寺庙。
LONG);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"beijie2",
		//"south" : __DIR__"qianzhuang",
		//"west" : __DIR__"xianlinsi",
		//"north" : __DIR__"beijie3",
	]));

	setup();
	replace_program(ROOM);
}


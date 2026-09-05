// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "厅堂");
	set("long", @LONG
这里是谏院里的一间厅堂，几个谏官正在讨论着什么。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"jianyuanb",
		//"south" : __DIR__"heningxi",
		//"east" : __DIR__"jianyuana",//吏部
		"west" : __DIR__"jianyuan2",//礼部
	]));
	set("objects", ([
    __DIR__"npc/jy_npc1" : 1,
	__DIR__"npc/jy_npc4" : 1,
        ]));  
	setup();
}
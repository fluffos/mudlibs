// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "演武场");
	set("long", @LONG
这里是步军都指挥使司的演武场，几个士兵正在切磋武艺。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"north" : __DIR__"bujundu1",
		"east" : __DIR__"bujundu3",
		"out" : __DIR__"bujundu",
		//"north" : __DIR__"streetn7",//吏部
		"west" : __DIR__"bujundu2",//礼部
	]));
	set("objects", ([
    __DIR__"npc/songbing_b" : 2,
        ]));  
	setup();
}
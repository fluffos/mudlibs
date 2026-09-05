// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "/d/hangzhou/to_song.h"
void create()
{
	set("short", "丽正门");
	set("long", @LONG
这里是皇城大内的南门，再往南就出城了。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"wallb",
		"south" : __DIR__"nanmen",
		"north" : __DIR__"palace/yudao4",
		"west" : __DIR__"wall2",
	]));
	set("dirs_to_song",(["enter":({"dianqian","里","殿前都都指挥使司"}),]));
	set("is_GaTe",1);
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
    __DIR__"npc/songbing_y" : 2,
        ]));
	setup();
	make_entrance();
}
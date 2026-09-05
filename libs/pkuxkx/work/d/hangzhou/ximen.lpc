// Room: /hangzhou/xidajie1.c
// hubo 2008/4/19 
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"
void create()
{
	set("short", "钱塘门");
	set("long", @LONG
这里是钱塘门，西面就是名满天下的西湖了。
LONG);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"xidajie1",
		"west" : __DIR__"xihu/duanjiaqiao",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
    __DIR__"npc/songbing" : 2,
        ])); 
	set("dirs_to_song",(["north":({"majun","北","马军都驻地"}),]));
	set("is_GaTe",1);
	setup();
	make_entrance();
}
// Room: /hangzhou/beidajie1.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"
void create()
{
	set("short", "大理寺");
	set("long", @LONG
这里是大理寺，西面出去是一条窄街通往钱塘门，东门通往东城，御街继续
往东南方向延伸。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "east" : __DIR__"dongdajie4",
                "southeast" : __DIR__"bazi",
                "west" : __DIR__"xidajie1",
                "north" : __DIR__"beidajie1",        
]));
		set("objects", ([
		__DIR__"npc/guanchai" : 1,
        ])); 
    set("building_type","官衙");
	set("dirs_to_song",(["northeast":({"guozijian","东北","国子监"}),"enter":({"dalisi","里","大理寺"}),]));
	setup();
	make_entrance();
}
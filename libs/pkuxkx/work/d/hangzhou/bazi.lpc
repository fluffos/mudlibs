// Room: /hangzhou/beidajie1.c
// hubo 2008/4/19
// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "to_song.h"
void create()
{
	set("short", "八字桥");
	set("long", @LONG
这里是八字桥，横跨小河，御街继续向南延伸。西面是临安府治所。
LONG);
        set("outdoors", "hangzhou");
        set("exits", ([
                "east" : __DIR__"jiulou",
                "northwest" : __DIR__"fengbo",
                "west" : __DIR__"linanfu",
                "south" : __DIR__"nandajie1",        
]));
		set("objects", ([
		__DIR__"npc/maiyi" : 2,
		__DIR__"npc/kanke" : 1,
        ])); 
  set("dirs_to_song",(["east":({"taichangsi","东","太常寺"}),"southeast":({"taiyiju","东南","太医局"}),]));
	setup();
	make_entrance();
}
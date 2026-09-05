// Room: /hangzhou/nandajie1.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/hangzhou/song_room";
#include "/d/hangzhou/to_song.h"
void create()
{
	set("short", "清波门");
	set("long", @LONG
清波门也是临安府门户之一，往西通往西湖。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"xijie",
		"southwest" : __DIR__"xihu/changqiao",
		"northwest" : __DIR__"hubian",
		//"north" : __DIR__"linanfu",
	]));
	set("dirs_to_song",(["west":({"shenwei","西","神卫驻地"}),]));
	set("is_GaTe",1);
   setup();
   make_entrance();
}


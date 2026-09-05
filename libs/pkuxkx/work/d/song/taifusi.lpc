// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "太府寺");
	set("long", @LONG
这里是太府寺的衙门。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"northeast" : "/d/hangzhou/nandajie1",
	]));
	set("objects", ([
          __DIR__"npc/taifu1" : 1,
		__DIR__"npc/taifu2" : 1,
        ])); 
	set("at_hangzhou",1);
	setup();
}
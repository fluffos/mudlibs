// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "太常寺");
	set("long", @LONG
这里是太常寺的衙门。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"west" : "/d/hangzhou/bazi",
	]));
	set("objects", ([
          __DIR__"npc/taichang1" : 1,
		__DIR__"npc/taichang2" : 1,
        ])); 
	set("at_hangzhou",1);
	setup();
}
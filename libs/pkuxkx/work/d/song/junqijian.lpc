// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "军器监");
	set("long", @LONG
这里是将军器监的衙门。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"junqi_ku",
		"northwest" : "/d/hangzhou/nandajie1",
	]));
	set("objects", ([
          __DIR__"npc/junqi1" : 1,
		__DIR__"npc/junqi2" : 1,
        ])); 
	set("at_hangzhou",1);
	setup();
}
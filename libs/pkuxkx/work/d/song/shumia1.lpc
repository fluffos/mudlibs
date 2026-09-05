// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "/d/song/shumi.h"
void create()
{
	set("short", "值房");
	set("long", @LONG
这里是枢密院长官的值房。
LONG
	);
        //set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
//		"north" : __DIR__"shumia2",
		"north" : __DIR__"shumia",
//		"east" : __DIR__"shumi2",//吏部
		//"out" : __DIR__"shumi",//礼部
	]));
	set("objects", ([
          __DIR__"npc/shumishi" : 1,
        ]));
	setup();
}
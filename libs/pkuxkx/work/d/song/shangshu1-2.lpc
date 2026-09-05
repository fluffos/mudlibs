// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "/d/song/meeting.h"
void create()
{
	set("short", "政事堂值房");
	set("long", @LONG
这里是政事堂里右首第一间值房。
LONG
	);
       // set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"south" : __DIR__"shangshu2",
		//"north" : __DIR__"shangshu_path1",
		"west" : __DIR__"shangshu_path1",//吏部
		//"east" : __DIR__"libu2",//礼部
	]));
	set("objects", ([
          __DIR__"npc/canzheng2" : 1,
        ]));
	setup();
}
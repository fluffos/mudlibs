// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
void create()
{
	set("short", "武学院大门");
	set("long", @LONG
这里是武学院的大门，有几个军士在站岗。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		//"west" : __DIR__"yw_1",
		//"east" : __DIR__"yw_2",
		"enter" : __DIR__"wuxue2",//吏部
		"southeast" : "/d/hangzhou/dongdajie4",//礼部
	]));
	set("objects", ([
          "/d/hangzhou/npc/songbing" : 2,
        ])); 
	set("at_hangzhou",1);
	setup();
}
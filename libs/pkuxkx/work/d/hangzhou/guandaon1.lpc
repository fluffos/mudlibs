// Room: /d/suzhou/road1.c
// Date: May 31, 98  Java

inherit ROOM;
#include "/d/hangzhou/to_song.h"
void create()
{
	set("short", "青石官道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆而过。
大道两旁有一些小货摊，似乎是一处集市。南面就是临安府了。
LONG );
	set("outdoors", "hangzhou");
	set("no_clean_up", 0);
    set("no_task",1);
	set("exits", ([
		"south"     : __DIR__"beimen",
		"north" : __DIR__"guandaon2",
		"west" : __DIR__"sitian",
	]));
	setup();
	set("dirs_to_song",(["enter":({"pengriwei","里","捧日卫驻地"}),]));
   setup();
   make_entrance();
}



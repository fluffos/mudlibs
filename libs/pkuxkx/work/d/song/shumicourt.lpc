// Room: /hangzhou/nandajie2.c
// hubo 2008/4/19 

// Zine 2013 to 临安
inherit "/d/song/song_extra_room";
#include <ansi.h>
#include "baoxiao.h"
void create()
{
	set("short", "官厅");
	set("long", @LONG
这里就是一间官厅，东西耳房分别是枢密院承旨、编修办公的所在，北面是
枢密院长官的值房。
LONG
	);
        set("outdoors", "hangzhou");

	set("exits", ([
		//"westdown" : __DIR__"taimiao",
		"north" : __DIR__"shumi2",
		"west" : __DIR__"shumi3",
		"east" : __DIR__"shumi4",//吏部
		"out" : __DIR__"shumi",//礼部
	]));
	
	set("yamen_id","枢密院");
	setup();
}

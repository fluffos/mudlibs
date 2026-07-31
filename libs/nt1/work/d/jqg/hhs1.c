// Room: /u/dubei/u/gumu/jqg/hhs1
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这里是间丈许见方的石室，四面光秃秃的都是石壁。只有一个
小孔射出微弱的光亮。热气蒸腾，让人无法忍受。
LONG
	);

	set("exits", ([
                "out" : __DIR__"hhs",
	]));

        set("objects", ([
		__DIR__"npc/puren" : 1,
	 ]));
	setup();
	replace_program(ROOM); 
}


// Room: /u/dubei/u/gumu/jqg/qzy
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "青芝院");
	set("long", @LONG
这是一间不大的小屋，桌上，柜中满列药罐，壁上一丛丛
的挂著无数乾草药，西首并列三座丹炉，铜迹斑斑，年代久远。
LONG
	);

	set("exits", ([
 
                "north" : __DIR__"st",
	]));
//	set("objects", ([
//		__DIR__"npc/ldr" : 1,
//	 ]));

   
	setup();
	replace_program(ROOM); 
}


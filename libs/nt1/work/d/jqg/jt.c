// Room: /u/dubei/u/gumu/jqg/jt
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "剑潭");
	set("long", @LONG
只见这里壁上、桌上、架上、柜中、几间，尽皆列满兵刃，式
样繁多，其中十之八九都是古剑，或长逾七尺，或短仅数寸，有的
铁口斑驳，有的寒光逼人。
LONG
	);

	set("exits", ([
 
                "north" : __DIR__"sqx",
	]));
 	setup();
	replace_program(ROOM); 
}


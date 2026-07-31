// Room: /u/dubei/u/gumu/jqg/hhs
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "火浣室");
	set("long", @LONG
这是一座烧砖瓦的大窑，越过砖壁，炽热更盛，两名粗工正
在搬堆柴炭，两人上身赤膊，下身只穿一条牛头短裤，兀自全身
大汗淋漓。
LONG
	);

	set("exits", ([
                "west" : __DIR__"zl1",
                "enter" : __DIR__"hhs1",
	]));

        set("objects", ([
		__DIR__"npc/puren" : 1,
	 ]));
	setup();
	replace_program(ROOM); 
}


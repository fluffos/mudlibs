// Room: /u/dubei/u/gumu/jqg/st
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "松堂");
	set("long", @LONG
面前一座三间朝东的白石敞轩，后有古朴的假山叠石。四
周遍植白皮松，两侧是绝壁，只见两名绿衫僮儿手执拂尘，站
在门前。
LONG
	);

	set("exits", ([
                "east" : __DIR__"hc11",
                "northup" : __DIR__"sl1",
                "westup" : __DIR__"sqx",
                "south" : __DIR__"qzy",
	]));
	set("objects", ([
		__DIR__"npc/boy" : 2,
	 ]));

        set("outdoors", "襄阳");
	setup();
	replace_program(ROOM); 
}


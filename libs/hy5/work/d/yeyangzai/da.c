// Room: /open/stst/sazai/da.c

#include <room.h>
inherit ROOM;

void create()
{
	set("short","野羊寨寨主室");
        set("long", @LONG
        这里是野羊寨大寨主的休息室，大寨主文武双全，据说是当年欧阳
锋的左右手，生性心狠手辣，狡猾多端，大理官府和江湖好汉几次围捕都被
他杀出重围。房间里挂满了兵器，一般的寨中弟子都不得到此来打扰。往南
就是大厅了。

LONG

        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dating",
]));
	set("objects",([
		__DIR__"npc/ouyangye":1,
]));

        setup();
        replace_program(ROOM);
}


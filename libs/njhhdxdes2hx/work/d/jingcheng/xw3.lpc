#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", BLK"十字路口"NOR);
	set("long", @LONG
这里是玄武大街和青龙大街的交叉路口。隐隐约约地可以听到西北
方向传来一阵教堂的钟声。从此以北虽还在城内，但管理不善，却
是个危险的去处。近年来从河南来的无业人口大多居于此地。
LONG
	);

	set("exits", ([
 "west"  :__DIR__"xw4",
 "east"  :__DIR__"xw2", 
 "north" :__DIR__"ql1",
 "south" :__DIR__"ql2",
	]));
	set("outdoors", "city");
	setup();
	replace_program(ROOM);
}


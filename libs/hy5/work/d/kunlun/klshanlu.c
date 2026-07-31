// klshanlu.c (kunlun)

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "昆仑山麓");
		  set("long",@long
整个昆仑山脉雪山连绵，冰河垂悬。远望昆仑，有如横卧云彩间的银色玉
龙。每年春天以后，冰雪融化，汇成一股股清澈溪流，流入长江，黄河。
long);
		 set("exits",([
            "northup" : __DIR__"shanmen",
				"east" : __DIR__"shankou",
				"west" : "/d/fairyland/shanlu1",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}

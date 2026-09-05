// Modified by iszt@pkuxkx, 2007-04-20

#include <ansi.h>

inherit ROOM;

void create ()
{
	set("short",HIC"西街"NOR);
	set("outdoors","xiangyang");
	set("long",YEL @LONG
这里是襄阳西街。兵荒马乱的年月，这里早失去了往日的繁华。站在这里只
听得道南道北叮叮当当响个不停，原来是两个打铁铺。这年月，还是手里有个家
伙比较让人放心。
LONG NOR);
	set("exits", ([
		"south":   __DIR__"datiepu1",
		"north":   __DIR__"datiepu2",
		"east" :   __DIR__"xycenter",
		"west" :   __DIR__"xywest2", 
	])); 
	setup();
	replace_program(ROOM);
}
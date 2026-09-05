// Modified by iszt@pkuxkx, 2007-04-20

#include <ansi.h>

inherit ROOM;

void create ()
{
	set("short",HIC"西街"NOR);
	set("outdoors","xiangyang");
	set("long",YEL @LONG
这里是襄阳西街。兵荒马乱的年月，这里早失去了往日的繁华。再往西，就
是襄阳的西门了。
LONG NOR);
	set("exits", ([
		"east" :   __DIR__"xywest2",
		"west" :   __DIR__"wgate", 
	]));
	setup();
	replace_program(ROOM);
}
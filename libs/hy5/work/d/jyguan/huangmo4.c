// huangmo4.c 荒漠
// shamo can to shaqiu
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY "荒漠"NOR);
	set("long",  @LONG
这里四面是茫茫沙海，沙丘起伏，偶尔可以看到些许绿色。在这样的地方
居然还有一条路可依稀辨认，想来是经常有人行走。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([		
                "south" : __DIR__"huangmo5",
                "northeast" : __DIR__"huangmo3",
	]));
	
		
	setup();
	replace_program(ROOM);
}


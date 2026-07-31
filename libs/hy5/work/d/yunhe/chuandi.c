// Room: /d/yunhe/chuandi
// Date: netkill  98/08/18

#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","船底密室" );
    set("long",  @LONG
这是一间船底密室，黑乎乎的，没有一点光亮。
LONG 
    );
	set("exits", ([
		"up" :__DIR__"ship",
			]));
     set("objects", ([
		"quest/weiguo/japan/japan1.c" : 2,
"quest/weiguo/japan/japan3.c" : 1,
	]));   
    set("outdoors", "yunhe");
    setup();
		
}


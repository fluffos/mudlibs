// 密林
// edit: by zine Aug 21 2010

inherit __DIR__"skfroom1";
#include "/d/city/milin.h"
void create()
{
	set("short", "密林");
	set("long", @LONG
这里是一片遮天蔽日的密林，进来之后，你不由迷失了方向。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"milin1",	
		"east" : __DIR__"milin2",	
		"south" : __DIR__"milin1",	
		"north" : __DIR__"milin1",	
		"southwest" : __DIR__"milin2",	
		"southeast" : __DIR__"milin3",	
		"northwest" : __DIR__"milin1",	
		"northeast" : __DIR__"milin2",	
    ]));
	set("no_task",1);
	setup();
	::create();
}

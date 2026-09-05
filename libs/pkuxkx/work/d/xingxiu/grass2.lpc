// 草地
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include "/d/xingxiu/flower.h"
#include <ansi.h>
void create()
{
	set("short", HIG"草地"NOR);
	set("long", @LONG
这里是一片绿油油的青草地，跑着几只小动物。远处是一个小山坡。
LONG
	);
    set("normaldesc", @LONG
这里是一片绿油油的青草地，跑着几只小动物。远处是一个小山坡。
LONG
	);
	set("exits", ([ 
		"east" : __DIR__"grass1",
        "south" : __DIR__"grass7",
        
		
    ]));
    set("outdoors", "xingxiuhai");

	set("objects", ([
        flower:random(2) ,
    ]));
	setup();
	::create();
}


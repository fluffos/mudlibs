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
		"south" : __DIR__"xiaohu",
        "west" : __DIR__"grass",
        "north" : __DIR__"grass4",
        
		
    ]));
    set("outdoors", "xingxiuhai");

	set("objects", ([flower:random(2) ,
    ]));
	setup();
	::create();
}

int valid_leave(object me,string dir)
{  
	if (dir=="south") 
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}

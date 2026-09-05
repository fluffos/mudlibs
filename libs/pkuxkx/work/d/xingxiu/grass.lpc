// 草地
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include "/d/xingxiu/flower.h"
#include <ansi.h>
void create()
{
	set("short", HIG"草地"NOR);
	set("long", @LONG
这里是一片绿油油的青草地，跑着几只小动物。远处是一个小山坡。南面是
一片小湖。
LONG
	);
    set("normaldesc", @LONG
这里是一片绿油油的青草地，跑着几只小动物。远处是一个小山坡。南面是
一片小湖。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"xiaohu",
        "east" : __DIR__"grass5",
        "west" : __DIR__"grass6",
        "northup" : __DIR__"xiaoshanpo",
		
    ]));
    set("outdoors", "xingxiuhai");

	set("objects", ([flower:random(3) ,
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

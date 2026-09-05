// 草地
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include "/d/xingxiu/flower.h"
#include <ansi.h>
void create()
{
	set("short", HIG"草地"NOR);
	set("long", @LONG
这里是一片绿油油的青草地，跑着几只小动物。远处是一个小山坡。北面是
一座被瘴气笼罩的山林。
LONG
	);
    set("normaldesc", @LONG
这里是一片绿油油的青草地，跑着几只小动物。远处是一个小山坡。北面是
一座被瘴气笼罩的山林。
LONG
	);
	set("exits", ([ 
		"southup" : __DIR__"xiaoshanpo",
        "north" : __DIR__"shanlinqian",
        "east" : __DIR__"grass3",
        "west" : __DIR__"grass2",
		
    ]));
    set("outdoors", "xingxiuhai");

	set("objects", ([(__DIR__"npc/squirrel") : 3,
        flower:random(2) ,
    ]));
	setup();
	::create();
}



int valid_leave(object me,string dir)
{  
	if (dir=="north") 
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}
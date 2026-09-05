// 密林
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "老林边缘");
	set("long", @LONG
南边就是南岭了，翻越南岭之后就到了闽南地区，林中极易迷失方向，没事还是
不要轻易尝试。
LONG
	);
	set("exits", ([ 
		"enter" : __DIR__"milin",			
		"northdown" : __DIR__"zhuang",	
		
    ]));
	set("no_task",1);
	setup();
	
}

void init()
{
	this_player()->delete_temp("nlpass");
	return;	
}

int valid_leave(object me,string dir)
{  
	if (dir=="enter")
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}
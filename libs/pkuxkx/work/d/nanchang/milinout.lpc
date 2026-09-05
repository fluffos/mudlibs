// 密林
// edit: by zine Aug 21 2010


#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "老林尽头");
	set("long", @LONG
北面是一片遮天蔽日的老林子，没事还是不要轻易进去。
LONG
	);
	set("exits", ([ 
			
		"enter" : __DIR__"milin",	
		"eastdown" : "/d/hangzhou/shanlu4",	
		
    ]));
    set("no_movecart",1);
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
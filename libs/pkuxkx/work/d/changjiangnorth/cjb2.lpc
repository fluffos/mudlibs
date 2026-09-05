//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江北岸，远远向南望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
             "northwest" : "/d/city/changjiang",
             "southeast" : __DIR__"cjb1",
        ]));
       

        set("no_task",1);

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");

        setup();
}

int valid_leave(object me,string dir)
{  
	if (dir=="northwest")
    {
           return notify_fail("满清鞑子杀过来了，你不要命了？还往上凑？\n");
        
    }
	return ::valid_leave(me, dir);
}



//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "长江岸边");
        set("long", @LONG
这里是长江南岸，远远向北望去，江面被雾色笼罩。
LONG
        );
        set("exits", ([
             "west" : __DIR__"cjn21",
             "northeast" : __DIR__"cjn19",
             "south" : "/d/yueyang/northgate",
        ]));
       

        

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "changjiang");

        setup();
}


int valid_leave(object me,string dir)
{  
	if (dir=="south")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}


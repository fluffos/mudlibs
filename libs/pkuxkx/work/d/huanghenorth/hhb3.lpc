//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河北岸"NOR);
        set("long", @LONG
这里是黄河北岸，滚滚黄河一刻不停地奔腾东去。
LONG
        );
        set("exits", ([
             "east" : __DIR__"dkb1",
             "northwest" : __DIR__"hhb4",
             "northeast" : "/d/beijing/tulupuyang",
        ]));
       
        set("couldfish",1);
        

        //set("objects", ([
        //        "/kungfu/class/xingxiu/zhaixing" : 1,
        //]) );

        set("no_clean_up", 0);
        set("outdoors", "huanghe");

        setup();
}

int rebuild()
{
    this_object()->set("exits/northwest", __DIR__"hhb4");
}

int valid_leave(object me,string dir)
{  
    if (dir=="northeast")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	if (dir=="northwest" &&  random(300)>289)
    {
        this_object()->delete("exits/northwest");
        call_out("rebuild",60);
        return notify_fail(HIY"你正要前行，有人大喝：黄河决堤啦，快跑啊！\n"NOR);
    }
	return ::valid_leave(me, dir);
}


//Zine 25 Nov 2010

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"黄河南岸"NOR);
        set("long", @LONG
这里是黄河南岸，滚滚黄河一刻不停地奔腾东去。
LONG
        );
        set("exits", ([
             "northeast" : __DIR__"hhn17",
             "southwest" : __DIR__"dkn4",
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
    this_object()->set("exits/northeast", __DIR__"hhn17");
}

int valid_leave(object me,string dir)
{  
    
	if (dir=="northeast" && random(300)>294)
    {
        this_object()->delete("exits/northeast");
        call_out("rebuild",60);
        return notify_fail(HIY"你正要前行，有人大喝：黄河决堤啦，快跑啊！\n"NOR);
    }
	return ::valid_leave(me, dir);
}



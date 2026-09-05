// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "浔阳楼");
        set("long", @LONG
这里是一座古朴的小楼，整体格局，浑朴典雅，飞檐翘角，雕梁画栋，气势
非凡。
LONG);
        set("outdoors", "jiangzhou");
        set("exits", ([     
                "east" : __DIR__"tulu1",
                "north" : "/d/changjiang/cjn12",
                "southwest" : __DIR__"eastgate",
                "up" : __DIR__"xunyang2",
                
]));
     
        
   setup();
}

int valid_leave(object me,string dir)
{  
	if (dir=="north")
    {
        if (!userp(me)&&!me->query_temp("rider")&&!me->query("is_trainee"))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}
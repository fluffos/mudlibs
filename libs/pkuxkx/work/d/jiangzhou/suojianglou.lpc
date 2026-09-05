// Zine Nov 26 2010
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"锁江楼"NOR);
        set("long", @LONG
锁江楼位于长江之滨，江州城东北隅，傲然屹立，高耸蓝天，潇洒古朴，伟
岸气昂，塔影锁江，风雅微妙。塔高丈十，造就七层，六面锥状，青砖砌身，石
凿拱顶，宛如撑天大柱突兀江畔。
LONG);
        set("outdoors", "jiangzhou");
        set("exits", ([     
                "north" : "/d/changjiang/cjn11",  
                "southwest" : __DIR__"tulu1",
                "up" : __DIR__"suojiang2",
                
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
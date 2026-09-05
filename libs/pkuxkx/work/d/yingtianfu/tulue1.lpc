//Zine 
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "土路");
        set("long", @LONG
这是一条土路，往西是应天府。往北是一座高山，大明的皇陵就坐落在那里。
LONG
        );

        set("exits", ([
               "west" : __DIR__"chaoyang",
               "eastdown" : __DIR__"tulue2",
               "northup" : __DIR__"neicheng/shanling",

        ]));

        set("outdoors", "yingtianfu");
        setup();
        
}

int valid_leave(object me,string dir)
{  
	if (dir=="east")
    {
        if (!me->query_temp("mingtasks/neigong/start")&&!me->query("mingpin")&&!me->query("ming/tj/pin"))
        {
            return notify_fail("皇陵正在修建，闲杂人等不得入内。\n");
        }
    }
	return ::valid_leave(me, dir);
}

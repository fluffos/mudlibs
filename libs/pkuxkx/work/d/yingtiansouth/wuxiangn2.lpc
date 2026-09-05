inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", CYN"石牛堡"NOR);
        set("long", 
"这里是建康府的东南的石牛堡，西北不远是通济门，再往南就是无想山了。\n"

        );
        set("exits", ([
                
				"northwest" : __DIR__"tongji",
				"south" : __DIR__"wuxiangn2-1",
        ]));
        /*set("objects", ([
		"/d/yingtiannorth/npc/wujiang" : 1,
        "/d/city/npc/bing" : 2,
        
        ]));*/
		set("no_task",1);
        set("outdoors", "yingtianfu");
        setup();
   
}


int valid_leave(object me,string dir)
{
	if (dir=="southup"&&!userp(me))
	return 0;
	return ::valid_leave(me,dir);
}
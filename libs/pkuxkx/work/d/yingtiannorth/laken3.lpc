inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG"湖边路"NOR);
        set("long", 
"这里是清凉门外，南面可以看见一片大湖。\n"

        );
        set("exits", ([
                
				"north" : __DIR__"qingliang",
				"southdown" : __DIR__"laken2",
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
	if (dir=="southdown"&&!userp(me))
	return 0;
	return ::valid_leave(me,dir);
}

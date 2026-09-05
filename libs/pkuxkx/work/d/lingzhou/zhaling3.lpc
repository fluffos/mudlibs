inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "扎陵湖畔");
        set("long", @LONG
这里是扎陵湖畔，西面就深入湖区了。
LONG
        );
        set("exits", ([
          //      "northwest" : __DIR__"huangyangtan",
                "eastup" : "/d/xingxiu/gu4",
        ]));
        set("objects", ([
//                __DIR__"npc/randomnpc" : 1,
        ]));

        set("outdoors", "dalunsi");
		set("no_task",1);
        setup();
        set("no_clean_up", 0);
        setup();
        
}

int valid_leave(object me,string dir)
{
	if (dir=="eastup"&&me->query("family/family_name")!="星宿派")
	return notify_fail(HIM"东面似有一股无形的邪气挡住了你的去路。\n"NOR);
	return ::valid_leave(me,dir);
}

// Room: /city/kedian3.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIG"花圃"NOR);
	set("long", @LONG
这里是一座花圃，不知为何却有几个弟子守卫在这里。北面是一处悬崖。
LONG);


	set("exits", ([
		"east" : __DIR__"zoudao2",
        "northup" : __DIR__"shanpu",
        "enter" : __DIR__"pu",
	]));
    set("outdoors", "jueqinggu");
    set("objects", ([
        __DIR__"npc/huapu-dizi" : 2,
        ]));
	setup();
}

int valid_leave(object me, string dir)
{  
    int i;
    object *all=all_inventory();
    object guard;
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("花圃"))
        {
            guard=all[i];
        }
    }
    if (!guard)
    {
        return ::valid_leave(me, dir);
    }
	if ( dir == "enter" && present(guard, environment(me)) )
	return notify_fail(guard->query("name")+"拦住了你：谷主有令，任何人不得接近情花。\n");
	return ::valid_leave(me, dir);
}
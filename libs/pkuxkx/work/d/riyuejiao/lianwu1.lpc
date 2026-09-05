
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short",HIY"练武场"NOR);
	set("long",@LONG 
这里是一座大练武场，若干日月神教的入室弟子正在刻苦练功。
LONG
	);
	set("exits", ([
        "east" : __DIR__"chengde",
	]));
	set("objects", ([
                __DIR__"obj/jia": 1,
        ]));
    
    set("no_task",1);
	set("outdoors", "riyuejiao");
	setup();
}

void init()
{
    object me=this_player();
	set("no_die",1);
	me->listen_to_die(this_object());
}
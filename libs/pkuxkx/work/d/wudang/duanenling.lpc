// duanenling.c
// by Llin
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "断恩岭");
        set("long",
"岭上是一片树林，大树参天，林中阴阴晦晦，十分寂静。\n"
"林中有一条小道从东面通向山下，小道几被荒草所掩盖，曲曲\n"
"折折的通向树林深处。望过去不知深浅，还是不要去的好。\n"

        );
        set("outdoors", "wudang");

        set("exits", ([
                "eastdown" : __DIR__"jueyigu",
                "westdown" : __DIR__"tyroad11"
        ]));
	set("objects",([
		__DIR__"npc/qiaofu" : 1,
		]));
        setup();
}
int valid_leave(object me,string dir)
{	if(dir=="eastdown" && !me->query_temp("down1"))
		return notify_fail("那条路不知深浅，还是不要去了。\n");
	me->delete_temp("down1");
	return ::valid_leave(me,dir);
}

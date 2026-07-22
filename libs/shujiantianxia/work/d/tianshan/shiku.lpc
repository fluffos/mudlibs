// Room: /d/tianshan/shiku.c
// By Linux

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "石窟");
	set("long", @LONG
这里是一个石窟，常年的酷寒把这个石窟变得如同一个流利宫一样。四周
都是光滑的冰面，几可照人。
LONG);
	 set("exits", ([
                "east" : __FILE__,
		"south" : __FILE__,
		"west" : __FILE__,
		"north" : __FILE__,
        ]));       
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "west") me->add_temp("mark/steps",-1);
	if (dir == "south") me->add_temp("mark/step",1);
	if (dir == "east") me->add_temp("mark/steps",1); 
	if (dir == "north") me->add_temp("mark/step",-1);
	if (me->query_temp("mark/steps") >= 3
	 && me->query_temp("mark/step") <= -7) {
		me->move(__DIR__"shishi");
		me->delete_temp("mark/steps");
		me->delete_temp("mark/step");
		return notify_fail(YEL"你依照姥姥的指示，默念着路径来到一间石室前。\n"NOR);
        }
        return ::valid_leave(me, dir);
}

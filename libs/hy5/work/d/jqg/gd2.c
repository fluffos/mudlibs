// Room: /u/dubei/u/gumu/jqg/gd2
// by dubei
#include <ansi.h> 
#include <room.h>

inherit ROOM;

void create()
{
	set("short", WHT"绝情谷底"NOR);
	set("long", @LONG
只觉阳光耀眼，花香扑鼻，竟是别有天地，他不即爬起，游
目四顾，只见繁花青草，便如同一个极大的花园，然花影不动，
幽谷无人。你又惊又喜，纵身出水，见十余丈外有几间茅屋。
LONG
	);
        set("exits", ([
                "enter" : __DIR__"mw",

        ]));
        setup();
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "tan di" ) return 0;
       if ( !arg ) return 0;
       if (!living(me)) return 0;

       message_vision("$N纵身向寒潭跳了进去。\n", me);
       me->move(__DIR__"ht1");
       tell_room(environment(me), me->name() + "从岸上跳了进来。\n", ({ me }));
       return 1;
}
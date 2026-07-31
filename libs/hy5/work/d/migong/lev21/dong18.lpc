
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"混沌的迷宫"NOR);
	set("long", RED @LONG
这里是混沌的迷宫,似乎是用来避难的地方。然而地
上到处是一堆堆的骨骸与乾掉的血迹。更让人觉得气氛
显得十分的诡异。高大的树木档住了阳光，你什么也看不见了。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}

void init()
{
        add_action("do_use", "use");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire",me)) return 0;
        if( arg=="fire" ) {
        remove_call_out("close");
        call_out("close", 15, this_object());
        message("vision","在火光下，你看清周围的情况了!!\n", me);
        set("long", @LONG
这里是混沌的迷宫,似乎是用来避难的地方。然而地
上到处是一堆堆的骨骸与乾掉的血迹。更让人觉得气氛
显得十分的诡异。在火光下你看清了出路。
LONG
        );
	set("exits", ([
                "west" : __DIR__"dong1"+(random(5)+5),
		"east" : __DIR__"dong1"+(random(3)+7),
		"south" : __DIR__"dong1"+(random(5)+5),
                "north" : __DIR__"dong1"+(random(5)+5),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong19",
                "north" : __DIR__"dong1"+(random(3)+7),
	]));
if (random(3)==1)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(3)+7),
                "west" : __DIR__"dong1"+(random(9)+1),
	]));




           if ( objectp(ob=present("fire", this_player())) )     {
            destruct(ob);
        return 1;
       }
        return notify_fail("你想用什么看情况？\n");
        }
}

void close(object room)
{
        message("vision","不一会儿，火熄灭了。\n", room);
        set("long", @LONG
这里是混沌的迷宫,似乎是用来避难的地方。然而地
上到处是一堆堆的骨骸与乾掉的血迹。更让人觉得气氛
显得十分的诡异。
LONG
);
        room->delete("exits");
}
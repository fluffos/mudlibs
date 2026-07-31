
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"古代遗迹"NOR);
	set("long", GRN @LONG
   这里是个危险的区域，很大且很容易迷路，从不少死里逃生的居民口中
获知这区域内除了一些毒物之外还住著专门猎人头的矮灵族，已经有不少
居民进去之後就没有回来过。高大的树木档住了阳光，你什么也看不见了。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);


         set("objects", ([
"/clone/box/gboxm" : random(2),
              __DIR__"npc/lev4" : random(7),
              __DIR__"npc/player" : random(3),
         ]));
	set("no_clean_up", 0);
	setup();
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
   这里是个危险的区域，很大且很容易迷路，从不少死里逃生的居民口中
获知这区域内除了一些毒物之外还住著专门猎人头的矮灵族，已经有不少
居民进去之後就没有回来过。在火光下你看清了出路。
LONG
        );

	set("exits", ([
		"east" : __DIR__"dong1"+(random(6)+3),
		"south" : __DIR__"dong1"+(random(6)+3),
                "west" : __DIR__"dong18",
                "north" : __DIR__"dong1"+(random(6)+3),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong1"+(random(6)+3),
                "west" : __DIR__"dong18",
	]));
if (random(4)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(3)+7),
                "north" : __DIR__"dong1"+(random(6)+3),
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
   这里是个危险的区域，很大且很容易迷路，从不少死里逃生的居民口中
获知这区域内除了一些毒物之外还住著专门猎人头的矮灵族，已经有不少
居民进去之後就没有回来过。
LONG
);
        room->delete("exits");
}
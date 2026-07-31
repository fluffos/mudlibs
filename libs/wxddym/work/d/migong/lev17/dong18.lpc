
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLK"黑之沼泽"NOR);
	set("long", BLK @LONG
   一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你
必须小心越往东走沼泽的水就越深, 而且你的视线也被雾几乎完全地遮
住了. 这地里你已经无法清楚地看到四周的状况了, 只知道你的脚已经
快深陷於沼泽里了.
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
   一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你
必须小心越往东走沼泽的水就越深, 而且你的视线也被雾几乎完全地遮
住了. 这地里你已经无法清楚地看到四周的状况了, 只知道你的脚已经
快深陷於沼泽里了.在火光下你看到了出路!!
LONG
        );
	set("exits", ([
                "west" : __DIR__"dong1"+(random(5)+5),
		"west" : __DIR__"dong19",
		"east" : __DIR__"dong1"+(random(5)+5),
		"south" : __DIR__"dong1"+(random(5)+5),
                "north" : __DIR__"dong1"+(random(5)+5),
	]));
if (random(4)==0)
	set("exits", ([
		"east" : __DIR__"dong19",
                "west" : __DIR__"dong1"+(random(5)+5),
	]));
if (random(4)==1)
	set("exits", ([
		"east" : __DIR__"dong19",
		"south" : __DIR__"dong1"+(random(5)+5),
                "north" : __DIR__"dong1"+(random(9)+1),
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
   一个黑漆漆的沼泽, 沼泽下似乎有著可怕的生物想把你拖下去, 你
必须小心越往东走沼泽的水就越深, 而且你的视线也被雾几乎完全地遮
住了. 这地里你已经无法清楚地看到四周的状况了, 只知道你的脚已经
快深陷於沼泽里了.
LONG
);
        room->delete("exits");
}
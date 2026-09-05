//mroad7.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是一条小路，两边都种满了茶花。路南边有间小屋，不过门(gate)
是紧锁的。
LONG
    );

    set("exits", ([
		"east" : __DIR__"mroad6",
		"northwest" : __DIR__"mroad8",
    ]));
    
 	set("item_desc",([
		"gate"	: "这是一扇木头门，上面上了把锁头，看来需要匙才能够打开(unlock)它。\n",
 	   ]));

    set("outdoors", "murong");
    setup();

}
void init()
{
	add_action("do_unlock","unlock");
}

int do_unlock()
{
	object me=this_player();
        if (present("gongju key",me) && me->query_temp("murong/gongju"))
	{
		message_vision("$N拿出一把钥匙，在其中的门锁里扭了几下。\n",me);
		message_vision("木门门「吱呀」一声开了，显然小屋是个工具房，里面放满了各种工具。\n",me);
		set("exits/south",__DIR__"mgongju");
		me->delete_temp("murong/gongju");
		return 1;
	}
	else
	{
                 tell_object(me,"你没事进工具房干什么啊？\n");
		return 1;
	}

}

//mbank.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "码头");
    set("long", @LONG
岸上种满了各种各样的茶花，各式各样，倒也好看。湖面上
停了一艘小船(boat)。
LONG
    );

    set("exits", ([
        "west" : __DIR__"mlin1",
    ]));

	set("item_desc", ([
				"boat" :
				"这是一艘小船，看来要从这里出去就要靠他了。",
                     ]));
    
    set("outdoors", "murong");
    setup();

}
void init()
{
    add_action("do_enter", "enter");
}

int do_enter(string arg)
{
    object me;
    me = this_player () ;

	if(arg!="boat")
	{
		message_vision("$N看清楚往哪里钻?\n",me);
		return 0;
	}
    message_vision("\n$N跃上小舟，船就划了起来。\n\n" ,me );
    me->move("/d/murong/dahu") ;
    tell_object(me, "\n小舟在湖中藕菱之间的水路上穿来穿去，$N的眼都花了...\n\n" ) ;
    call_out("waittime", 30 , me ) ;
    return 1 ;
}
void waittime(object me)
{
	tell_object(me, "\n小舟终于划到近岸，$N从船上走了出来。\n\n" ) ;
	me->move ("/d/murong/hubian2") ;
}
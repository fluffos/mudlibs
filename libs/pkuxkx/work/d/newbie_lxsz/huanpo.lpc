// D:\xkx\d\liuxiu-shanzhuang\huanpo.c缓坡
// labaz  2012/10/21.
#include <room.h>
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

int do_climb(string); 
void climb_wait(object);
void climb_finish(object);

void create()
{
    set("short", "缓坡");
    set("long", "这是一段较为平缓的山路，你往山路"+YEL"(path)"NOR+"下一望，吓得缩了回来，\n下面明显较为陡峭。往北走，像是有个集镇，人头攒动。使劲往北望去，\n云山雾罩之下，似乎有户大户人家。\n");

    set("outdoors","liuxiu-shanzhuang");

    set("item_desc", ([
		"path":HIY"这是一段陡峭的山坡，应该可以向下攀爬下去。"+HBBLU+WHT"(climb down)\n"NOR,
        ]));

    set("exits", ([
        "north" : __DIR__"jizhen-xiaodao1",
        ])
     );

    setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("show_quest", "quest");
}

int do_climb(string arg)
{
    object me;
	me=this_player();
	
	if (me->is_busy()) return 0;
	
	if (arg!="down" && arg!="path")
	{
		tell_object(me,"你要往哪里爬？\n");
		return 1;
	}
	else{
		me->start_busy(6);
		call_out("climb_wait",0,me);
		call_out("climb_wait",3,me);
		call_out("climb_wait",6,me);
		call_out("climb_finish",8,me);
		return 1;
	}
}

void climb_wait(object me)
{
	tell_object(me,RED"你小心翼翼的向下爬去。\n"NOR);
}

void climb_finish(object me)
{
	message_vision("$N费了九牛二虎之力，终于爬到了谷底！\n", me);
	me->move(__DIR__"weiminggu");
	me->start_busy(0);
}



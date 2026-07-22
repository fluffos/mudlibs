#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_climb(string arg);
void create()
{
		set("short", WHT"钟乳石洞"NOR);
	set("long", WHT @LONG
 洞顶都是尖尖的钟乳石，四周不停的有水珠滴下。 洞顶有个小洞
爬(climb)上去似乎可以直达地面 。
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong100",
                               	]));
	set("no_clean_up", 0);
	setup();
	}
void init()
{
 add_action("do_climb", "climb");
}
int do_climb(object me)
{
    me= this_player();
    me->move("/d/migong/migong3");
 message_vision(   "$N手脚并用，一会儿功夫就爬出了洞。\n", this_player());
}

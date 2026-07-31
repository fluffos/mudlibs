#include <room.h>
#include <ansi.h>
inherit ROOM;

int do_climb(string arg);
void create()
{
		set("short", RED"熔岩洞"NOR);
	set("long", RED @LONG
    滚烫岩浆不断散发着热气，令人喘不过气来，一些前所
未见的巨大生物在这里走动着。 洞顶有个小洞爬(climb)上去
似乎可以直达地面 。
LONG NOR);
	set("exits", ([
		"east" : __DIR__"dong100",
                               	]));
 set("objects", ([
             "/d/migong/obj/npc1" : random(2),
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

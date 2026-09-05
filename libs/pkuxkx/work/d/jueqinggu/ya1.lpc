// Room: /city/kedian3.c
// YZC 1995/12/04 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", CYN"陡峭山路"NOR);
	set("long", @LONG
这里已是越来越陡，只有手足并用才能爬(climb)上去。
LONG);


	set("exits", ([
		"down" : __DIR__"shanpu",
        //"up" : __DIR__"ya1",
	]));
    set("outdoors", "jueqinggu");
	setup();
}

void init()
{
    add_action("do_pa",({"pa","climb"}));
}

int do_pa()
{
    object me=this_player();
    object room;
    if (me->is_busy())
    {
        tell_object(me,"看你手忙脚乱的，这时候爬不怕摔死吗？\n");
        return 1;
    }
    if (me->query_skill("dodge")<10)
    {
        tell_object(me,"你试了试，这里的陡峭远超你的能力，只好作罢。\n");
        return 1;
    }
    room=load_object(__DIR__"ya2");
    me->add_busy(2);
    tell_room(room,me->query("name")+"费力的攀爬上来。\n");
    me->move(room);
    tell_object(me,"你终于攀上了断肠崖。\n");
    tell_room(this_object(),me->query("name")+"费力的攀爬上去。\n");
    return 1;
}


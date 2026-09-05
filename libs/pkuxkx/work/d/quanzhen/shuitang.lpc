// Room: /u/kiss/quanzhen/qichao.c
// Made by: kiss

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "水塘");
    set("outdoors","quanzhen");
	set("long", @LONG
这里是一片水塘，水塘里可能有鱼。你也可以在这里打水(dashui)。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qichao",
  "north" : __DIR__"fenken",
]));
	set("no_clean_up", 0);
    set("couldfish",1);
	setup();
}

void init()
{
    add_action("do_dashui","dashui");
}

int do_dashui()
{
    object me=this_player();
    object tong;
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (!present("shui tong",me))
    {
        tell_object(me,"你要打水起码要个桶吧？\n");
        return 1;
    }
    tong=present("shui tong",me);
    if (tong->query("is_tong")!=1)
    {
        tell_object(me,"你的水桶在哪？\n");
        return 1;
    }
    if (tong->query("full"))
    {
        tell_object(me,"桶里已经装满水了，不要浪费。\n");
        return 1;
    }
    tong->set("full",1);
    message_vision("$N打起了满满一桶水。\n",me);
    return 1;
}
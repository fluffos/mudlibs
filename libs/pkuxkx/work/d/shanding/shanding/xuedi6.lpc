// File     : xuedi6.c
// Created By   : iszt@pkuxkx, 2006-09-05

#include <ansi.h>
#include "snow.h"

inherit ROOM;

void create()
{
    set("short", HIW"雪地"NOR);
    set("long", @LONG
这里是一片雪地，厚厚的积雪足以没膝,再往南就进入松林深处了。
LONG);

    set("outdoors", "凌霄城");

    set("item_desc", ([
        "snow": (: snow :),
    ]));

  //  set("objects", ([
  //      __DIR__"npc/wolf" : 1,
  //  ]));

    set("exits", ([
        "north" : __DIR__"guangchang",
        "southdown" : __DIR__"songlin",
    ]));

    setup();
}

void init()
{
    add_action("do_look", "look");
    add_action("do_go", "go");
}

int do_look(string arg)
{
    if(arg != "southdown")
        return 0;
    write("那边是一片浓密的松林，什么也看不到。\n");
    return 1;
}

int do_go(string dir)
{
    object me = this_player();

    if(dir != "southdown")
        return 0;
    if(!userp(me))
        return 1;

    message_vision("$N深一脚浅一脚的踏入了松林深处。\n", me);
    call_out("do_move", 1, me);
    me->start_busy(2);

    return 1;
}

int do_move(object me)
{
    object room;

    room = new(__DIR__"songlin");
    me->move(room);
    message_vision("$N方进入此地，惊觉自己已然陷身林海之中，找不到来时的路了！\n", me);

    return 1;
}

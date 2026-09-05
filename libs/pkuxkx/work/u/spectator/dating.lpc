
#include <ansi.h>

inherit ROOM;

int do_search(string);

void create()
{
    set("short","大厅");
    set("long",@LONG
这里是百花谷大厅。
LONG);

    set("no_fight", 1);
    set("objects", ([
        __DIR__"npc/jane" : 1,
        __DIR__"npc/ddk" : 1,
    ]));
    set("exits", ([
        "east" : __DIR__"dongxiang",
        "west" : __DIR__"xixiang",
    ]));

    setup();
/*
    replace_program(ROOM);
*/
}

void init()
{
    add_action("do_search","search");
}

int do_search(string arg)
{
    if (arg != "test")
    {
    message_vision("你要找什么？\n",this_player());
    }
    else
    {
        message_vision("你什么也没有找到？\n",this_player());
    }
    return 1;
}

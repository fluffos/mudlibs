// Room: /d/beijing/hubu2.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED"户部府衙"NOR);
        set("long",
CYN"这里是由原来的大街打了围墙围起来的，东边一带的民房拆了一半，
其余都是新盖的库房，一排排煞是整齐，到处点着“气死风”灯，周围
的衙役就有几十号人，有的守库，有的看门，十分整肃井然。\n"NOR
        );

        set("exits", ([
                "north" : __DIR__"hubuyamen",

        ]));

        setup();
        replace_program(ROOM);
}



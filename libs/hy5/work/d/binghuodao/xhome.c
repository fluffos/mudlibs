// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "Ð»Ñ·¾Ó");
        set("long", @LONG
LONG );
set("exits", ([
 //                "east" : __DIR__"road5",
 "southwest" : __DIR__"mroad3",
        ]));

//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

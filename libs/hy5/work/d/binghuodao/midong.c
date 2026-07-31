// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "迷洞");
        set("long", @LONG
又湿又潮的一个石洞,还散发着野兽的腥臭.
LONG );
set("exits", ([
                "out"   : __DIR__"mdongkou",
        ]));
set("objects", ([
                __DIR__"npc/wuji" : 1,
               __DIR__"obj/fire" : 1,
               "d/lingshedao/obj/mublade" : 1,
        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
//      replace_program(ROOM);
}

//mhuadi1.c
//by hehe
//2003.3.5
//modified Zine 2014/7/16 不限制动作会导致#N个callouts.
#include <ansi.h>
#include <room.h>

inherit ROOM;
#include "plant.h"
void create()
{
    set("short", "茶花地");
    set("long", @LONG
这是小山背后的一片空地，此处甚为阴凉，
是曼陀山庄栽种(zai/zhong/plant)茶花的地方。
LONG
    );

    set("exits", ([
		"west" : __DIR__"mhuadi2",
		"southeast" : __DIR__"mroad4",
    ]));
    
    set("outdoors", "murong");
    setup();

}


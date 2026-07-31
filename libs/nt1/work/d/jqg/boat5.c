// boat5.c 小舟
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","小舟");
        set("long", @LONG
你正身处一叶扁舟之内，舟内狭小异常，最多也就能载二、三个人。你双
手扳桨，慢慢地顺溪而下。
LONG
        );
        set("exits", ([ 
		"out"  : __DIR__"xibian",
        ]));

        set("outdoors","绝情谷"); 
        setup();
}

void init()
{
        call_out("run", 0, this_player());
}

void run()
{
        if (environment(this_player())== this_object())
        message_vision(HIW"\n又划出三四里，溪流曲折，小舟经划过了几个弯后又回到溪边。\n"NOR,this_player());
}

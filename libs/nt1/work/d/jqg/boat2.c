// boat2.c 小舟
// By River 99.5.25
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","小舟");
        set("long", @LONG
你正身处一叶扁舟之内，舟内狭小异常，最多也就能载二、三个人。你双
手扳桨，慢慢地溯溪上行。
LONG
        );
        set("exits", ([ 
		"out"  : __DIR__"xiaoxi",
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
        message_vision(HIW"\n又划出三四里，溪心忽有九块大石迎面耸立，犹如屏风一般，挡住了来船去路。\n"NOR,this_player());
}

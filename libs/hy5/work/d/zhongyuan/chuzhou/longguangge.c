// 楚州龙光阁 /d/city/chuzhou/longguangge.c
// by lala, 1997-12-04

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"龙光阁"NOR);
    set("long", @LONG
龙光阁位于楚州南门外的一座小丘陵上，和城西北的文通塔遥相呼应，相映
成趣。阁分两层，飞檐高挑，下面多植花木，也是楚州士民消闲多去的一个去处。
阁本身虽然不高，但是由于占了地利，所以登阁凭栏一望，还是能看到许多不错
的景致的。
LONG
    );
    set( "no_kill",  "yangzhou" );
    set("exits", ([
        "west"      : __DIR__"nan_men",
        "up"        : __DIR__"longguangge2",
    ]));
    set("objects", ([
    ]));
    setup();
}

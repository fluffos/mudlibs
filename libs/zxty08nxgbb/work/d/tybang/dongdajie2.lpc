#include "/d/tybang/tybang.h";
inherit ROOM;
void create()
{
        set("short", HIR"东大街"NOR);
        set("long", @LONG
你走在东大街上，踩着坚实的青石板地面。东边是东城门，可以听到天
涯第一城的官兵的吆喝声，不由想到第一城就是不同啊。
LONG
        );
        set("outdoors", "city");
        set("exits", ([
                "east" : __DIR__"dongmen",
                "west" : __DIR__"dongdajie1",                
        ]));
        set("objects", ([
        ]));
        setup();
}

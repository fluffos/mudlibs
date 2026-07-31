// /d/kunming/shilin
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "石林" NOR);
        set("long", @LONG
各种形状各异的石头，有的象人，有的象树，有的又象动物，你
这边看着象这样，也许换个角度又象其他的，千姿百态。把你眼睛都
看花了。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "north" : __DIR__"xiaolu1", 
                "southwest"  :__DIR__"shilin1",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}

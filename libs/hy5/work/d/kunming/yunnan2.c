// /d/kunming/yunnan2
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "原始森林" NOR);
        set("long", @LONG
走进原始森林，只见迷迷茫茫全是参天大树，遮天闭日，四周光线
很暗，分不清东南西北，任是谁进来都别想在出去了。幸好当年诸葛亮
入滇时曾开出了一条路。否则，你不被猛兽吃了，也要被毒瘴毒死，所
以还是快离开这里！
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"yunnan3", 
                "north"  :__DIR__"yunnan1",
                
        ]));

             
        setup();
        replace_program(ROOM);
}

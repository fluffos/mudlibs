 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "绸缎庄");
        set("long", @LONG
陈大倌的绸缎庄并不大，但在这种地方，已经可以算是很有气派了。三尺宽的
柜台上堆满了一匹匹鲜艳的绸缎、一套套现成的衣服。店里面两个伙计却显得没精
打采的样子，只希望天快黑，他们在店里虽然是伙计，在家里却是老板。后房的门
敞开着，不过挂着半透明的珠帘，看不清里面的情景。
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"nstreet1",
                "south": __DIR__"road3",
                "north": __DIR__"silkshop2",
        ]));
        set("objects", ([
                __DIR__"npc/huoji":     1,
                __DIR__"npc/pregnant_woman": 1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",190);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}   

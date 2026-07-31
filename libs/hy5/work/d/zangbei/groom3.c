 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "侧房");
        set("long", @LONG
律香川的屋子精致而干净，每样东西都恰好在它应该在的地方，无论在什么地
方都找不出粒灰尘，就象他的衣着一样，整洁、简单、朴素。他憎恶“多余”，从
不做多余的事，从不要多余的装饰，也从不说多余的话。因为多余就是浪费。只有
愚蠢的人才浪费。灯光很亮，但屋子里看来还是冷清清的不像是个家。
LONG
        );
        set("exits", ([ 
                "south" :       __DIR__"garden4",
                "west":         __DIR__"kitchen", 
        ]));
        set("objects", ([
                __DIR__"npc/lv":        1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}      

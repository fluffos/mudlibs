//qianting.c 前厅 

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIC"前厅"NOR);
        set("long", @LONG
厅很大，布置的极有气派，正对厅门是一面屏风，屏风上画的是一片云
雾缭绕的山峰，十分的险恶，看上去有些象华山，可又比华山多了些秀美，
谁也不知道画上所描何处。屏风前是一把高大的紫檀木椅，上面有用紫绒布
做的靠垫，两边墙上挂满了名家书画，除了这些，大厅里没有别的摆设。
LONG
        ); 
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));
        set("exits", ([        
        "northeast" : __DIR__"caodi2",
        "northwest" : __DIR__"caodi1",
        "north" : __DIR__"zoulang1",
        "south" :__DIR__"gate",
        ]));
        
        set("no_death",1);set("bwdhpk",1);

        setup();
}

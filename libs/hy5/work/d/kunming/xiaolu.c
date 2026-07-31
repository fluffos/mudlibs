// /d/kunming/xiaolu
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "小路" NOR);
        set("long", @LONG
一条小路，颇为不平，两边耸立着一些怪石，奇形怪状，甚是有
趣，一直向南去就可以到达昆明了！北去则进入可怕的原始森林.
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "north" : __DIR__"yunnan4", 
                "south"  :__DIR__"xiaolu1",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}

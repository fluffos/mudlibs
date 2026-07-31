//houting 后厅

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIC"后厅"NOR);
        set("long", @LONG
这里是试剑山庄的后厅，屋内非常干净，庄主平时不太喜欢陌生人进入他
的房间，屋子的后面有一扇不起眼的小门，不知道通往何处。
LONG
        );
        set("exits", ([        
        "south" : __DIR__"zoulang2",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
     
        setup();
}


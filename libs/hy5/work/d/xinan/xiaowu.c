
#include <room.h>

inherit ROOM;



void create()
{
    set( "short", "小屋" );
    set( "long", @LONG
一间密林中的破旧的小木屋，看上去已经废弃好久了。周围浓密的林子，几
乎遮盖住了整个木屋，如果不到近处几乎就看不出这间木屋。近来被一帮泼皮，
流氓盘踞着，周围的村民叫苦不叠。
LONG
    );
    set( "exits", ([
        "south"    : __DIR__"milin2",
    ]) );
    set( "objects", ([
        __DIR__"npc/xinghu" : 1,
    ]) );
    setup();
}

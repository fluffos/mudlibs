 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "菊花园");
        set("long", @LONG
一曲长廊环绕著半亩小园，小园中都种著菊花。菊花园里，清水池边，
有几间朴素的轩房。轩外绕著一曲竹篱，与前面华丽精致的建筑大不相称。
竹篱外，掩映著千竿翠竹。廊下悬著一只小小的金铃，随风发出清脆的叮当
声。这里的一切，似乎都与红尘隔绝，显得是那样超然脱俗。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"bookhouse",
  "south" : __DIR__"tang",
]));
        set("objects", ([
        __DIR__"obj/bell" : 1,
        __DIR__"npc/killerbee" : 1,
                        ]) );
        set("outdoors", "palace"); 
        set("coor/x",310);
        set("coor/y",-60);
        set("coor/z",10);
        setup();
}
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("bell", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) && !random(5)) {
        item = new(__DIR__"obj/guo");
        item->move(con);
        }
}     

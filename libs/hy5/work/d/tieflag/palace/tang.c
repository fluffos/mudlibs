 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "轩堂");
        set("long", @LONG
轩堂中一尘不染，窗明几净，四壁堆满了书架，屋角一张琴几，琴旁一
方棋枰。还有几张未完成的画，散乱地堆在另一角的画桌上。门上挂著湘妃
帘，偷过竹帘，可以看见那一洼盛开的菊花。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"juhua",
]));
        set("objects", ([
        __DIR__"obj/desk" : 1,
        __DIR__"npc/laofuren" : 1,
        __DIR__"npc/maid" : 1,
                        ]) ); 
        set("coor/x",310);
        set("coor/y",-70);
        set("coor/z",10);
        setup();
}
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("desk", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv)) {
        item = new(__DIR__"obj/picture");
        item->move(con);
        }
}      

 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "黑石道路");
        set("long", @LONG
往前走向，眼前豁然开朗。丛林已盏，山势渐低。一条黑石道路，笔
直通达下面。通路两旁，排列著一个个翁仲石像！只见这些石像有的骑马
横刀，有的衣甲俱全，俱都雕塑得栩栩如生，须眉宛然。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"stonelin",
  "north" : __DIR__"black",
]));
        set("objects", ([
        __DIR__"obj/stonexiang" : 1,
        __DIR__"npc/ghost" : 3,
                        ]) ); 
        set("outdoors", "palace");
        set("coor/x",160);
        set("coor/y",-10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",-10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",-10);
        set("coor/z",20);
        set("coor/x",160);
        set("coor/y",-10);
        set("coor/z",20);
        setup();
}
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("shixiang", this_object());
   inv = all_inventory(con);
        if( !sizeof(inv)) {
        item = new(__DIR__"obj/guistaff");
        item->move(con); }
}      

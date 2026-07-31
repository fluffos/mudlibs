 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "小山坡西面");
        set("long", @LONG
北面是风云城，天气好时隐隐约约地还可以看到风云城的黑色纶廓。
再向东则是一个光秃秃的小山坡，坡上已被路过的行人踏出了一条黄土
路。路的两边还长了一些半人高的焦黄茅草。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "eastup" : __DIR__"sroad2",
//  "west" : "/d/sharen/zmen",
  "north" : __DIR__"road0",
  "south" : "/d/xinjiang/zhenlong",
]));
        set("objects", ([
        __DIR__"obj/grass" : 1,
                        ]) );
        set("outdoors", "fengyun");
        set("coor/x",10);
        set("coor/y",-430);
        set("coor/z",10);
        set("coor/x",10);
        set("coor/y",-430);
        set("coor/z",10);
        setup();
} 
void reset()
{
object con, item, *inv;
::reset();
if( con = present("grass",this_object()))
if( inv = all_inventory(con))
if( !sizeof(inv))
        {
        item = new(__DIR__"obj/9whip");
        item->move(con);
        item = new(__DIR__"obj/9whip");
        item->move(con);
        item = new(__DIR__"obj/9whip");
        item->move(con);
        item = new(__DIR__"npc/obj/killersword1");
        item->move(con);
        item = new(__DIR__"npc/obj/killersword1");
        item->move(con);
        item = new(__DIR__"npc/obj/killersword1");
        item->move(con);

   }       
}     

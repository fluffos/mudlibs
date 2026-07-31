 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
// #include "/questnpc/lovestory1/event_place.h"
void create()
{
        set("short", "沉香台");
        set("long", @LONG
如果说这里是个广场还不如说这里是个巨大的竹亭，南方
天气酷热，竹林茂盛，这个竹亭居然是天然形成，竹根，竹叶，
和竹杆交织在一起，真是鬼斧神功。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs1",
  "west" : __DIR__"cxw1",
  "south" : __DIR__"cxs2",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-500);
        set("coor/y",-520);
        set("coor/z",0);
        setup();
 
} 
/* int valid_enter(object me)
{ 
        if(me->query("lovestory1"))
                add_trigger_count(me);
        return 1;
}   
*/
 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit ROOM;
void create()
{
        set("short", "绿山坡");
        set("long", @LONG
在这里似乎可以闻到烟雨江南的味道。当年小而精致可爱的沉香
镇已经成为鼎盛繁荣的沉香城，旧年的镇影还是忽隐忽现的。在破晓
前后，天空是灰色的，云层也是灰色的，把整个沉香城全部溶入了这
一片灰潆。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northdown" : __DIR__"road",
  "southwest" : __DIR__"cx0",
]));
        set("outdoors", "chenxiang");
        set("coor/x",-510);
        set("coor/y",-440);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       

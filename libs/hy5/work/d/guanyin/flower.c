 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "花香中");
        set("long", @LONG
走了也不知多久，风中突然传来一阵阵甜蜜的花香。这花香不是牡
丹，不是玫瑰，也不是梅，不是菊......这花香甜蜜得竟非世间所有。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sand",
  "north" : __DIR__"valley",
])); 
        set("outdoors", "fengyun");
        set("coor/x",-1090);
        set("coor/y",50);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}    

 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "巨大的镜子");
        set("long", @LONG
拉起空布幔便露出一面晶莹而巨大的镜子，镜框上镶满了翡翠和珠宝，但
就算这些价值连城的珠宝，也不能掩蔽镜子的光彩，这镜子本身就象是带着神
秘的魔力。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"bedroom",
  "southup" : __DIR__"flower2",
]));
        set("objects", ([
                __DIR__"obj/mirror" : 1,
                __DIR__"npc/mirror_soul" : 1,
       ]) );
        set("coor/x",-1090);
        set("coor/y",70);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}       

// Room: /shenlongjiao/changlang1.c
// kiden 06/08/25

#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short",YEL"长廊"NOR);
        set("long", @LONG
        这里是一道长廊，八名弟子排列两旁，手中各持一把长剑，目光警惕地打量着进出的行人。
LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
                "north" : __DIR__"changlang2",  
                "south" : __DIR__"lianwuchang",                     
                       
        ]));

   set("objects", ([
              __DIR__"npc/dizi1" : 2,
              __DIR__"npc/dizi2" : 2,
              __DIR__"npc/dizi3" : 2,
              __DIR__"npc/dizi4" : 2,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}


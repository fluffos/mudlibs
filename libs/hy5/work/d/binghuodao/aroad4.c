// Room: /guiyun/duchuan.c
// Date: Nov.18 1998 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "山坡");
        set("long", @LONG
小山坡上灌木丛生,偶有小动物,窜来窜去.
在向北山势渐陡,树木丛生.
LONG );
set("exits", ([
                  "south" : __DIR__"aroad3",
                 "northup" : __DIR__"aroad9",        
                // "east" : __DIR__"aroad",
                // "west"  : __DIR__"road6",
        ]));
set("objects", ([
                __DIR__"npc/deer" : 2,
                        ]));
        set("outdoors", "binghuodao");
//      set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

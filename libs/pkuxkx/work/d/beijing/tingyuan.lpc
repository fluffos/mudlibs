// Room: /d/beijing/tingyuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"庭院"NOR);
        set("long",
CYN"面前是一片宽阔的空场，东边用毛竹拚搭成歇山式戏台，好似琼阁仙
台般立在当院，台上文生、武生、花旦、丑角在台上蝴蝶穿花似的穿行，
台前一大片空地上设了许多矮几，给人边看戏边饮茶用的，都密密麻麻
的挤满了人。\n"NOR
        );


        set("exits", ([
                "east" : __DIR__"ludinggong",
                "west" : __DIR__"dating",
                "north" : __DIR__"duchang3",
                "south" : __DIR__"duchang4",
        ]));
 	set("outdoors", "beijing");
        setup();
        replace_program(ROOM);
}



// /d/baituo/jiudian.c
#include <ansi.h> 

inherit ROOM;
void create()
{
        set("short", "酒店");
        set("long",
             "这里是一家独具特色的酒店，由于地处『"GRN"白驼山"NOR"』下，酒店可以\n"
         "供应风味食品－－蛇肉。许多中原来客都爱来这里尝尝鲜，所以酒店\n"
         "生意颇为兴隆。同时，酒店还经营零售散装酒的业务。\n"
        );
        set("exits", ([
                "south" : __DIR__"xijie",
        ]));
        set("objects",([
                __DIR__"npc/xiaoer" : 1,
        ]));
        set("resource/water", 1);
        setup();
        replace_program(ROOM);
}

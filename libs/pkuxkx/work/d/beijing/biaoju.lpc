
// Room: biaoju 镖局大院

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"镖局大院"NOR);
        set("long",
CYN"这里是武胜镖局的大院，青石地面上一尘不染，院内种了不少花草，一片幽
静的气象，与院外的嘈杂形成鲜明的对比。武胜镖局的总镖头，人称「金枪无敌」
的王武通就经常在院内处理镖局事务。\n"NOR
        );

        set("exits", ([
                "south" : __DIR__"wusheng",
        ]));

        set("objects", ([
                __DIR__"npc/wangwutong" : 1,
        ]));

        setup();
        replace_program(ROOM);
}


//wupinfang.c by river
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "物品房");
        set("long", @LONG
这里是武馆的物品房。进屋就看见一个大架子，上面整整齐齐地放满了各
种物品，看来这里的管家是很认真负责的，一些人正在和管物品工具的六弟子
吴坎说着什么。
LONG
        );

        set("exits", ([
                "northwest" : __DIR__"dating",
        ]));

        set("no_fight",1);

        set("objects", ([
                   __DIR__"npc/dizi6" : 1,
        ]));

        setup();
}

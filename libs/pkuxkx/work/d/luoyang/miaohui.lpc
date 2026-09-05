//洛阳，扩展地图
//by kiden
//2006-9-8
//Zine Oct 12 2010
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIC"庙会"NOR);
        set("long", @LONG
这里是洛阳城的庙会，只要你身上有两钱儿，在这里就会受到热情的
招呼。任何你不知道的事，你在这里打听一下，都可以知道个八九不离十。
整个庙会里有货郎，卖肉的，卖玩具的，卖艺的，卖药的，杂耍的，风味
小吃，应有尽有。
LONG
        );

        set("exits", ([
//               "east" : __DIR__"dongdajie2",
//               "west" : __DIR__"center",
//               "north" : __DIR__"miaohui",
               "south" : __DIR__"dongdajie1",  
               "enter" : __DIR__"wumiao",  
        ]));
        set("objects", ([
                __DIR__"npc/randomnpc2" : random(5),
                __DIR__"npc/dian" : 1,
        ]));

        setup();
        replace_program(ROOM);
}

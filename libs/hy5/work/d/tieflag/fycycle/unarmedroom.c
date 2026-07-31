#include <room.h>
inherit ROOM;
void create()
{
        set("short", "拳屋");
        set("long", @LONG
你一走进这屋子，就有一股寒冷之气，扑面而来，此屋中床、几全是石制，
四壁也是用青石所铺，壁上挂着一把铁掌，旁边悬着一个锦囊，石几上放着一些
书籍，最引人注目的是正中有个白玉做的雕像，塑的是一个打拳的道人。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
                "center" : __DIR__"groundroom",
        ])); 
        set("objects", ([
               __DIR__"npc/unarmedbook" : 1,
                        ]));
        set("indoors", "fengyun");
        set("coor/x",-160);
        set("coor/y",50);
        set("coor/z",0);
        set("no_magic",1);
        set("no_spell",1);
        setup();
}       

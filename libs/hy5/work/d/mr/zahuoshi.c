// this is made by beyond
// update 1997.6.20

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"杂货室"NOR);
        set("long", @LONG
这里是曼佗罗山庄的杂货室，里面摆满了各种不用的旧物品，在杂货室
的一角摆放着一个兵器架。
LONG    );
        set("exits", ([ 
                "west" : __DIR__"hhyuan",
                "east" : __DIR__"cl4-5",
        ]));
        set("objects",([
        		__DIR__"obj/jia" : 1,
   		]));
        setup();

}


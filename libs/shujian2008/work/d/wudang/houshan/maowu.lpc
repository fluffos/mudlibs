// /u/dubei/wudang/maowu

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short",HIW+"茅屋"+NOR);
        set("long", @LONG
这里是一间由竹子搭成的茅屋，屋内摆设简朴。西面的墙壁上挂着一幅山
水画，下面一把藤椅上坐着一位老者。傍边一张桌子上摆放了许多书籍。
LONG                           
        );     
        
        set("exits", ([               
                 "north" : __DIR__"taoyuan3",
        ]));

        set("objects",([
                   "/d/wudang/npc/laoweng" : 1,
        ])); 
        setup();
}

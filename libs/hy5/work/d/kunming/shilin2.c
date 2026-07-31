// /d/kunming/shilin2
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "石林" NOR);
        set("long", @LONG
各种形状各异的石头，有的象人，有的象树，有的又象动物，北边
有一座高峰，却甚是象朵莲花，名为：莲花峰。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "northup" :__DIR__"lianhua",
                "east" : __DIR__"shilin1", 
                "southwest"  :__DIR__"qingshilu",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}

//changlang1.c 长廊
inherit ROOM;
#include <ansi.h>
void create()
{
            set("short",HIY"长廊"NOR);
            set("long",@LONG
这是条幽静的长廊，两边均设着红色雕花扶栏，再配以白色的粉墙，显得
十分素雅。尤其是挂在长廊檐下的水晶风玲，在微风的轻抚之下，洒出一阵阵
细碎悦耳的玲声，令人遐思纷飞。此廊北通向花园，南通向后堂。
LONG
    );

            set("exits",([
               "north": __DIR__"huayuan",
               "south": __DIR__"houtang",
               "east": __DIR__"lang2",
               "west": __DIR__"lang4",
            ]));
             
	    setup();
            replace_program(ROOM);
}

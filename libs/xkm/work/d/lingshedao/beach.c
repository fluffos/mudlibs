//Cracked by Roath
//fear 2002 1 31
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", YEL"海滩"NOR);
        set("long", @LONG
一片金黄色的沙滩。这里风平浪静，景色怡人。沙滩上有几个色泽
亮丽光彩的小贝壳。再往西边过去就是灵蛇岛的码头了。
LONG
        );
        set("exits", ([
                "west" : __DIR__"haian",
        ]));

	set("outdoors", "lingshedao");
        set("objects", ([ /* sizeof() == 2 */
        "/d/lingshedao/obj/trumpet" : 1,
        "/d/lingshedao/obj/shell" : 1,
         ]));

	set("cost", 2);
        setup();
	replace_program(ROOM);
}


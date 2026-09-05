//观月阁
// by aiai 98/10/28
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", HIY"观月阁"NOR);
        set("long", @LONG

                 [1;5;35m★[0;1;33m         ︵[0;37m       ☆[1;32m             ★   
           [34m ☆             [33m ）〕 [5;36m          ★                
                         [0;1;33m   ︶     [0;32m         

    此阁无顶。每当深夜，微风袭袭，繁星点点；一轮明月，悬于正央。
放眼眺望，苍穹暗淡，唯阁烛一盏；万物尽淡，唯侠骨豪情。。。
LONG NOR
        );
        set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"yingbinguan",
		"west"  : __DIR__"xiting",
		"east"  : __DIR__"dongting",
		"north" : __DIR__"backyard",

]));
        set("objects", ([
                        ]) );

	set("outdoors","xiakedao");
        setup();
        replace_program(ROOM);
}

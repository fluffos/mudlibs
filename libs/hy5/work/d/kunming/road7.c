// /d/kunming/road7
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "山路" NOR);
        set("long", @LONG
你走在一条崎岖的山路上，再往南，就进入了云贵高原了。北面是一条
大河拦住去路。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
		"south": __DIR__"yunnan",
                "north"  :__DIR__"road6",
                
        ]));

             
       setup();
        replace_program(ROOM);
}

// 谷底
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>

void create()
{
	set("short", YEL"草庐内"NOR);
	set("long", @LONG
一间十分简陋的草庐，你可以在这里简单休息一下。
LONG
	);
    set("objects", ([(__DIR__"obj/hook") : 1,
    ]));
    set("exits", ([
             "out" : __DIR__"gu4",
        ]));
    set("sleep_room", "1");
	set("no_fight", "1");
    setup();
	::create();
}

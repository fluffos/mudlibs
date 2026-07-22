#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "不归崖");
    set("long", @LONG
你仿佛来到了路的尽头,面前白茫茫一片什么都看不清,你正
不知所措之时,脚下踩到了一根藤条(tengtiao),你顺着藤条
小心翼翼的往下看,下面深不见底.让你不知该不该下去看看.
LONG );

    set("exits", ([
        "east" : __DIR__"shandao3",
    ]));
    setup();
    replace_program(ROOM); 
}

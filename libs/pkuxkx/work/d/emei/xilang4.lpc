// Room: /d/emei/xilang4.c 峨嵋派 西廊

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西廊");
        set("long",
"这里是千佛庵西边的过道，过道上很安静。不时能听\n"
"到从走廊两边传来的木鱼声和颂经声。东边是静照师太的\n"
"禅房，西边是静玄师太的禅房。\n"
        );

        set("exits", ([
		"north" : __DIR__"beilang4",
                "south" : __DIR__"xilang3",
		"east" : __DIR__"chfang8",
		"west" : __DIR__"chfang7",
               ]));
        setup();
        replace_program(ROOM);
}

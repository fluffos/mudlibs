// Room: /d/emei/xilang2.c 峨嵋派 西廊

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西廊");
        set("long",
"这里是千佛庵西边的过道，过道上很安静。不时能听\n"
"到从走廊两边传来的木鱼声和颂经声。东边是静真师太的\n"
"禅房，西边是静空师太的禅房。\n"
        );

        set("exits", ([
		"north" : __DIR__"xilang",
                "south" : __DIR__"xilang1",
		"east" : __DIR__"chfang4",
		"west" : __DIR__"chfang3",
               ]));
        setup();
        replace_program(ROOM);
}

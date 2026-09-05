// Room: /d/emei/xicemen.c 峨嵋派 西侧门

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "西侧门");
        set("long",
"这里是千佛庵的西侧门了，这是一个月亮门，不时有\n"
"峨嵋弟子们来来往往。出西侧门后一条小道展现在你眼前\n"
"，沿小道走就到了弟子们练功的草坪。\n"
        );

        set("exits", ([
		"east" : __DIR__"xilang",
		"west" : __DIR__"xiaodao",
               ]));
        setup();
        replace_program(ROOM);
}

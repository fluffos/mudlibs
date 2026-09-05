// Room: /d/emei/xiaodao.c 峨嵋派 小道

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小道");
        set("long",
"这里是西侧门外的小道，连接西侧门和两个练功的草\n"
"坪。不时有小女孩和小尼姑来来往往。\n"
        );

        set("exits", ([
		"northup" : __DIR__"taizi",
		"east" : __DIR__"xicemen",
		"southwest" : __DIR__"leidong",
               ]));
        setup();
        replace_program(ROOM);
}

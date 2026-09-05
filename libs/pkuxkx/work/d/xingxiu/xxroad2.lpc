// Room: /d/xingxiu/xxroad1.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "大道");
	set("long", @LONG
这是一条青石大道。东面隐约可以看到长安城的城墙。北面有座小山丘。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		  "northup" : __DIR__"xxroad3",
//		  "westup" : "/d/pker/shanlu42",
		  "east" : __DIR__"xxroad1",
		]));
	set("outdoors", "xingxiuhai");
	set("no_clean_up", 0);
        setup();
}


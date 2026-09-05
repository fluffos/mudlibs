
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
这里是这座大宅子的大厅，前后通透亮堂，十分气派。
LONG
	);

	set("exits", ([
        "east" : __DIR__"houyuan",
        "west" : __DIR__"tingyuan",
        "north" : __DIR__"xiangfang1",
        "south" : __DIR__"xiangfang2",
	]));
    set("max_contain_items",10);
	setup();
}


#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", "石路");
		  set("long",@long
这是一条铺的十分平整的石板路，路面打扫的干干净净，南面过去
是个花圆，传来阵阵花香，西面是静修室，东面传来些读书声，那里是
书房了。
long);
		 set("exits",([
"north" : __DIR__"qianting",
"south" : __DIR__"huayuan1",
"west" : __DIR__"jingxiushi",
"east" : __DIR__"shufang",
]));
set("outdoors", "kunlun");
setup();
replace_program(ROOM);
}

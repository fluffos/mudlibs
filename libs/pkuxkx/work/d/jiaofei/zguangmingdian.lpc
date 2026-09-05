//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "光明殿");
	set("long", @LONG
这是铁掌峰上的光明大殿。殿内面积之大，已不能用宽敞形容，你抬头向上
看去，屋顶上的画日月交映，巧夺天工。而这么大的屋子却没有半根柱子，但真
让人惊诧。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		  "north" : __DIR__"zhouyuan",
		  "south" : __DIR__"zguangchang",
		]));
 	//set("outdoors", "tiezhang");
    setup();
    replace_program(ROOM);
}

//Create by whuan@pkuxkx
//铁掌帮
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
眼前忽然一亮，此处竟然是一个极大的广场，巨大的青石板无缝相连，几根
石柱冲天而起，上面雕刻着凶神恶煞的鬼面。一排排战旗迎风猎猎，想当年应是
一个阅兵的所在，不意今日却将成为人间地狱。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
		  "north" : __DIR__"zguangmingdian",
		  "south" : __DIR__"zshanlu6",
		]));
 	set("outdoors", "tiezhang");
    setup();
    replace_program(ROOM);
}

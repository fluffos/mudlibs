// Room: /d/beijing/west/lingjing.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"灵境胡同"NOR);
	set("long",
CYN"这是一条十分宽阔的胡同，但却没什么普通百姓来往。南面有
一扇朱漆大门，门口有一对石狮子，守卫相当森严，显然是官宦人
家。西北面是繁华的阜成大街。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"kangqin/door",
// 	"east" : __DIR__"fuyoujie",
	"northwest" : __DIR__"fuchengdajie_s",
]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

// Room: /d/beijing/zijin/yard1.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"玉石通道"NOR);
	set("long",
HIC"这是一条汉白玉石建造的通道,连接着乾清宫和乾清门,通道两
侧栏杆上雕刻着一条条盘旋飞舞的龙.通道下面两侧是两个的小广场。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"qianqingmen",
  	"north" : __DIR__"qianqinggong",
]));
	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

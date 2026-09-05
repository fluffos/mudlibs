// Room: /d/beijing/kangqin/zhongmen.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"中门"NOR);
	set("long",
MAG"这是康亲王府的中门，额枋正中有三宝火焰纹珠。靠额板柱子两侧饰单浮云，
柱顶有望天吼，门楣上透雕二龙戏珠，拱眼雕成圆腹的宝瓶状孔。真是气势非凡。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"dating",
  	"north" : __DIR__"tingyuan",
]));

	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}

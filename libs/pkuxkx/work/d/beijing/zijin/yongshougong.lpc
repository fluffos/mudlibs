// Room: /d/beijing/zijin/yongshougong.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"永寿宫"NOR);
	set("long",
HIC"永寿宫是内廷西六宫之一,也是明清两代后妃居住的宫殿。
黄琉璃瓦歇山式顶，檐里装修，明间前后檐开门，次间、梢间
槛墙、槛窗，双交四棂花隔扇门、窗。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"yushanfang",
  	"west" : __DIR__"taijidian",
  	"east" : __DIR__"tongdao1",
]));

	setup();
	replace_program(ROOM);
}

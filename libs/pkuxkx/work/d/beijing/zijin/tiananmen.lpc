// Room: /d/beijing/zijin/tiananmen.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"天安门广场"NOR);
	set("long",
HIC"雄威壮观的天安门城楼，代表着王朝的强大，疆土的辽阔。各藩
国，各驸属国的使者从四面八方向天安门奔来，带来各国的物产。门
前两个高大雄武的石狮向人们展示着帝国的威姿。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"south" : __DIR__"tianansquare",
 	 "north" : __DIR__"duanmen",
]));
	set("outdoors", "beijing");
	set("objects", ([
                "/clone/npc/camel1":0,
	]));


	setup();
	replace_program(ROOM);
}

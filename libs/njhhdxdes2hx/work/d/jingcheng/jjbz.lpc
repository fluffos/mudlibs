// Room: /d/jingcheng/jjbz.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m贾家灌汤包子铺[2;37;0m");
	set("long", @LONG
贾家灌汤包子由贾氏兄弟三人始创，十多年来也在长安结下了人缘。
提到灌汤包子，长安城里的人都会说贾家的第一。屋里摆设干净，十
几张八仙桌有序排列，挤满了吃客。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"ql2",
  "north" :__DIR__"chuf",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jia" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

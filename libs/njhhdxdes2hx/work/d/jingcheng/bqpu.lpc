// Room: /d/jingcheng/bqpu.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m兵器铺[2;37;0m");
	set("long", @LONG
刚一进门就看到兵器架上摆着各种兵器，从上百近重的大刀到轻如
芥子的飞磺石，是应有尽有。女老板是老英雄萧振远的小女儿，也
是振远镖局二老板，巾帼不让须眉。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"dchjie1",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaoxiao" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

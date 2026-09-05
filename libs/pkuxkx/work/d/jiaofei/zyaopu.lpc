// Room: /city/yaopu.c

#include <ansi.h>
inherit ROOM;

void create()
{
      set("short", HIC"五指山药铺"NOR);
	set("long", @LONG
这是五指山的药铺，正所谓“人在江湖漂，谁能不挨刀”，土匪做
的是刀头舔血的买卖，受伤在所难免，有了地利的优势，这里的买卖
实在是红火的不得了。
LONG
	);

	set("objects", ([
		"/adm/npc/yaopu-laoban" : 1,
	]));

	set("exits", ([
		"north" :__DIR__"zjiedao1",
	]));

	setup();
	replace_program(ROOM);
}

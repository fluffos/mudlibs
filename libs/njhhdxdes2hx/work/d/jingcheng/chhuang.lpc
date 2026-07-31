// Room: /d/jingcheng/chhuang.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[1;37m城隍庙[2;37;0m");
	set("long", @LONG
城隍庙里香火极盛。大多是来保佑家里平安，生意兴隆之类。正中
前方一座白白胖胖，满脸福相的城隍，左边有一位手持帐簿和毛笔
的判官。一位庙祝走前走后，和大家打着招呼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"chhgch",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/miaozhu" : 1,
]));

	setup();
	replace_program(ROOM);
}

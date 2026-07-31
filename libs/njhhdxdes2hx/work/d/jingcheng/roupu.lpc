// Room: /d/jingcheng/roupu.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m荣记肉店[2;37;0m");
	set("long", @LONG
肉铺中亮堂堂的，打扫的也比较干精。肉铺的老板原是行武出身，
也曾跟随将军去西域打过仗。退伍后回长安开了个小肉铺。因人
老实，从不短斤缺两，肉铺的生意也是一日好过一日。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"baih4",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/rong" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

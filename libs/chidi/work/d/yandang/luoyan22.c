// Room: /d/yandang/luoyan22.c

inherit ROOM;

void create()
{
	set("short", "女弟子浴室");
	set("long", @LONG
这里是女弟子的浴室,地上铺的是名贵的玉石,房中摆的是一只大
木桶,热气从水桶中冒出来,细看下,水面上还飘着点点花瓣,不用担心,
此处现在还没有别人.
LONG
	);
	set("bath_room", "1");
	set("no_fight", "1");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"luoyan19",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

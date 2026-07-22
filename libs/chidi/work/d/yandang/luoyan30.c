// Room: /d/yandang/luoyan30.c

inherit ROOM;

void create()
{
	set("short", "闺房");
	set("long", @LONG
这里是小姐的闺房,除了一张红木象牙床之外,仅在窗边摆了一个高
可齐人的大花瓶,里面插了刚摘下来的白菊,从窗户看出去,远处的山,近
处的水,都那么的清晰.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luoyan28",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiaojie.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

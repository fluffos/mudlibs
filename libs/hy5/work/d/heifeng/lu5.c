// Room: /d/heifeng/lu5.c

inherit ROOM;

void create()
{
	set("short", "平坦山路");
	set("long", @LONG
这是半山腰中一段平坦的山路，西面是长满灌木杂草的陡峭
的山坡，路东面是陡峭的山壁，顺着山壁向上望去云雾缭绕中的
山顶隐约可见。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"lu6",
  "south" : __DIR__"lu4",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}

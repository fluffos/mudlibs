// Room: /d/hainan/midao2.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
山腹中的一条密道,十分陡峭,在两边的山壁上时常能看到一些手印.
不知道是谁能在这样坚硬的石头上刻上手印,你十分惊奇.在山道的一头
有一块莲花形状的石头,看来十分光滑.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "石头" : "这是一块莲花形状的山石,由于经常给人搬动的原因,显得十分
光滑,与四周的山石很不一致,不知道你能不能搬动它(push stone).
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"cave5",
  "southdown" : __DIR__"midao1",
]));

	setup();
	replace_program(ROOM);
}

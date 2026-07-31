// Room: /d/lumaji/s_kou.c

inherit ROOM;

void create()
{
	set("short", "鹿马集南口");
	set("long", @LONG
这里就是南村口了，路边树着一个牌子，上面写着“鹿马集”
三个字。方圆几十里内唯一的马市就在村里，所以经常有马贩子
赶着马群向这里来，又从这里去。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : "/d/annan/shulin9",
  "north" : __DIR__"lu10",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}

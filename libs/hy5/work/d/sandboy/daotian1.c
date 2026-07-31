// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "稻田");
	set("long", @LONG
金灿灿的一片稻田,微风轻送,谷浪涟涟,远望去,一片金色,直连到天的
尽头.稻草人手中摇晃着破扇子,守卫着今年的好收成.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1",
  "east" : __DIR__"daotian3",
]));

	setup();
	replace_program(ROOM);
}

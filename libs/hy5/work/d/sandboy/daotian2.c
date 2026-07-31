// Room: /d/sandboy/daotian2.c

inherit ROOM;

void create()
{
	set("short", "稻田");
	set("long", @LONG
金灿灿的一片稻田,微风轻送,谷浪涟涟,远望去,一片金色,直连到天的
尽头.稻草人手中摇晃着破扇子,守卫着今年的好收成.东面有一片晒谷场.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road1",
  "east" : __DIR__"ground",
]));

	setup();
	replace_program(ROOM);
}

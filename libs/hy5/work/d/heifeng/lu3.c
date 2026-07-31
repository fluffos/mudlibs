// Room: /d/heifeng/lu3.c

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是一条崎岖的上山小道，路边的杂草中长满了低矮的灌木，
路上大概是因为经常有人走的缘故却寸草未生，偶尔还能看到一
些马蹄印。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lu4",
  "westdown" : __DIR__"lu2",
]));

	set("outdoors","heifeng");
	setup();
	replace_program(ROOM);
}

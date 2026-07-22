// Room: /d/hainan/haibian.c

inherit ROOM;

void create()
{
	set("short", "海边");
	set("long", @LONG
眼前就是一望无际的大海,身后是陡峭壁立的石壁.不远处的海水
中,一块巨石特别引人注目,上面刻了'天涯海角'四字.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shatan",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yuwen.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

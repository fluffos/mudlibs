// Room: /d/mingjiao/house.c

inherit ROOM;

void create()
{
	set("short", "小木屋");
	set("long", @LONG
这里是一间破烂的小木屋，虽然简陋，可是东西摆放的很整齐，一位老人
    独自坐在屋中。墙上有几张字画（picture)，文字弯弯曲曲，不似中土文字。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "picture" : "你看不懂上面的文字。
",
]));
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaozhen",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/laozhe" : 1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

// Room: /d/menggu/buluo2.c

inherit ROOM;

void create()
{
	set("short", "蒙古包");
	set("long", @LONG
蒙古人以游牧为生,所居住的就是以毛毡所作的帐篷,通常称为蒙古包.
帐篷中堆放了几口箱笼,一边是壶弓箭,蒙人自幼长于马上,弓箭是绝对少不
得的.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhebie.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "southeast" : __DIR__"buluo",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/menggu/shuchi.c

inherit ROOM;

void create()
{
	set("short", "术赤营帐");
	set("long", @LONG
术赤是铁木真的大儿子,他的营帐布置得比较豪华,连挂在壁上的弓箭
都用金漆仔细描过.一张大红的毡子铺在帐幕中间,矮几上的金杯装满了血
色的葡萄酒.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shuchi.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}

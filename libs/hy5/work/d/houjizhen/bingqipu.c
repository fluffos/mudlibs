// bingqipu.c
// by dicky

inherit ROOM;

void create()
{
	set("short", "兵器铺");
	set("long", @LONG
这是一间非常常见的兵器铺，由于现在天下并不太平，所以兵器铺
的生意比较火热，但是这里却显得非常的冷清。只是偶尔有人匆匆忙忙
买两样东西，后又匆匆忙忙离开。虽然这里生意不好，但是这里东西质
量倒蛮不错。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"shilu3",
]));

	set("objects", ([
		__DIR__"npc/weaponboss.c" : 1,
	]));

	setup();
	replace_program(ROOM);
}

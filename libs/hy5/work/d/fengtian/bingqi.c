// Room: /d/fengtian/bingqi.c

inherit ROOM;

void create()
{
	set("short", "兵器铺");
	set("long", @LONG
这原来是一家铁匠铺，后来由于战时为部队打造了很多兵器
，就干脆变成了兵器铺，如果你可以找到玄铁这里是可以给你打
造神兵的地方。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ll3",
]));

	set("objects",([
	__DIR__"npc/weaponboss" : 1,
]));

	setup();
	replace_program(ROOM);
}

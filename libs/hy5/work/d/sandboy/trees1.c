// Room: /d/sandboy/trees1.c

inherit ROOM;

void create()
{
	set("short", "杂树林");
	set("long", @LONG
一片斑驳的杂树林,许多树叶在秋风下飘落,在林中铺了厚厚的一层,长
着尖刺的灌木丛稍不留神就容易划破衣衫.在树林的深处时不时传来两声古
怪的鸟鸣,让人听了心惊胆战.向东是一片草地.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"trees2",
  "east" : __DIR__"turf",
]));

	setup();
	replace_program(ROOM);
}

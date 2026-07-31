// Room: /d/yanjing/road1.c

inherit ROOM;

void create()
{
	set("short", "鹅卵石小道");
	set("long", @LONG
这是穿插于花木之间的一条小道,用五色石子细细的铺成花纹,一缕
幽香在花木间飘浮,贴近地面的地方一层白雾把地面遮挡了起来.西面是
王府中院,东北面露出廊檐一角.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "southwest" : __DIR__"road",
  "north" : __DIR__"gardon2",
  "west" : __DIR__"gardon1",
  "northeast" : __DIR__"lack",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}

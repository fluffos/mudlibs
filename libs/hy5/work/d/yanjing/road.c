// Room: /d/yanjing/road.c

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
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/binu.c" : 1,
  __DIR__"npc/puren.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhongyuan",
  "northeast" : __DIR__"road1",
]));
	set("outdoors", "yanjing");

	setup();
	replace_program(ROOM);
}

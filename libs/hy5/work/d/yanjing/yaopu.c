// Room: /d/yanjing/yaopu.c

inherit ROOM;

void create()
{
	set("short", "回春药铺");
	set("long", @LONG
三开间的门面,一边竖着的金字招牌"回春堂",一个紫金小药葫芦在牌
匾下摇摇晃晃,店堂中一溜长的柜台,几杆小药称摆在柜台之上,后面是高
高的药柜,一个个小巧的抽屉中是各类中药材.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhaosanqian.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"street1",
]));

	setup();
	replace_program(ROOM);
}

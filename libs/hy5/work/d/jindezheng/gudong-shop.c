// Room: /d/jindezheng/gudong-shop.c

inherit ROOM;

void create()
{
	set("short", "藏珍阁");
	set("long", @LONG
藏珍阁的老板端木良庸,是武林中有名的端木世家的人,至于为何到 
此开了这么个店铺,谁都不知道,店铺中除了一张半人高的柜台之外,沿墙 
摆着的都是高及屋顶的红木柜子,上面都是大小不一的抽屉. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"street3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/duanmu.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/xiangyang/dangpu.c
// Date: by jason(残叶) Tue May  1 18:34:30 2001
inherit F_HOCKSHOP;

void create()
{
	set("short", "襄阳当铺");
	set("long", @LONG
这里是襄阳的当铺，兵荒马乱的，很多穷苦人家把自己的东西都典当过来了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		  "south" : __DIR__"xywest2",
		]));
    set("objects",([
   __DIR__"npc/shichunqiu":1,
]));
	set("no_clean_up", 0);
	unique_id=4;
	setup_shop();
	setup();
}

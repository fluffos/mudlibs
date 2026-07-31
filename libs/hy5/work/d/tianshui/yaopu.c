// Room: /u/xiaozhen/yaopu.c

inherit ROOM;

void create()
{
	set("short", "王记药铺");
	set("long", @LONG
这里天水镇的药铺，一走进来一股浓重的中药香扑鼻而来。
药铺的掌柜王济世是这一带的名医，镇子里的居民有个病都来找
他。据说王家祖上传下了一部药典，所以这里卖的药都药到病除，
生意非常好，有人还从关内不远千里来到这里采购药品。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"eroad3",
]));
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/jishi" : 1,
	__DIR__"npc/ywaiter" : 1,
]));
	setup();
	replace_program(ROOM);
}

// Room: /open/dt/kongzici.c

inherit ROOM;

void create()
{
	set("short", "孔子祠");
	set("long", @LONG
这里是一座颇为古老的孔子祠，原本涂成红色的墙壁已经斑驳
不堪了，院中一株上百年树龄的古柏肆意的伸展着它的枝桠，零乱
的树叶在青石板上洒下片片阴影。祠中香火鼎盛，不时有一两个读
书人在祠中的孔圣像前顶礼摩拜。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"huaandao3",
]));

	setup();
	replace_program(ROOM);
}

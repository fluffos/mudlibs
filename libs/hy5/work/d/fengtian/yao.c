// Room: /d/fengtian/yao.c

inherit ROOM;

void create()
{
	set("short", "药店");
	set("long", @LONG
药店柜台后面的伙计正忙着给客人抓药，帐房先生带个眼镜
在看帐本，墙上挂着牌子上面有各种药材的价格，柜台外面还有
个小伙计在碾刚刚凉好的药材。
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"kd5",
]));

	set("objects",([
	__DIR__"npc/huoji.c" : 1,
	__DIR__"npc/doctor" : 1,
]));

	setup();
	replace_program(ROOM);
}

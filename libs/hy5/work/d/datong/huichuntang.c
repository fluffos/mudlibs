// Room: /open/dt/huichuntang.c

inherit ROOM;

void create()
{
	set("short", "回春堂");
	set("long", @LONG
走进这里，一股刺鼻的药香使你稍微觉得有点不舒服，迎面
是一张大柜台，十来个人正排队等候抓药。旁边一张木床上躺着
一位病人，一个六七十岁的老大夫正在把一根根银针刺在病人的
穴道里。原来这里不光卖药材，而且也给一些急症病人诊治。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"youfujie3",
]));

	set("objects",([
	__DIR__"npc/huiboss" : 1,
]));

	setup();
	replace_program(ROOM);
}

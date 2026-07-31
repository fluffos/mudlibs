// Room: /d/tianshui/eroad3.c

inherit ROOM;

void create()
{
	set("short", "小镇东街");
	set("long", @LONG
这条街道熙熙攘攘，操着南腔北调的行人来来往往，很多人
向西边的广场走去。北面是一家杂货铺，南面是一家药房，镇里
的人生病都来这里抓药。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"zahuopu",
  "west" : __DIR__"eroad2",
  "south" : __DIR__"yaopu",
  "east" : __DIR__"ekou",
]));
	set("outdoors","tianshui");

	set("objects",([
"/clone/npc/man" : 2,
]));

	setup();
	replace_program(ROOM);
}

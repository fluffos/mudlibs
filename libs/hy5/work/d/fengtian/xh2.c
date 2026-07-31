// Room: /d/fengtian/xh2.c

inherit ROOM;

void create()
{
	set("short", "新汇路");
	set("long", @LONG
新汇路是盛京北城比较繁华的一条街道，这里聚集了不少北
方的店铺，还有很有东北特色的茶馆，路边还有一些小贩，贩卖
由长白山上采的草药，有时您还真能买到不少好东西。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shenwu",
  "south" : __DIR__"xh1",
  "east" : __DIR__"mofang",
  "north" : __DIR__"xh3",
]));
        set("outdoors", "fengtian");

	set("objects",([
"/clone/npc/man" : 3,
]));

	setup();
	replace_program(ROOM);
}

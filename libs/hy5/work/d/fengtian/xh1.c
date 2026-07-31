// Room: /d/fengtian/xh1.c

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

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"cross",
  "east" : __DIR__"chaguan",
  "north" : __DIR__"xh2",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}

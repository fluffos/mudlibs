// Room: /open/dt/mafang.c

inherit ROOM;

void create()
{
	set("short", "马房");
	set("long", @LONG
这里是大同城里存放马匹的地方。因为在客店里放马很不方
便，所以大家都把马匹存放在这里由马夫统一管理。现在这里寄
存了十几匹毛色各异的马，一个马夫正在给其中一匹马洗澡，这
匹马毛色纯白，一看就知道是一匹神驹。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu2",
]));

	set("objects",([
	"/d/city/npc/mafu" : 1,
]));

	setup();
	replace_program(ROOM);
}

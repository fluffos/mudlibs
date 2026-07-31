// Room: /open/dt/minju2.c

inherit ROOM;

void create()
{
	set("short", "民居");
	set("long", @LONG
这是一户颇为富裕的人家，对着门的墙上挂着几串通红的代
县辣椒，院子边角围了一个小园地，里面种着几十株稷山板枣。
院子里没有人，几只鸡却因为你的到来不安地来回巡逡，不时咯
咯地叫上几声。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luzhuxiang3",
]));

	setup();
	replace_program(ROOM);
}

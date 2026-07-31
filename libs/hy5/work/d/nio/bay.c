// Room: /u/jpei/thd/bay.c

inherit ROOM;

void create()
{
	set("short", "小渔港");
	set("long", @LONG
这里是海边的一个小渔港，附近唯一可以出海的地方就是这里了。正要出
海的渔民忙碌地来来往往，一个船老大摸样的人正在拼命呼喝着在船上做帮工
的渔家孩子。
LONG
	);
	set("no_clean_up", 0);

	set("outdoors","nio");

	set("exits", ([
		"west": __DIR__"hbroad.c",
	]) );

	setup();
	replace_program(ROOM);
}

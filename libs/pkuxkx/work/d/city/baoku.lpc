// Room: /city/baoku.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "宝库");
	set("long", @LONG
这里是扬州城中的一个宝库。小侠杨过忠告你：不是自己的东西最好不要乱
拿，小心天打雷劈。墙上有块金牌(jinpai)。
LONG);
	set("no_beg",1);
  set("no_fight",1);
	set("no_perform",1);
	set("item_desc", ([
                "jinpai" : "举报信箱∶admin@pkuxkx.com\n",
	]));

	set("exits", ([
		"out" : __DIR__"guangchang",
	]));

	setup();
	replace_program(ROOM);
}

// Room: /d/suzhou/qianzhuang.c

inherit ROOM;

void create()
{
	object ob;
	set("short", "当铺货仓");
	set("long", @LONG
当铺的货仓，所有东西都在这，你不应当出现在这儿。
LONG
	);
	set("no_clean",1);
	setup();
}

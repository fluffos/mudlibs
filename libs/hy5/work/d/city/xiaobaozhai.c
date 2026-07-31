// Room: /city/xiaobaozhai.c

inherit ROOM;

void create()
{
	set("short", "小宝斋");
	set("long", @LONG
抚远大将军挂官出逃后，带了七个老婆，躲在这里偷偷开了这个
小宝斋。卖些当年带回来的金银珠宝，收购一些古董倒卖，着实发了
不少横财。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("objects", ([
		"/quest/weixiaobao" : 1,
	]));

  set("roomif","$botten#任务|交工|取消任务:quest|give <物品> to wei|give 20 silver to wei$#");

	set("exits", ([
		"down"   : __DIR__"dangpu",
	]));

	setup();
	replace_program(ROOM);
}


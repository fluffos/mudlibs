// Room: /d/xiangyang/chaguan.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "茶館");
	set("long", @LONG
你一走進來，就聞到一股茶香沁入心脾，精神為之一爽。
幾張八仙桌一字排開，坐滿了客人，或高聲談論戰局，或交頭
接耳元兵勢大。你要想打聽什麼，恐怕不是時候。
LONG );
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("exits", ([
		"west" : __DIR__"northjie",
	]));
	set("coor/x", -500);
	set("coor/y", -460);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
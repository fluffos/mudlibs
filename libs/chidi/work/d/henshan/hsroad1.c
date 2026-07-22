// Room: /d/henshan/hsroad1.c 黄土路
// Modified By Jave Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里向北通往
扬州，往南就进入湖南地界了。
LONG );
        set("outdoors", "henshan");

	set("exits", ([
		"northdown" : "/d/wudang/wdroad4",
		"southeast" : __DIR__"hsroad2",
	]));

        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


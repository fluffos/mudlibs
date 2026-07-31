// wdroad1.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，人来人往非常繁忙，不时地有人骑着马匆匆
而过。大道两旁有一些小货摊，似乎是一处集市。北边通向扬州城。东南
是一大片树林。
LONG );
        set("outdoors", "wudang");
	set("exits", ([
		"south"     : __DIR__"wdroad2",
		"north"     : "/d/city/nanmen",
	"west" : "/d/bawang/xinghuacun",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


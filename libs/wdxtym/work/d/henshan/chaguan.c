// Room: /d/henshan/chaguan.c
inherit ROOM;

void create()
{
	set("short", "衡阳茶馆");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字
排开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，
这里是个好所在。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"north" : __DIR__"hengyang",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
}


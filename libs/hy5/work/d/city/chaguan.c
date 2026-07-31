// Room: /city/chaguan.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "春来茶馆");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙桌一字
排开，坐满了客人，或高声谈笑，或交头接耳。你要想打听江湖掌故和谣言，
这里是个好所在。请用(help tea)来查询茶的含义和资料
LONG );
	set("resource/water", 1);
//	set("no_clean_up", 0);
	set("exits", ([
		"east" : __DIR__"nandajie2",
		"west" : __DIR__"huadian2",
	]));

set("roomif","$botten#查看|购买|疗伤|行医|学医:list|buy <物品选取>|ask ye about heal|ask ye about 银针|give 20 silver to ye$#");
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
//		"d/pingan/npc/wang" : 1,	
		"d/pingan/shenzhen/npc/shenyi" : 1,	
		//"/quest/newbie/qiandao/yuexm" : 1,	
	]));
	setup();
	replace_program(ROOM);
	"/clone/board/player_b"->foo();
}


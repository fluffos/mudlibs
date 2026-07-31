// /d/city/dongting.c
// this is made by beyond
// update 1997.7.4
inherit ROOM;     

void create()
{
	set("short", "东厅");
	set("long", @LONG
这里是衙门东厅，是知府待客的所在。厅中摆着一张杉木圆桌图刚椅子，
桌上是一套精致的宜兴瓷器。墙上挂着一幅中堂，画的是百鸟朝奉图，内行人
一看就知是唐寅的手笔。
LONG);
	set("no_fight", 1);
	
	set("exits", ([
		"west" : __DIR__"ymzhengting",
	]));

	set("objects", ([
        __DIR__"npc/zhang" : 1,
	]));

	set("incity",1);
	setup();
}


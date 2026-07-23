inherit ROOM;

void create()
{
	set("short", "翠微阁");
	set("long", @LONG
你一走进来，就闻到一股茶香沁入心脾，精神为之一爽。几张八仙
桌一字排开，坐满了客人，或高声，或交头接耳。
LONG );
	set("resource/water", 1);
	set("exits", ([
		"southeast" : __DIR__"beishi",
	]));
	set("objects",([
	__DIR__"npc/xiaoer":1,
	]));
	setup();
	replace_program(ROOM);
}


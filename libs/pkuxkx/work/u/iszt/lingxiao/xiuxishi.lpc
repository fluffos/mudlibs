// File		: xiuxishi.c
// Created By	: iszt@pkuxkx, 2006-08-16

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这里是雪山派男弟子休息的地方。也许是有意磨炼其心志，房间里竟没有火
炉，只在床铺上整齐地铺着厚厚的被褥，以供御寒。再往里是静修室，没事还是
不要去打搅的好。你找到自己的铺位，准备躺下睡觉。
LONG);

	set("indoors", "凌霄城");
	set("no_fight", 1);
	set("exits", ([
		"south" : __DIR__"stonen1",
		"north" : __DIR__"jingxiushi",
	]));

	setup();
	replace_program(ROOM);
}
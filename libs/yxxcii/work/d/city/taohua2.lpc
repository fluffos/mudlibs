// taohua2.c
// Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "桃花溪");
	set("long", @LONG
“桃花林畔桃花溪，桃花溪水清如洗。浪子浮云空相照，浣衣歌女梦
依稀。”这里就是桃花溪岸长草小径。桃花开有花落时，桃花落时，片片
飞红空坠溪中，流水送去，决无怜惜。你伶立溪上，睹物思人，伤情无限。 
LONG );
	set("outdoors", "city");
	set("exits", ([
		"westup" : __DIR__"taohua3",
		"south"  : __DIR__"taohua1",
	]));
	setup();
	replace_program(ROOM);
}


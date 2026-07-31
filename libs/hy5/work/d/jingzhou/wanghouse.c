// Room: wanghousemen
// congw 980830

inherit ROOM;

void create()
{
	set("short", "大门");
	set("long", @LONG
一座富丽堂皇的大宅院出现在你的眼前，两头高大的石狮子镇住了大门两侧，朱漆
大门足足有三寸厚。门上挂着两个灯笼，写着“万府”两个金漆大字。
LONG
	);

	set("exits", ([
		"south" : __DIR__"xidajie1",
		"north" : __DIR__"dayuan",
	]));

	setup();
	replace_program(ROOM);
}


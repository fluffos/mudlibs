// Room: /d/taishan/fefe6.c
// Date: ERIC 96/9/23

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
这里是装潢华丽的卧室，从外表绝对看不出这座茅屋里还有
如此花哨的一个地方，床上零零落落的到处都是用过的衣服
和其他东西，却不见有人在。
LONG
	);

	set("exits", ([
		"north" : __DIR__"fefe3",
		"west" : __DIR__"fefe5",
		"south" : __DIR__"fefe9",
	]));

	set("outdoors", "taishan");
	setup();
	replace_program(ROOM);
}


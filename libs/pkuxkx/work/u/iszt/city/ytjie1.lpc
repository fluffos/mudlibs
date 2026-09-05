// Room: /city/yuntaijie1.c
// 云台街：酒馆，小吃店

inherit ROOM;

void create()
{
	set("short", "云台街");
	set("long", @LONG
这一条街道本来是很冷清的，但因为最近扬州的商业繁荣，忽然间也就热闹
了起来。北边是一家酒铺，酒铺中飘出阵阵酒香，南边是一家小吃店，店里的小
吃是全扬州数一数二的。东边则是妇女们经常光顾的沈记衣店和谢记鞋帽店。
LONG);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"ytjie2",
		"south" : __DIR__"xiaochidian",
		"west" : __DIR__"nandajie3",
		"north" : __DIR__"jiuguan",
	]));

	setup();
}
// Room: /city/yuntaijie3.c
// 云台街：茶馆，水果店

inherit ROOM;

void create()
{
	set("short", "云台街");
	set("long", @LONG
这一条街道本来是很冷清的，但因为最近扬州的商业繁荣，忽然间也就热闹
了起来。北边是一家出售各种茶叶的茶叶店，南边是一家供应鲜花的花店，老板
好象是一位漂亮姑娘。西边传来阵阵讨价还价的声音。东边就到了街的尽头，但
是最近开了一家房产经销公司，人来人往，很是热闹！ 
LONG);
        set("outdoors", "city");

	set("exits", ([
		"east" : __DIR__"fangchan",
		"south" : __DIR__"chadian",
		"west" : __DIR__"ytjie2",
		"north" : __DIR__"huadian",
	]));

	setup();
}
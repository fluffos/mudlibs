// Room: /open/dt/xiaojiuguan.c

inherit ROOM;

void create()
{
	set("short", "小酒馆");
	set("long", @LONG
这是一家很小的酒馆，店里只有三四张桌子，店主人叫老张
头，家住附近的绿竹巷里。店里除了卖酒，也供应一些烤肉小菜，
价格非常便宜，这条街上的摊贩中午的时候都到这里来喝两杯，
所以生意还不错，但老张头却好像没有打算把门面再扩大一点。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu1",
]));

	setup();
	replace_program(ROOM);
}

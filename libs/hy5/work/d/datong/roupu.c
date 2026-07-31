// Room: /open/dt/roupu.c

inherit ROOM;

void create()
{
	set("short", "肉铺");
	set("long", @LONG
肉铺的主人郑万屠曾经夸口说，他的肉铺除了人肉和蚊子肉
不卖以外，其它什么肉都有得卖。虽然夸张了一点，但他卖的肉
品种还真是不少，什么猪肉牛羊肉就不用说了，像獐子肉、免肉、
鸡鸭肉、狗肉、熊肉熊掌等等是应有尽有。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"huayanlu4",
]));

	setup();
	replace_program(ROOM);
}

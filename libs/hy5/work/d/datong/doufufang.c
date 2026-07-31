// Room: /open/dt/doufufang.c

inherit ROOM;

void create()
{
	set("short", "豆腐坊");
	set("long", @LONG
大同本地人是不吃豆腐的，只因为近来到此地的外地人很多，
于是这儿就开了一家豆腐店，店主人于三嫂的豆腐又软又嫩，于是
很多本地人也慢慢喜欢起豆腐来。城里的几家酒楼和居民们都到这
里来订豆腐，于三嫂的生意也慢慢的好了起来。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huaandao3",
]));

	setup();
	replace_program(ROOM);
}

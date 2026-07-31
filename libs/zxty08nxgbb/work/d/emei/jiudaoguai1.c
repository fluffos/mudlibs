// Room: /d/emei/jiudaoguai1.c 峨嵋派 九十九道拐1

inherit ROOM;

void create()
{
	set("short", "九十九道拐");
	set("long", @LONG
这里是山谷中一道窄窄的小路，你现在站在谷口，只见两边峭壁直
立，道路虽然比较平缓，但弯弯曲曲的看不到尽头，走进山谷中，时不
时的听到轰轰声，好象是瀑布奔腾而下，冲击地面发出的声响。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
                 "north" : __DIR__"shangu",
		"southwest" : __DIR__"jiudaoguai2",
	]));

	setup();
}




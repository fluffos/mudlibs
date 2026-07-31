// Room: caohai4.c

inherit ROOM;

void create()
{
	set("short", "草海");
	set("long", @LONG
之所以称为草海，就是说四周都是一望无际的草原，它辽阔的程度就好象
海洋一样。在草海中行走是很容易迷路的，因为四周地面都被草覆盖了，没有
路可以辨认，只能凭借日月星辰辨别方向，草海中还有很多危险的沼泽地。
LONG
	);

	set("exits", ([
		"north" : __DIR__"caohai5",
		"south" : __DIR__"zhaoze"+(random(3)+1),
		"west" : __DIR__"zhaoze"+(random(3)+1),
		"east" : __DIR__"caohai"+(random(6)+1),   
	]));
	set("outdoor","大草原");
	setup();
}

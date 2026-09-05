// guestroom.c	梅庄客房
// by bing

inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", 
@LONG  这里是梅庄招待远来客人暂时休息的地方。由于梅庄绝少有人来防，所以
客房里陈设并不豪华，但却也很舒适。墙上挂着一些名家的字画，体现出主人
的高雅情趣。临墙摆着一张大床，你可以在上面舒舒服服地睡上一觉。
LONG
	);
	set("sleep_room",1);
	set("exits", ([
"east" : __DIR__"tianjing",

	]));
	setup();
	set("no_fight",1);
}

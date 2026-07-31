// Room: /d/emei/basipan3.c 峨嵋派 八十四盘3

inherit ROOM;

void create()
{
	set("short", "八十四盘");
	set("long", @LONG
这里是八十四盘最后的一段路，地势已经稍现平缓，道路也略宽阔了
一些，可以相挟缓缓而上，在正对面有一条向上的石阶，走上去已经可以
遥遥望到有一座寺庙矗立在上方。往西通往峨嵋山的金顶。
LONG
           );
        set("outdoors", "emei");
	set("exits", ([
                "northdown":__DIR__"basipan2",
                "south":__DIR__"jieyindian",
                "west": __DIR__"shijie1",
                "east": __DIR__"milin3",
	]));

	setup();
}




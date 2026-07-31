// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/gulou.c

inherit ROOM;

void create()
{
        set("short", "鼓楼");
        set("long", @LONG
这里是长安城的鼓楼。楼上置一大鼓，击鼓报时，故称鼓楼。与东南方向
的钟楼遥相呼应，晨钟暮鼓，昭示祥和。青砖灰瓦的鼓楼重檐斗拱，攒顶高耸，
屋檐微翘，华丽庄严，在四周建筑的映衬下显得十分雄伟庄严。
LONG
        );
        set("outdoors", "长安");

        set("exits", ([
                "southeast": __DIR__"zhonglou",
                "south" : __DIR__"westjie1",
        ]));

        set("incity",1);
	setup();
}
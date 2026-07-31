// Room: /d/snow/square_sw.c
inherit ROOM;
void create()
{
        set("short", "广场西南");
        set("long", @LONG
这里是雪亭镇广场的西南边，广场中央的大榕树就在你的东北
方不远处，这里的北边可以看见一家客栈，往西是一条街道，东边
穿过一个路口可看见一家打铁铺子。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                "west" : __DIR__"wstreet1",
                "east" : __DIR__"guangchang_s",
                "north" : __DIR__"guangchang_w",
	])
	);
        set("outdoors","xueting");
        setup();
}

// Room: d/fuzhou/chalou.c
// Lklv 2001.9.8

inherit ROOM;

void create()
{
        set("short", "茶楼");
        set("long", @LONG
这是福州西巷的一家茶楼。只见屋内几张长条桌排开，旁边凳子上坐满了
茶客，或高声谈笑，或交头接耳，来自各地的口音混杂在一起，听起来熙熙攘
攘很是热闹。室内飘散着一股淡淡的茶香，闻着格外舒服。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "east" : __DIR__"xixiang4",
                "up" : __DIR__"chalou2",
        ]));

        set("item_desc", ([
                "up" : "楼上的人很多，在这里看不清楚。\n"
        ]));
        set("objects", ([
                __DIR__"npc/chaboshi" : 1,
        ]));
	setup();
}

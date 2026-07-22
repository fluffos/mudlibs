// Room: d/fuzhou/chalou2.c
// Lklv 2001.9.10

inherit ROOM;

void create()
{
        set("short", "茶楼");
        set("long", @LONG
这是茶楼的二楼，屋内摆着几排长条桌，旁边凳子上坐了几位茶客，或高
声谈笑，或交头接耳，来自各地的口音混杂在一起，听起来很是热闹。室内飘
散着一股淡淡的茶香。靠窗户的位置有张桌，后面坐了位说书先生。
LONG
        );
        set("resource/water", 1);

        set("exits", ([
                "down" : __DIR__"chalou",
        ]));
        set("objects", ([
                "/d/city/npc/shuren" : 1,
        ]));
	setup();
}

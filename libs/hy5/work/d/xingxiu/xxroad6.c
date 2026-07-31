// Room: /d/xingxiu/xxroad6.c

inherit ROOM;

void create()
{
        set("short", "山间平地");
        set("long", @LONG
山间平地，地上是嫩绿的小草，周围布了几棵桦树，山边有一眼清
泉。草地上树着几个毒僵尸，显是星宿弟子练功所用。
LONG );

        set("resource/water", 1);
        set("objects", ([
                __DIR__"npc/obj/yangrou.c" : 3,
                __DIR__"npc/dujiangshi" : 5
        ]));
        set("exits", ([
            "south" : __DIR__"xxroad5",
        ]));
//        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");
        setup();
        replace_program(ROOM);
}

// matou1.c 北码头
// hongdou 98.10.15

inherit ROOM;

void create()
{
        set("short", "北码头");
        set("long", @LONG
这里是泉州北码头，已经比较冷清了，有几个东洋人在这里耀武扬威
的，使许多人都退避三舍，不敢招惹他们。海边停着许多船只，但是没有
一个船家在这里。
LONG
        );

        set("exits", ([
                "south" : __DIR__"matou0",
        ]));
        set("objects", ([
                __DIR__"npc/langren_t":1,
		__DIR__"npc/wo_kou":2,
         ]));
        set("outdoors", "diaoyudao");
        setup();
        replace_program(ROOM);
}

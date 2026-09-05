// matou1.c 南码头
// hongdou 98.10.15
// 找浪人头目 ask lang ren about 珍珠项链
// bihua 后 得到 珍珠项链
// give xianlian to jia

inherit ROOM;

void create()
{
        set("short", "南码头");
        set("long", @LONG
这里是泉州南码头，海边停满了大大小小的船只，有商船、鱼船。
一条船上的船家看到你在东张西望，想找船出海的样子，连忙向
你招手，示意你上他的船。
LONG
        );

        set("exits", ([
                "north" : __DIR__"matou0",
        ]));
        set("objects", ([
                __DIR__"npc/chuan_jia":1,
         ]));
        set("couldfish",1);
        set("outdoors", "diaoyudao");
        setup();
        replace_program(ROOM);
}

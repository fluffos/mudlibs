// jiulou1.c
inherit ROOM;

void create()
{
        set("short", "酒楼");
        set("long", @LONG
这家酒楼是武功镇方圆百里内的唯一一家，不过连名字都没
有。楼下布置简易，顾客多是匆匆的行人，买点包子、鸡腿、米
酒就赶路去了。楼上是雅座。
LONG
        );
        set("exits", ([
                "south" : __DIR__"beijie",
                "up" : __DIR__"jiulou2",
        ]));
        set("objects", ([
                //__DIR__"npc/xiaoer" : 1,
                "/d/jinyong/book8/quanzhen/npc/xiaoer" : 1,
        ]));

        setup();
       	replace_program(ROOM);
}
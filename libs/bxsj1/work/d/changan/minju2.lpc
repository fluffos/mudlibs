// Write By Yanyang@SJ 2001.10.2
// Room: /d/changan/minju2.c

inherit ROOM;

void create()
{
        set("short", "民居");
        set("long", @LONG
这所房子看起来好像已经很久没人住了。雕花漆彩的门窗已是破败不堪，
满目蛛丝鼠粪，墙上地下到处都是灰尘，几只老鼠跑来跑去。院子里杂草丛生，
宅外墙满是青苔蜘网，显得既荒凉又阴森。四周死一般的沉寂。
LONG
        );

        set("exits", ([
                "north" : __DIR__"shiji",
        ]));

        set("objects", ([
                __DIR__"npc/dalaoshu" : 2,
        ]));

        set("incity",1);
	setup();
}
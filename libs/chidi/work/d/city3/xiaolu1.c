//modified by wind

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
你来到了鄂川交界的小路上，偶尔会有人骑着马匆
匆而过，卷起飞扬的尘土。东北边通向峨嵋山，往西则
是进入天府之国之首府成都的大道。
LONG
        );

        set("exits", ([
                "west" : __DIR__"xiaolu2",
                "north" : "/d/changan/ca34",
//                "northeast" : "/d/emei/xiaolu2",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}



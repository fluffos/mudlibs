//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
你来到了鄂川交界的小路上，偶尔会有人骑着马匆匆
而过，卷起飞扬的尘土。东北边通向扬州城，往西则进入
四川的大道。
LONG
        );

        set("exits", ([
                "east" : __DIR__"xiaolu1",
                "west" : __DIR__"yidao4",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}



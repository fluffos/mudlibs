//bye enter

inherit ROOM;

void create()
{
        set("short", "浣花溪");
        set("long",@LONG
季节虽然已经是深秋，但日正当中的阳光，仍旧是十分
炎热的。四周是一片芙蓉树，远山隐在云雾之中，恍若迷离
的美人，不远处有着，一丛丛的树林，有一条溪流，沿着林
旁蜿蜒流去。这里已是浣花溪，往东就是北大街了。
LONG
        );

        set("outdoors", "/d/chengdu");

        set("exits", ([
                "southwest" : __DIR__"huanhuaxi1",
                "northeast" : __DIR__"beijie1",
            ]));
        setup();
        replace_program(ROOM);       
}



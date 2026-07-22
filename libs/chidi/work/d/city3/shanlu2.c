//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是川蜀的一条驿道，路上行人已经很少了，因为道路已
经逐步狭窄，你越来越觉得行走困难。向西通往就要开始翻大
巴山了。
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"shanlu1",
                "westup" : __DIR__"shanlu3",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}



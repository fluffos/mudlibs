//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这是通往川蜀的一条崎岖的山路，路上行人匆匆，似乎都
在忙着赶路，道路越往西南延伸，就越是让人觉得行走困难。
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"yidao3",
                "southwest" : __DIR__"shanlu2",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}



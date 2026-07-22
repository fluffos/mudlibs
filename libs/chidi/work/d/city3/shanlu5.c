//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
两旁古树参天,树阴替你遮住了强烈的阳光,但知了的
叫声异常扰人心烦.再向西走就是名城---成都了.
LONG
        );

        set("exits", ([
                "eastup" : __DIR__"shanlu4",
                "west" : __DIR__"guandao4",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}



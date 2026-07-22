//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "大巴山");
        set("long", @LONG
这是一条通往成都的必经山路，两旁树木郁郁葱葱，不时传来
叮叮咚咚的山泉声，偶尔路旁会窜出一两只小动物来。景色虽是宜
人,但你脚下都是稀泥和碎石,使你举步维艰。
LONG
        );

        set("exits", ([
                "eastdown" : __DIR__"shanlu2",
                "westdown" : __DIR__"shanlu4",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}



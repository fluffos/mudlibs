//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
    这里已是成都地界了。一条青石板铺成的路，比较宽敞。
道路两旁种的是整整齐齐的柳树。微风吹过沙沙做响。由于
这儿靠近成都城，来往的行人倒也不少。向南望去，可隐约
见到成都城雄伟的城墙。
LONG
        );

        set("exits", ([
                "north" : __DIR__"dadao7",
                "south" : __DIR__"dadao5",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}



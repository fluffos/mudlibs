// Room: /d/snow/lane2.c
inherit ROOM;
void create()
{
        set("short", "溪边小路");
        set("long", @LONG
你现在来到一处巷子的入口，往北通往一条溪边的小路，西边
是一栋大瓦屋，大门深锁著，东边有一家磨坊，磨坊屋旁一个水车
正辘辘地转著，往南通往巷子里的一个转角。
LONG
        );
        set("item_desc", ([ /* sizeof() == 3 */
                "大瓦屋": "一间高大的瓦屋，在雪亭镇这样的山间小镇而言，这样的屋子并不
多见，可算得上是有钱人家。
",
                "水车": "这架水车是磨坊动力的来源，平常溪水丰沛的季节就直接用水力，
一到秋冬枯水季节，就得雇工人用脚踩。
",
                "磨坊": "一家用水车辗面粉的磨坊，磨坊的门是关著的，不过从里面传来的
声音判断，应该有工人正在里面工作。
",
]));
        set("exits", ([ /* sizeof() == 2 */
                "south" : __DIR__"lane1",
                "north" : __DIR__"npath3",
]));
        set("outdoors", "xueting");
        setup();
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter(string arg)
{
        if( !arg || arg!="磨坊") return 0;
        message_vision("$N推开磨坊的门，走了进去。\n", this_player());
        if( this_player()->move(__DIR__"mill") )
                message("vision", this_player()->name() + "推开门从外面走了进来。\n",
                        environment(this_player()), this_player());
        return 1;
}

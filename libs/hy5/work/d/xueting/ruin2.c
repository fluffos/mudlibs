// Room: /d/snow/ruin2.c
inherit ROOM;
void create()
{
        set("short", "破旧大宅正厅");
        set("long", @LONG
这里是一栋破旧大宅的正厅，北面的墙壁跟屋顶已经整个坍塌
了，凉飕飕的冷风从北边的缺口直灌进来，另你觉得意外的是，这
里清扫得相当整洁，地上用乾草整整齐齐地铺著一个床铺，说是流
浪汉在这里栖宿却也不像，哪里会有这麽爱整洁的流浪汉？大厅倒
塌的梁柱挡住了往西的出口。
LONG
        );
       set("item_desc", ([ /* sizeof() == 3 */
                "梁柱": "一跟粗大的梁柱倒了下来，正好挡住了正厅的出口。
",
                "床铺": "一个用乾草铺成的床铺，虽然简陋，但是却乾乾净净，当你靠近的
时候竟还闻到一股淡淡的脂粉香气。
",
                "缺口": "从缺口往外望去，只见大宅的其他部份都已经成为瓦砾堆了，如果
你想过去，勉强可以从缺口爬出去。
",
]));
        set("exits", ([
                "north": __DIR__"riverbank",
                "east" : __DIR__"ruin3",
        ]));
        set("objects", ([
               // __DIR__"master/master-yang" : 1
        ]) );
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        if( arg == "梁柱" )
        message_vision("$N爬过倒塌的梁柱，往大宅的前院离去。\n", this_player());
        this_player()->move(__DIR__"ruin1");
        message("vision", this_player()->name() + "从倒塌梁柱的另一头爬了出来。\n",
                environment(this_player()), this_player());
        return 1;
}

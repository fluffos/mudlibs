// Room: /d/snow/ruin3.c
inherit ROOM;
void create()
{
        set("short", "破旧大宅侧厅");
        set("long", @LONG
这里是破旧大宅的侧厅，西边是破旧大宅的正厅。这里虽然破
旧，但是有一些简单的家具。
LONG
        );
       set("item_desc", ([ /* sizeof() == 3 */
	"梁柱": "一跟粗大的梁柱倒了下来，正好挡住了正厅的出口。",
	"床铺": "一个用乾草铺成的床铺，虽然简陋，但是却乾乾净净，当你靠近的
时候竟还闻到一股淡淡的脂粉香气。",
	"缺口": "从缺口往外望去，只见大宅的其他部份都已经成为瓦砾堆了，如果
你想过去，勉强可以从缺口爬出去。",
]));
        set("exits", ([
                "west": __DIR__"ruin2"
        ]));
        set("objects", ([
                // __DIR__"master/master-li" : 1
        ]) );
        setup();
}


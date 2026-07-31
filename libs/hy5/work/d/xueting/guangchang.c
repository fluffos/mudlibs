// Room: /d/snow/guangchang.c
// edit by pian
inherit ROOM;
void create()
{
        set("short", "广场中央");
        set("long", @LONG
这里是雪亭镇广场的中央，一株巨大的老榕树盘根错结地站在
中央，一些孩童常常爬上这株老榕嬉戏，榕树下七横八竖地放著几
张长凳供人歇息聊天，树旁还有一个水缸供路人取水解渴。
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"npc/gammer" : 1,
        ]));
        set("all_water",200);
        set("item_desc", ([ /* sizeof() == 2 */
                "榕树": "这株榕树少说也有两三百岁了，一条条长长的须根几乎垂到地面，
树干因为经常被人抚摸而显得光滑。
",
                "长凳": "十分普通常见的长凳，如果你累了，不必客气，尽管做下来休息。
",
]));
        set("exits", ([ /* sizeof() == 4 */
                "east"  : __DIR__"guangchang_e",
                "north" : __DIR__"guangchang_n",
                "west"  : __DIR__"guangchang_w",
                "south" : __DIR__"guangchang_s",
        ]));
        set("outdoors", "xueting");
        setup();
}
/* void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object obj;
      //  object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "榕树" ) 
	{
        message_vision("$N攀著榕树的树干爬了上去。\n", this_player());
        if( this_player()->move(__DIR__"tree") )
                message("vision", this_player()->name() + "从树下爬了上来。\n",
                environment(this_player()), this_player());
        return 1;
	}
   	else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
*/
void init()
{
	add_action("do_drink", "drink");
	add_action("do_climb", "climb");
}

int do_drink(string arg)
{
	object me = this_player();

	if(query("all_water") <= 0)
		return notify_fail("水缸里一滴水也没有了。\n");

	if( (int)me->query("water") >= (int)me->max_water_capacity() )
                return notify_fail("你已经再也喝不下一滴水了。\n");

	message_vision("$N在水缸边用杯子舀起水喝了几口。\n", me);
	me->add("water", 20);
	add("all_water",-1);
	if(query("all_water") <= 0)
		return notify_fail("水缸已经被你给喝干了。\n");
	return 1;
}
int do_climb(string arg)
{
        if( arg!="榕树" ) return 0;
        message_vision("$N攀著榕树的树干爬了上去。\n", this_player());
        this_player()->move(__DIR__"tree");
        message("vision", this_player()->name() + "从榕树下的爬了上来。\n",
                environment(this_player()), this_player());
        return 1;
}
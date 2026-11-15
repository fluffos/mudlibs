inherit ROOM;

void create()
{
	set("short", "桃花厅");
	set("long", @LONG
这里是移花宫的用餐室，地方虽然不大，但是里面却坐满了很多用餐的
女弟子。也许练了一天的功，大家都很累了，只有这里可以放松一下，所以
女孩子们都在互相打闹着。如果你也想吃点什么,也可以 (order)一份。
LONG
	);
	set("exits",([
		"east" : __DIR__"changlang",
]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
        add_action("do_order","order");
}

int do_order(string arg)
{
       object me;
	object food;
	object water;
       me=this_player();
       if (arg)  return notify_fail("Sorry, 这样东西这里没有啊。\n");
       message_vision("伺女把一碗鲜花粥和一袋百花酿拿了给$N。\n",me);
	food=new(__DIR__"obj/zhou");
	water=new(__DIR__"obj/niang");
	food->move(me);water->move(me);
       return 1; 
}
int valid_leave(object me,string dir)
{
	me=this_player();
        if(dir=="east" && (present("niang",this_player()) || present("rice",this_player()))) 
             return notify_fail("伺女说道：这位师姐,你还是吃完再走吧。\n");
        return ::valid_leave(me,dir);
}

// shitang.c

inherit ROOM;

void create()
{
        set("short", "食堂");
        set("long", @LONG
这里便是全真第子用餐的地方。地方极大，足可容纳上千人同时进餐。从
东到西一排排摆满了长长的餐桌的长凳，几位小道童正来回忙碌着布置素斋。
桌上摆了几盆豆腐，花生，青菜以及素鸭等美味素食。你也可以(order)一份。
LONG
        );
        set("exits",([
                "east" : __DIR__"houyuan",
//                "north" : __DIR__"chufang",
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
       message_vision("道童叫道：“稍等片刻，饭菜马上就来。”\n"
                      "一会功夫，道童把一碗米饭和一碗水拿了给$N。\n",me);
        food=new(__DIR__"obj/rice");
        water=new(__DIR__"obj/bowl");
        food->move(me);water->move(me);
       return 1; 
}
int valid_leave(object me,string dir)
{
        me=this_player();
        if(dir=="east" && (present("bowl",this_player()) || present("rice",this_player()))) 
             return notify_fail("道童说道：对不起，掌教真人吩咐不能带食物离开这里。\n");
        return ::valid_leave(me,dir);
}



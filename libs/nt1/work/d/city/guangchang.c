inherit ROOM;

void create()
{
        set("short", "中央广场");
        set("long", @LONG
这里是城市的正中心，一个很宽阔的广场，铺着青石地面。一些游手
好闲的人在这里溜溜达达，经常有艺人在这里表演。中央有一棵大榕树，
盘根错节，据传已有千年的树龄，是这座城市的历史见证。树干底部有一
个很大的树洞(dong)。你可以看到北边有来自各地的行人来来往往，南面
人声鼎沸，一派繁华景象，东边不时地传来朗朗的读书声，西边则见不到
几个行人，一片肃静。
LONG );
        set("no_sleep_room",1);
        set("outdoors", "city");
        set("item_desc", ([
                "dong" : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n",
        ]));

        set("exits", ([
                "east" : __DIR__"dongdajie1",
                "south" : __DIR__"nandajie1",
                "west" : __DIR__"xidajie1",
                "north" : __DIR__"beidajie1",
        ]));

        set("objects", ([
                __DIR__"npc/liapo" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me;
        mixed *local;
        local = localtime(time());
        me = this_player();
        /*
        if (local[6] == 6 && ! environment(me)->query("ok"))
                return notify_fail("树干上布满了青苔,看样子是没法爬上的!\n");
        */
        if (! arg || arg != "up") return notify_fail("你要往哪个方向爬？\n");

        if (me->is_busy() )
        {
                return notify_fail("你的动作还没有完成，不能移动。\n");
        }

        if (me->query_temp("is_riding")) 
                return notify_fail("你的坐骑无法和你一到爬树！\n");

        if (me->query_condition("killer"))
        {
                message("vision",
                        me->name() + "战战兢兢地拉着大榕树的盘根，屁股一扭一扭地往上爬，突然一声惨叫，又掉了下来。\n",
                        environment(me), ({me}));
                write("你战战兢兢地拉着大榕树的盘根往上爬，一不小心摔了个狗吃屎。\n");
                return 1;
        }
        if (me->query("gender") != "女性")
                message("vision",
                        me->name() + "战战兢兢地拉着大榕树的盘根，屁股一扭一扭地往上爬。\n",
                        environment(me), ({me}));
        else if(me->query("age") < 40 && me->query("per") > 24)
                message("vision",
                        me->name() + "轻轻一跳，衣裙飘飘，象仙子般飞上大榕树。\n",
                        environment(me), ({me}));
        else message("vision",
                        me->name() + "战战兢兢的抓住树干往上爬去。\n", environment(me), ({me}));
                        
        me->move(__DIR__"chatroom");
        
        if (me->query("gender") != "女性")
                message("vision",
                        me->name() + "气喘嘘嘘地爬了上来。\n",
                        environment(me), ({me}) );
        else if(me->query("age") < 40 && me->query("per") > 24)
                        message("vision","一阵清香飞来，你定眼一看，"+
                                me->name() + "已经婷婷玉立在你眼前。\n",
                                environment(me), ({me}));
        else  message("vision", me->name() + "战战兢兢地从下面爬了上来。\n", environment(me), ({me}));   
        return 1;
}   

int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
        return 0;

        if( arg=="dong" ) 
        {
                if (me->query_temp("is_riding")) 
                        return notify_fail("你的坐骑无法和你一到进洞！\n");

                if (me->is_busy() )
                {
                        return notify_fail("你的动作还没有完成，不能移动。\n");
                }

                message("vision",
                        me->name() + "一弯腰往洞里走了进去。\n",
                        environment(me), ({me}) );
                me->move("/d/gaibang/inhole");
                message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                return 1;
        }
}       


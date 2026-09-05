// donkey.c 小毛驴

inherit ITEM;

mapping default_dirs = ([
        "north":       "北",
        "south":       "南",
        "east":        "东",
        "west":        "西",
        "northup":     "北边",
        "southup":     "南边",
        "eastup":      "东边",
        "westup":      "西边",
        "northdown":   "北边",
        "southdown":   "南边",
        "eastdown":    "东边",
        "westdown":    "西边",
        "northeast":   "东北",
        "northwest":   "西北",
        "southeast":   "东南",
        "southwest":   "西南",
        "up":          "上",
        "down":        "下",
        "enter":       "里",
        "out":         "外",
]);

mapping ride_dirs = ([
        "north":       "南",
        "south":       "北",
        "east":        "西",
        "west":        "东",
        "northup":     "南边",
        "southup":     "北边",
        "eastup":      "西边",
        "westup":      "东边",
        "northdown":   "南边",
        "southdown":   "北边",
        "eastdown":    "西边",
        "westdown":    "东边",
        "northeast":   "西南",
        "northwest":   "东南",
        "southeast":   "西北",
        "southwest":   "东北",
        "up":          "下",
        "down":        "上",
        "enter":       "外",
        "out":         "里",
]);

void setup()
{}

void init()
{
    add_action("do_go","go");
    add_action("do_ride","ride");
    add_action("do_unride","unride");
}

void create()
{
    set_name("小毛驴", ({"donkey", "maolu", "lu"}));
    set_weight(15000);
    set_max_encumbrance(20000);
    if (clonep())
        set_default_object(__FILE__);
    else
    {
        set("unit", "匹");
        set("long", "一匹黑色的小毛驴，可以骑(ride)，骑上后可以赶(go)。\n");
        set("value", 400);
    }
}
int do_unride(string arg)
{
    object me = this_player();
    if (!id(arg))
        return notify_fail("你要下什么？\n");
    message_vision("$N顺着$n的屁股慢悠悠的滑了下来。\n",me,this_object());	
    me->delete_temp("marks/ride");
    return 1;        
}

int do_ride(string arg)
{
        object me = this_player();
    if (!id(arg))
        return notify_fail("你要骑什么？\n");
    if (this_player()->query_temp("marks/ride") )
    {
       write("你已经骑在马上了。还想再骑驴?!\n");
       return 1;
    }
    else
    {
        if(this_player()->query_skill("dodge",1) < 60 )
                {
                message("vision",this_player()->name() + "翻身上驴。毛驴一撩蹄子，"
               "又把"+this_player()->name() + "掀下驴背。\n",environment(me), ({me}) );
                write("你想骑毛驴，可它不让你骑。\n");
                return 1;
        }
        else
        {
                message("vision",this_player()->name() + "紧紧抓住毛驴，一偏腿骑了上去，"
               "毛驴很不高兴地拱了拱背。\n",environment(me), ({me}) );               write("你翻身上驴。\n");
            this_player()->set_temp("marks/ride",1);
                return 1;
        }
    }}

int do_go(string arg)
{
    string dest, mout, min, dir,ride_dir;
    mapping exit;
        object me,env,obj,*f_obs, *ob;
    int count = 0, my_dex, i;

        me = this_player();
    env = environment(me);
    exit = env->query("exits");

    if(!me->query_temp("marks/ride")) return 0;
    if(!env)
    {
        write("你哪里也去不了。\n");
        return 1;
    }
    switch(arg)
    {
        case "north":     arg="south";break;
        case "south":     arg="north";break;
        case "east":      arg="west";break;
        case "west":      arg="east";break;
        case "northup":   arg="southdown";break;
        case "southup":   arg="northdown";break;
        case "eastup":    arg="westdown";break;
        case "westup":    arg="eastdown";break;
        case "northdown": arg="southup";break;
        case "southdown": arg="northup";break;
        case "eastdown":  arg="westup";break;
        case "westdown":  arg="eastup";break;
        case "northeast": arg="southwest";break;
        case "northwest": arg="southeast";break;
        case "southeast": arg="northwest";break;
        case "southwest": arg="northeast";break;
        case "up":        arg="down";break;
        case "down":      arg="up";break;
        case "enter":     arg="out";break;
        case "out":       arg="enter";break;
        default:          arg="none";break;
    }
    if( !mapp(exit) || undefinedp(exit[arg]) )
    {
        write("小毛驴拼命向另一个没去路的方向挤。\n");
        return 1;
    }
    if( me->over_encumbranced() )
    {
        write("你的负荷过重，小毛驴一步也走不动。\n");
        return 1;
    }
    if( me->is_busy() )
    {
        write("你的动作还没有完成，没法驾驴。\n");
        return 1;
    }
    if (me->is_fighting())
    {
        f_obs = me->query_enemy();
        if (objectp(f_obs[0]))
        if (5 + random((int)me->query("dex")) <=  random((int)f_obs[0]->query("dex")))
        {
            me->start_busy(1);
            message_vision("$N见势不好，调转驴头要走，被$n一把拦在前面。想走？没那么容易！\n", me,
f_obs[0]);
            write("你逃跑失败。\n");
            return 1;
        }
    }
    dest = exit[arg];
    if( !(obj = find_object(dest)) )
        call_other(dest, "???");
    if( !(obj = find_object(dest)) )
    {
        write("无法移动。\n");
        return 1;
    }
    if(!obj->query("long") || !obj->query("short") || !obj->query("exits"))
    {
        destruct(obj);
        call_other(dest,"???");
        if( !(obj = find_object(dest)) )
        {
            write("无法移动。\n");
            return 1;
        }
    }
    if( !env->valid_leave(me, arg) ) return 1;
    if( !undefinedp(default_dirs[arg]) )
    {
        dir = default_dirs[arg];
        ride_dir = ride_dirs[arg];
    }
    else
        dir = arg;

    if( me->is_fighting() )
    {
        mout = "$N把驴向"+ride_dir+"一拉，毛驴猛地往" + dir + "落荒而逃了。\n";
        min = "$N骑着驴，一颠一颠地狼狈地跑了过来。\n";
    }
    else
    {
        mout = "$N把驴向"+ride_dir+"一拨，毛驴却调头往" + dir + "离开。\n";
        min  = "$N骑着驴过来了。\n";
    }
    message_vision(mout, me );
    if( me->move(obj) )
    {
        me->remove_all_enemy();
        message_vision(min, me );
        me->set_temp("pending", 0);
        all_inventory(env)->follow_me(me, arg);        this_object()->move(environment(me));
        return 1;
    }
    return 0;
}


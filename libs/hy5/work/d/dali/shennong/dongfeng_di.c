// 东峰麓 /d/menpai/shennong/dongfeng_di.c

inherit ROOM;



void create()
{
    set("short",    "东峰麓");
    set("long",@LONG
你来到无量山的东麓。小路似乎已经走到了尽头。在你的西面有一座挺拔的
山峰，据说那就是无量山了。东面也有一座山，不过远远没有西面那座高。上面
不时的传来泉水汩汩的声音。如果凝神细望，能看到东边山腰中有几缕青烟飘出。
山上似乎有人烟。可以爬上去看一下。
LONG    );
    set("exits",    ([  /*sizeof()==1*/
        "southwest" :   __DIR__"xiaodao3"  
    ]) );
    set("outdoors", "wuliang");
    setup();
}

void init()
{
    add_action("do_climb",  "climb");
}

int do_climb( string arg )
{   
    object ppl=this_player();

    if( !arg )
        return notify_fail("你要向什么方向爬？\n");
    if( arg != "up" )
        return notify_fail("这个方向无处着手，没法爬。\n");
    message_vision("$N手脚并用，向上爬去。\n",ppl);
    ppl->move( __DIR__"shanxi" );
    return 1;
}

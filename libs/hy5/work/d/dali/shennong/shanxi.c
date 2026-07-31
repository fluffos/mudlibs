// 山溪 /d/menpai/shennong/shan_xi.c
// By lala, 1998-01-26

inherit ROOM;



void create()
{   
    set("short",    "山溪");
    set("long",@LONG
一条弯弯曲曲的小溪从山上淙淙流下，转过一个山头，然后不见了。溪水很
清澈，可以一眼望到底。偶尔还有几条不知名的鱼游来游去，你正想去捉时，他
们一转眼又不见了。往山上又有了一条小路，山上的丛林中隐隐有几缕青烟冒出，
不知道是甚么古怪的所在。
LONG    );
    set("exits",    ([  /*sizeof()==1*/
        "eastup" :   __DIR__"wuqian",
    ]) );
    set("outdoors", "wuliang");
    set("resource/water",   1);
    set("fillplace",   "山溪");
    setup();
}

void init()
{   
    add_action("do_climb",  "climb");
}

int do_climb( string arg )
{
    object ppl = this_player();

    if( !arg ) 
        return notify_fail("你要向什么方向爬？\n");
    if( arg != "down" )
        return notify_fail("这个方向无处着手，没法爬。\n");
    message_vision("$N手脚并用，向下爬去。\n", ppl);
    ppl->move( __DIR__"dongfeng_di" );
    return 1;
}

// Room: /d/snow/kitchen.c
inherit ROOM;
void create()
{
        set("short", "厨房");
        set("long", @LONG
你现在正在一户有钱人家的厨房里，不过和你想像中的有钱人
家厨房好像不太一样，并没有堆满了鸡鸭鱼肉跟山珍海味，想来有
钱人也是省吃俭用才能有钱的，厨房的门在你的南边，不过锁住了，
东边则是你进来的围墙。
LONG
        );
       set("objects", ([
	"/clone/food/jitui":3,
        "/clone/food/baozi":1,
       "/clone/food/jiudai":1,
        ]) );
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        if( arg!="围墙" ) return 0;
        message_vision("$N用手攀上围墙，蹬了几下翻了过去。\n", this_player());
        this_player()->move(__DIR__"epath");
        message("vision", this_player()->name() + "从围墙的另一头爬了出来。\n",
                environment(this_player()), this_player());
        return 1;
}

// Room: room8.c
inherit ROOM;
int do_climb(string arg);
void create()
{
        set("short", "围墙");
        set("long", @LONG
只见眼前是一堵高高的围墙(wall)，周围并没一扇门户。围墙里
有两栋茅屋，一圆一方。
LONG
        );
        set("exits", ([ 
  "southeast" : __DIR__"room7",
  "west" : __DIR__"room11",
]));

    set("item_desc", ([
        "wall" : "墙很高，可能翻不过去(climb)。\n",
    ]) );

        setup();
}
void init()
{
    object book, me;
    me = this_player();
    add_action("do_climb", "climb");
}
int do_climb(string arg)
{
    int n;
    n = this_player()->query_skill("dodge",1);
    if( !arg || arg!="wall" ) {
        write("不要到处乱爬！\n");
        return 1;
    }
    message_vision(
    "$N在墙前站定,深吸一口气，猛然跃起.\n", this_player());
        
    if (n>=1000) {
        message_vision(
        "只见$N足尖在墙上一点,已悠然飘落院中.\n", this_player());
        this_player()->move(__DIR__"room9");
    }
    else if (n>=800) {
        message_vision(
        "只见$N双手在墙上一攀,勉强翻过围墙,跌落院中.\n", this_player());
        this_player()->move(__DIR__"room9");
    }
    else {
        message_vision(
        "$N高高跃起,可还差一大截呢,看来是轻功不够好。\n", this_player());
     }
    return 1;
}

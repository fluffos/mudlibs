// chufang.c 厨房
// Lklv 2001.9.10

inherit ROOM;

void create()
{
        set("short", "饭厅");
        set("long", @LONG
这里是僧人们用斋的地方，饭厅不是很大，但是也能容纳个三五十人同时
用餐。屋子里摆了十几张桌子和三十几条长凳，几个小沙弥在一旁在负责伺候
大家用饭。桌上摆几个大盆，在桌子的一端有面小铜锣(luo) 没吃饱的可以敲
一下锣。
LONG
        );

        set("exits", ([
                "south" : __DIR__"celang5",
        ]));

        set("item_desc", ([
                "luo" : "这是一面铜制的小锣，是僧人们召唤侍斋的小沙弥用的。\n",
        ]));

        set("objects",([
                "/d/shaolin/npc/xiao-nan1" : 1
        ]));

        setup();
}

void init()
{

        add_action("do_tap", "qiao");
        add_action("do_tap", "knock");
        add_action("do_zuo", "zuo");
        add_action("do_zuo", "sit");
}

int do_tap(string arg)
{

        object me;
        object shami;
        me = this_player();

        if (!arg || (arg != "luo"))
                return notify_fail("你要敲什么？\n");

        if( !objectp(shami = present("xiao shami", environment(me))) )
                return notify_fail("你敲了一下小锣，却发现没人理你。\n");

        if( !me->query_temp("marks/sit") )
                return notify_fail("你敲了一下小锣，锣声在饭厅内回荡，你突然感觉自己很愚蠢。\n");

        if( me->query_temp("marks/served")){
                message_vision("小沙弥对$N说道：我少林寺虽物产甚丰，可也不能象你这样吃呀！！！\n", me);
                return notify_fail("");
        }

        message_vision("$N端坐在桌前，轻轻敲了一下桌上的小锣，小沙弥弓身作了个揖，过来招呼。\n", me);

        shami->serve_food(me) ;
        me->set_temp("marks/served", 1);
        call_out("delete_served", 20, me);
        return 1;
}

void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}

int do_zuo(string arg)
{

        if ( !arg || (arg != "changdeng" && arg != "chair") )
                return notify_fail("你要坐什么上面？\n");

        if (this_player()->query_temp("marks/sit"))
                return notify_fail("你已经有了个座位了。\n");

        this_player()->set_temp("marks/sit", 1);
                return notify_fail("你找了个空位座下。\n");
}

int valid_leave(object me, string dir)
{
        me->delete_temp("marks/sit");
        me->delete_temp("tea_cup");
        return ::valid_leave(me, dir);
}

//chayuan.c

inherit ROOM;



void create()
{
    set("short","太和茶园");
    set("long", @LONG
这里是大理有名的茶园－－“太和茶园”，相传在这里，你能看到几乎所有的名
种茶花，象“早桃红”，“松子壳”，“牡丹茶”，“恨天高”等等，但是奇怪的是
，这里那么多姹紫嫣红的茶花却从来没有人拿去卖，听人说，这茶园的主人是一个古
怪的老头，酷爱茶花，他栽茶花就是为了让人看的，不是为了赚钱，在园旁，蹲着几
只凶恶的大狼犬，据说是主人特意寻来的良种狼犬，专门来守住茶园里的名贵茶花不
给人偷的。这狼犬极是凶恶，已经咬伤了不少来偷茶花的人。
LONG
);
    set("exits", ([
		"west" : __DIR__"taihe_cun",
                    ]) );
    set("objects", ([
                __DIR__"npc/langquan" : 3,
                 ]) );
	set("outdoors", "xinan" );
    setup();
}

void init()
{
    add_action("do_tou","tou");
}

int do_tou( string arg )
{
    object me;
    me = this_player();
    if( !arg )
    return notify_fail("你要偷什么？\n");
    if( arg == "茶花" || arg == "chahua" )
    {
	if( query_temp("flowers") >= 4 )
        return notify_fail("这里的花已经被偷光了。\n");
        message_vision("$N轻手轻脚地走到花园边上，准备下手.....\n", me);
        me->start_busy(3);
        call_out("get_chahua",3,me);
        return 1;
    }
    else return notify_fail("你要偷什么？\n");
}           

void get_chahua( object me )
{
    object dog, owner, flower;
    dog = present("lang quan", environment(me) );
    flower = new(__DIR__"obj/chahua");
    if( random( me->query("kar") + me->query("dex") ) > 30 || !dog )
    {
        flower->move(me);
	add_temp("flowers", 1);
        message_vision("$N悄悄地拿下一盆" + flower->name()
         + "，神不知鬼不觉地藏了起来。\n", me);
    }
    else 
    {
        message_vision("$N刚想把一盆" + flower->name() + "拿起来，不想发出了一点响动，惊动\n"
                        "了一只大狼犬，大狼犬疯狂地吼叫了几声就向$N面门扑来！\n",me);
        dog->kill_ob(me);
        me->fight_ob(dog);
        message_vision("看花老头听到响动，马上冲了过来，一见$N要偷他的茶花，便目露凶\n"
                      "光，大声喝道：“你敢偷我的茶花！”，便向$N扑去。\n", me );     
        if( !owner = present( "lao tou", environment( me ) ) )
        owner = new(__DIR__"npc/boss");
        owner->move( environment(me) );
        owner->kill_ob( me );
        me->start_busy(3);
    }
}

                                
    

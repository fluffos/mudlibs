inherit ROOM;
int do_use(string arg);
int do_tiao(string arg);
void create()
{
    set("short", "石室");
    set("long", @LONG
这个山洞里伸手不见五指，黑沉沉的甚么也瞧不见。
LONG );
	set("item_desc",([]));
        setup();
}
void init()
{
        add_action("do_use", "use");
        add_action("do_tiao", "tiao");
}
int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
"    火光下只见四面石壁都是晶莹白玉，地下放着几张桌椅，伸手在桌上一按，
桌子居然仍是坚牢完固，原来山洞密闭，不受风侵，是以洞中物事并不朽烂。\n"

             );
    set("long", @LONG
火光下只见四面石壁都是晶莹白玉，地下放着几张桌椅，伸手在桌上一按，
桌子居然仍是坚牢完固，原来山洞密闭，不受风侵，是以洞中物事并不朽烂。
LONG
);
    set("item_desc", ([
        "石壁" : 
"    石壁上有一大裂缝，从黑黢黢的裂缝里飘出阵阵的阴风。\n", 
])); 
             this_player()->set_temp("marks/跳2", 1);
             return 1;
       }
	return 0;
}
int do_tiao(string arg)
{
        object me;
        me = this_player();
        if (me->query_temp("marks/跳2") ) {
        if( !arg || arg!="down") return notify_fail("你要往哪跳？\n");          
            write("你犹豫了一下，鼓气勇气，跳了下去。\n");
        if ((int)me->query_skill("dodge",1) < 500 ) {
        message("vision",me->name()+"急剧向下坠去。看来是凶多吉少了!\n",
            environment(me), ({me}) );
        me->unconcious();
        me->receive_wound("qi", 400);
        me->move(__DIR__"room33");
        message("vision","砰！的一个人掉了下来。\n", environment(me));
        return 1;
        }
            message("vision", me->name() + "“嗖”地一声跳了下去。\n", environment(me), ({me}) );
            me->move(__DIR__"room33");
            message("vision", me->name() + "从上面跳了下来。\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/跳2");
            return 1;
        }else {
            write("你想往哪儿跳?!\n");
            return 1;
        }
}

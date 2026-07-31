// 2002-8-26

inherit ROOM;

int do_use(string);
int do_zuan(string);

void create()
{
        set("short", "山洞");
        set("long", @LONG
这个山洞里伸手不见五指，只有出口处透进一丝光线。
黑暗中，你觉得有东西向你袭来！你借助洞口的亮光一看，天哪！巨蟒！
LONG
        );
        set("exits", ([
            "out" : __DIR__"yunzhonglu",
]));


         set("objects", ([
                 "/d/huashan/npc/snake" : 1,
          ]) );
        set("no_clean_up", 0);

	set("cost", 2);
        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "你点燃了火折，发现西面石壁上有一道裂缝，似乎可以钻(zuan)出去。\n"
             );
             return 1;
       }
}

int do_zuan(string arg)
{
	object me = this_player();

        if (me->query_temp("mark/猴子") ) {
            message("vision", me->name() + "滋溜一下不知从什么地方钻出去了。\n",
                    environment(me), ({me}) );
            me->move("/d/huashan/yunzhongcave2");
            message("vision", me->name() + "从石缝里钻了出来。\n",
                    environment(me), ({me}) );

            return 1;
          }
        else {
            write("你想往哪儿钻?!\n");
            return 1;
        }
}


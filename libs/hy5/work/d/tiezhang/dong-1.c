// room: dong-1.c
// zqb


inherit ROOM;


void create()
{
        set("short", "山洞");
        set("long", @LONG
    一个黑漆漆的山洞，黑沉沉的一眼望不到底。两侧的石壁上生满的
苔藓，摸起来又湿又滑。这石洞似乎是人工开凿的，从四周的石壁上仍能看
出斧凿的痕迹。你站在这里，一股恐惧由然而生，似乎身体随时都会被这片
黑暗吞噬掉。
LONG
        );
        set("exits", ([
            "out" : __DIR__"dezj",
            "enter" : __DIR__"dong-2",
]));

        set("objects", ([
               
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_use", "use");
//        add_action("do_zuan", "zuan");
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
             this_player()->set_temp("marks/钻", 1);
             return 1;
       }
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/钻") ) {
            message("vision", me->name() + "滋溜一下不知从什么地方钻出去了。\n",
                    environment(me), ({me}) );
            me->move(__DIR__"cave2");
            message("vision", me->name() + "从石缝里钻了出来。\n",
                    environment(me), ({me}) );
            this_player()->set_temp("marks/钻", 0);

            return 1;
        }
        else {
            write("你想往哪儿钻?!\n");
            return 1;
        }
}


inherit ROOM;

int do_use(string arg);
int do_zuan(string arg);

void create()
{
        set("short", "密道");
        set("long", @LONG
在密道中阴风逼人。光线极暗，什么也看不清。
LONG
        );

        set("exits", ([
                "up" : __DIR__"woshi",
                "north" : __FILE__,
                "south" : __FILE__,
                "west" : __FILE__,
                "east" : __FILE__,
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
        add_action("do_use", "use");
        add_action("do_zou", "zou");
}

int do_use(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "你点燃了火折，发现密道中似乎有一条路可以(zou)下去。\n"
             );
             this_player()->set_temp("marks/走1", 1);
             return 1;
       }
}

int do_zou(string arg)
{
        object me;
        me = this_player();

        if (me->query_temp("marks/走1") ) {
            message("vision", me->name() + "消失在一阵黑暗之中。\n",
                    environment(me), ({me}) );
            me->move(__DIR__"midao_out");
            message("vision", me->name() + "从密室里爬了出来。\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/走1");

            return 1;
        }
        else {
            write("你想往哪儿走?!\n");
            return 1;
        }
}


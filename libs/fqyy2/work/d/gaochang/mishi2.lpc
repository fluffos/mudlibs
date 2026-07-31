// Room: /d/gaochang/mishi2.c

inherit ROOM;

int do_study(string arg);

void create()
{
        set("short", "地下室");
        set("long", @LONG
这里是宫殿底下的地下密室。密室虽小，却也五脏俱全，
石桌石椅，石几石床，连室内放的几件器皿，也都是石制的。
看来似乎很久以前有人在这里住过。正中的石桌(table)上平
放着一块薄薄的石板，上面好象刻着些什么。
LONG
        );
    set("exits", ([
       "south" : __DIR__"mishi",
]) );
   set("objects", ([
// "/clone/book/skybook" : 1,
       ]) );

        set("item_desc", ([
                "table" : "这是一整块巨石雕成的石桌，上面刻了些奇怪的图形。\n",
        ]));

        setup();
}

void init()
{
        add_action("do_study", "study");
}


int do_study(string arg)
{
        object me;
        int    jing_cost;

        me = this_player();

        if ( !arg || ( arg != "table" ) )
                return notify_fail("什么？\n");

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

        jing_cost = (-1) * random(2);
        if((int)me->query("jing") < jing_cost)
                return notify_fail("你现在精神无法集中！\n");

        me->add("jing", jing_cost);

        message_vision("$N正专心研读石桌上的古怪图形。\n", me);
 if ( (int)me->query_skill("literate", 1) < 150)


                {
                        me->improve_skill("literate", me->query("int")*10);
                        write("你对着石桌琢磨了一回儿，似乎对读书识字有点心得。\n");
                        me->set_temp("stone_learned",1);
                }


        if ( !me->query_temp("stone_learned") )
        {
                write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
        }
        return 1;
}


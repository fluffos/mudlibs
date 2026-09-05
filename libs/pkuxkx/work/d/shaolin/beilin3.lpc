// Room: /d/shaolin/beilin3.c
// Date: YZC 96/01/19
// Modified by iszt@pkuxkx, 2007-03-10, study by times

inherit ROOM;

int do_study(string);

void create()
{
        set("short", "地下室");
        set("long", @LONG
这里是佛塔底下的地下密室。密室虽小，却也五脏俱全，
石桌石椅，石几石床，连室内放的几件器皿，也都是石制的。
看来似乎很久以前有人在这里住过。正中的石桌上平放着一块
薄薄的石板，上面好象刻着些什么。
LONG
        );

        set("objects",([
                "d/shaolin/obj/book-stone" : 1,
        ]));

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
        object me = this_player();
        int times = 0, stone_learned = 0;

        if(me->is_busy())
                return notify_fail("你正忙着呢。\n");
        if(!arg || (sscanf(arg, "table %d", times) != 1 && arg != "table"))
                return notify_fail("你要读什么？\n");
        if(!times)
                times = 1;
        if(times > 50)
        {
                write("学习次数不能超过五十次。\n");
                return 1;
        }

        if ( (int)me->query_skill("literate", 1) < 1)
        {
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if ((int)me->query("jing") < 20 * times)
        {
                write("你已经很累了，歇歇再读吧。\n");
                return 1;
        }
        me->receive_damage("jing", 20 * times);

        message_vision("$N正专心研读石桌上的古怪图形。\n", me);

        switch( random(5) ) 
        {
            case 0:
                if ( (int)me->query_skill("finger", 1) < 100)
                {
                        me->improve_skill("finger", me->query("int") * times);
                        write("你对着石桌琢磨了一回儿，似乎对指法有点心得。\n");
                        stone_learned = 1;
                }
                break;
            case 1:
                if ( (int)me->query_skill("claw", 1) < 100)
                {
                        me->improve_skill("claw", me->query("int")*2 * times);
                        write("你对着石桌琢磨了一回儿，似乎对爪法有点心得。\n");
                        stone_learned = 1;
                }
                break;
            case 2:
                if ( (int)me->query_skill("strike", 1) < 100)
                {
                        me->improve_skill("strike", me->query("int")*3 * times);
                        write("你对着石桌琢磨了一回儿，似乎对掌法有点心得。\n");
                        stone_learned = 1;
                }
                break;
            case 3:
                if ( (int)me->query_skill("cuff", 1) < 100)
                {
                        me->improve_skill("cuff", me->query("int")*3 * times);
                        write("你对着石桌琢磨了一回儿，似乎对拳法有点心得。\n");
                        stone_learned = 1;
                }
                break;
            case 4:
                if ( (int)me->query_skill("hand", 1) < 100)
                {
                        me->improve_skill("hand", me->query("int")*2 * times);
                        write("你对着石桌琢磨了一回儿，似乎对手法有点心得。\n");
                        stone_learned = 1;
                }
        }

        if(!stone_learned)
                write("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
        return 1;
}

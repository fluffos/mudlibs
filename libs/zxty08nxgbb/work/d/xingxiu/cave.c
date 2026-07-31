// room: /d/xingxiu/cave.c
// Mei 7/12/98
inherit ROOM;
int do_use(string arg);
int do_study(string arg);
void create()
{
        set("short", "山洞");
        set("long", @LONG
这个山洞里伸手不见五指，只有出口处透进一丝光线。
LONG
        );
        set("exits", ([
            "out" : __DIR__"tianroad5",
]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_use", "use");
        add_action("do_study", "study");
}
int do_use(string arg)
{
        object me,ob;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!ob=present("fire", me))  return 0;
        if(me->query_temp("marks/钻"))
         return 0;
        if( arg=="fire" ) {
             write(
             "你点燃了火折，发现西面石壁上画有一幅老僧持刀图，及一些乱七八糟的线条。\n"
             );
        me->set_temp("marks/钻", 1);
        set("long", @LONG
山洞西面石壁上画有一幅老僧持刀图，及一些乱七八糟的线条。
LONG
        );
             call_out("dest_fire",300,me,ob);
             return 1;
       }
}
int do_study(string arg)
{
        object me;
        int jing_cost;
        int skill;
        me = this_player();

        if ( !arg || ( arg != "tu" ) )
                return notify_fail("你要读什么？\n");

        if (!me->query_temp("marks/钻")){
                tell_object(me,"四周一片漆黑你要读什么？\n");
                return 1;
        }

        if ( (int)me->query_skill("literate", 1) < 1){
                write("你是个文盲，先学点文化(literate)吧。\n");
                return 1;
        }

        if ( (int)me->query_int() < 35){
                write("你的悟性不够，先学点文化(literate)吧。\n");
                return 1;
        }

        jing_cost = me->query("max_jing")/10;
        if((int)me->query("jing") < jing_cost){
                write("你现在眼花缭乱，精疲力尽了。\n");
                return 1;
        }
        me->receive_damage("jing", jing_cost );

        message_vision("$N正以掌作刀模仿石壁上的古怪图案，比划了几下。\n", me);
        
        write("你对着图案琢磨了一回儿，似有所悟。\n");
        skill=(int)me->query_skill("blade", 1);
        if ( skill < 450 && random(10)>5 && skill*skill*skill/20 < me->query("combat_exp")){
                        me->improve_skill("blade", me->query_int());
                }
        return 1;
}   
void dest_fire(object me,object ob)
{
        if (!me || !ob) return;
        message("vision",HIB"插在石壁上的"+ob->name()+"燃尽了。\n"NOR,this_object());
        me->delete_temp("marks/钻");
        destruct(ob);
        set("long", @LONG
这个山洞里伸手不见五指，只有出口处透进一丝光线。
LONG
        );
}


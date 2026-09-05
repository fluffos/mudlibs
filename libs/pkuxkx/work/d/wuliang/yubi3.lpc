// by paladin

inherit ROOM;

void create()
{
set("short","大石壁");
        set("long", @LONG
这面石壁比刚才的要大. 站在两面镜子之间，大镜子便能照出了小镜子中的像. 
石壁上隐隐似有彩色流动，凝神瞧去, 赫然有一把长剑的影子. 剑尖斜指向下，
而剑影中更发出彩虹一般的晕光，闪烁流动，游走不定. 西首峭壁之后，峭壁
(stiff)上有一洞孔. 
LONG
        );
        set("outdoors", "dali");

        set("no_fight", 1);

        set("exits", ([
           "east" : __DIR__"yubi",
        ]));


        setup();

}

void init()
{
add_action("do_climb","climb");
}


int do_climb(string arg)
{
        object me=this_player();
/*
        if (!arg || arg!="stiff") {
                write("你要爬什么？\");
                return 0; }

        else { */
        me->set_temp("times",3);
        message_vision("$N一咬牙，用手指扣住崖上的岩石，手脚并用向上爬去。\n",me);
//        remove_call_out("climbing");
        call_out("climbing",1,me);
        return 1;
}

int climbing(object me)
{
        int times=me->query_temp("times");
        int skl=(int)me->query_skill("dodge",1);
        int hurt=(int)me->query("max_qi")/3;

        if (times==3) {
        me->move(__DIR__"stiff");
        me->start_busy(5);
        me->add_temp("times",-1);
        call_out("climbing",5,me);
        return 1;}

        if (times==2 || times==1)
    {
       if (skl<250 && random(300-skl)>50) {
        tell_object(me,"突然你突然脚下踏了个空，向下一滑，听得一声惨叫：啊...... 直坠而下。\n");
        me->move(__DIR__"yubi");
        me->receive_wound("qi", hurt, "爬大石壁摔下来");
        message("vision","忽听得崖上一声惨叫，只见" + (string)me->name() + "从半空摔将下来......\n",
                environment(me),me);
        me->unconcious();
        me->delete_temp("times");
        return 1;}
        me->start_busy(5);
        message_vision("$N手扯草根，脚踏岩缝，在凛冽的山风中艰难的向上爬着。\n", me);
        me->add_temp("times",-1);
        call_out("climbing",5,me);
        return 1;
    }
        if (times==0) {
        tell_object(me,"你终于爬到崖洞中\n");
        me->move(__DIR__"yadong");
        return 1;
        }
}

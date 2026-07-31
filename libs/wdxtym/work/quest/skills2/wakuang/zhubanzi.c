// zhujia.c 铸甲房
// 星星lywin 2000/9/2 

#include <ansi.h>
inherit ROOM;
int do_zhujia(string arg);

 void create()
{
        set("short", "铸板指房");
        set("long", @LONG
这是一个很平常普通的铸板指房！四周都是乱七八糟的铜皮铁块，人们
把捡来的矿石在这儿炼化以后铸造成各种名板指。
LONG
        );

        set("exits", ([
                "west" : __DIR__"zhudao",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
}

void init()
{
        add_action("do_zhujia","zhubanzi"); 
        add_action("do_quit","quit");
        add_action("do_quit","exit");
        add_action("do_quit","exercise");
        add_action("do_quit","dazuo");
        add_action("do_quit","exert");
        add_action("do_quit","learn"); 
        add_action("do_quit","yun");
        add_action("do_quit","xue");
        add_action("do_quit","respirate");
        add_action("do_quit","tuna"); 
        add_action("do_quit","fight");
        add_action("do_quit","hit");
        add_action("do_quit","perform");
        add_action("do_quit","persuade");
        add_action("do_quit","quanjia");
        add_action("do_quit","practice");
        add_action("do_quit","lian"); 
        add_action("do_quit","study");
        add_action("do_quit","du");
        add_action("do_quit","teach");
        add_action("do_quit","jiao");
}

int do_zhujia(object ob)
{
        object me,ob1;
        int b1,b2;
        me=this_player();
        b1 = this_player()->query("work/zhubanzi");
        
        if (!(ob = present("tong kuang", this_player())) &&
             !(ob = present("tie kuang", this_player())) &&
             !(ob = present("ying kuang", this_player())) &&
             !(ob = present("jing kuang", this_player())) &&
             !(ob = present("xuantie kuang", this_player())) &&
             !(ob = present("han tie", this_player())) )
                return notify_fail("你身上没有矿石，如何铸板指？\n");
                 
        if ( (int)me->query("jing")<100)
                return notify_fail("你的精力不足，无法铸板指。\n");

        if( me->is_busy() )
                return notify_fail("你现在很忙！不能铸板指！\n");

        if ( (int)me->query("qi")<100)
                return notify_fail("你的体力不足，无法铸板指。\n");

        if ( (int)me->query("neili")<150)
                return notify_fail("你的内力不足，无法铸板指。\n");

        message_vision(HIY"$N先将矿石放进炉中炼化成块状状。\n"NOR,me); 
        message_vision(HIY"接着$N再拿出一个大锤开始铸板指。\n"NOR,me); 
        message_vision(HIY"不一会儿！一只很好的板指摆在了$N的面前。\n"NOR,me); 
        if (me->query("combat_exp")<1000000)
        {
        me->add("combat_exp",20+random(30));
        me->add("potential",15+random(25));
        }
        else 
        {
        me->add("combat_exp",6+random(19));
        me->add("potential",6+random(15));
        }
        me->add("jing",-50);
        me->add("qi",-80);
        me->add("neili",-100);
        me->start_busy(6); 

        if ( ob->query("name") ==YEL"铜矿石"NOR )
        {
        destruct(ob);             
        ob1=new(__DIR__"weapon/banzi/banzi1");
        b2 = b1/8;
        if ( b2 < 20) b2 = 1000;
        if ( b2 > 50) b2 = 2000;
	ob1->set("value", 2000);
        ob1->move(me);
        me->add("work/zhubanzi", 1);       
        return 1;
        }
        if ( ob->query("name") ==CYN"铁矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 70 ) 
        {
        me->add("work/zhubanzi",1);
        return notify_fail("由于你铸板指之技太低，板指根本不能用！\n");
        }
        ob1=new(__DIR__"weapon/banzi/banzi2");
        b2 = b1/8;
        if ( b2 < 20) b2 = 2500;
        if ( b2 > 50) b2 = 5000;
        ob1->set("value", 5000);
        ob1->move(me);
        me->add("work/zhubanzi", 1);       
        return 1;
        }
        if ( ob->query("name") ==HIW"银矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 150 )
        {
        me->add("work/zhubanzi",1);
        return notify_fail("由于你铸板指之技太低，板指根本不能用！\n");
        }
        ob1=new(__DIR__"weapon/banzi/banzi3");
        b2 = b1/6;
        if ( b2 < 30) b2 = 5000;
        if ( b2 > 80) b2 = 10000;
        ob1->set("value", 10000);
        ob1->move(me);
        me->add("work/zhubanzi", 1);       
        return 1;
        }
        if ( ob->query("name") ==HIY"金矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 220 )
        {
        me->add("work/zhubanzi",1);
        return notify_fail("由于你铸板指之技太低，板指根本不能用！\n");
        }
        ob1=new(__DIR__"weapon/banzi/banzi4");
        b2 = b1/5;
        if ( b2 < 50) b2 = 15000;
        if ( b2 > 150) b2 = 30000;
        ob1->set("value", 30000);
        ob1->move(me);
        me->add("work/zhubanzi", 1);       
        return 1;
        }
        if ( ob->query("name") ==WHT"玄铁矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 300 )
        {
        me->add("work/zhubanzi",1);
        return notify_fail("由于你铸板指之技太低，板指根本不能用！\n");
        }
        ob1=new(__DIR__"weapon/banzi/banzi5");
        b2 = b1/4;
        if ( b2 < 80) b2 = 30000;
        if ( b2 > 200) b2 =60000;
        ob1->set("value", 60000);
        ob1->move(me);
        me->add("work/zhubanzi", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIG"寒铁矿石"NOR )
        {
        destruct(ob);             
        if ( b1 < 400 )
        {
        me->add("work/zhubanzi",1);
        return notify_fail("由于你铸板指之技太低，板指根本不能用！\n");
        }
        ob1=new(__DIR__"weapon/banzi/banzi6");
        b2 = b1/3;
        if ( b2 < 120) b2 = 50000;
        if ( b2 > 400) b2 = 100000;
        ob1->set("value", 100000);
        ob1->move(me);
        me->add("work/zhubanzi", 1);       
        return 1;
        }
        else
        if ( ob->query("name") ==HIR"千年寒铁"NOR )
        {
        destruct(ob);             
        if ( b1 < 500 )
        {
        me->add("work/zhubanzi",1);
        return notify_fail("由于你铸板指之技太低，板指根本不能用！\n");
        }
        ob1=new(__DIR__"weapon/banzi/banzi7");
        if ( b1 > 1000 )
        {
        ob1=new(__DIR__"weapon/banzi/banzi8");
        }
        b2 = b1/2;
        if ( b2 < 200) b2 = 75000;
        if ( b2 > 600) b2 = 150000;
        ob1->set("value", 150000);
        ob1->move(me);
        me->add("work/zhubanzi", 1);       
        return 1;
        }
} 

int do_quit(string arg)
{
        write(this_player()->query("name")+"，安心的铸板指吧！\n");
        return 1;
}

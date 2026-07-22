#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "铸鞭房");
        set("long", @LONG
这是一个很平常普通的铸鞭房！四周都是乱七八糟的铜皮铁块，人们
把捡来的矿石在这儿炼化以后铸造成各种长鞭。
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
        add_action("do_zhubian","zhubian");
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
        add_action("do_quit","kill");
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
int do_zhubian(object ob)
{
        object me;
        me=this_player();

        if (!(ob = present("tong kuang", this_player())) &&
            !(ob = present("tie kuang", this_player())) &&
            !(ob = present("ying kuang", this_player())) &&
            !(ob = present("jing kuang", this_player())) &&
            !(ob = present("xuantie kuang", this_player()))&&
            !(ob = present("han tie", this_player())) )
            return notify_fail("你身上没有矿石，如何铸造长鞭？\n");

        if ( (int)me->query("jing")<100)
            return notify_fail("你的精力不足，无法铸造长鞭。\n"); 

        if( me->is_busy())
            return notify_fail("你现在很忙！不能铸造长鞭！\n");

        if ( (int)me->query("qi")<100)
                return notify_fail("你的体力不足，无法铸造长鞭。\n");

        if ( (int)me->query("neili")<150)
                return notify_fail("你的内力不足，无法铸造长鞭。\n");

        message_vision(HIY"$N先将矿石放进炉中炼化成块状状。\n"NOR,me);
        message_vision(HIY"接着$N再拿出一个大锤开始铸造长鞭。\n"NOR,me);
        message_vision(HIY"不一会儿！一只很好的长鞭摆在了$N的面前。\n"NOR,me);
        me->add("combat_exp",50+random(20));
        me->add("potential",25+random(5));
        me->add("jing",-50);
        me->add("qi",-80);
        me->add("neili",-100);
        me->start_busy(6);

        if(present("tong kuang", me))
        {
        new(__DIR__"weapon/bian/bian1")->move(environment(me));
        me->add("work/zhubian", 1);
        destruct(ob);
        return 1;     
        } else
        if(present("tie kuang", me) && me->query("work/zhubian")>100)
        {
        new(__DIR__"weapon/bian/bian2")->move(environment(me));
        me->add("work/zhubian", 1);
        destruct(ob);
        return 1;     
        }else
        if(present("ying kuang", me) && me->query("work/zhubian")>200)
        {
        new(__DIR__"weapon/bian/bian3")->move(environment(me));
        me->add("work/zhubian", 1);
        destruct(ob);
        return 1;     
        }else
        if(present("jing kuang", me) && me->query("work/zhubian")>300)
        {
        new(__DIR__"weapon/bian/bian4")->move(environment(me));
        me->add("work/zhubian", 1);
        destruct(ob);
        return 1;     
        }else
        if(present("xuantie kuang", me) && me->query("work/zhubian")>400)
        {
        new(__DIR__"weapon/bian/bian5")->move(environment(me));
        me->add("work/zhubian", 1);
        destruct(ob);
        return 1;     
        }else
        if(present("han tie", me) && me->query("work/zhubian")>500)
        {
        new(__DIR__"weapon/bian/bian6")->move(environment(me));
        me->add("work/zhubian", 1);
        destruct(ob);
        return 1;     
        }else
        {
        write("可是你的铸造技术太差了，铸造的兵器根本不能用！\n");
        destruct(ob);
        return 1;     
        }

}
int do_quit()
{
        write("你还是好好的铸造兵器吧！\n");
        return 1;
}


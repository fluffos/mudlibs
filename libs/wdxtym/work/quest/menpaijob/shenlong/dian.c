          // dian.c
#include <ansi.h>;
inherit ROOM;

int piaodown(object me);
int piaoup(object me);
string* haiyu = ({
        "dashayu",
        "dajqy",
        "jqy",
        "dahaiyu",
        "haiyu",
        "xiami"
});

void create()
{
        set("short", "天然堤岸");
        set("long", @LONG
你走到一道岩石天然形成的堤岸上，堤岸一直延伸的海的中间，尽头有一个小
弯，挡住了汹涌的海涛，恰巧形成一个水流平静的深潭。透过清澈的海水，你看见
几尾海鱼正在悠闲的游来游去。
LONG
        );
        set("exits", ([
                        "west" :"/d/shenlong/haitan" ,
                        "east" :__DIR__"dian1" ,
        ]));

        setup();

}

void init()
{
        add_action("do_dy","diaoyu");
        add_action("do_tai","tai");
}

int do_dy(string arg)
{
        object obgan, obhaiyu, me,obj;
        int i;
int maxpot;
        me = this_player();
        
        if( me->is_busy() )
                        return notify_fail("你正忙着呢！\n");
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
        if( me->query("family/family_name") != "神龙教")
        return notify_fail("这里只允许神龙弟子钓鱼!\n");
        if( !me->query_skill("shenlong-xinfa"))
        return notify_fail("你没有神龙心法!\n");
        if ( me->query_temp("fishing",1)==1 )
                return notify_fail("你不是正在钓鱼么？\n");
        if (! (obgan = present("diaoyu gan", me)) )
                return notify_fail("你想怎么钓？用手么？\n");
        if ( me->query_temp("fishing") )
                return notify_fail("你不是正在钓鱼么？\n");
        if ( ! (obgan->query("yuer")) )
        {
                message_vision("$N将手中的空钓鱼钩抛向水中，颇有当年姜太公之风范。\n", me);
                return 1;
        }

        message_vision("$N将手中的钓鱼杆一挥，钓线远远的甩将出去，鱼漂静静的漂浮在水中。\n", me);       
        me->start_busy(3);
        me->set_temp("fishing", 1);

if( !environment(me)->query("no_fight"))
{
if (random(40)==1 && me->query("combat_exp") > 1000000)
{
obj=new(__DIR__"menggu"); 
obj->move(environment(me));
obj->do_copy(me,maxpot,2);
obj->set("title",HIC"清兵先锋"NOR);
obj->set("usename",me->query("name"));
me->start_busy(1);
message_vision(HIC"从海上开来一只小船，船上冲下一名清兵！\n"NOR, obj);
message_vision(HIR"$N说道：我奉命，请来消灭你等妖人！\n"NOR, obj);
me->kill_ob(obj);
obj->kill_ob(me);
return 1;
}
}    
        call_out("piaodown", 10+random(20), me);
        
        return 1;
}
        
 
int do_tai(string arg)
{
        object obgan, obhaiyu, me;
        int i, yunum;
int exp,pot;
        me = this_player();
        
        if( me->is_busy() )
                        return notify_fail("你正忙着呢！\n");
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");

        if (! (obgan = present("diaoyu gan", me)) )
                return notify_fail("你想抬起什么？\n");
        if ( ! me->query_temp("fishing") )
        {
                 message_vision("只见$N把手中的鱼杆四下挥舞了几下，就好象是在发神经。\n", me);
                  return 1;
        }
        me->delete_temp("fishing");
       if ( ! obgan->query("yuer") )
        {
                  message_vision("只见$N把手中的鱼杆猛的向上一抬，钓线前面只有一个亮晶晶的鱼钩。\n", me);
                return 1;
        }
        obgan->delete("yuer");
        if( ! obgan->query("hasfish") )
        {
                message_vision("只见$N把手中的鱼杆猛的向上一抬，钓线前鱼钩上穿着半条蚯蚓。\n",  me);
                return 1;
        }
        obgan->delete("hasfish");
        yunum = me->query_temp("canqi")-random(5);
//       printf("beryunum = %d\n", yunum);
        if( yunum < 0 )
                yunum = 0;
        if( yunum > 5 )
                yunum = 5;
        yunum = 5 -random(yunum);
//        printf("aftyunum = %d\n", yunum);
        me->delete_temp("canqi");
        obhaiyu = new(__DIR__"obj/" + haiyu[yunum]);
        message_vision("只见$N手握钓竿用力一甩，一条" + obhaiyu->name()
                        + "被钓了上来！\n", me);
        obhaiyu->move(me);
exp=32+random(20);    
pot=28+random(10);    
                        me->add("combat_exp", exp);
                        me->add("potential", pot);
             tell_object(me,HIW"你被奖励了：" + chinese_number(exp)
               + "点实战修为，"+ chinese_number(pot) + "点潜能。\n"NOR);
me->start_busy(2);
        return 1;       
}




int piaodown(object me)
{
        object obgan;
if (!me) return 1;
        if ( ! me->query_temp("fishing") )
                return 1;
        if (! (obgan = present("diaoyu gan", me)) )
                return 1;
        if ( ! (obgan->query("yuer")) )
                return 1;
        message_vision("只见$N的鱼漂在水中动了几下，猛的向下一沉......\n", me);
        call_out("piaoup", 2, me);
        obgan->set("hasfish", 1);
        if ( ! me->query_temp("canqi") )
                me->set_temp("canqi", 1);
        else if ( me->query_temp("canqi") < 10 )
                me->add_temp("canqi", 1);
        
        return 1;
}

int piaoup(object me)
{
        int odds;
        object obgan;
if (!me) return 1;
        obgan = present("diaoyu gan", me);

        if ( ! me->query_temp("fishing") )
                return 1;
    
        odds = me->query_temp("canqi");
        message_vision("只见$N的鱼漂在水中一颤，又猛的向上了浮出来！\n", me);
        obgan->delete("hasfish");
        if ( random(odds) >= 2)
                obgan->delete("yuer");
        call_out("piaodown", 2+random(5), me);
        return 1;
}


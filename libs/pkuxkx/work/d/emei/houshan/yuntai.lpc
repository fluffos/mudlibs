//  云台
// by yuntai

#include <ansi.h>
inherit ROOM;

int inc(object me);
void init()
{
add_action("do_jingzuo","jingzuo");
}

void create()
{
        set("short", "云台");
        set("long", @LONG
这是金顶上的一个云台，一些峨嵋弟子在这里静坐。
LONG
        );

        set("exits", ([
                "south" : __DIR__"jinding",
        ]));
        set("no_perform",1);
        set("no_exert",1);
        set("no_fight",1);
        setup();
}
int do_jingzuo()
{       object me=this_player();
        mapping fam;

        if (!(fam=me->query("family")) || fam["family_name"]!="峨嵋派")
        return notify_fail("你又不是峨嵋派弟子，在这里凑什么热闹！\n");

        if((int)me->query_skill("mahayana",1)<150)
        return notify_fail("你在大乘涅磐功上尚且达不到可以无师自通的地步！\n");

        if((int)me->query("jing")<(int)me->query("max_jing"))
        return notify_fail("你心神无法专一，怎能静坐？\n");
        
        if((int)me->query("qi")<(int)me->query("max_qi"))
        return notify_fail("你气血亏缺，无法静下心来静坐！\n");

        if (me->is_busy())
        return notify_fail("你现在无法静下心来静坐！\n");

        me->set_temp("duration",6);
        if (me->query_skill("emei-jiuyanggong",1)>60)
        {
            me->set_skill("emei-jiuyanggong",60);
            write(HIR+BNK+"你的峨嵋九阳功被恢复到六十级。\n"+NOR);
        }
        inc(me);
        return 1;
}

int inc(object me)
{       
        int dur,inc,limit_sk;
        if (!me||!living(me)||base_name(environment(me))!="/d/emei/houshan/yuntai")
        {
            return 1;
        }
        dur=me->query_temp("duration");
        inc=(int)me->query_skill("mahayana",1)*1*(int)me->query("int")/30;
        limit_sk=to_int(pow((int)me->query("combat_exp")/100,0.333)*10)/25;
        if (dur==6&&base_name(environment(me))=="/d/emei/houshan/yuntai"){
        tell_object(me,"你盘膝坐下，身躯挺直，双手结定印于肚脐前，心中默念“南无阿弥陀佛”。\n"
              WHT"渐渐的你心如止水，开始神游太虚。\n"NOR);
        message("vision", 
                me->name() + "坐在金顶上，盘膝坐下，口中仿佛念念有词。\n",environment(me),me);
        me->add_temp("duration",-1);
        me->start_busy(10);
        call_out("inc",5,me);
        return 1;
        }

        if (dur<6 && dur>0&&base_name(environment(me))=="/d/emei/houshan/yuntai") {
        tell_object(me,HIW"你闭目冥想佛学中的真谛，心中的疑惑逐渐释然，对大乘涅磐功的理解也更进了一步。\n"NOR);
        me->improve_skill("mahayana",inc);
        me->add_temp("duration",-1);
        me->start_busy(30);
        call_out("inc",5,me);
        return 1;}
                
        if (dur==0&&base_name(environment(me))=="/d/emei/houshan/yuntai"){
        message_vision("$N静坐完毕，收心定神，满心释然的站了起来。\n",me);
        me->start_busy(0);
        if (me->query("emeinewbiejobdone")&&me->query("family/family_name")=="峨嵋派"&&me->query("emeinewbiejobdonedone")&&me->query("safari_skill/em_jyg")&&
                me->query_skill("emei-jiuyanggong",1)>1&&((int)me->query_skill("emei-jiuyanggong",1)*50+random(10000)>9500||wizardp(me))&&me->query_skill("emei-jiuyanggong",1)<limit_sk&&me->query_skill("emei-jiuyanggong",1)<60)
            {
                me->improve_skill("emei-jiuyanggong",1+random(2));
                if (me->query_skill("emei-jiuyanggong",1)!=10&&me->query_skill("emei-jiuyanggong",1)!=20
                    &&me->query_skill("emei-jiuyanggong",1)!=30&&me->query_skill("emei-jiuyanggong",1)!=40
                    &&me->query_skill("emei-jiuyanggong",1)!=50)
                {
                    me->improve_skill("emei-jiuyanggong",1+random(2*(int)me->query_skill("emei-jiuyanggong",1)));
                }
                tell_object(me,HIW"你的峨嵋九阳功获得了些许进步！\n"NOR);
            }
       
        return 1;}
}

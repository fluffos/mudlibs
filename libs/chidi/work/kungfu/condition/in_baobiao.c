#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
        object yuanwai = present("zhang yuanwai",environment(me));
        if(duration!=1) return 0;
        if(!yuanwai) yuanwai = find_living("zhang yuanwai");
        if(!yuanwai) {
                me->set("title",me->query("baktitle")?me->query("baktitle"):me->
query("title"));
                me->del_condition("in_baobiao");
                me->del_temp("baobiaod");
                return 1;
        }
        yuanwai->command("tell "+me->query("id")+"你怎么不来保护我？看来你是不愿
意做了，我也不勉强了");
        me->set("title",me->query("baktitle")?me->query("baktitle"):me->query("t
itle"));
        me->del_condition("in_baobiao");
        me->del_temp("baobiaod");
        yuanwai->add("baobiao",-1);
        return 1;
}


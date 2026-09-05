// tupo.c 
// Zine 2012/10/14
#include <ansi.h>
#include "special_permit.h"
inherit F_CLEAN_UP;
int help(object me);
int tupo(object me)
{
    if (me)
    {
        me->delete_temp("mingspecial/tupo");
        tell_object(me,"突破特技使用过良久，你的气息终于调匀下来。\n");
        return 1;
    }
}
int main(object me,string arg)
{
    object room=environment(me);
    string need="tuji";
    if (arg=="-h")
	return help(me);
	if (special_permit(me,need)==0)
    {
		return 1;
    }
    if (!me->is_fighting())
    {
        tell_object(me,"你不在战斗中，还要怎么突破？走过去就可以了。\n");
        return 1;
    }
    
    else
    {
        mapping exits;
        string *dirs;
        string dir;
        object dest;
        int i;

        if(!environment(me)) 
        {
            tell_object(me,"此地诡异非常，没有可以突破的方向。\n");
            return 1;
        }
        if(sizeof(environment(me)->query("exits")) == 0) 
        {
            tell_object(me,"此地诡异非常，没有可以突破的方向。\n");
            return 1;
        }
        if( !mapp(exits = environment(me)->query("exits")) ) 
        {
            tell_object(me,"此地诡异非常，没有可以突破的方向。\n");
            return 1;
        }
        if ((int)me->query("neili")<(int)me->query("max_neili")/2)
        {
            tell_object(me,"你的内力太少，根本无法突破！\n");
            return 1;
        }
        if (me->query_temp("mingspecial/tupo"))
        {
            tell_object(me,"你刚刚使用过突破特技，现在气血汹涌。\n");
            return 1;
        }
        if (random(100)>10)
        {
            dirs = keys(exits);
            dir = dirs[random(sizeof(dirs))];
            dest = exits[dir];
            message_vision(HIR"$N大喝一声，不顾敌人攻击，开始奋力突破。\n"NOR,me);
            me->set("neili",0);
            tell_room(dest,me->query("name")+"大喝一身，冲了过来。\n");
            me->move(dest);
            me->set_temp("mingspecial/tupo",1);
            remove_call_out("tupo");
            call_out("tupo",5+random(10),me);
            return 1;
        }
        else
        {
            tell_object(me,"你陷入战团，全未能突破出去。\n");
            me->set_temp("mingspecial/tupo",1);
            remove_call_out("tupo");
            call_out("tupo",3+random(5),me);
            return 1;
        }
        
    }
}
int help(object me)
{
    write("
指令格式 : ming wencai
突破敌人封锁，需要大明特技突击。
"    );
    return 1;
}

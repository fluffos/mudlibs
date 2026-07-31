// kill.c
#include <ansi.h>
#include <localtime.h>
inherit F_CLEAN_UP;
#include "/quest/givegift.c"
#include "/quest/where.h"
int main(object me, string arg)
{
    int my_idle,your_idle;
    object obj,ob;
    string callname,msg;
    	 mapping target;
    	int exp,pot,score;
    	int m;
	mixed *ltime;
	string time;
	ltime = localtime(time());
	m = ltime[LT_MIN];
//return notify_fail("你想找谁对练武功？\n"+m);
    if (!me)    return 0;



    if( !arg )
        return notify_fail("你想找谁对练武功？\n");

    if( !me->query_temp("obj/liangong"))
    {
                tell_object(me,"你现在没有练功的任务。\n");
                return 1;
    } 
    
	if( (int)me->query("jing") < me->query("max_jing")/10 )
{
	        return notify_fail("你的精不够了。\n");
}
    
	if( (int)me->query("qi") < me->query("max_qi")/10 )
{
	        return notify_fail("你的气不够了。\n");
}


    if(!objectp(obj = present(arg, environment(me))) || !me->visible(obj))
        return notify_fail("这里没有这个人。\n");

    if( environment(me)->query("no_fight") && !obj->query_condition("killer"))
        return notify_fail("这里不准对练。\n");

     if( obj->query("env/no_fight") )
        return notify_fail("这个人不想和你对练！\n");
     if( obj->query_temp("no_kill") )
        return notify_fail("这个人不想和你对练！\n");

    if( !obj->is_character() || obj->is_corpse() )
        return notify_fail("看清楚一点，那并不是活物。\n");

    if(obj==me)
        return notify_fail("不能和自己对练额:P。\n");

    if(me->is_busy())
        return notify_fail("你现在正忙。\n");
//免战系统
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("这个人不想和你对练！！\n");

    if(userp(me) && userp(obj) && me->is_fighting() && obj->is_fighting()) 
    {
        return notify_fail("你正在打架啊！\n");
    }

if (userp(obj))
{
	if( (int)obj->query("jing") < obj->query("max_jing")/10 )
	        return notify_fail("对方的精不够了。\n");
    
	if( (int)obj->query("qi") < obj->query("max_qi")/10 )
	        return notify_fail("对方的气不够了。\n");
}



        if( !obj->query("pubduilian") && me->query("family/family_name")  !=  obj->query("family/family_name"))
           {
                      return notify_fail("这个人看来不想和你对练！！\n");
                      //return 1;
            }

        if( obj->query("pubduilian") && me->query("combat_exp",1) >= 2000000)
           {
                      return notify_fail("你的武功已经不能从这里对练学到东西了！！\n");
                      //return 1;
            }

	if( userp(obj) && query_ip_name(obj)==query_ip_name(me) )
	return notify_fail("这个人看来不能和你对练！！\n");

	if( m==obj->query_temp("liangongtime"))
	return notify_fail("这个人才和你对练过,需要休息一会！！\n");
   
msg = "$N对$n行了师门礼，和$n开始对练武功！！\n";
if (me->query_temp("obj/liangong")==8)	message_vision(msg, me, obj);

//message_vision("$N和$n一招一式的对练了起来。\n", me,obj);
//message_vision("$N和$n左一拳，右一掌，打的大汗淋漓。\n", me,obj);
tell_object(me,"你和"+obj->query("name")+"一招一式的对练了起来。\n"NOR);
tell_object(me,"你和"+obj->query("name")+"左一拳，右一掌，打的大汗淋漓。\n"NOR);

    if(userp(obj))
    {
         //me->start_busy(2);
if (!obj->is_busy())
         obj->start_busy(2);
    obj->add("jing",-obj->query("max_jing")/100);
obj->add("qi", -obj->query("max_qi")/100);
    }
    
me->add("jing",-me->query("max_jing")/100);
me->add("qi", -me->query("max_qi")/100);
me->add_temp("obj/liangong",-1);

if( me->query_temp("obj/liangong")<=1)
{
msg = "$N对$n行了师门礼，结束和$n的对练。\n";
	exp = 18+random(18);


	             pot = exp*2/3;
             
             score = pot/2+1;
exp=exp/2;
if ((int)me->query("combat_exp",1) < 12000000 && !me->query("zhuanshen") && !me->query("zhuanbest")  && !me->query("guard/flag"))
{
exp=exp+18;
}


me->add_temp("mpjobn3",1);
 me->add_temp("nbjob34",1);
addnl(me,"exp",exp);
             //me->add("score",score);
if ((int)me->query("combat_exp",1) <= 6000000)
{
if (random(16)==0 && me->query_skill("unarmed",1)< 300 && me->query_skill("unarmed",1)> 1)
{
me->improve_skill("unarmed", score);
tell_object(me,"你的基本拳脚有了进步。\n"NOR);
}
if (random(16)==1 && me->query_skill("dodge",1)< 300 && me->query_skill("dodge",1)> 1)
{
me->improve_skill("dodge", score);
tell_object(me,"你的基本轻功有了进步。\n"NOR);
}
if (random(16)==2 && me->query_skill("force",1)< 300 && me->query_skill("force",1)> 1)
{
me->improve_skill("force", score);
tell_object(me,"你的基本内功有了进步。\n"NOR);
}
if (random(16)==3 && me->query_skill("parry",1)< 300 && me->query_skill("parry",1)> 1)
{
me->improve_skill("parry", score);
tell_object(me,"你的基本招架有了进步。\n"NOR);
}
if (random(16)==4 && me->query_skill("cuff",1)< 300 && me->query_skill("cuff",1)> 1)
{
me->improve_skill("cuff", score);
tell_object(me,"你的基本拳法有了进步。\n"NOR);
}
if (random(16)==5 && me->query_skill("strike",1)< 300 && me->query_skill("strike",1)> 1)
{
me->improve_skill("strike", score);
tell_object(me,"你的基本掌法有了进步。\n"NOR);
}
if (random(16)==6 && me->query_skill("finger",1)< 300 && me->query_skill("finger",1)> 1)
{
me->improve_skill("finger", score);
tell_object(me,"你的基本指法有了进步。\n"NOR);
}

if (random(16)==7 && me->query_skill("hand",1)< 300 && me->query_skill("hand",1)> 1)
{
me->improve_skill("hand", score);
tell_object(me,"你的基本手法有了进步。\n"NOR);
}

}
if (me->query("family/family_name") && random(5)==0 && me->query("combat_exp",1)>300000 )
{
target = wheres[random(sizeof(wheres))];
tell_object(me,obj->query("name")+"告诉你 听说在"+target["chinese"]+"有人在为恶。\n"NOR);
tell_object(me,obj->query("name")+"告诉你 如果你有空可以去"+target["chinese"]+"刺探(citan)一下。\n"NOR);
//message_vision"你得到了新任务:"+target["chinese"]+"除恶!", me, obj);
if (wizardp(me)) tell_object(me,"位置:"+target["weizhi"]+"\n"NOR);
me->set_temp("dl_job_target",target["weizhi"]);
}
message_vision(msg, me, obj);
me->delete_temp("obj/liangong");
obj->set_temp("liangongtime",m);
return 1;
}

    me->start_busy(2);
    return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : duilian <人物>
门派任务指令.可以和本门人物对练武功. 


HELP
    );
    return 1;
}
 

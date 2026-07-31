//lestat 2001

#include <ansi.h>
inherit F_SSERVER;

int exert(object me)
{
        int invocation_time;
        object soldier;
object target;
int skill;
mapping ob_fam; 
        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能化三清。\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这门绝学只能对战斗中的对手使用。\n");
                
                        if((int)me->query_skill("taiyi",1) < 200)
                return notify_fail("你的太乙道法还不够。。。\n");
   


        if((int)me->query_skill("kongdong-xinfa",1) < 200)
                return notify_fail("你的崆峒心法还不够。。。\n"); 
                
        
        if(me->query_skill("taiyi", 1) < 220)
                return notify_fail("以你现在修为还不能化三清。\n");  
        
        if ((!(ob_fam = me->query("family")) || ob_fam["family_name"] != "崆峒派") && userp(me))
return notify_fail("崆峒派才能化三清。\n");  
        
        invocation_time=30+(200-(int)me->query_skill("taiyi"));
        
        if(invocation_time<30) invocation_time=30;
        
        if((time()-me->query_temp("last_invocation"))<invocation_time+30)
                return notify_fail("你刚化过三清，心力不足！\n");

        if ((int)me->query_condition("zdizi_busy"))  
        return notify_fail("你刚化过三清，心力不足！\n");

        if( (int)me->query("neili") < 1000 )
                return notify_fail("你的内力不够了！\n");
   

if (!userp(me) && me->query_temp("nozh"))
	return notify_fail("分身无法再分身！\n");

if (me->query_temp("invoker"))
return notify_fail("分身无法再分身！\n");

if (!userp(me) &&  me->query_temp("zhrs",1)>30)
return notify_fail("超出一次战斗上限。\n");         

        if( (int)me->query("jing") < 500 )
                return notify_fail("你的精神无法集中！\n");

        skill=(int)me->query_skill("kongdong-xinfa",1);
        skill=skill*0.6;
        message_vision(HIG"$N跳出圈子来，把发冠一推，只见顶上三道气出，化为三清。\n"NOR, me);

        me->add("neili", -600);
        me->receive_damage("jing", 300);

        if( random(me->query("max_neili")) < 500 ) 
        {
                message("vision", "但是什么也没有发生。\n",environment(me));
                return 1;
        }
if (!userp(me)) me->add_temp("zhrs",1);
        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set("possessed", me);
        soldier->set_temp("nozh",1);
              soldier->set_name(this_player()->query("name")+"的太清化身",({"dizi"}));
   

        soldier->invocation(me);
        soldier->initlvl(skill,0);
         message_vision(HIG"$N喝道：道友 莫慌,我来助你！\n"NOR, soldier);
        me->set_temp("last_invocation",time());
        me->start_busy(1);
        me->apply_condition("zdizi_busy",5);
        if(me->query_skill("kongdong-xinfa", 1) >= 400)
                call_out("sanqing2", 1, me, target);   
        return 1;
}

int sanqing2(object me, object target)
{
        object soldier;
        int skill;
        skill=(int)me->query_skill("kongdong-xinfa",1);
        skill=skill*0.6;

        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));

        soldier->set_temp("invoker",me);
        soldier->set_temp("invoker",me);
        soldier->set_temp("nozh",1);
           soldier->set("possessed", me);
              soldier->set_name(this_player()->query("name")+"的玉清化身",({"dizi"}));        
        soldier->invocation(me);
        soldier->initlvl(skill,30);
 message_vision(HIG"$N喝道：道友 莫慌,我来助你！\n"NOR, soldier);
        if(me->query_skill("kongdong-xinfa", 1) >= 600)
                call_out("sanqing3", 1, me, target);   

        return 1;
}

int sanqing3(object me, object target)
{
        object soldier;
        int skill;
        skill=(int)me->query_skill("kongdong-xinfa",1);
        skill=skill*0.6;

        seteuid(getuid());
        soldier = new("/d/biwu/hs");
        soldier->move(environment(me));
        soldier->set_temp("invoker",me);
        soldier->set("possessed", me);
   soldier->set_temp("nozh",1);

              soldier->set_name(this_player()->query("name")+"的上清化身",({"dizi"}));          
        soldier->invocation(me);
         soldier->initlvl(skill,56);
 message_vision(HIG"$N喝道：道友 莫慌,我来助你！\n"NOR, soldier);
        return 1;
}


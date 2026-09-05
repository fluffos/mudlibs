// neilisuck.c
//增加了一个条件，任我行的弟子不会走火

#include <ansi.h>
int increase_max_neili(object me)
{
	int max_neili=me->query("max_neili"),inc;
	me->add("max_neili", (int)me->query_skill("xixing-dafa",1)/50 );
	inc=me->query_max_neili()-max_neili;
	if (inc>0)
	me->add("sucked_neili",inc);
}
int exert(object me, object target)
{
    int sp, dp, i , lv=0;
    mapping skills = me->query_skills();
	string* sname;
	string skill;
    if ( me == target )
        return notify_fail("你不能吸取自己的丹元！\n");

        if( !objectp(target) )
                return notify_fail("你要吸取谁的丹元？\n");

        if ( me->query_temp("sucked") )
                return notify_fail("你刚刚吸取过丹元！\n");

        if( !me->is_fighting() || !target->is_fighting())
                return notify_fail("你必须在战斗中才能吸取对方的丹元！\n");

        if( (int)me->query_skill("xixing-dafa",1) < 120 )
                return notify_fail("你的吸星大法功力不够，不能吸取对方的丹元！n");
        if( (int)me->query_skill("xixing-dafa",1) < (int)me->query("max_neili")/20 )
                return notify_fail("你的吸星大法功力不够，即使吸取了对方丹元也不能化为己用！n");
        if( (int)me->query("neili",1) < 100 )
                return notify_fail("你的内力不够，不能使用吸星大法。\n");

        if( (int)target->query("max_neili") <= 0 )
                return notify_fail( target->name() +
                        "没有任何内力！\n");
        if( (int)target->query_skill("force",0) < 40)
                return notify_fail( target->name() +
                        "内功修为太低了，没法吸取丹元！\n");
        message_vision(
                HIR "$N掌法一变，双手平平的贴向$n的胸口！\n\n" NOR,
                me, target );

        if( !target->is_killing(me->query("id")) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
        dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");

        me->set_temp("sucked", 1);              

        if( F_KUNGFU->hit_rate( sp, dp, 9, me, target) )
        {
        	tell_object(target, HIR "你觉得胸口一阵刺痛，内力丹元仿佛决堤之水，滚滚而出！\n" NOR);
         	tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);

        	me->add("potential", (int)target->query_skill("force")*(int)me->query_skill("xixing-dafa", 1)*(int)me->query_skill("xixing-dafa", 1)/(2000*(int)me->query_skill("force")) );
            if ((string)me->query("family/master_id") != "ren woxing")//如果不是任我行的弟子，使用吸星大法可能会走火
            {
                if( !((int)me->query("potential") - (int)me->query("learned_points") < 300 ))
                {
                        i = (int)me->query("learned_points")+300;
                        me->set("potential",i);
                        tell_object(me, HIG "你一时承受不起这么多丹元的冲击，有些控制不住经脉里的内力流动了！\n" NOR);
                        me->add_temp("crazy",1);
                        if (me->query_temp("crazy")>10)
                        {
                                tell_object(me, HIR "突然间，你的内息犹如脱缰野马，再也不受你的控制，你走火入魔了！！！\n" NOR);
                                me->set("potential",i-300);
                                me->add("max_neili",-100);
                                me->unconcious();
                                call_out("del_sucked",1,me);
                        }
                }
	    }
		increase_max_neili(me);
    		me->add("combat_exp",(int)( target->query_skill("force") * 10 / me->query_skill("force") ));
    					me->add("exp/suck",(int)( target->query_skill("force") * 10 / me->query_skill("force") )); //增加suck的经验记录，跟踪是否利用此bug
/*
            if (me->query("max_neili") > 10*me->query_skill("force"))
            	me->set("max_neili",10*me->query_skill("force"));
*/
        sname = keys(skills);
        for(i=0;i<sizeof(skills);i++)
        {
            skill = sname[i];
            if(SKILL_D(skill)->valid_enable("force")&&me->query_skill(skill,1)>lv)
            {
                lv=(int)me->query_skill(skill,1);
            }
        }
        if (wizardp(me))
        {
            tell_object(me,chinese_number(lv)+"\n");
        }
        lv=(int)me->query_skill("force",1)/2+lv+(int)me->query("level");//lv为最大内功支持的，可不为xixing，比较符合武侠意境。ZINE
        lv=lv*10;
        if (wizardp(me))
        {
            tell_object(me,chinese_number(lv)+"\n");
        }
            if (me->query("max_neili") >  me->query_max_neili() )
            {
                me->set("max_neili", me->query_max_neili() );
            }
            target->add("max_neili",-1*(int)me->query_skill("xixing-dafa",1)/40);
            target->add("neili",-1*(int)me->query_skill("xixing-dafa",1)/20);
            me->start_busy(random(4));
            me->add("neili", -20);
            if (target->query("neili")<0)
            {
                 tell_object(target,HIR "你内力已尽，身子一软，便晕了过去。\n" NOR);
                 tell_object(me,HIG "" + target->name() + "的内力已经被你吸完了！\n" NOR);
                 target->set("neili",0);
                 target->receive_damage("qi", 0, me);
                 target->unconcious();
                 call_out("del_sucked",4,me);
           	}
            call_out("goonexert", 4, me,target);
        }
        else
        {       
                message_vision(HIY "可是$p看破了$P的企图，向旁边一闪，躲过了$P的进攻。\n" NOR, me, target);
                me->start_busy(4);
                call_out("del_sucked", 6, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if (!me) return;
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}

void goonexert(object me,object target)
{
        mapping skills = me->query_skills();
	    string* sname;
	    string skill;
        int sp,dp,i,xixing,lv=0;
        object *enemy;
        object feilong,jujing,mengzhu;
        if (!me) return;
        enemy = me->query_enemy() - ({ 0 });
        sname = keys(skills);
        for(i=0;i<sizeof(skills);i++)
        {
            skill = sname[i];
            if(SKILL_D(skill)->valid_enable("force")&&me->query_skill(skill,1)>lv)
            {
                lv=(int)me->query_skill(skill,1);
            }
        }
        lv=(int)me->query_skill("force",1)/2+lv+(int)me->query("level");//lv为最大内功支持的，可不为xixing，比较符合武侠意境。ZINE
        lv=lv*10;
        for(i=0; i<sizeof(enemy); i++)
        {
           if(enemy[i] == target)
           {
                sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
                dp = target->query_skill("force") + target->query_skill("dodge") + me->query("kar");
                me->set_temp("sucked", 1);              

                if( F_KUNGFU->hit_rate( sp, dp, 9, me, target) )
                {
                        tell_object(target, HIR "你觉得胸口一阵刺痛，内力丹元仿佛决堤之水，滚滚而出！\n" NOR);
                        tell_object(me, HIG "你觉得" + target->name() + "的丹元自手掌源源不绝地流了进来。\n" NOR);

        			me->add("potential", (int)target->query_skill("force")*(int)me->query_skill("xixing-dafa", 1)*(int)me->query_skill("xixing-dafa", 1)/(2000*(int)me->query_skill("force")) );
                        if ((string)me->query("family/master_id") != "ren woxing")//如果不是任我行的弟子，使用吸星大法可能会走火
			{
                        if( !((int)me->query("potential") - (int)me->query("learned_points") < 300 ))
                        {
                                i = (int)me->query("learned_points")+300;
                                me->set("potential",i);
                                tell_object(me, HIG "你一时承受不起这么多丹元的冲击，有些控制不住经脉里的内力流动了！\n" NOR);
                                me->add_temp("crazy",1);
                                if (me->query_temp("crazy")>(3+random(8)))
                                {
                                        tell_object(me, HIR "突然间，你的内息犹如脱缰野马，再也不受你的控制，你走火入魔了！！！\n" NOR);
                                        me->set("potential",i-300);
                                        me->add("max_neili",-100);
                                        xixing = me->query_skill("xixing-dafa",1);
                                        xixing = xixing - 25;
                                        if (me->query_temp("maxcrazy"))
                                        {       
                                                xixing = 100;
                                        }
                                        me->set_skill("xixing-dafa",xixing);
                                        if(!( feilong = find_living("feilong")) )
                                                feilong = load_object("/clone/npc/feilong");
                                        if( me->query("id") == feilong->query("winner"))
                                        {
                                                feilong->set_skill("xixing-dafa",xixing);
                                                feilong->save();
                                        }
                                        if(!( jujing = find_living("jujing")) )
                                                feilong = load_object("/clone/npc/jujing");
                                        if( me->query("id") == jujing->query("winner"))
                                        {
                                                jujing->set_skill("xixing-dafa",xixing);
                                                jujing->save();
                                        }
                                        if(!( mengzhu = find_living("mengzhu")) )
                                                mengzhu = load_object("/clone/npc/meng-zhu");
                                        if( me->query("id") == mengzhu->query("winner"))
                                        {
                                                mengzhu->set_skill("xixing-dafa",xixing);
                                                mengzhu->save();
                                        }
                                        me->unconcious();
                                        call_out("del_sucked",1,me);
                                }
                        }
                    }
			increase_max_neili(me);
            me->add("combat_exp",(int)( target->query_skill("force") * 10 / me->query_skill("force") ));
            me->add("exp/suck",(int)( target->query_skill("force") * 10 / me->query_skill("force") )); //增加suck的经验记录，跟踪是否利用此bug
                if (me->query("max_neili") > me->query_max_neili())
                        me->set("max_neili",me->query_max_neili());

                        target->add("max_neili",-1*(int)me->query_skill("xixing-dafa",1)/40);
                        target->add("neili",-1*(int)me->query_skill("xixing-dafa",1)/20);
                        me->start_busy(4);
                        me->add("neili", -5);
                        if (target->query("neili")<0)
                        {
                                tell_object(target,HIR "你内力已尽，身子一软，便晕了过去。\n" NOR);
                                tell_object(me,HIG "" + target->name() + "的内力已经被你吸完了！\n" NOR);
                                target->set("neili",0);
                                target->receive_damage("qi", 0, me);
                                target->unconcious();
                                call_out("del_sucked",4,me);
                        }
                        else
                        {
                                call_out("goonexert", 4, me,target);
                        }
                }
                else
                {       
                        message_vision(HIY "可是$p看破了$P的企图，向旁边一闪，躲过了$P的进攻。\n" NOR, me, target);
                        me->start_busy(4);
                        /*去掉这个判断，吸不中为什么要发疯？
                        if (random(20) == 1) 
                        {
                                me->add_temp("crazy",1);
                        if ((string)me->query("family/master_id") != "ren woxing")//如果不是任我行的弟子，使用吸星大法可能会走火
							{
                                if ( ((int)me->query("potential") - (int)me->query("learned_points") + (int)me->query_temp("crazy") * 10) > 200 )
                                {
                                        me->set_temp("maxcrazy",1);
                                        me->set("potential",(int)me->query("learned_points")+300);
                                        call_out("goonexert",3,me,target);
                                }
                             }
                        }
                        */
                        call_out("del_sucked", 6, me);
                }       
             }
        }
        call_out("del_sucked",1,me);
        

}


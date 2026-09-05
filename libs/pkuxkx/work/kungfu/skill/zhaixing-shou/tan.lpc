//tan.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string* valid_weapon() 
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other";
}

int perform(object me, object target)
{       
    int sp, dp, pflv;      
    int i, skilllevel, damage, shoot, duration, throwing_wield = 0;
    object obj, * allob, right_weapon, left_weapon;
	string anqi;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() )
        return notify_fail("暗器射敌只能对同地方的对手使用。\n");

    right_weapon = me->query_temp("weapon");
    left_weapon = me->query_temp("secondary_weapon");

    if ( (objectp(right_weapon) && right_weapon->query("skill_type")=="throwing") ||
         (objectp(left_weapon) && left_weapon->query("skill_type")=="throwing") )
        throwing_wield = 1;

    if ( !throwing_wield && me->check_hand() >= 2 )
        return notify_fail("你必须空出一只手才能发射暗器。\n");

	skilllevel = (int)me->query_skill("zhaixing-shou", 1);
	
    if( skilllevel < 50 )
        return notify_fail("你的摘星手手不够娴熟，弹不出暗器。\n");

    if( (int)me->query_skill("huagong-dafa", 1) < 50 )
        return notify_fail("你的化功大法不够高，不能用内力发射暗器。\n");

    if( (int)me->query("neili", 1) < 100 )
        return notify_fail("你现在内力太弱，不能发射暗器。\n");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "星宿派") 
		pflv=0;
	if (pflv>5) pflv=5;
	if (!anqi = me->query_temp("perform_use_anqi"))
		anqi="jile ci";

	obj=F_KUNGFU->find_throwing(me, anqi);       //星宿暗器太多了，极乐刺优先，其他暗器靠后
	if (!obj) return notify_fail("你身上没有暗器，怎能使出暗器绝技？\n");
    
    tell_object(me, BLU "你左手在袖底轻轻一扬，一道闪光，向" + target->name() +BLU+ "激射过去。！\n" NOR);
    message("vision", BLU "你只见眼前一闪，似乎有什么东西向" + target->name() +BLU+ "直射过去！\n" NOR, environment(me), ({ me }));
    sp = me->query_skill("force", "huagong-dafa") + me->query_skill("throwing", "zhaixing-shou");
    dp = target->query_skill("dodge");

    me->start_busy(2);
    me->add("neili", -100);
    if (obj && obj->query("id")=="jile ci" && !me->query("newbiehongdou")&& !me->query("newbiediaoyu"))
        {
            tell_object(me, target->name() + HIR + "被一枚" + obj->name() + 
                HIR + "射在身上。\n" NOR);
            message("vision", HIR + target->name() + HIR+"忽然惨叫一声，似乎是中了什么暗器！\n" + NOR, environment(me), ({target,me}));
            tell_object(target, HIR "\n你忽然觉得气血穴像被针扎一样的剧痛，不由惨叫一声，退后步许！！\n" NOR);
            F_KUNGFU->hit_wound("qi", target->query("max_qi")/10, 0, me, target);
            COMBAT_D->report_status(target);
            if (me->query_skill("poison",1)>=500 && me->query("family/family_name")=="星宿派")// && obj->query("owner")==me->query("id"))
																						// 因为 owner 的设计跟暗器袋抵触，取消。by lordstar 2017/10/26
            {
                message("vision", HIR + obj->name() + "突然裂成许多小刺，激射向在场众人！\n" + NOR, environment(me));
                duration=me->query_skill("poison",1)/20;
                if (duration>30)
                {
                    duration=30;
                }
                allob = all_inventory(environment(me));
                if (me->query("env/jile") == "npc")
                {
                    for(i=0;i<sizeof(allob);i++)
                    {   
                        if(userp(allob[i])) continue;
                        if(!objectp(allob[i])) continue;
                        if(!living(allob[i])) continue;
                        if(allob[i]==me) continue;
//由于毒术存在天花板，所以命中率差不多在A和A+之间
//                        if ( !F_KUNGFU->hit_rate(allob[i]->query_skill("dodge",1), (me->query_skill("poison",1)+me->query_skill("zhaixing-shou",1))*2, 9, me, allob[i]) )
//原先的算法写得太奇怪，实测完全达不到注释说的效果。改为正常样式。。。by lordstar 20171027
                        if ( F_KUNGFU->hit_rate((me->query_skill("poison",1)+me->query_skill("zhaixing-shou",1))*2, allob[i]->query_skill("dodge",1), 7-((pflv>=4)?(pflv-3):0), me, allob[i]) )
                        {
                            F_KUNGFU->hit_busy("dianxue", 5*((pflv>=4)?(pflv-2):1), allob[i] );
							message_vision(HIM"$N" HIM "感觉被小刺射中的部位一阵麻痹，身体动弹不得！\n" NOR, allob[i]);
                        }
//命中率级别B+
                        if ( !F_KUNGFU->hit_rate(allob[i]->query_skill("parry",1), me->query_skill("zhaixing-shou",1)*2, 9, me, allob[i]) )
                        {
                            F_KUNGFU->hit_wound("qi", 0, me->query_skill("poison",1), me, allob[i]);
                            COMBAT_D->report_status(allob[i]);
                        }
//命中率级别C-
                        if ( F_KUNGFU->hit_rate(me->query_dex(), allob[i]->query_dex(), 9, me, allob[i]) && 
                        	   !allob[i]->query_temp("dabeiwan") )
                        {
							F_POISON->poison_attack(me,allob[i],"xx-poison-palsy", duration + allob[i]->query_condition("xx-poison-palsy"));
                            //allob[i]->set_temp("death_cond_origin/xxx_poison", me);
							F_POISON->poison_attack(me,allob[i],"xxx_poison",skilllevel/15 + allob[i]->query_condition("xxx_poison"));
                            //tell_object(allob[i], HIR"\n你仔细一看，竟然是星宿派绝门暗器" + NOR"极乐刺!!\n");
                        }
                    }
                }
                else
                {
                    for(i=0;i<sizeof(allob);i++)
                    {   
                        if(!objectp(allob[i])) continue;
                        if(!living(allob[i])) continue;
                        if(allob[i]==me) continue;
//由于毒术存在天花板，所以命中率差不多在A和A+之间
//                        if ( !F_KUNGFU->hit_rate(allob[i]->query_skill("dodge",1), (me->query_skill("poison",1)+me->query_skill("zhaixing-shou",1))*2, 9, me, allob[i]) )
//原先的算法写得太奇怪，实测完全达不到注释说的效果。改为正常样式。。。by lordstar 20171027
                        if ( F_KUNGFU->hit_rate((me->query_skill("poison",1)+me->query_skill("zhaixing-shou",1))*2, allob[i]->query_skill("dodge",1), 7-((pflv>=4)?(pflv-3):0), me, allob[i]) )
                        {
                            F_KUNGFU->hit_busy("dianxue", 5*((pflv>=4)?(pflv-2):1), allob[i] );
							message_vision(HIM"$N" HIM "感觉被小刺射中的部位一阵麻痹，身体动弹不得！\n" NOR, allob[i]);
                        }
//命中率级别B+
                        if ( !F_KUNGFU->hit_rate(allob[i]->query_skill("parry",1), me->query_skill("zhaixing-shou",1)*2, 9, me, allob[i]) )
                        {
                            F_KUNGFU->hit_wound("qi", 0, me->query_skill("poison",1), me, allob[i]);
                            COMBAT_D->report_status(allob[i]);
                        }
//命中率级别C-
                        if ( F_KUNGFU->hit_rate(me->query_dex(), allob[i]->query_dex(), 9, me, allob[i]) && 
                        	   !allob[i]->query_temp("dabeiwan") )
                        {
							F_POISON->poison_attack(me,allob[i],"xx-poison-palsy",duration + allob[i]->query_condition("xx-poison-palsy"));
                            //allob[i]->set_temp("death_cond_origin/xxx_poison", me);
							F_POISON->poison_attack(me,allob[i],"xxx_poison",skilllevel/15 + allob[i]->query_condition("xxx_poison"));
                            tell_object(allob[i], HIR"\n你仔细一看，竟然是星宿派绝门暗器极乐刺！\n");
                        }
                    }
                }
	            me->start_busy(0);
                me->add("score",-1);
                
            }
            shoot=0;
            destruct(obj);
            return 1;
        }
    if( F_KUNGFU->hit_rate(sp, dp, 9-((pflv>=4)?(pflv-3):0), me, target) )
    {
        
        damage = (int)(me->query_skill("throwing", "zhaixing-shou") * 3/2);
        damage += obj->query("weapon_prop/damage") * 5;
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        
        if(obj && obj->query("id")=="bilin zhen")
        {
            tell_object(me, obj->name() + HIR + "狠狠地扎在了" + target->name() + 
                "身上，" + target->name() +HIR+ "疼得嗷嗷直叫！！\n" NOR);
            message("vision", HIR + target->name() + "忽然惨叫一声，似乎是中了什么暗器！\n" + NOR, environment(me), ({target,me}));
            tell_object(target, HIR "\n你忽然觉得身上某处针扎一样的剧痛，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
            F_KUNGFU->hit_wound("qi", 0, 300, me, target);
            //target->set_temp("death_cond_origin/xxx_poison", me);
			F_POISON->poison_attack(me,target,"xxx_poison",skilllevel/15 + target->query_condition("xxx_poison"));
			if (pflv>0)
			{
				target->set_temp("xx_disorder/pflv", pflv);
				F_POISON->poison_attack(me, target, "xx_disorder", 1 + (pflv*skilllevel/50) + target->query_condition("xx_disorder"));
				message_vision("$N似乎感觉伤处有些异样的热感，但又说不出有什么不妥之处。\n", target);
			}
            tell_object(target, HIR"\n你仔细一看，竟然是星宿派绝门暗器碧磷针！\n" NOR);
            shoot=1;
        }
        else if (obj && obj->query("id")=="wuxing fen" && !me->query("newbiehongdou")&& !me->query("newbiediaoyu"))
        {
            tell_object(me, target->name() + HIB + "被一蓬" + obj->name() + 
                HIB + "撒在身上，瞬间白烟直起" + target->name() +HIB+ "疼得嗷嗷直叫！！\n" NOR);
            message("vision", HIB + target->name() + "忽然惨叫一声，似乎是中了什么暗器！\n" + NOR, environment(me), ({target,me}));
            tell_object(target, HIB "\n你忽然觉得身上到处像被针扎一样的剧痛，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
            
            if (me->query_skill("poison",1)>=400) // && obj->query("owner")==me->query("id")) 因为 owner 的设计跟暗器袋抵触，取消。by lordstar 2017/10/26
            {
                duration=me->query_skill("poison",1)/20;
                if (duration>30)
                {
                    duration=30;
                }
                F_KUNGFU->hit_wound("qi", 0, me->query_skill("poison",1), me, target);
				F_POISON->poison_attack(me,target,"xx-poison-palsy", duration + target->query_condition("xx-poison-palsy"));
                //target->set_temp("death_cond_origin/xxx_poison", me);
				F_POISON->poison_attack(me,target,"xxx_poison",skilllevel/15 + target->query_condition("xxx_poison"));
                tell_object(target, HIR"\n你仔细一看，竟然是星宿派绝门暗器无形粉！\n" NOR);
            }
            destruct(obj);
            shoot=0;
        }
        else if (obj && obj->query("id")=="shuoxin dan" && !me->query("newbiehongdou")&& !me->query("newbiediaoyu"))
        {
            tell_object(me, target->name() + HIM + "被一枚" + obj->name() + 
                HIM + "击在身上，瞬间窜起几处火苗" + target->name() +HIM+ "疼得嗷嗷直叫！！\n" NOR);
            message("vision", HIB + target->name() + "忽然惨叫一声，似乎是中了什么暗器！\n" + NOR, environment(me), ({target,me}));
            tell_object(target, HIB "\n你忽然觉得身上到处像被扑不灭的烈火灼烧一样剧痛，不由惨叫一声！！\n" NOR);
            
            if (me->query_skill("poison",1)>=200) // && obj->query("owner")==me->query("id")) 因为 owner 的设计跟暗器袋抵触，取消。by lordstar 2017/10/26
            {
                duration=me->query_skill("poison",1)/20;
                if (duration>10)
                {
                    duration=10;
                }
                F_KUNGFU->hit_wound("qi", 0, me->query_skill("poison",1), me, target);
                //target->set_temp("death_cond_origin/shuoxin", me);
				F_POISON->poison_attack(me,target,"shuoxin", duration + target->query_condition("shuoxin"));
                tell_object(target, HIR"\n你仔细一看，竟然是星宿派独门暗器烁心弹！\n" NOR);
            }
            destruct(obj);
            shoot=0;
        }
        else if (obj && obj->query("id")=="chuanxin ding" && !me->query("newbiehongdou")&& !me->query("newbiediaoyu"))
        {
            tell_object(me, target->name() + HIR + "被一枚" + obj->name() + 
                HIR + "射入心口，" + target->name() +HIR+ "惨叫一声瘫软了下去！！\n" NOR);
            message("vision", HIR + target->name() +HIR+ "忽然惨叫一声，似乎是中了什么暗器！\n" + NOR, environment(me), ({target,me}));
            tell_object(target, HIR "\n你忽然觉得心口到处像被剖开一样的剧痛，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
            
            if (me->query_skill("zhaixing-shou",1)>=300) // && obj->query("owner")==me->query("id")) 因为 owner 的设计跟暗器袋抵触，取消。by lordstar 2017/10/26
            {
                duration=me->query_skill("zhaixing-shou",1)/30;
                if (duration>20)
                {
                    duration=20;
                }
                F_KUNGFU->hit_wound("qi", 0, me->query_skill("zhaixing-shou",1)*3+random(500), me, target);
                //target->set_temp("death_cond_origin/chuanxin", me);
				F_POISON->poison_attack(me,target,"chuanxin", duration + target->query_condition("chuanxin"));
                
                tell_object(target, HIR"\n你仔细一看，竟然是星宿派绝门暗器穿心钉！\n" NOR);
                destruct(obj);   
            }
            shoot=1;
        }
        else
        {
            tell_object(me, HIR + target->name() + HIR "躲闪不及，被射了个正着！\n" NOR);
            message("vision", HIR + target->name() + "忽然惨叫一声，似乎是中了什么暗器！\n" + NOR, environment(me), ({target,me}));
            tell_object(target, HIR "\n你躲闪不及，被射了个正着！\n" NOR);
            shoot=1;
        }
        if(obj && obj->query("slumber"))
        {
            tell_object(me, obj->name() + HIR + "狠狠地扎在了" + target->name() + 
                "身上，" + target->name() + "疼得嗷嗷直叫！！\n" NOR);
            message("vision", HIR + target->name() + "忽然惨叫一声，似乎是中了什么暗器！\n" + NOR, environment(me), ({target,me}));
            tell_object(target, HIR "\n你忽然觉得身上某处针扎一样的剧痛，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
            //target->set_temp("death_cond_origin/slumber_drug", me);
			F_POISON->poison_attack(me,target,"slumber_drug",skilllevel/6 + target->query_condition("slumber_drug"));
            tell_object(target,HIR"\n你觉得痛处忽然一阵麻木，原来暗器是涂了蒙汗药的！\n" NOR);
            shoot=1;
        }
        if(obj && obj->query("poison"))
        {
            tell_object(me, obj->name() + HIR + "狠狠地扎在了" + target->name() + 
                "身上，" + target->name() + "疼得嗷嗷直叫！！\n" NOR);
            message("vision", HIR + target->name() + "忽然惨叫一声，似乎是中了什么暗器！\n" + NOR, environment(me), ({target,me}));
            tell_object(target, HIR "\n你忽然觉得身上某处针扎一样的剧痛，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
            //target->set_temp("death_cond_origin/xxx_poison", me);
			F_POISON->poison_attack(me,target,"xxx_poison",skilllevel/10 + target->query_condition("xxx_poison"));
            tell_object(target,HIR"\n你觉得伤口一阵剧痛，原来暗器是涂了断肠散的！\n" NOR);
            shoot=1;
        }
		if (pflv>=4 && target->query_condition())
		{
			message_vision(RED "$N禁不住一阵气血翻涌……\n" NOR, target);
			for (i=0;i<(pflv-3);i++)
				target->update_condition();
		}
        COMBAT_D->report_status(target);
        if (obj && shoot>0)
        {
            obj->move(target);
        }
    }
    else
    {
        destruct(obj);
        me->start_busy(2);     
        message_vision(MAG"$N"+MAG"眼疾手快，在暗器近身之前，已看准暗器来路，一个鹞子翻身躲开来袭的暗器!\n"NOR, target);
    }                                    

    if( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 9, me, target) )
    {  
        tell_object(target, HIC "\n你没有发现暗器的来源！\n" NOR);
    } 
    else
    {
        tell_object(target, HIR "\n你发现了射暗器的人了！\n" NOR);
        target->kill_ob(me);
    }
    return 1;
}


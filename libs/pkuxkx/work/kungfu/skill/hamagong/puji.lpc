//Cracked by Roath
// /kungfu/skill/hamagong/puji.c  perform 蛤蟆扑击
// sdong, 10/24/98
// maco 8/17/2000
// Modified by iszt@pkuxkx, 2007-04-18, no busy target while puji

#include <ansi.h>
#include <armor.h>
#include <char.h>
#include <combat.h>
inherit F_SSERVER;

void tie_hit(object me, object target, int pflv);
void pu_hit(object me, object target,int ptimes,int hmg,int force,int lp_time,int pflv,int hit_times);

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    object armor,weapon;
    int damage;
    int flage,hmg,force,lp_time;
    string *limb, type, result, str;
    int ptimes; //扑击的次数，超过６００连续扑６下，７００以上７下，６００以下５下
	int pflv;

    type = "内伤";

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「扑击」只能对战斗中的对手使用。\n");

/*
if(me->query("family/family_name")!="白驼山" && me->query("chushi/last_family")!="白驼山")
            return notify_fail("你跟西毒欧阳锋毫无关系，哪里会知道蛤蟆功之奥秘！\n");
*/

    if ( me->check_hand() >= 1 )
        return notify_fail("你双手不空，怎能发招！\n");

    if( (int)me->query_skill("hamagong", 1) < 120 )
        return notify_fail("你的蛤蟆功修为不够。\n");

    if ( me->query_skill_mapped("force") != "hamagong" )
        return notify_fail("你现在运使的内功并非蛤蟆功！\n");
/*    if( me->query_skill_mapped("strike") != "hamagong" )
        return notify_fail("你现在运使的掌法并非蛤蟆功！\n");*/

    if( me->query("neili") <= 600 )
        return notify_fail("你的内力不够！\n");

    if( me->query("jing") <= 300 )
        return notify_fail("你的精力不够！\n");

    hmg = (int)me->query_skill("hamagong", 1);
    force = (int)me->query_skill("force", 1);
    if(hmg<600)
        ptimes = 5;
    else if(hmg>700)
        ptimes = 7;
    else
        ptimes = 6;
	if (me->query("safari_skill/bts1"))
	{
		ptimes += 1;
	}
	lp_time = 3 - hmg/650;
	if (lp_time<1)
	{
		lp_time=1;
	}
	if(me->query("chushi/done"))
	{
		lp_time+=1;
	}
    me->delete_temp("puji_time");

	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "白驼山") 
		pflv=0;

    remove_call_out("pu_hit");

    pu_hit(me, target, ptimes,hmg,force,lp_time,pflv,0);

    return 1;
}

void pu_hit(object me, object target,int ptimes,int hmg,int force,int lp_time,int pflv,int hit_times)
{
        object armor;
        int flag;
        int damage, time, ap, dp, pp, point, rstime;
        string msg, *limb, type, result, str;
        object weapon;
        object room, *enemy;
		mapping attack_val = ([
                            "base" : ([ "no_weapon" : "strike", ]), //基本功夫类型
                            "skill" : ([ "no_weapon" : "hamagong", ]), //高级技能名称
                           ]);

        if (!me) return;



        if( !living(me) || me->is_ghost() ) return;

        if( !objectp(target) || !me->is_fighting(target) ) return notify_fail("你和对方不在战斗中。\n");

        if( me->query_skill_mapped("force")!="hamagong" )
            return notify_fail("你现在运使的内功并非蛤蟆功！\n");
/*        if( me->query_skill_mapped("strike")!="hamagong")
            return notify_fail("你现在运使的掌法并非蛤蟆功！\n"); */

        type = "内伤";


		me->set_temp("attack_val", attack_val);
        ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
		me->delete_temp("attack_val");
        if( ap < 1 ) ap = 1;
        ap = ap*(1+time);
		if (pflv>=4) ap += ap*(pflv-3)/10;

        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        if( dp < 1 ) dp = 1;

        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
        if( pp < 1 ) pp = 1;

        me->add_temp("puji_time", 1);
        time = (int)me->query_temp("puji_time");

        if( time == 1 ) msg = HIB "\n$N双腿一弯，蹲下身来，“阁”的一声大叫，运起蛤蟆功劲力，双掌齐发，向前推出。\n这一推实乃$P毕生功力之所聚，$n猛然感受到山洪海啸般的劲力袭来。\n" NOR;
        else if( time == 2 ) msg = HIM "\n$N第一推刚完，第二推又已迅速异常的赶到，前劲未衰，后劲继至，掌风越发猛烈。\n" NOR;
        else msg = HIR "\n$N眼看前招落空，却毫无慌乱，顺势又是一推，第"+chinese_number(time)+"推的掌风犹如沙漠风暴，一阵猛过一阵，呼啸着向$n扑来。\n"NOR;

        message_vision(msg , me,target);
        
//      me->add("neili", -hmg);
        me->add("neili", -hmg*2/3);
        me->add("jing", -hmg/3);

 //       fap = random(ap + dp);
//命中率级别C-
        if( living(target) && !F_KUNGFU->hit_rate(ap + dp, 2*dp, 9, me, target) ) {

                if(time == 1)
                        message_vision(HIY "$n眼见这一推来势凶猛，挡既不能，避又不可，当下双足一点，跃高四尺，躲开了这一推。\n只听身後腾的一声大响，$N这一推的劲力激起一股狂风巨浪，顿时尘土纷扬，令人惊骇不已。\n\n" NOR, me, target);
                else
                        message_vision(HIY "$n眼见这一推气势汹汹，当下双足一点，侧跃三尺，又躲开了这一推。\n只听轰的一声巨响，蛤蟆功猛劲激得灰泥弥漫，又是一片尘土飞扬，声势惊人。\n" NOR, me, target);
                if(!target->is_busy())
        	        target->start_busy(2 + time);
                me->start_busy(3);
                if( me->query_skill("strike","hamagong") > time*100 && time < ptimes)
				{//bt大招，n扑不中后面连扑无cd，直到命中或者8扑不中
					if (me->query_temp("hamatuxi")&&(time > lp_time))
					{
						pu_hit(me, target, ptimes,hmg,force,lp_time,pflv,hit_times);
					}
					else
					{
						call_out("pu_hit",2 ,me,target,ptimes,hmg,force,lp_time,pflv,hit_times);
					}
				}
				else
					message_vision(HIC"\n$N长吸了一口气，将内力缓缓收归丹田。\n\n"NOR, me);
        }
//命中率级别C-        
        else if( !F_KUNGFU->hit_rate(ap + pp, 2*pp, 9, me, target) && 
        	       random(8) == 0 && target->query("race") == "人类" )
        {
                weapon = target->query_temp("weapon");
                if(weapon)
                {
                        weapon->move(room);
//                      weapon->unequip();
                        weapon->move(environment(target));
                        target->reset_action();
                        message_vision(HIR"$N猛觉得劲风罩来，心知不妙，手中"NOR + weapon->name() + HIR"脱手飞出，赶紧也是双掌向前平推。这一下是以硬接硬，刹那之间，两下里竟然凝住不动。\n"NOR, target );
                }
                else
                        message_vision(HIR"$N猛觉劲风罩来，心知不妙，也是双掌向前平推。这一下是以硬接硬，刹那之间，两下里竟然凝住不动。\n\n"NOR, target );

                message("vision", HIW BLK"两人本是忽纵忽窜、大起大落的搏击，突然间变得两具僵尸相似，连手指也不动一动，似乎气也不喘一口。\n\n"NOR, environment(me), ({ me, target }) );

                target->add("neili", -hmg);
                target->receive_damage("jing", hmg, me);
                COMBAT_D->report_status(target);
                if(!target->is_busy())
                target->start_busy(2 + time);
                me->start_busy(3 + time);
                remove_call_out("tie_hit");
                call_out("tie_hit",2 ,me,target,pflv);
        }
        else {
                if( target->query_temp("armor/cloth") )
                        armor = target->query_temp("armor/cloth");
//由于低端命中率压制不够，适当下调了命中率级别从理论上的C-调整到D-
                if( (!living(target) || 
                	   (!armor || (armor && armor->query("armor_prop/armor") < 150) )) && 
                	  F_KUNGFU->hit_rate( (me->query_skill("strike","hamagong") + me->query_skill("force"))*2/3, 
                	                      2*( target->query_skill("dodge")+target->query_skill("parry") ), 12, me, target ) && 
                	  target->query("race") == "人类")
                {
                        message_vision(HIR"只听$n一声惨叫，$N这一掌正中小腹。但见$n一个身躯突然平平飞出，\n腾的一响，尘土飞扬，跌在丈许之外，直挺挺的躺在地下，再也不动。\n\n"NOR, me, target);
						damage=(int)target->query("eff_qi");
						if (damage<0)
						{
							damage=0;
						}
                        target->receive_wound("qi", damage, me);
						damage=(int)target->query("qi");
						if (damage<0)
						{
							damage=0;
						}
                        target->receive_damage("qi", damage+1,  me);                        
						COMBAT_D->report_status(target);
                        me->add("neili", -(me->query("jiali") + hmg/3));
                        me->add("jing", -me->query("jiali")/3);
						hit_times++;
						message_vision(HIC"\n$N长吸了一口气，将内力缓缓收归丹田。\n\n"NOR, me);
                }
                else
                {
                        damage = (me->query("jiali") +random(me->query("jiali")) ) * (int)me->query_skill("force")/60 + (random(hmg+force))*time +me->query_temp("apply/damage");

                        if(damage > me->query_skill("strike","hamagong")*(9+time) )
							damage = me->query_skill("strike","hamagong")*(8+time)+random(me->query_skill("strike","hamagong"));
                        if(damage < me->query_skill("strike","hamagong")*time ) 
							damage = me->query_skill("strike","hamagong")*time;
						//大招加成
						if (me->query_temp("hamatuxi")&&(!me->query("chushi/done")))
						{
						if (time > lp_time)
							{
							damage += me->query_skill("strike","hamagong")*(time-lp_time);
							}
						else
							{
							damage += me->query_skill("strike","hamagong");
							}
						}
                        if( (me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) || 
                            me->query("family/family_name")=="白驼山" || me->query("chushi/last_family")=="白驼山" )
                            flag=2;
                        else
                            flag=1;
                        damage=damage*flag/2;
                        me->add("neili", -(me->query("jiali")+hmg/3));
                        me->add("jing", -me->query("jiali")/3);
						if (damage<1)
						{
							damage=1;
						}
						if (pflv>=4) damage += damage*(pflv-3)/10;
						// 蛇阵给予的朱红蛇血攻击加成
						rstime = (int) me->query_temp("baituo_redsnake/time"); 
						if ( rstime && time() < rstime )
							damage += damage/5;
						
						F_KUNGFU->hit_wound("qi", damage, random(damage/2)+damage/4, me, target);
                        if(!target->is_busy())
							target->start_busy(1+random(3) * time);

                        limb = target->query("limbs");
                        if(random(2) ) type = "瘀伤";
                        result = COMBAT_D->damage_msg(damage, type);
                        result = replace_string( result, "$l", limb[random(sizeof(limb))]);
                        result = replace_string( result, "$p", target->name() );
                        message_vision(result, me, target);
                        COMBAT_D->report_status(target);
                        hit_times++;
                        //if(wizardp(me)) tell_object(me, "puji damage: "+ damage +"\n");
						
						if ( pflv>=4 && time < ptimes && hit_times < (pflv-2) && random(2) && me->query_skill("strike","hamagong") > time*100 )
						{
							if ( !target || !living(target) || target->query("qi")<=0 ) 
							{
								if (pflv>=5)
								{
									enemy = me->query_enemy();
									enemy -= ({target});
									if (sizeof(enemy) > 1)
									{
										target = enemy[random(sizeof(enemy))];
										message_vision(HIC"\n$N这一击得手，后势延绵不绝，“呱”的一声大叫，掌力排山倒海地推向$n。\n\n"NOR, me, target);
										if (me->query_temp("hamatuxi")&&(time > lp_time))
										{
											pu_hit(me, target, ptimes,hmg,force,lp_time,pflv,hit_times);
										}
										else
										{
											call_out("pu_hit",2 ,me,target,ptimes,hmg,force,lp_time,pflv,hit_times);
										}
									}
								}
							}
							else 
							{
								if (me->query_temp("hamatuxi")&&(time > lp_time))
								{
									pu_hit(me, target, ptimes,hmg,force,lp_time,pflv,hit_times);
								}
								else
								{
									call_out("pu_hit",2 ,me,target,ptimes,hmg,force,lp_time,pflv,hit_times);
								}
							}
						}
						else
							message_vision(HIC"\n$N长吸了一口气，将内力缓缓收归丹田。\n\n"NOR, me);
                }
        }
		
		point = 3+random(2) * time;
		if (point>5) point=5;
		if (pflv>=4) point-=(pflv-3);
        me->start_busy(point);
}


void tie_hit(object me, object target, int pflv)
{
        int sum, n1, n2;
        string msg;

        if( !living(me) || me->is_ghost() ) return;

        if( !objectp(target) || !me->is_fighting(target) ) return notify_fail("你和对方不在战斗中。\n");

        if( me->query_skill_mapped("force")!="hamagong" )
            return notify_fail("你现在运使的内功并非蛤蟆功！\n");
/*        if( me->query_skill_mapped("strike")!="hamagong")
            return notify_fail("你现在运使的掌法并非蛤蟆功！\n");*/

        sum = me->query_skill("force") + me->query_skill("strike","hamagong") + target->query_skill("force") + target->query_skill("parry");
        n1 = me->query("neili");
        n2 = target->query("neili");
		//纯门派大招加成
		if (me->query_temp("hamatuxi")&&(!me->query("chushi/done")))
		{
			me->add("neili", -50 * sum / ( me->query_skill("force") + me->query_skill("strike","hamagong") ) ); 
		}
		else
		{
			me->add("neili", -100 * sum / ( me->query_skill("force") + me->query_skill("strike","hamagong") ) ); 
		}
        if(me->query("neili")<0)me->set("neili",0);

        target->add("neili", -150 * sum / ( target->query_skill("force") + target->query_skill("strike","hamagong") ) );
        if(target->query("neili")<0)target->set("neili",0);

        if( n1 > 1000 && n2 > 1000) {
                msg = WHT"此时双方掌力均极强劲，欲分胜负，非使对方重创不可。\n"NOR;

                if( n1 > n2 )
                msg += HIW"二人又僵持一会，$n头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR;
                else msg += HIW"二人又僵持一会，$N头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR;
        }

        else {

                if( n1 > n2 ) msg = WHT"$N不断催动蛤蟆功猛劲，毫无衰颓迹象。稍过片刻，$n已是全身大汗淋漓。\n"NOR;
                else msg = WHT"$N脸上黑气大盛，将蛤蟆功发挥到了极致。稍过片刻，$N已是全身大汗淋漓。$n似乎依然中气十足，头顶热气蒸蒸而上。\n"NOR;
                }

        message_vision(msg , me,target );


        if( me->query("neili") > 0 && target->query("neili") > 0 && me->is_busy() && target->is_busy() && living(me) && living(target) )
        {
                target->start_busy(4);
                me->start_busy(4);
                remove_call_out("tie_hit");
                call_out("tie_hit",2, me,target,pflv);
                return;
        }

        if( target->query("neili") <= 0 )
        {
                message_vision(HIR "\n$N突然喘不过气来，全身发抖，原来内力已全部耗尽。突闻前胸一片骨裂之声，已被蛤蟆功一掌击中，\n哼也哼不出一声，仰身向后跌倒，双眼紧闭，脸如白纸，端的是生死难料。\n\n" NOR, target);
                target->receive_wound("qi", (int)target->query("eff_qi"), me);
                target->receive_damage("qi", (int)target->query("eff_qi")+1,  me);
                COMBAT_D->report_status(target);
                return;
        }

        if( me->query("neili") <= 0 )
        {
			if (pflv>=5)
			{
                message_vision(HIR "\n$N突然喘不过气来，手上急忙使了一个巧劲，将双方掌力推开，身子滑不溜手地跳出圈外。\n"
					+HIC"只听砰的一声闷响，$n积累的掌力打在前方空处，激起了好一阵尘土。\n" NOR, me, target);
			}
			else
			{
                message_vision(HIR "\n$N脸上黑气大作，突然喘不过气来，全身发抖，原来内力已全部耗尽。蛤蟆功立时全部反弹回来，\n但闻前胸一片骨裂之声，哼也哼不出一声，俯身跌倒，双眼紧闭，脸如黑墨，端的是生死难料。\n\n" NOR, me);
                me->receive_wound("qi", (int)me->query("eff_qi"), target);
                me->receive_damage("qi", (int)me->query("eff_qi")+1,  target);
                COMBAT_D->report_status(me);
			}
        }

//      remove_call_out("tie_result");
//      call_out("tie_result",1,me,target);
}
// 阴阳磨

#include <ansi.h>
#include <armor.h>
#include <combat.h>

inherit F_SSERVER;

void tie_hit(object me, object target);
void pu_hit(object me, object target);

int exert(object me, object target)
{
        object armor,weapon;
        int damage;
        int flage;
        string *limb, type, result, str;


        type = "内伤";

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");


        if ( objectp(me->query_temp("weapon")) || objectp(me->query_temp("secondary_weapon")))
                return notify_fail("你手持兵器，无法施展“阴阳磨”。\n");

        if( (int)me->query_skill("kongdong-xinfa", 1) < 180 )
                return notify_fail("你的崆峒心法修为不够。\n");

        if ( me->query_skill_mapped("force") != "kongdong-xinfa")
                return notify_fail("你现在运用的内功并非崆峒心法！\n");

        if( me->query("neili") <= 600 )
                return notify_fail("你的内力不够！\n");


        me->delete_temp("puji_time");
        remove_call_out("pu_hit");
        pu_hit(me, target);

        return 1;
}

void pu_hit(object me, object target)
{
        object armor;
           int flag;
        int damage, time, ap, dp, pp, fap, hmg, force;
        string msg, *limb, type, result, str;
        object weapon;
        object room;

        if (!me) return;

        if( !target || !me->is_fighting(target) ) return;

        if( !living(me) || me->is_ghost() ) return;

        if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

        if( me->query_skill_mapped("force")!="kongdong-xinfa")
                return;

        type = "内伤";

        hmg = (int)me->query_skill("kongdong-xinfa", 1);
        force = (int)me->query_skill("force", 1);

        ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
        if( ap < 1 ) ap = 1;
        ap = ap*(1+time);

        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        if( dp < 1 ) dp = 1;

        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
        if( pp < 1 ) pp = 1;

        me->add_temp("puji_time", 1);
        time = (int)me->query_temp("puji_time");

        if( time == 1 ) msg = HIC "\n$N中宫直进，运起内力，双掌齐发，向前推出。这一推实乃$P毕生功力之所聚，$n猛然感受到山洪海啸般的劲力袭来。\n" NOR;

        message_vision(msg , me,target);
        

        me->add("neili", -hmg*2/3);


        fap = random(ap + dp);
      	
        if(target->query("neili") < 1000 || random(ap + pp) >= pp) 
        	{
                if( target->query_temp("armor/cloth") )
                        armor = target->query_temp("armor/cloth");

                if( (!living(target) || (!armor || (armor && armor->query("armor_prop/armor") < 150) )) && ( target->query_skill("dodge")+target->query_skill("parry") ) < random(me->query_skill("force")*2/3) && target->query("race") == "人类")
                {
                        message_vision(HIR"只听$n一声惨叫，$N这一掌正中胸口。\n"NOR, me, target);
                        target->receive_wound("qi", (int)target->query("eff_qi"), me);
                        target->receive_damage("qi", (int)target->query("qi")+1,  me);
                        me->add("neili", -(me->query("jiali") + hmg/3));
                }
                else
                {
//                      damage = random(((int)me->query_skill("strike"))+me->query("jiali"))*( 1 + random(me->query("jiajin")/5) ) ;

                        damage = me->query("jiali") * (int)me->query_skill("force")/60 + (random(hmg)+force)*time +me->query_temp("apply/damage");

                        if(damage > me->query_skill("force")*(8+time) ) damage = me->query_skill("force")*(8+time);
                        if(damage < me->query_skill("force")*time ) damage = me->query_skill("force")*time;
//                       if(me->query("family/family_name")=="白驼山" || me->query("chushi/last_family")=="白驼山")  flag=2;
//                                else flag=1;
//                                damage=damage*flag/2;
                        me->add("neili", -(me->query("jiali")+hmg/3));

                        target->receive_damage("qi", damage,  me);
                        target->receive_wound("qi", random(damage/2)+damage/4, me);
                        target->start_busy(1+random(3) * time);

                        limb = target->query("limbs");

                        if(random(2) ) type = "瘀伤";
                        result = COMBAT_D->damage_msg(damage, type);
                        result = replace_string( result, "$l", limb[random(sizeof(limb))]);
                        result = replace_string( result, "$p", target->name() );
                        message_vision(result, me, target);

                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("( $N"+str+" )\n", target);
                        if(wizardp(me)) tell_object(me, "阴阳磨 damage: "+ damage +"\n");
                }
        }
        else if( random(ap + pp)< pp && random(2) == 0 && target->query("race") == "人类" )
        {
                weapon = target->query_temp("weapon");
                if(weapon)
                {
//                        weapon->move(room);
//                      weapon->unequip();
                        weapon->move(environment(target));
                        target->reset_action();
                        message_vision(HIR"$N猛觉得劲风罩来，心知不妙，手中"NOR + weapon->name() + HIR"脱手飞出，赶紧也是双掌向前平推。这一下是以硬接硬，刹那之间，两下里竟然凝住不动。\n"NOR, target );
                }
                else
                        message_vision(HIR"$N猛觉劲风罩来，心知不妙，也是双掌向前平推。这一下是以硬接硬，刹那之间，两下里竟然凝住不动。\n\n"NOR, target );

                message("vision", HIW BLK"两人本是忽纵忽窜、大起大落的搏击，突然间变得两具僵尸相似，连手指也不动一动，似乎气也不喘一口。\n\n"NOR, environment(me), ({ me, target }) );

                target->add("neili", -hmg);
                target->start_busy(5 + time);
                me->start_busy(5 + time);
                remove_call_out("tie_hit");
                call_out("tie_hit",2 ,me,target);
        }
        else
        	message_vision(HIY"$n深知$N这一招的厉害，并不敢硬接，一侧身躲了过去。\n"NOR, me, target);

        me->start_busy(3);
}


void tie_hit(object me, object target)
{
        int sum, n1, n2;
        string msg;

        if( !target || !me->is_fighting(target) ) return;

        if( !living(me) || me->is_ghost() ) return;

        if( !target || environment(me) != environment(target) || !me->is_fighting() ) return;

        sum = me->query_skill("force") + target->query_skill("force") + target->query_skill("parry");
        n1 = me->query("neili");
        n2 = target->query("neili");

        me->add("neili", -100 * sum / me->query_skill("force")  ); 
        if(me->query("neili")<0)me->set("neili",0);

        target->add("neili", -120 * sum / target->query_skill("force")  );
        if(target->query("neili")<0)target->set("neili",0);

        if( n1 > 1000 && n2 > 1000) {
                msg = HIC"此时双方掌力均极强劲，欲分胜负，非使对方重创不可。\n"NOR;

                if( n1 > n2 )
                msg += CYN"二人又僵持一会，$n头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR;
                else msg += CYN"二人又僵持一会，$N头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR;
        }

        else {

                if( n1 > n2 ) msg = HIC"$N不断加催内劲，毫无衰颓迹象。稍过片刻，$n已是全身大汗淋漓。\n"NOR;
                else msg = HIC"$N脸上黑气大盛，将内力发挥到了极致。稍过片刻，$N已是全身大汗淋漓。$n似乎依然中气十足，头顶热气蒸蒸而上。\n"NOR;
                }

        message_vision(msg , me,target );


        if( me->query("neili") > 0 && target->query("neili") > 0 && living(me) && living(target) )
        {
                target->start_busy(5);
                me->start_busy(5);
                remove_call_out("tie_hit");
                call_out("tie_hit",2, me,target);
                return;
        }

        if( target->query("neili") <= 0 )
        {
                message_vision(HIR "\n$N突然喘不过气来，全身发抖，原来内力已全部耗尽。$N双眼紧闭，脸如白纸，端的是生死难料。\n\n" NOR, target);
                target->receive_wound("qi", (int)target->query("eff_qi"), me);
                target->receive_damage("qi", (int)target->query("eff_qi")+1,  me);
                return;
        }

        if( me->query("neili") <= 0 )
        {
                message_vision(HIR "\n$N脸上黑气大作，突然喘不过气来，全身发抖，原来内力已全部耗尽。内劲立时全部反弹回来，但见$N双眼紧闭，脸如黑墨，端的是生死难料。\n\n" NOR, me);
                me->receive_wound("qi", (int)me->query("eff_qi"), target);
                me->receive_damage("qi", (int)me->query("eff_qi")+1,  target);
                return;
        }

//      remove_call_out("tie_result");
//      call_out("tie_result",1,me,target);
}


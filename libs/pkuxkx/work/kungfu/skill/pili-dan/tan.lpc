// tan.c  霹雳弹 「弹字诀」
//create bye cuer
// 霹雳弹增加群攻效果，如果战斗中并且敌人是多人，将会自动发动暗器的群攻效果。
// 群攻最大效果为一次性攻击5个人
// by seagate@pkuxkx

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
    int damage, skilllevel, throws, throwing_wield = 0;
    object obj, *eny, right_weapon, left_weapon;
	string anqi;

    if( !target ) target = offensive_target(me);

    if( !objectp(target)|| !target->is_character() )
        return notify_fail("暗器射敌只能对同地方的对手使用。\n");

    right_weapon = me->query_temp("weapon");
    left_weapon = me->query_temp("secondary_weapon");

    if ( (objectp(right_weapon) && right_weapon->query("skill_type")=="throwing") ||
         (objectp(left_weapon) && left_weapon->query("skill_type")=="throwing") )
        throwing_wield = 1;

    if ( !throwing_wield && me->check_hand() >= 2 )
        return notify_fail("你必须空出一只手才能发射暗器。\n");

    if( skilllevel = (int)me->query_skill("pili-dan", 1) < 80 )
        return notify_fail("你的霹雳弹不够娴熟，不会使用「弹字诀」。\n");

    if( (int)me->query_skill("linji-zhuang", 1) < 30 )
        return notify_fail("你的临济十二庄不够高，不能用内力发射暗器。\n");

    if( (int)me->query("neili", 1) < 100 )
        return notify_fail("你现在内力太弱，不能发射暗器。\n");
	  
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "峨嵋派")  pflv=0;

	eny=me->query_enemy();
    throws=sizeof(eny);
    if (throws>=5) throws=5;
    
	if (!anqi = me->query_temp("perform_use_anqi"))
		anqi="pili dan";
    obj=F_KUNGFU->find_throwing(me, anqi);
    if (!obj) return notify_fail("你身上没有暗器，怎能使出暗器绝技？\n");
  
    tell_object(me, HIG "你手一甩，" + obj->name() + HIG "激射而出，直射向" + target->name() + "！\n" NOR);
    message("vision", HIG "你只见眼前一闪，似乎有什么东西向" + target->name() + "直射过去！\n" NOR, environment(me), ({ me }));
    sp = me->query_skill("force", "linji-zhuang") + me->query_skill("throwing", "pili-dan");
    dp = target->query_skill("dodge");

    me->start_busy(2);
    me->add("neili", -100);
    if ( throws<=1 )
    {
        if( F_KUNGFU->hit_rate( sp, dp, 9-((pflv>=3)?(pflv-2):0), me, target) )
        {
            obj->move(target);
            damage = (int)(me->query_skill("throwing", "pili-dan") * 3/2);
            damage += obj->query("weapon_prop/damage") * 5;    

            if(obj->query("id")=="pili dan")
            {
                destruct(obj);
                damage += 100 + random(800) + (pflv>=3)?(pflv*(500+random(500))):0;
                message_vision( HIR "霹雳弹轰的一声炸开，$N被炸得浑身上下体无完肤！！\n" NOR, target);
				F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
				if (pflv>=3){
					if (target->query_busy() < (pflv*2)) target->start_busy(pflv*2);
					target->set_temp("death_cond_origin/hyd_condition", me);
					target->apply_condition("hyd_condition", 11 + target->query_condition("hyd_condition"));
				}
            }
			else
			{
				tell_object(target, HIR "你眼见暗器射到身上，偏偏无法避开，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
				message("vision", HIR "结果" + target->name() + 
                    "被暗器射中，惨叫一声，身子一歪，退后丈许！！\n" NOR, environment(me), target);
				F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
			}
			COMBAT_D->report_status(target);
        }
		else
		{
			destruct(obj);
			message_vision( HIC "\n可是$N身子急退，躲开了扑面而来的暗器攻击。\n" NOR, target);
		}    
	}
    else
    {
        for(int i=0;i<throws;i++)
        {
            if ( i>0 )
               obj=F_KUNGFU->find_throwing(me, anqi);              
            if ( !obj )
               break;
		    if (i>0)
				message_vision(HIG "\n$N一甩手，又是一记" + obj->name() + HIG "激射而出！\n" NOR, me);
			if( F_KUNGFU->hit_rate( sp, eny[i]->query_skill("dodge"), 9-((pflv>=3)?(pflv-2):0), me, eny[i]) )
			{
                
                obj->move(eny[i]);
                damage = (int)(me->query_skill("throwing", "pili-dan") * 3/2);
                damage += obj->query("weapon_prop/damage") * 5;
                
                if(obj->query("id")=="pili dan")
                {
                    destruct(obj);
					damage += 100 + random(800) + (pflv>=3)?(pflv*(500+random(500))):0;
					message_vision( HIR "霹雳弹轰的一声炸开，$N被炸得浑身上下体无完肤！！\n" NOR, eny[i]);
                    F_KUNGFU->hit_wound("qi", damage, damage/2, me, eny[i]);
					if (pflv>=3)
					{
						if (eny[i]->query_busy() < (pflv*2)) eny[i]->start_busy(pflv*2);
						eny[i]->set_temp("death_cond_origin/hyd_condition", me);
						eny[i]->apply_condition("hyd_condition", 11 + eny[i]->query_condition("hyd_condition"));
					}
                }
				else
				{
					tell_object(eny[i], HIR "你眼见暗器射到身上，偏偏无法避开，不由惨叫一声，身子一歪，退后丈许！！\n" NOR);
					message("vision", HIR "结果" + eny[i]->name() + 
                        "被暗器射中，惨叫一声，身子一歪，退后丈许！！\n" NOR, environment(me), eny[i]);
					F_KUNGFU->hit_wound("qi", damage, damage/3, me, eny[i]);
                }
                COMBAT_D->report_status(eny[i]);
                if( (int)me->query("neili") < 150 )
                    break;
                me->add("neili", -150);
            }
			else
			{
				destruct(obj);
				message_vision( HIC "可是$N身子急退，躲开了扑面而来的暗器攻击。\n" NOR, eny[i]);
			}    
		}
    }

    return 1;
}

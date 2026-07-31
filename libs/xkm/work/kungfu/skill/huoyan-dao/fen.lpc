//Cracked by Roath
// /kungfu/skill/huoyan-dao/fen.c  perform 焚
// Summer, 11/10/96.
// kane, 25/11/98.
// xuanyuan, 29/11/2001

#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object armor, weapon;
        int damage, jiali, jiajin, ap, dp, pp, dmg, lvl, my_exp, max_dmg;
        string *limbs, limb, type, result, str, dodge_skill;

        my_exp = me->query("combat_exp");
        type = "内伤";

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("你不在战斗中。\n");

        if ( objectp(me->query_temp("weapon")) )
                return notify_fail("你不是空手。\n");

        if( (lvl=(int)me->query_skill("huoyan-dao", 1)) < 120 )
                return notify_fail("你的火焰刀修为不够。\n");

        if ( me->query_skill_mapped("force") != "xiaowuxiang"
        && me->query_skill_mapped("force") != "longxiang-banruo")
                                         return notify_fail("你所用内功不对！\n");

        if( me->query("neili") <= lvl*2 )
                                         return notify_fail("你的内力不够！\n");

        if( me->query("jingli") <= 150 )
                                         return notify_fail("你的精力不够！\n");

        message_vision(HIR "$N长吸一口气，身上衣衫缓缓涨起，两掌变得通红，射出一股灼人热气。$n的身影被笼罩在一团火焰之中。\n\n" NOR, me,target);
		if ( me->query("gender") == "无性" )
			tell_object(me, "但你体内阴气太重，火焰刀的功力只能大打折扣。\n");
		lvl = (int)(lvl / 5);
        me->add("neili", -lvl*2); 
        me->add("jingli", -100);  
        jiali = me->query("jiali");
        jiajin = me->query("jiajin");

        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE)/3;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE)/3;

	if (wizardp(me))
		printf("ap = %d , pp = %d , dp = %d .\n",ap*2,pp,dp);	// check overflow

        ap = (ap+random(ap*2))/2.5;

        if( ap > dp ) {
			weapon = target->query_temp("weapon");
			if(	target->query_skill_mapped("parry") == "yunu-jianfa" && 
				target->query_skill_mapped("force") == "yunu-xinjing" && 
				target->query_temp("suxin") && 
				target->query("neili") > 200 && 
				target->query_temp("weapon") &&
				target->query_skill("yunu-jianfa", 1) > 120){
				message_vision(HIY"$N已然看穿了$n的招数，不退反进，" + weapon->query("name") + HIY"中宫直进，直取$n手掌！\n"NOR, target, me);
				if( random((int)target->query_skill("yunu-jianfa", 1)) > random((int)me->query_skill("huoyan-dao", 1)) ){
					message_vision(HIR"$N大惊，但是此掌乃是全力，待$N发觉急收掌力，哪里还来得及，手掌眼看要被" + weapon->query("name") + HIR"刺穿！\n"NOR, me);
        			message_vision(HIR"\n$N“哎哟”一声，手掌急缩，再看时已是鲜血淋漓。\n"NOR, me);
        			me->add("eff_qi", -random(400));
					me->start_busy(2+random(3));
        			str = COMBAT_D->status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
					message_vision("($N"+str+")\n", me);
					return 1;
				}
					message_vision(HIR"$N大惊，掌缘微侧急收掌力避过了$n迎面刺来的" + weapon->query("name") + HIR"，这一避，掌上的威力势必也打了个折扣。\n\n"NOR, me, target);
					me->set_temp("target_suxin", 1);
			}
            tell_object(target, RED"你只觉一股热浪扑面，霍的胸口一阵剧痛。\n"NOR);
            if( target->query_temp("armor/cloth")){
                armor = target->query_temp("armor/cloth");
                if( armor->query("armor_prop/armor") < 150){
                
		if( armor->query("id") == "armor")
                     message_vision(HIY"只见$N身上的$n"+HIY+"已被震得粉碎，变成一块块碎片四下飞散！\n"NOR, target, armor);
		else message_vision(HIY"只见$N身上的$n"+HIY+"已被震得粉碎，变成一块块破布掉在地上。\n"NOR, target, armor);

                     armor->unequip();
                     armor->move(environment(target));
                     armor->set("name", "破碎的" + armor->query("name"));
                     armor->set("value", 0);
                     armor->set("armor_prop/armor", 0);
                     target->reset_action();
                }
            }
            dmg = me->query_skill("force")+me->query_skill("strike")+me->query("jiajin");
            dmg = (dmg + random(dmg*2))/2;   
            damage = dmg*(1+random(me->query("jiali")/15)); 
            max_dmg = 2000;
            // set the max damage according to player level
            // since now player can do way more damage to 2k
            // so for a 5M player here, his max damage is 4k
            if (my_exp > 1000000) {
                max_dmg = max_dmg + (int)((my_exp-1000000)/2000);
            }
            if( damage > max_dmg )
            {  
                damage = max_dmg;
            }
			//add by xuanyuan
			//eunuch get less damage
			if ( me->query("gender") == "无性" )
				damage = damage/3;
			//target perform suxin will let damage down
			if ( me->query_temp("target_suxin")){
				damage = damage/3;
				me->delete_temp("target_suxin");
			}

	if (wizardp(me))
		printf("damage = %d .\n",damage);	// check damage

            if( ap < pp ) damage = random(damage);
            //damage = random((int)me->query_skill("strike"))*5;  
            target->receive_damage("qi", damage,  me);
            target->receive_wound("qi", damage/2+random(damage/2), me);
            target->start_busy(1+random(2));                                                                        // target busy time > own busy time
            me->start_busy(2+random(2));
            if(jiali > me->query("neili"))
                jiali = me->query("neili");
            if(jiajin > me->query("jingli"))
                jiajin = me->query("jingli")-1;
            
            me->add("neili", -jiali-lvl);			// cost neili 140
            me->add("jingli", -jiajin-lvl/2);		// cost jingli 120

            limbs = target->query("limbs");

            result = COMBAT_D->damage_msg(damage, type);
            result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
            result = replace_string( result, "$p", target->name() );
            message_vision(result, me, target);

            str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
            message_vision("($N"+str+")\n", target);
        
        } else {
            message_vision(HIY "$p赶紧向後跃开数丈，躲开$P的攻击。\n" NOR, me, target);
            me->start_busy(1+random(3));
        }


        return 1;
}

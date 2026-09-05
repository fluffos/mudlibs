#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg,*skill, type;
        int i, pct, level;
        object weapon, oweapon;
        mapping pmap;
        mapping tname=(["sword":"剑", "blade":"刀", "whip":"索", "hammer":"鞭", "axe":"鞭", "staff":"枪", "spear":"枪", "halberd":"枪", "dagger":"剑", "throwing":"箭"]);
        mapping kname=(["sword":"胡砍乱刺", "blade":"胡劈乱砍", "whip":"胡缠乱绕", "hammer":"胡劈乱砸", "axe":"胡劈乱砍",
						"staff":"胡劈乱打", "spear":"胡刺乱打", "halberd":"胡刺乱打", "dagger":"胡刺乱戳", "throwing":"胡丢乱扔",]);
        mapping attack_val = ([
            "base" : ([ "weapon" : "sword", ]),//基本功夫类型
            "skill" : ([ "weapon" : "dugu-jiujian", ]),//高级技能名称
            ]);

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("独孤九剑绝招只能对战斗中的对手使用。\n");

        if(me->is_busy()) return notify_fail("你现在正忙着呢！\n");

        if( (level=me->query_skill("dugu-jiujian", 1)) < 80 )
            return notify_fail("你的独孤九剑不够娴熟，不会使用此招。\n");

        if (!objectp(oweapon = me->query_temp("weapon"))
         || (string)oweapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if(!objectp(weapon=target->query_temp("weapon")))
          if (!objectp(weapon=target->query_temp("secondary_weapon")))
                return notify_fail("对方是空手，没有兵器可破！\n");

        switch(weapon->query("skill_type") )
        {
          case "sword":
          case "blade":
          case "whip":
          case "staff":
          case "spear":
		  case "halberd":
          case "dagger":
		  case "hammer":
		  case "axe":
		  case "throwing":
            type=weapon->query("skill_type");
            break;
          default:
            return notify_fail("你不了解对方这奇门兵器，无法用独孤九剑破除。\n");
        }

        if ( me->query_skill(type,1)<100 && me->query_skill("dugu-jiujian", 1)<1000)
          return notify_fail("你的"+to_chinese(type)+"修为太低，独孤九剑又没有融会贯通，无法寻找对方的破绽！\n");

        if((int)me->query("neili") < 200)
              return notify_fail("你的内力不够施展独孤九剑！\n");

         pct=level/100;
         pct+=random(pct);
         if ( pct > 25 )
            pct=25;

        me->add("neili",-200);
        msg = HIC "只见$N剑锋一转，后发先至，迳剌$n的小腹。$n急忙躲闪，而$P一剑抢到了先着，\n"
			+"第二剑、第三剑便源源不绝地发出，每一剑都是又狠且准，剑尖锋刃，始终不离对手要害。\n"
			+"$n顿觉自己浸淫多年的武功漏洞百出，有如儿戏，一时间不免手忙脚乱！\n\n" + NOR;


        if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target) )
        {
          msg += HIR + "$n方寸大乱，越忙越慌，只顾着"+kname[type]+"，" +
				"一路武功已被这" + HIW + "『破"+tname[type]+"式』" + HIR + "尽数破个精光，\n"
				"全然溃不成招，似乎每一剑都能教$p断臂折足、破肚开膛，无论如何也挡不开。到这地步，\n" +
				"$n霎时间只觉万念俱灰，哇的一声，张嘴喷出一大口鲜血。\n\n" + NOR;
          if (target->query_wprepared(type))
          {
            pmap = target->query_wprepare();
            skill = keys(pmap);
            for (i=0; i<sizeof(skill); i++)
            {
              target->prepare_wskill(skill[i]);
            }
          }
          target->map_skill(type);
          target->reset_action();
          if ( !me->query_temp("active_buffer/dugu-jiujian.pobing") )
          {
            me->add_temp("apply/deep_injure", pct);
            me->set_temp("active_buffer/family","华山派");
            me->set_temp("active_buffer/dugu-jiujian.pobing/name", "破"+tname[type]+"式");             //buff名称
            me->set_temp("active_buffer/dugu-jiujian.pobing/last_time", time() + me->query("int")/4 ); //持续时间
            me->set_temp("active_buffer/dugu-jiujian.pobing/effect1", "物理攻击伤害+"+pct+"%");        //效果描述1
            call_out("end1", me->query("int")/4, me, pct);
          }

          if ( !target->query_temp("active_debuff/dugu-jiujian.pobing") &&
               target->query_temp("active_debuff/dugu-jiujian.poqi") )
          {
            target->add_temp("apply/kf_hit_rate", -level/500);
            target->add_temp("apply/kf_def_wound", -level/50);
            target->set_temp("active_debuff/dugu-jiujian.pobing/name", "破"+tname[type]+"式");             //buff名称
            target->set_temp("active_debuff/dugu-jiujian.pobing/last_time", time() + me->query("int")/4 ); //持续时间
            target->set_temp("active_debuff/dugu-jiujian.pobing/effect1", "特技攻击命中-"+level/500+"级"); //效果描述1
            target->set_temp("active_debuff/dugu-jiujian.pobing/effect2", "承受特效攻击伤害+"+level/50+"%"); //效果描述2
            call_out("end2", me->query("int")/4, target, level);
          }

          msg+=HIY "$N"HIY"乘$n"HIY"手忙脚乱的机会连出三剑！\n" NOR;
          message_vision(msg, me, target);
          me->set_temp("attack_val", attack_val);
          COMBAT_D->do_attack(me, target, oweapon, TYPE_SPECIAL);
          me->set_temp("attack_val", attack_val);
          COMBAT_D->do_attack(me, target, oweapon, TYPE_SPECIAL);
          me->set_temp("attack_val", attack_val);
          COMBAT_D->do_attack(me, target, oweapon, TYPE_SPECIAL);
          me->start_busy(2);
        } else {
          me->start_busy(3);
          msg += HIG + "$n临危不乱，运气于肩，肩使臂，臂使肘，肘使腕，于$N凌厉剑招中发出一记决然反击。\n" +
               "只听叮的一声脆响，双方兵刃相交，$N虎口剧震，竟被$p这一击带得剑势一偏。\n" + NOR;
          message_vision(msg, me, target);
		  if ((me->query("safari_skill/9jian"))&&(me->query("family/family_name")=="华山派")&&(!me->query("chushi/done"))&&(!me->query("betrayer")))
		  {
			if ( !me->query_temp("active_buffer/dugu-jiujian.pobing") )
			  {
				message_vision(HIY "\n但独孤九剑一招连着一招，后势无穷，$N顺势一挺剑锋，攻势更加凌厉！\n" NOR, me);
				me->add_temp("apply/deep_injure", pct);
				me->set_temp("active_buffer/family","华山派");
				me->set_temp("active_buffer/dugu-jiujian.pobing/name", "破"+tname[type]+"式");             //buff名称
				me->set_temp("active_buffer/dugu-jiujian.pobing/last_time", time() + me->query("int")/3 ); //持续时间
				me->set_temp("active_buffer/dugu-jiujian.pobing/effect1", "物理攻击伤害+"+pct+"%");        //效果描述1
				call_out("end1", me->query("int")/3, me, pct);//失败后有busy，持续时间比命中加长一点
			  }
			}
        }
        return 1;
}

void end1(object me, int pct)
{
        if (!me) return;
        me->add_temp("apply/deep_injure", -pct);
        me->delete_temp("active_buffer/dugu-jiujian.pobing");
        if ( sizeof(me->query_temp("active_buffer"))==1 )
        	me->delete_temp("active_buffer");
        message_vision(HIW"$N的独孤九剑恢复了平常的攻击。\n"NOR, me);
}

void end2(object target, int level)
{
        if (!target) return;
        target->add_temp("apply/kf_hit_rate", level/500);
        target->add_temp("apply/kf_def_wound", level/50);
        target->delete_temp("active_debuff/dugu-jiujian.pobing");
        if ( target->is_ghost() ) return;
        message_vision(HIY "\n$N渐渐适应了独孤九剑，攻守自如多了。\n" NOR, target);
}


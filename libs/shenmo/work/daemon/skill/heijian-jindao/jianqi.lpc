// heijian-jindao 剑气封闭对手
/*
    他见杨过提索出战，当即叫道：“看剑！”黑剑颤动，当胸刺去，可是剑尖并非直进，
却是在他身前乱转圈子。杨过不知这黑剑要刺向何方，大惊之下，急向后跃。
    公孙谷主出手快极，杨过后跃退避，黑剑划成的圆圈又已指向他身前，剑圈越划越大，
初时还只绕着他前胸转圈，数招一过，已连他小腹也包在剑圈之中，再使数招，剑圈渐渐扩
及他的头颈。杨过自颈至腹，所有要害已尽在他剑尖笼罩之下。金轮法王、尹克西、潇湘子
等生平从未见过这般划圈逼敌的剑法，无不大为骇异。
*/
#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
	int i,damage;
	object *inv;
	object weapon2;
	string msg;
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("剑气封闭对方只能对战斗中的对手使用。\n");

        if( me->query_dex() < 40 )
                return notify_fail("你在身法上先天禀赋不足，不能使用剑气封闭对方！\n");
        
        if( me->query_skill("dodge") < 150 )
                return notify_fail("剑气封闭对方需要超绝的轻功配合，方能有效施展！\n");

        if( me->query_skill("sword") < 150 )
                return notify_fail("你剑法未到炉火纯青之境，还不会使用剑气封闭对方！\n");
        if( me->query_skill("blade") < 150 )
                return notify_fail("你刀法未到炉火纯青之境，还不会使用剑气封闭对方！\n");
        if( me->query_skill("heijian-jindao",1) < 150 )
                return notify_fail("你黑剑金刀未到炉火纯青之境！\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("你的内力不够使用剑气封闭对方！\n");

        if( me->query("jing") <= 500 )
                return notify_fail("你的精力不够使用剑气封闭对方！\n");

        if (!weapon)
                return notify_fail("你手中无剑怎能使用剑气封闭对方？！\n");
        if (target->is_busy())
                return notify_fail("对方正自顾不暇你可以放胆进攻！\n");
        if (me->query_temp("heijian-jindao/nizhuan",1))
                return notify_fail("你正在使用阴阳倒乱刃法无法再用剑气封闭对方！\n");

        if ( me->query_skill_mapped("sword") != "heijian-jindao"
          || me->query_skill_mapped("parry") != "heijian-jindao"
          || me->query_skill_mapped("blade") != "heijian-jindao"
          && userp(me))
             	return notify_fail("你必须先将黑剑金刀相互配合。\n");
       inv = all_inventory(me);
       for(i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
		if (weapon->query("skill_type") == "blade") {
        	   if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   i = 3;
			   break;
		   }
		}
		if (weapon->query("skill_type") == "sword") {
   	        if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   i = 2;
			   break;
		   }
		}
       }
	if (!objectp(weapon2)) return notify_fail("你只有一种兵器就想剑气封闭对方？\n");
	if (i>2) weapon=weapon2; 
message_vision(HIM"$N叫道：“看剑！”"+weapon->name()+HIM"颤动，当胸刺去，可是剑尖并非直进，却是在$n身前乱转圈子。\n"+
		HIW"$n不知这"+weapon->name()+HIW"要刺向何方，大惊之下，急向后跃。\n"+
		HIM"$N出手快极，$n后跃退避，"+weapon->name()+HIM"划成的圆圈又已指向$n身前，剑圈越划越大，\n"+
		"初时还只绕着$n前胸转圈，数招一过，已连$n小腹也包在剑圈之中，再使数招，剑圈渐渐扩及$n的头颈。\n"+
		HIR"$n自颈至腹，所有要害已尽在他剑尖笼罩之下。\n"NOR,me,target);
	if((random(me->query("max_neili")) + me->query_skill("force",1)) >
	    (target->query("max_neili") + target->query_skill("force",1))/3 ||(target->is_busy()&&random(2))){
		damage = me->query_skill("heijian-jindao",1);
		damage += me->query_skill("sword",1);
		damage += random(damage);
		target->start_busy(damage/300);
    		target->add_temp("lost_attack", damage/100);
              target->start_busy(4);
		target->add("neili",-(500+random(150)));
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		msg = damage_msg(damage, "割伤");
		msg = replace_string(msg, "$w", weapon->name());
		msg = replace_string(msg, "$l", "小腹");
		message_vision(msg, me, target);
		COMBAT_D->report_status(target, random(2));
		me->add("neili",-300);
		me->add("jing",-50);
	} else {
		damage=600;
	}
        me->start_busy(2);
        me->add("neili", -500);
        me->add("jing", -50);
	me->start_perform(damage/300,"剑气封闭对方");

        return 1;
}

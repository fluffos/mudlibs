//shaolin ro+lh+qs+jm+san
//liu 2002

#include <ansi.h>

int shaolin(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(4)==1) {

		string* xuedao1 = ({"肩井穴","紫宫穴","中庭穴","关元穴","天池穴"});
		string* xuedao2 = ({"中渎穴","风市穴","环跳穴","渊液穴","阴谷穴","足三里"});
		string* xuedao3 = ({"中府穴","尺泽穴","孔最穴","列缺穴","太渊穴","少商穴"});
		string* xuedao4 = ({"商阳穴","合谷穴","手三里","曲池穴","迎香穴"});
		string* xuedao5 = ({"百会穴","灵台穴","太阳穴","膻中穴","命门穴","鸠尾穴","气海穴"});

		int sp, dp, time;

		sp = me->query_skill("dodge") + me->query_skill("parry") ;
		dp = target->query_skill("dodge") + target->query_skill("parry") ;

		time = (me->query_skill("force") - target->query_skill("force") + me->query_skill("finger"))/10;
		if (time > 10) time = 10;

		if( random(sp) > dp/2 && time > 0 )
		{
			if( me->query_skill("finger") >=  90 && me->query_skill("finger") < 115)
			message_vision(HIR "\n$N五指并拢，身形闪动间，已点中了$n的" + xuedao1[random(5)] + "！\n\n" NOR, me, target);
			if( me->query_skill("finger") >= 115 && me->query_skill("finger") < 140)
			message_vision(HIR "\n$N伸出三根手指，一挥手点中了$n的" + xuedao2[random(6)] + "！\n\n" NOR, me, target);
			if( me->query_skill("finger") >= 140 && me->query_skill("finger") < 165)
			message_vision(HIR "\n$N双指如刀如戟，着着进逼，唰地一声，已戳在了$n的" + xuedao3[random(6)] + "上！\n\n" NOR, me, target);
			if( me->query_skill("finger") >= 165 && me->query_skill("finger") < 190)
			message_vision(HIR "\n$N伸出一根中指，一道青气破空而出，嗤地射中了$n的" + xuedao4[random(5)] + "！\n\n" NOR, me, target);

			if( me->query_skill("finger") >= 190 )
			message_vision(HIR "\n$N指端微伸，劲力无影无踪地发出，$n顿时全身酸麻，已被点中了" + xuedao5[random(7)] + "！\n\n" NOR, me, target);

			me->add("neili", (-50)*time);
			target->start_busy(time);
        	}
		else
		{	
			message_vision(HIW "\n$N一指点去，可是$n早已料敌机先，一闪身避了开去！ \n\n$N身前顿时空门大露，狼狈地招架着 .... \n" NOR, me, target);
	         	me->start_busy(time/5);
		}

	} else if( random(4)==2) {

        	int org_enfor, enfor;
        	org_enfor = me->query("jiali");

		enfor = me->query("max_neili")/10;
		enfor = org_enfor + enfor/2;
		enfor = enfor/2+random(enfor);

        	me->set("jiali", enfor);

		if( wizardp(me) ) tell_object(me, "enforce : " + enfor);

		me->set_temp("sl_perform/san", 1);
		if(me->query_skill("banruo-zhang")) {
			me->set_temp("banruo",me->query_skill("banruo-zhang",1));
			me->set_skill("banruo-zhang", dk/2+me->query_skill("banruo-zhang",1)/2);
		} else me->set_skill("banruo-zhang", dk);
		me->map_skill("strike", "banruo-zhang");
		me->prepare_skill("strike", "banruo-zhang");

        	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

		me->delete_temp("sl_perform/san");
		if(me->query_temp("banruo")) me->set_skill("banruo-zhang",me->query_temp("banruo",1));
		else me->delete_skill("banruo-zhang");
		me->delete_temp("banruo");
		me->prepare_skill("strike");
		me->map_skill("strike");

        	me->add("neili",-(500+enfor*2));
        	me->add("jingli",-(300+enfor));
		if( me->query("neili") < 0 ) me->set("neili", 0);
		if( me->query("jingli") <= 0 ) me->set("jingli", 1);
        	me->set("jiali", org_enfor);
        	me->start_busy(4+random(3));

	} else if( random(4)==3) {

		int claw, lv, i, hit;
		string weapon, lzg_msg;

		if(me->query_skill("longzhua-gong")) {
			me->set_temp("longzhua",me->query_skill("longzhua-gong",1));
			me->set_skill("longzhua-gong", dk/2+me->query_temp("longzhua")/2);
		} else me->set_skill("longzhua-gong", dk);
		me->map_skill("claw", "longzhua-gong");
		me->prepare_skill("claw", "longzhua-gong");

		claw = me->query_skill("claw");
		lv = (int)me->query_skill("longzhua-gong",1);
		hit = (lv/100)*2;
		if(hit > 8) hit = 8;
		if(hit <4) hit = 4;

		me->add_temp("apply/speed", lv/10);
		me->add_temp("apply/attack", lv/10);
		me->add_temp("apply/damage", lv/10);

		lzg_msg = HIY"\n$N突然间大喝一声，纵身而上，双手犹如狂风骤雨，";
	
		if(hit >= 4)lzg_msg += "「捕风式」、「捉影式」、「抚琴式」、「鼓瑟式」";
		if(hit >= 6)lzg_msg += "、「批亢式」、「捣虚式」";
		if(hit >= 8)lzg_msg += "、「抱残式」、「守缺式」";
	
		lzg_msg += "，"+chinese_number(hit)+"式连环，疾攻而至！\n"NOR;

		message_vision(lzg_msg, me, target);
	        for( i=0; i < hit; i++ )
	        {
	                COMBAT_D->do_attack(me, target, weapon);
	        }

	        message_vision(HIY"\n这"+chinese_number(hit)+"式连环的龙爪手绵绵不绝，便如是一招中的"+chinese_number(hit)+"个变化一般，快捷无比！\n"NOR, me);

		me->add("neili", -hit*40+20);
		me->add("jingli", -hit*5);
		me->start_busy(1+random(2));
		me->add_temp("apply/speed", -lv/10);
		me->add_temp("apply/attack", -lv/10);
		me->add_temp("apply/damage", -lv/10);

		if(me->query_temp("longzhua")) me->set_skill("longzhua-gong",me->query_temp("longzhua",1));
		else me->delete_skill("longzhua-gong");
		me->delete_temp("longzhua");
		me->prepare_skill("claw");
		me->map_skill("claw");

		me->apply_condition("tong",1);

	} else {

		object weapon;
        	string msg;
	        int lv, hit, i, num;

		if(me->query_skill("qianye-shou")) {
			me->set_temp("qs",me->query_skill("qianye-shou",1));
			me->set_skill("qianye-shou", dk/2+me->query_temp("qs")/2);
		} else me->set_skill("qianye-shou", dk);
		me->map_skill("hand", "qianye-shou");
		me->prepare_skill("hand", "qianye-shou");

		weapon = me->query_temp("weapon");
        	lv = me->query_skill("hand");
		hit = (random(lv)/10);
		if(hit <2) hit = 2;
		if(hit >= 2) hit = 2;
		if(hit >= 4) hit = 4;
		if(hit >= 8) hit = 8;
		if(hit >= 16) hit = 16;

		me->add_temp("apply/speed", lv/15);
		me->add_temp("apply/attack", lv/15);
		me->add_temp("apply/damage", lv/15);

		msg = NOR "\n$N当下更不耽搁，轻飘飘拍出一掌，叫道：“施主，请接掌。”\n" NOR;
        	msg += HIY "这一掌招式寻常，但掌到中途，忽然微微摇晃，登时";

		if(hit = 2)msg += "一掌变两掌";
		if(hit = 4)msg += "，两掌变四掌";
		if(hit = 8)msg += "，四掌变八掌";
		if(hit = 16)msg += "，八掌变十六掌";
	
		msg += "！"+NOR+CYN+"\n$n脱口叫道：“千手如来掌！”知道只须迟得顷刻，$N便"+chinese_number(hit)+"掌变"+chinese_number(hit*2)+"掌，进而幻化为"+chinese_number(hit*4)+"掌！\n"NOR;

	        message_vision(msg, me, target);

		if(hit >= 2) num = 2;
		if(hit >= 4) num = 4;
		if(hit >= 8) num = 6;
		if(hit >= 16) num = 8;

		for( i=0; i < num; i++ )
		{
			COMBAT_D->do_attack(me, target, weapon);
		}

		me->add_temp("apply/speed", -lv/15);
		me->add_temp("apply/attack", -lv/15);
		me->add_temp("apply/damage", -lv/15);
		me->add("neili", -hit*100);

		if(me->query_temp("qs")) me->set_skill("qianye-shou",me->query_temp("qs",1));
		else me->delete_skill("qianye-shou");
		me->delete_temp("qs");
		me->prepare_skill("hand");
		me->map_skill("hand");

		me->apply_condition("tong",1);
	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}
//sanban, 无敌三板斧
//created 6-10-97 pickle
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

string *hitone = ({
    "$n试图侧身避开，但为时已晚。大斧劈在肩上，留下一道深可见骨的伤口！\n",
    "$n高举手中兵刃试图架开，但挡不住$N的来势，被震得吐出一口鲜血！\n",
    "$n以攻为守，但去势不够凌厉。虽逼得$N回斧自护，但还是在$n肩膀带出一道伤口。\n",
});
string *missone = ({
    "$n轻轻一闪，大斧带着一阵劲风从身边斩下，但没伤到$n分毫。\n",
    "$n高举手中兵刃奋力一架，只听「当」的一声巨响，$N巨斧已被弹开！\n",
    "$n不顾大斧来势，反而向$N疾攻，逼得$N不得不回斧自保，这一势「开瓜」就此落空。\n",
});
string *hittwo = ({
    "$n似乎没有觉出危险，顺手一挡。待到发觉来势之疾，为时已晚。脸上已多了一条数寸长的伤口！\n",
    "$n没想道$N攻势如此之快，急忙低头闪避，但无法躲开，被刀刃划得皮开肉绽！\n",
    "$n攻势已然发出，来不及回防，脸上被割掉一片皮，显然伤得不轻！\n",
});
string *misstwo = ({
    "$n脑袋微微一侧，避过了$N的攻势。\n",
    "$n似乎早已料到这一招，顺势在斧杆上一推，避了开去。\n",
    "眼看这招要把$n脑袋戳个对穿，突然间$n使个铁板桥，护手刀落了个空。\n",
});
string *hitthree = ({
    "$n似乎已被这三斧连环的威势吓破了胆，懒懒散散地一歪，被大斧横劈在肩头。\n",
    "$n看准来势，以手中兵器架去，但已力不从心，被斧头震得虎口出血，显然内伤不轻！\n",
    "$n眼见来势凌厉，企图低头避过，但不料大斧随着下劈，从$n背上割下一大片皮肉！\n",
});
string *missthree = ({
    "$n似乎早已熟知大斧来路，斧未到，人已先轻飘飘地避开了。\n",
    "$n眼见躲不过来招，急忙在地上一滚。虽然避得狼狈，但丝毫没有受伤。\n",
    "$n不顾自身危险，中宫直进，向$N攻去，果然将来招化解了。\n",
});
string *hit=({
    RED"$N"RED"道：也叫你尝尝这无敌三板斧的厉害！\n"NOR,
    RED"这无敌三板斧一气呵成，$n"RED"被攻了个措手不及，伤势甚为可怕！\n"NOR,
    RED"$N"RED"狂笑道：就凭你这点本事，也来跟我斗？\n"NOR,
});
string *miss=({
    HIB"$n"HIB"哈哈大笑道：$1听说这无敌三板斧有多少威力，现在一看，也不过如此嘛！\n"NOR,
    HIB"$n"HIB"长笑一声，对$N"HIB"不屑地说道：就这点本事，$1还没放在眼里！\n"NOR,
    HIB"$n"HIB"仰天大笑道：还有什么本事，尽管拿出来吧！\n"NOR,
  });

int perform(object me, object target)
{
	string msg,succ_msg,limb;
	int damage,hits=0;
	object weapon;

	if( me->query_level()<20 )
		return notify_fail("你的人物等级不够。\n");
	if(me->query("family/family_name")!="将军府")
        	return notify_fail("你不是将军府弟子，不能使用这项技能！\n");
	if((string)me->query_skill_mapped("force")!="lengquan-force")
        	return notify_fail("无敌三板斧必须以冷泉神功为底子。\n");
	if(me->query_skill("lengquan-force",1) < 200)
        	return notify_fail("你的内功底子不足，无法运斧如风，施展不出无敌三板斧。\n");
	if(me->query_skill("sanban-axe",1)<200)
        	return notify_fail("你对宣花三斧不够熟悉，无法一气呵成地使出！\n");
	if(me->query("force")<800)
        	return notify_fail("你的内力不足，难以随意挥动一柄大斧。\n");
	if( time()<me->query_temp("jjf_sanban")+8 )
        	return notify_fail("绝招用多就不灵了。\n");
	weapon=me->query_temp("weapon");
	if( !weapon
	 || ( weapon->query("skill_type")!="axe"
	   && weapon->query("use_apply_skill")!="axe" ) )		
        	return notify_fail("你的斧子呢？\n");
        if( !target ) target = offensive_target(me);
	if( !target
 	|| !target->is_character()
 	|| target->is_corpse()
 	|| target==me
 	|| !me->is_fighting(target) )
        	return notify_fail("无敌三板斧不是练着好看的，只能对战斗对手施用。\n");

	me->set_temp("jjf_sanban",time());        	
	me->add("force",-300);
	
	damage = me->query_skill("axe")/100*me->query_str()+me->is_knowing("jjf_sanban")*5;
	msg = CYN "$N"CYN"一声暴喝：开瓜！剔牙！掏耳朵！三招一气呵成！\n\n只见一道青影划过，大斧直劈$n"CYN"顶门！\n" NOR;
	succ_msg = hitone[random(sizeof(hitone))];
	limb = ({"头部","颈部","左肩", "右肩"})[random(4)];
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,limb,damage);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(missone[random(sizeof(missone))],me,target);
		me->add("force",-50);
	}
	else	hits++;	
	
	damage = me->query_skill("axe")/60*me->query_kar()+me->is_knowing("jjf_sanban")*5;
	msg = CYN"$N"CYN"$w"CYN"已经带过，顺势以斧尾护手尖刀疾挑$n"CYN"面门！\n"NOR;
	succ_msg = hittwo[random(sizeof(hittwo))];
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,"头部",damage);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(misstwo[random(sizeof(misstwo))],me,target);
		me->add("force",-50);
	}	
	else	hits++;	
	
	damage = me->query_skill("axe")/80*(me->query_kar()+me->query_str())+me->is_knowing("jjf_sanban")*5;;
	msg = CYN"$N"CYN"迅疾无伦地翻转斧头，$w"CYN"向$n"CYN"脑袋横劈过去！\n"NOR;
	succ_msg = hitthree[random(sizeof(hitthree))];
	limb = ({"头部","颈部","左肩", "右肩","后心"})[random(5)];
	me->set_temp("pfm_msg",1);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg,limb,damage);
	me->set_temp("pfm_msg",0);
	if( damage<1 )
	{
		message_combatd(missthree[random(sizeof(missthree))],me,target);
		me->add("force",-50);
	}	
	else	hits++;	
	
	if( hits>0 )
		message_combatd(hit[random(sizeof(hit))],me,target);
	else
	{
		msg = miss[random(sizeof(miss))];
		msg = replace_string(msg,"$1",RANK_D->query_self_rude(target));
		message_combatd(msg,me,target);
	}
	return 1;
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：无敌三板斧
        外功所属：宣花三斧
        外功效果：程咬金的独门绝技
        	  对敌进行三次带固定伤害的要害攻击
                  冷却时间8秒
        外功条件：
        	  将军府弟子
        	  人物等级20级
                  内力800点，消耗300点，每未命中1击，增加消耗50点
                  宣花三斧200级
                  冷泉心法200级
LONG;
me->start_more(str);
return 1;
}

//lingjiu bh+hm
//liu 2002

#include <ansi.h>
#include <armor.h>
#include <combat.h>

string* xuedao1 = ({"肩井穴","紫宫穴","中庭穴","关元穴","天池穴"});
string* xuedao2 = ({"中渎穴","风市穴","环跳穴","渊液穴","阴谷穴","足三里"});
string* xuedao3 = ({"中府穴","尺泽穴","孔最穴","列缺穴","太渊穴","少商穴"});
string* xuedao4 = ({"商阳穴","合谷穴","手三里","曲池穴","迎香穴"});
string* xuedao5 = ({"百会穴","灵台穴","太阳穴","膻中穴","命门穴","鸠尾穴","气海穴"});

void tie2_hit(object me, object target);
void nuan_hit(object me, object target);
void han_hit(object me, object target);

int lingjiu(object me,object target)
{
	int dk = me->query_skill("douzhuan-xingyi",1);

	me->set_temp("tong",1);

	if( random(2) == 1 )
	{
		int strike;

		if(me->query_skill("liuyang-zhang")) {
			me->set_temp("memory",me->query_skill("liuyang-zhang",1));
			me->set_skill("liuyang-zhang", dk/2+me->query_skill("liuyang-zhang",1)/2);
		} else me->set_skill("liuyang-zhang", dk);
		me->map_skill("strike", "liuyang-zhang");
		me->prepare_skill("strike", "liuyang-zhang");

		me->add("neili", -100);
		me->add("jingli", -150);

		strike = me->query_skill("strike")/2;

		me->add_temp("apply/attack", strike);

		message_vision(WHT "\n$N左掌拍出，右掌一带，左掌之力吞吐不定。
这门功夫乃是逍遥派上乘掌法中的"+ HIW +"‘白虹掌力’"+ NOR + WHT +"，此刻$N掌力曲直如意，当真了得！\n"NOR, me);

		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->add_temp("apply/attack", -strike);

		if(me->query_temp("memory")) me->set_skill("liuyang-zhang",me->query_temp("memory",1));
		else me->delete_skill("liuyang-zhang");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

		me->start_busy(1+random(1));

	} else {

		me->add_temp("ly_nuan",1);
		remove_call_out("nuan_hit");
		nuan_hit(me, target);
		return 1;
	}
	if(me->query("neili",1)<0) me->set("neili",0);
	me->delete_temp("tong");
	return 1;
}


void nuan_hit(object me, object target)
{
	object armor;
	int damage, time, ap, dp, pp, fap, lyz, force;
	string msg, *limb, type, result, str;
	object weapon;

	int dk = me->query_skill("douzhuan-xingyi",1);

	if( !target || !me->is_fighting(target) || !living(me) || me->is_ghost() ||
	 !target || environment(me) != environment(target) || !me->is_fighting() ) 
	{
		me->delete_temp("tong");
		return;
	}

	type = "内伤";


		if(me->query_skill("liuyang-zhang")) {
			me->set_temp("memory",me->query_skill("liuyang-zhang",1));
			me->set_skill("liuyang-zhang", dk/2+me->query_skill("liuyang-zhang",1)/2);
		} else me->set_skill("liuyang-zhang", dk);
		me->map_skill("strike", "liuyang-zhang");
		me->prepare_skill("strike", "liuyang-zhang");

		if(me->query_skill("zhemei-shou")) {
			me->set_temp("memory2",me->query_skill("zhemei-shou",1));
			me->set_skill("zhemei-shou", dk/2+me->query_skill("zhemei-shou",1)/2);
		} else me->set_skill("zhemei-shou", dk);
		me->map_skill("hand", "zhemei-shou");
		me->prepare_skill("hand", "zhemei-shou");


	lyz = (int)me->query_skill("liuyang-zhang", 1);
	force = (int)me->query_skill("force", 1);

	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;
	ap = ap*(1+time);

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	
	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
	if( pp < 1 ) pp = 1;

	msg = HIM "\n突然$N右掌向前一推，六阳掌雷霆而出，犹如六日同升，四周涌起一片暖意向$n袭来。\n" NOR;
	message_vision(msg , me,target);
	
	me->add("neili", -lyz);
	me->add("jingli", -lyz/2);

	fap = random(ap + dp);

	if( living(target) && fap < dp ) {

		if (target->query_skill("liuyang-zhang") > me->query_skill("liuyang-zhang")*2/3)
		{
		message_vision(HIY "\n$n已将天山六阳掌练得甚熟，竟然一一格开，挡架之中，还隐隐蓄有坚实浑厚的反击之力！\n\n" NOR, me, target);
		}
		else {
		message_vision(HIY "\n$n大吃一惊，骤然退步抽身，万分惊险中堪堪躲过了这招，却早已吓出了一身冷汗！\n\n" NOR, me, target);
		if(me->query_skill("hand") >= me->query_skill("strike")*2/3){
			call_out("han_hit",1+random(2),me,target);
			}
		}
		target->start_busy(2+random(2));
		me->start_busy(1);
		me->delete_temp("tong");
	}

	else if( random(ap + pp)< pp && random(5) == 0 && target->query("race") == "人类" )
	{
		weapon = target->query_temp("weapon");
		if(weapon)
		{

			if(target->query("neili") > me->query("neili")){
					message_vision(HIR"\n$N猛觉得一股灼流压来，冷笑一声，手中"NOR + weapon->name() + HIR"护住全身，另一只手单掌劈出。只听碰然一声大响，两掌相对，周围尘土四处飞散。\n"NOR, target );
				}
			else if(target->query("neili") < me->query("neili")){

					weapon->unequip();
					weapon->move(environment(target));
					target->reset_action();
					message_vision(HIR"\n$N猛觉得一股灼流压来，心知不妙，手中"NOR + weapon->name() + HIR"脱手飞出，赶紧举掌来架。只听碰然一声大响，两掌相对，周围尘土四处飞散。\n"NOR, target );
				}
		}
		else message_vision(HIR"\n$N猛觉一股灼流压来，心知不妙，赶紧举掌来架。只听碰然一声大响，两掌相对，周围尘土四处飞散。\n\n"NOR, target );

		message_vision(HIW BLK"$N身子一震，察觉$n以内力相攻，立运内力回攻。。\n\n"NOR, target, me);
		me->delete_temp("tong");
		target->add("neili", -lyz);
		target->add("jingli", -lyz);
		target->start_busy(3+random(2));
		me->start_busy(2+random(2));
		remove_call_out("tie2_hit");
		call_out("tie2_hit",3+random(2),me,target);
	} else {
		if( target->query_temp("armor/cloth") )
			armor = target->query_temp("armor/cloth");

		if( (!living(target) || (!armor || (armor && armor->query("armor_prop/armor") < 150) )) && ( target->query_skill("dodge")+target->query_skill("parry") ) < random((me->query_skill("strike") + me->query_skill("force"))*2/3) && target->query("race") == "人类")
		{
			message_vision(HIR"\n这一掌纯是阴柔之力，两人相距又近，$N待得发觉，待欲招架，掌力已袭到胸前，只觉气息闭塞，经脉已然受到重创，眼前一黑，便什么都看不见了。\n\n"NOR, target,target );
			target->receive_wound("qi", (int)target->query("eff_qi"), me);
			target->receive_damage("qi", (int)target->query("qi")+1,  me);
			me->add("neili", -(me->query("jiali")+lyz/2));
			me->add("jingli", -me->query("jiajin"));
			me->delete_temp("tong");
		}
		else
		{
			damage = (me->query("jiali") + me->query("jiajin")) * (int)me->query_skill("force")/60 + (random(lyz)+force)*time +me->query_temp("apply/damage");

			if(damage > me->query_skill("strike")*10 ) damage = me->query_skill("strike")*10;
			if(damage < me->query_skill("strike")*2 ) damage = me->query_skill("strike")*2;

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage/2)+damage/4, me);
			target->start_busy(1+random(3));

			limb = target->query("limbs");

			if(random(2) ) type = "瘀伤";
			result = COMBAT_D->damage_msg(damage, type);
			result = replace_string( result, "$l", limb[random(sizeof(limb))]);
			result = replace_string( result, "$p", target->name() );

			if( damage < 600 ) 
			message_vision(HIR"\n$N慌忙中闪身一避，不料迎上了四周的六阳掌力，顿时被一股灼流压的几乎透不过气来！\n"NOR, target,me );
			else if( damage < 1200 ) 
			message_vision(HIR"\n只听喀喇喇几声响，$N被掌力拍中了前胸，断了几根肋骨！\n"NOR, target,me );
			else if( damage < 2000 ) 
			message_vision(HIR"\n$N慌忙中闪身想避，不料拍的一声响，$N长声惨呼，后心“至阳穴”上中了$n一掌重手！\n"NOR, target,me );
			else 			
			message_vision(HIR"\n这掌乃贴身施为，$N别说出手抵挡，斜身闪避，仓卒中连运气护穴也是不及，身子给一掌震飞，摔在丈许之外！\n"NOR, target,me );

			message_vision(result, me, target);

			str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
			message_vision("( $N"+str+" )\n", target);
			if(wizardp(me)) tell_object(me, "hanmei damage: "+damage+"\n");
		}
		me->delete_temp("tong");
	}
	me->start_busy(3+random(2));

		if(me->query_temp("memory")) me->set_skill("liuyang-zhang",me->query_temp("memory",1));
		else me->delete_skill("liuyang-zhang");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

		if(me->query_temp("memory2")) me->set_skill("zhemei-shou",me->query_temp("memory2",1));
		else me->delete_skill("zhemei-shou");
		me->delete_temp("memory2");
		me->prepare_skill("hand");
		me->map_skill("hand");
		me->delete_temp("tong");
}

void han_hit(object me, object target)
{
	int ap, dp, pp, time;

	int dk = me->query_skill("douzhuan-xingyi",1);

	if( !target || !me->is_fighting(target) || !living(me) || me->is_ghost() ||
	 !target || environment(me) != environment(target) || !me->is_fighting() ) 
	{
		me->delete_temp("tong");
		return;
	}


		if(me->query_skill("liuyang-zhang")) {
			me->set_temp("memory",me->query_skill("liuyang-zhang",1));
			me->set_skill("liuyang-zhang", dk/2+me->query_skill("liuyang-zhang",1)/2);
		} else me->set_skill("liuyang-zhang", dk);
		me->map_skill("strike", "liuyang-zhang");
		me->prepare_skill("strike", "liuyang-zhang");

		if(me->query_skill("zhemei-shou")) {
			me->set_temp("memory2",me->query_skill("zhemei-shou",1));
			me->set_skill("zhemei-shou", dk/2+me->query_skill("zhemei-shou",1)/2);
		} else me->set_skill("zhemei-shou", dk);
		me->map_skill("hand", "zhemei-shou");
		me->prepare_skill("hand", "zhemei-shou");


	ap = COMBAT_D->skill_power(me, "strike", SKILL_USAGE_ATTACK);
	if( ap < 1 ) ap = 1;

	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
	if( dp < 1 ) dp = 1;
	
	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
	if( pp < 1 ) pp = 1;

	time = (me->query_skill("force") - target->query_skill("force") + me->query_skill("hand"))/10;
	if (time > 12) time = 12;
	if (time < 4) time = 4;
	message_vision(HIC "\n同时$N左手顺势一拂，折梅手含而不露，却似香梅傲雪，隐隐带着一丝寒意拂向$n的" + xuedao3[random(6)] + "！\n\n" NOR, me, target);

	if( random(ap) < dp/2 && time > 0 )
	{
		message_vision(HIY "$n只觉一道寒意袭来，不禁打了个冷战，脚步一错，滑了开去。\n" NOR, me, target);
		me->add("neili", -100);
		me->start_busy(time/5);
		me->delete_temp("tong");
	}
	else if( random(ap) < pp/2 && time > 0 ){
		message_vision(HIW "$n听风辨形，随机应变，一觉到$N的手指将要碰到自己肩头，当即沉肩斜身，反手往$N手背按去。\n" NOR, me, target);
		COMBAT_D->do_attack(target, me, target->query_temp("weapon"));
		me->add("neili", -100);
		me->start_busy(time/5);
		me->delete_temp("tong");
	}
	else{
		message_vision(WHT "$N小指的一拂之中，含有最上乘的“小无相功”，$n的功力便再深三四十年，也难躲过这一拂。\n" NOR, me, target);
		message_vision(HIR "$N一拂即中，$n登时动弹不得。\n" NOR, me, target);
		me->delete_temp("ly_nuan");
		remove_call_out("nuan_hit");
		me->add_temp("ly_han",1);
		me->add("neili", (-50)*time);
		target->start_busy(time);
	}

		if(me->query_temp("memory")) me->set_skill("liuyang-zhang",me->query_temp("memory",1));
		else me->delete_skill("liuyang-zhang");
		me->delete_temp("memory");
		me->prepare_skill("strike");
		me->map_skill("strike");

		if(me->query_temp("memory2")) me->set_skill("zhemei-shou",me->query_temp("memory2",1));
		else me->delete_skill("zhemei-shou");
		me->delete_temp("memory2");
		me->prepare_skill("hand");
		me->map_skill("hand");
		me->delete_temp("tong");
}

void tie2_hit(object me, object target)
{
	int sum, n1, n2;
	string msg;

	if( !target || !me->is_fighting(target) || !living(me) || me->is_ghost() ||
	 !target || environment(me) != environment(target) || !me->is_fighting() ) 
	{
		me->delete_temp("tong");
		return;
	}

	sum = me->query_skill("force")*2 + target->query_skill("force") + target->query_skill("parry");
	n1 = me->query("neili");
	n2 = target->query("neili");

	me->add("neili", -100 * sum / ( me->query_skill("force")*2 ) ); 
	if(me->query("neili")<0)me->set("neili",0);

	target->add("neili", -100 * sum / ( target->query_skill("force") + target->query_skill("strike") ) );
	if(target->query("neili")<0)target->set("neili",0);

	if( n1 > 3000 && n2 > 3000) {
		msg = WHT"此时双方掌力均极强劲，欲分胜负，非使对方重创不可。\n"NOR;

		if( n1 > n2 )
		msg += HIW"二人又僵持一会，$n头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR;
		else msg += HIW"二人又僵持一会，$N头顶透出一缕缕的白气，渐渐越来越浓，就如蒸笼一般。\n"NOR;
	}

	else {

		if( n1 > n2 ) msg = WHT"$N不绝催发内力，毫无衰颓迹象。稍过片刻，$n已是全身大汗淋漓。\n"NOR;
		else msg = WHT"$N脸上隐约见黑气。稍过片刻，$N已是全身大汗淋漓。$n的内力源源而至，显然不致立时便即耗竭。\n"NOR;
		}

	message_vision(msg , me,target );

	if( me->query("neili") > 0 && target->query("neili") > 0 && me->is_busy() && target->is_busy() && living(me) && living(target) )
	{
		if (me->query_skill("beiming-shengong") > 120 && !target->query_skill("beiming-shengong") && me->query_skill_mapped("force") == "beiming-shengong" )
		{
			message_vision(HIR "\n$N惊觉自己的内力源源地从手掌流向$n，正是$n体内的北冥真气在作怪！\n\n" NOR, target, me);
			me->add("neili", me->query_skill("beiming-shengong") ); 
			target->add("neili", -1 * ( me->query_skill("beiming-shengong") ) ); 
		}
		target->start_busy(3+random(2));
		me->start_busy(3+random(2));
		remove_call_out("tie2_hit");
		call_out("tie2_hit",2+random(2), me,target);
		return;
	}

	if( target->query("neili") <= 0 )
	{
		message_vision(HIR "\n$N忽听得$N“啊”的一声，被一个筋斗震了开去，扑通一响，摔跌在丈许开外。\n\n" NOR, target);
		target->receive_wound("qi", (int)target->query("eff_qi"), me);
		target->receive_damage("qi", (int)target->query("eff_qi")+1,  me);
		return;
	}

	if( me->query("neili") <= 0 )
	{
		message_vision(HIR "\n$N内力突然间失却控制，便如洪水泛滥，立时要溃堤而出。顷刻之间，只觉全身各处穴道中同时麻痒，惊惶之余，已知此伤绝不可治，眼前一黑，便什么都看不见了。\n\n" NOR, me);
		me->receive_wound("qi", (int)me->query("eff_qi"), target);
		me->receive_damage("qi", (int)me->query("eff_qi")+1,  target);
	}
	me->delete_temp("tong");
}

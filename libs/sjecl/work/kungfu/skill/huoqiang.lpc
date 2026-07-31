// huoqiang.c 火墙
#include <ansi.h>
#include <combat.h>
#include <pktime.h>

inherit F_SSERVER;
int start_huoqiang(object me);
int check_pfm(object me, object target, object ob);
int perform(object me, string target)
{
	object ob, tar;

	if(!target)
		return notify_fail("你想驱动「火墙」对付谁？\n");

	if(!objectp(tar = present(target, environment(me))))
		return notify_fail("这里没有你想对付的这个人。\n");

	if(!tar->is_character())
		return notify_fail("看清楚一点，那并不是生物。\n");

	if(!living(tar))
		return notify_fail(tar->name()+"已经无法战斗了。\n");

	if(tar==me) return notify_fail("和自己拼命？！\n");

	if( me->query("no_pk") && userp(tar))
		return notify_fail("你已经退出江湖，还是老老实实的吧。\n");

	if( tar->query("no_pk"))
		return notify_fail( target->name()+"已经退出江湖了，得饶人处且饶人吧！\n");

	if ( pktime_limit(me, tar))
		return 0;

	if( me->query_temp("user_type") == "worker" && userp(tar))
		return notify_fail("你是工匠，无法使用「火墙」。\n");

	if( me->is_busy())
		return notify_fail("你先忙完再说拼命的事。\n");

	if (userp(tar) && userp(me)
	&& me->query("combat_exp") < me->query("mud_age")/6)
		return notify_fail("你的火墙用的太多了，还是多花点时间去练功吧。\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用「火墙」！\n");

	if(!objectp(ob = present("huo yan", environment(me))) && !wizardp(me))
		return notify_fail("没有火堆怎么驱动「火墙」进行攻击？\n");

	if(me->query_temp("pfm_chousui"))
		return notify_fail("你正在驱动火堆进行攻击！\n");

	if(environment(me)->query("no_fight"))
		return notify_fail("在这里好象施展不开！\n");

       	message_vision(BLU"\n$N神色惨淡，伸手打开发髻，长发下垂，覆在脸上，跟着点燃红磷粉，咬破舌尖，\n"+
			"一口"RED"鲜血"BLU"向火焰中喷去。"HIR"火焰忽地一暗，随即大为"RED"明亮"HIR"，耀得众人眼睛也不易睁开。\n\n"NOR,me);

	me->start_busy(1);
	me->set_temp("pfm_chousui", 1);
	me->start_perform(10, "火墙");
	if(random(me->query_kar()) > 5 && tar->query_temp("user_type") != "worker")
		check_pfm(me, tar, ob);
	else 	call_out("check_pfm", 5, me, tar, ob);
	return 1;
}

int check_pfm(object me, object target, object ob)
{
	string msg;
	int ap, dp, p, i;

	if(!me) return 0;
	me->delete_temp("pfm_chousui");
	me->start_busy(1);
	if(!living(me) || me->is_ghost()) return 1;

	if(!objectp(present(ob, environment(me)))){
	   	message_vision(HIY"$N眼看火堆熄灭，散开内息。\n"NOR,me);
	   	return 1;
	}

	if( me->query_skill("chousui-zhang", 1) < 220 ){
		tell_object(me, "你发现自己的星宿毒掌还不够娴熟，无法使用「火墙」进行攻击。\n");
		return 1;
	}
	if( (int)me->query_skill("huagong-dafa",1) < 220 ){
		tell_object(me,"你发现自己的化功大法修为不够，无法使用「火墙」进行攻击。\n");
		return 1;
	}
	if((int)me->query_skill("poison",1) < 150){
		tell_object(me,"你发现自己体内聚毒不够，无法使用「火墙」进行攻击。\n");
		return 1;
	}
	if(me->query("family/master_name") != "丁春秋" ){
		tell_object(me,"你不是丁春秋的弟子，如何学到足够的抽髓掌？\n");
		return 1;
	}
	if (me->query_skill_prepared("strike") != "chousui-zhang"
	|| me->query_skill_mapped("strike") != "chousui-zhang"
	|| me->query_skill_mapped("parry") != "chousui-zhang"){
		tell_object(me,"你必须用抽髓掌才能使用「火墙」进行攻击。\n");
		return 1;
	}
	if( me->query_skill_mapped("force") != "huagong-dafa"){
		tell_object(me,"你发现自己所用的内功无法进行「火墙」攻击。\n");
		return 1;
	}
	if( (int)me->query("max_neili") < 1000) {
		tell_object(me,"你发现自己内力实在太弱，无法驱动「火墙」进行攻击。\n");
		return 1;
	}
	if(me->query("neili") < 800){
		tell_object(me,"你发现自己现在真气实在太弱，举不起「火墙」进行攻击。\n");
		return 1;
	}
	if(!target || !living(target)
	|| environment(me)!=environment(target)){
	   	message_vision(HIY"$N衣袖再拂，将抬起的"HIR"火墙"HIY"压回火焰之中。\n"NOR,me);
	   	return 1;
	}

	me->add("neili", -1000);
	me->add("jingli", -300);

	msg = BLU"\n$N猛地身子急旋，如陀螺般连转了十多个圈子，接着$P大袖拂动，"HIR"整个火焰堆陡地拨起，凌空\n"+
		"燃烧，便如一座"RED"火墙"HIR"般，夹着排山倒海之势向$n压来！\n"NOR;

	if(!target->is_killing(me->query("id"))) me->kill_ob(target);

	ap = me->query("combat_exp", 1)/100 * me->query_str(1)/2;
	dp = target->query("combat_exp", 1)/100 * target->query_str(1)/2;
	
	if( (i = random(ap)) > to_int(dp/2.5) ){

		if( wizardp(target) ) tell_object(target, me->name() +"对你使用了【"RED"火墙"NOR"】命中率为：
		臂力 A = "+me->query_str(1)+" ：B = "+target->query_str(1)+"
		参数 A = "+ap+" : B = "+dp+"
		命中判断 A = "+i+" ：B = "+to_int(dp/2.5)+"\n"NOR);

		msg += HIY"碧焰映照之下$p微一迟疑，那火墙来得快极，便要扑到身上，$p只得双掌齐出，\n"+
			"两股轻风向外送出，衣袖鼓风飘起，劲力已推向那堵绿色的光墙！\n\n" NOR;
		target->add("neili", -1000);
		target->add("jingli", -200);
		me->set_temp("huoqiang_target", target->query("id"));
		me->set_temp("huoqiang/period", 1);
		target->set_temp("huoqiang_target", me->query("id"));
		target->set_temp("huoqiang/period", 1);
		me->start_busy((: start_huoqiang :));
		target->start_busy((: start_huoqiang :));
		message_vision(msg, me, target);
		return 1;
	}

	else if( (i = random(ap)) > dp/3 ) {

		if( wizardp(target) ) tell_object(target, me->name() +"对你使用了【"RED"火墙"NOR"】命中率为：
		臂力 A = "+me->query_str(1)+" ：B = "+target->query_str(1)+"
		参数 A = "+ap+" : B = "+dp+"
		命中判断 A = "+i+" ：B = "+dp/3+"\n"NOR);

		me->start_busy(random(2));
		msg += HIY"\n$n只吓目瞪口呆，一怔之间，急忙跃起，但一朵"HIW"火花"HIY"已射到身前，嗤的一声响，\n"+
		"火花已烧上肚腹。$n“啊”的一声大叫，落了下来。那团"HIR"大火墙"HIY"也即回入火焰堆中。\n" NOR;
		target->receive_damage("qi", me->query_skill("force")*2, me);
		p = (int)target->query("qi")*100/(int)target->query("max_qi");
		me->add("neili", 700);
		me->add("jingli", 150);
		msg += COMBAT_D->damage_msg(me->query_skill("force"), "刺伤");
		msg += "( $n"+COMBAT_D->eff_status_msg(p)+" )\n";
		msg = replace_string(msg, "$l", "肚腹");
		msg = replace_string(msg, "$w", HIW"火花"NOR);
	}
      	else {

		if( wizardp(target) ) tell_object(target, me->name() +"对你使用了【"RED"火墙"NOR"】命中率为：
		臂力 A = "+me->query_str(1)+" ：B = "+target->query_str(1)+"
		参数 A = "+ap+" : B = "+dp+"\n"NOR);

		me->add("neili", 800);
		me->add("jingli", 200);
		me->start_perform(2, "火墙");
		me->start_busy(random(2));
		msg += HIY"$n只吓目瞪口呆，一怔之间，"HIR"火墙"HIY"已射到身前，急忙跃起，"HIR"火墙"HIY"堪堪从$p足底下飞过！\n" NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

int start_huoqiang(object me)
{
	string msg, tar;
	object target, ob;
	int neili_lost, period, neili, neili2;

	if(!me) return 0;
	tar = me->query_temp("huoqiang_target");
	target = present(tar, environment(me));
	if(!objectp(target) || target->is_ghost() || environment(me)!=environment(target) || !target->is_busy() ){
	    	message_vision(CYN"$N当下内劲一收，一双衣袖便即垂下，摇摇晃晃地站了起来。\n"NOR, me);
	    	return 0;
	}
	neili_lost = 15 + target->query_skill("force")/10 + me->query("jiali")/2 + target->query("jiali")/2;
	period = (int)me->query_temp("huoqiang/period");
	neili = me->query("neili");
	neili2 = target->query("neili");

	me->receive_damage("neili", neili_lost);
	me->receive_damage("jingli", 3+random(5));
	me->improve_skill("force", random(2));

	if(me->is_ghost()) return 0;

	if(neili < neili_lost){
		message_vision(HIY"$N内力消耗殆尽，终因不支倒地！\n"NOR, me);
		me->set_temp("last_damage_from", target);
		me->unconcious();
		return 0;
	}
	if(!living(target) && living(me) && target->query_temp("faint_by") == me){
		msg = HIR"$N双掌拍出，一道"GRN"碧焰"HIR"吐出，射向$n。$p此刻已无丝毫还手余地，连站起来逃命的力气也无。\n"+
			GRN"碧焰"HIR"一射到$p身上，霎时间头发衫着火，狂叫惨号声中，全身都裹入"RED"烈焰"HIR"之中。\n"NOR;
		msg += "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		msg += "( "RED"$n受伤过重，已经有如风中残烛，随时都可能断气。"NOR")\n";
		message_vision(msg, me, target);
		target->set_temp("last_damage_from", me);
		target->die();
		return 0;
	}
	if(!living(me) && !living(target)){
		message_vision(HIW"此时$N和$n的脸上都已无半点血色，看来已经到了油尽灯枯之时！\n"NOR,me,target);
		me->set_temp("last_damage_from", "和"+target->name()+"同归于尽");
		target->set_temp("last_damage_from", "和"+me->name()+"同归于尽");
		me->die();
		target->die();
		return 0;
	}
	if(!objectp(ob = present("huo yan", environment(me)))) {
		message_vision(HIY"$N眼看火堆熄灭，也慢慢收功，站了起来。\n"NOR,me);
		return 0;
	}

	switch(period) {
	case 3:
	case 9:
	case 15:
	case 21:
	case 27:
	case 33:
	case 39:
	case 45:
	case 51:
	case 57:
	case 63:
	case 69:
	case 75:
	case 81:
	case 87:
	case 93:
	case 99:
	case 115:
	case 145:
	case 175:
	case 205:
		if(neili > neili2){
		 	msg = random(2)?HIR"碧焰在一点点向$N的方向移动！\n"NOR:HIR"眼看$N使出全力，试图将那步步逼进的碧炎推挡回去！\n"NOR;
		 	message_vision(msg,target);
		}
		break;
	case 12:
	case 24:
	case 42:
	case 60:
	case 78:
	case 96:
	case 125:
	case 155:
	case 185:
		 if(neili > neili2){
		 	msg = random(2)?HIR"$N眼看"GRN"碧焰"HIR"$N使出全力，试图将那步步逼进的碧炎推挡回去！\n"NOR:HIR"$N眼看"GRN"碧焰"HIR"向自己移来，却不能开口停送真气，不然碧焰卷将过来，立时会被活活烧死！\n"NOR;
		 	message_vision(msg, target);
		 }
		 break;
	case 36:
	case 54:
	case 72:
	case 90:
	case 105:
	case 135:
	case 165:
	case 195:
		 if(me->query("jiali") > target->query("jiali")){
		 	msg = random(2)?HIR"这片"GRN"碧焰"HIR"在空中略一停滞，便缓缓向$N面前退去，$N大惊，又在舌尖\n"+
		"上一咬，一口"RED"鲜血"HIR"再向火焰喷去，火焰一盛，回了过来！\n"NOR:HIW"$N此时脸上已无半点血色，一口口"RED"鲜血"HIW"不住向火焰中吐去，要将火焰逼回！\n"NOR;
		 	message_vision(msg, me);
		 }
		 break;
	}

	period++;
	me->set_temp("huoqiang/period", period);
	return 1;
}

string perform_name(){ return HIB"火墙"NOR; }

int help(object me)
{
	write(HIB"\n抽髓掌之「火墙」："NOR"\n\n");
	write(@HELP
	要求：  当前内力 800 以上；
		最大内力 1000 以上；
		抽髓掌等级 220 以上；
		化功大法等级 220 以上；
		基本毒技等级 150 以上；
		激发掌法为抽髓掌；
		激发招架为抽髓掌；
		激发内功为化功大法；
		有火堆且手无兵器。

HELP
	);
	return 1;
}

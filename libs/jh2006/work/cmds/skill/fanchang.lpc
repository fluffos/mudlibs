// fanchang.c 梵唱

#include <ansi.h>

inherit F_SSERVER;

int main(string arg)
{
	object *ob;
	int i, skill, damage;
	object me=this_player();
	object target = offensive_target(me);
	int j;

	if( me->query("family/family_name")!="少林派" )
		   return notify_fail("你不是少林弟子，不能使用佛门梵唱绝学。\n");

	if( me->query("class")!="bonze" && !wizardp(me))
		   return notify_fail("你不是出家人，不能使用佛门梵唱绝学。\n");

	if (me->is_exert())
		return notify_fail("你刚使用了"+me->query_exert()+"。\n");
	if (me->is_perform())
		return notify_fail("你刚使用了"+me->query_perform()+"。\n");
	if(me->query_temp("fanchang"))
		   return notify_fail("金刚梵唱你刚用过不久，目前无法再次使用。\n");

	skill = me->query_skill("force");
	if( (int)me->query("neili") < skill * 3 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("max_neili") < 1500 )
		return notify_fail("你的内力修为不够。\n");

	if( (int)me->query("shen") < 10000 )
		return notify_fail("佛门梵唱需要高深的定力，你气色不正，难以施展！\n");

	if( environment(me)->query("no_fight"))
		return notify_fail("在这里不能攻击他人。\n");

	if( me->query_skill("buddhism", 1) < 100 )
		return notify_fail("你连禅宗心法还未完全领悟，何以施展佛门梵唱绝学？\n");

	if( me->query_skill("yijin-jing", 1) < 100 )
		return notify_fail("你连易筋经还未完全领悟，何以施展佛门梵唱绝学？\n");

	me->receive_damage("neili", skill*3/2);
	if (!me->is_fighting())
		me->add_busy(1);
	else
		me->add_busy(2);
	me->set_temp("fanchang",1);
	me->start_exert(8,"金刚梵唱");
	me->start_perform(8,"金刚梵唱");
	message_vision(YEL"\n$N深深地吸一口气，面露宝象，一声"BLINK+HIY"阿…弥…陀…佛…"YEL"梵音回旋环绕，所有人都为之一震！\n\n" NOR, me);

	if( intp(j = me->query_temp("yueyin")) 
	&& me->query_skill("yijin-jing", 1) > 200
	&& me->query_skill("buddhism", 1) > 200 ){
/*	      me->add_temp("apply/dexerity", j );
		me->add_temp("apply/dodge", j*2 );
		me->clear_condition("no_perform");
		me->delete_temp("yueyin");
		message_vision(HIW"$N心情於瞬息之间接连数变，恢复了明智！\n\n"NOR, me);
*/      }

	if( !target || !me->is_fighting() 
/*	 || ( target->query("family/family_name")!="丐帮"
	   && target->query("family/family_name")!="铁掌帮" 
	   && target->query("family/family_name")!="嵩山派")*/) {
		me->clear_condition("no_perform");
		me->clear_condition("no_exert");
		me->clear_condition("no_enable");
		me->delete_temp("no_enable");
		me->add_busy(1);
		message_vision(HIW"$N心情於瞬息之间接连数变，恢复了明智！\n\n"NOR, me);
	}
	ob = all_inventory(environment(me));
    
	for(i=0; i<sizeof(ob); i++) {
		if( !ob[i]->is_character() || !living(ob[i]) || ob[i]==me ) continue;
		if( skill < ob[i]->query_skill("force")/2 ) continue;
		if( me->query_skill("buddhism", 1) < ABS(ob[i]->query("shen"))/10000 
		   && me->query_skill("buddhism")<200 ) continue;
/*	      if( intp(j = ob[i]->query_temp("yueyin")) 
			&& me->query_skill("yijin-jing", 1) > 200
			&& me->query_skill("buddhism", 1) > 200 ){
			ob[i]->add_temp("apply/dexerity", j );
			ob[i]->add_temp("apply/dodge", j*2 );
			ob[i]->clear_condition("no_perform");
			ob[i]->delete_temp("yueyin");
			tell_object(ob[i], HIW"你心情於瞬息之间接连数变，恢复了明智！\n\n"NOR);
			continue;
			}
*/
		if( ob[i]->query_condition("yysan_poison")
			&& me->query_skill("yijin-jing", 1) > 200
			&& me->query_skill("buddhism", 1) > 200 
			&& ob[i]->query("shen") > 10000){
			ob[i]->clear_condition("yysan_poison");
			tell_object(ob[i], HIW"你猛觉这梵唱如同当头棒喝，一瞬间恢复了明智，不再药物所迷！\n\n"NOR);
			continue;
		}

		if( ob[i]->is_fighting() && !ob[i]->is_killing()){
			if(ob[i]->query("shen") > 0 ){
				ob[i]->remove_all_enemy();
				message_vision("\n$N受到$n感招，身行向后一跃，跳出战圈不打了。\n", ob[i], me); 
				continue;
			}
			else if(ob[i]->query("shen") > -10000 && me->query("combat_exp") > ob[i]->query("combat_exp")){
				ob[i]->remove_all_enemy();
				ob[i]->add("shen", skill*10);
				message_vision("\n$N全身一震，脸上邪气稍减，跳出战圈不打了。\n", ob[i], me); 
				continue;
			}
			else if( me->query("combat_exp") > ob[i]->query("combat_exp")*2){
				ob[i]->remove_all_enemy();
				message_vision("\n$N向后一跳，哈哈道：$n多心了，我们不过切磋切磋罢了。\n", ob[i], me); 
				continue;
			}
		}
		
		damage = skill * 2;
		if( random(skill) > ob[i]->query_skill("force")/2 && ob[i]->query("shen") < 0 ) {
			ob[i]->receive_damage("jing", damage/2, me);
			if(ob[i]->query("jing") < 10) ob[i]->set("jing", 10);
			ob[i]->receive_damage("neili", damage);
			if(ob[i]->query("neili") < 20) ob[i]->set("neili", 20);
			tell_object(ob[i], "你觉得心神一震，全身出了一身的冷汗！\n");
		}
		if( ob[i]->is_killing(me->query("id")) && random(skill) > ob[i]->query_skill("force")/2){
			if(random(2) == 1)
				ob[i]->apply_condition("no_perform", 2+random(2)+ob[i]->query_condition("no_perform"));
			else	ob[i]->apply_condition("no_exert", 2+ob[i]->query_condition("no_exert"));
			tell_object(ob[i], "你一惊，总觉得这梵唱有一股说不出的压迫感，使你感到很不舒服！\n");
			continue;
		}
		
		if( userp(ob[i]) && ob[i]->query("shen") < 0 && random(3) == 1) {
			message_vision("$N大喝一声：快闭嘴！惹得"+RANK_D->query_self_rude(ob[i])+"火起！\n", ob[i]); 
			COMBAT_D->do_attack(ob[i], me, ob[i]->query_temp("weapon"), 1);
		}
		
	}
	call_out("remove_effect",8,me);
	return 1;
}

void remove_effect(object me)
{
    if(!me) return;
    me->delete_temp("fanchang");
    tell_object(me,HIG"经过一段时间的调息，你又可以使用金刚梵唱了。\n"NOR);
    return;
}

int help(object me)
{
	write(HIY"\n易筋经之「金刚梵唱」："NOR"\n");
	write(@HELP
	金刚，坚利之意，历百劫千生，流转六道，而觉性不坏。即以金刚之坚，喻
	般若体；以金刚之利，喻般若用。梵唱乃是将一口真气以祥合之意唱出，内
	夹伏魔神功，能抗拒心魔，清心明志，使人悬崖勒马。
	
	要求：  易筋经等级 100 以上；
		易筋经等级 100 以上；
		正气 10000 以上；
		最大内力 1500 以上；
		内力为内功等级三倍以上。
HELP
	);
	return 1;
}

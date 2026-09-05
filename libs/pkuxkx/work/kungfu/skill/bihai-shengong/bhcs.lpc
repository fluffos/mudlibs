// bhcs.c 碧海潮声曲

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string tune(int section)
{
	string *song=
	({"尘寰外，碧海中，桃花之间桃花岛。",
    "秋风起，海波兴，几度潮来听玉箫。",
    "箫声起处落英飞，遽引心情向碧霄。",
    "桃花纷飞诉往事，风中烟柳叶飘摇。",
    "相逢本是瑶池间，盈盈花开芙蓉仙。",
    "芙蓉仙子织涟漪，油壁香车待鲜妍。",
    "蓬莱三山固所道，亦羡人间好情缘。",
    "从此千里不独行，侠义江湖同仗剑。",
    "未必女流让须眉，兰心蕙质更比肩。",
    "博闻强记天下事，九阴真经只等闲。",
    "九阴又何贵? 九阴竟使君命违。",
    "明日峰前再论剑，相伴华山知者谁？",
    "由来文字与武功，未如心意双高飞。",
    "十年不得慕红颜，敢笑唐皇与杨妃。",
    "梦时抚琴商转徵，丁香愁肠枉自悲。",
    "梧桐故事漫嗟呀，细把云烟裁作纱。",
    "一处杜鹃悄无语，一处萧萧半白发。",
    "七月七日梦天桥，闻道君思寄桃花？",
    "若无鸿雁奉鱼书，还叫无常带句话。",
    "我于浊世间，君在黄泉下，",
    "相忆相依两无期，相思何事纪年华! ",
    "碧海潮起天地惊，碧海潮落鬼神泣。",
    "碧海桃花之精英，凝于碧海潮生曲。",
    "此曲一出奋鹰扬，能使妖魔胆尽丧。",
    "弹指一挥风波起，太虚蹑后步天罡。",
    "再吟此曲凋日月，纷纷四海大浪张。",
    "世人未谙碧海意，尽道此潮最泱泱。",
    "不知潮起潮落间，碧海一曲为君飨。",
    "桃花飞殇哀往事，曲尽碧海尚彷徨。"});
	
	if ( section<0 || section>=sizeof(song) )
		return "";
	
	return HIC+song[section]+"\n"NOR;
}

void apply_slow_eff(object ob, int pflv)
{
	int i,c;
	ob->set_temp("no_perform",1);
	ob->set_temp("no_exert",1);
	i = (int)ob->query_temp("bihai_chaosheng_eff/slow");
	c = pflv*100 - i;
	if (c>0)
	{
		ob->add_temp("bihai_chaosheng_eff/slow", c);
		ob->add_temp("apply/attack_speed", -c);
	}
}

void remove_slow_eff(object ob)
{
	int i;
	ob->delete_temp("no_perform");
	ob->delete_temp("no_exert");
	if ( i = (int)ob->query_temp("bihai_chaosheng_eff/slow") )
		ob->add_temp("apply/attack_speed", i);
	ob->delete_temp("bihai_chaosheng_eff");
}

int exert(object me, object target)
{
        object tar, *ob, *exob;
        int pflv, i, skill, damage;
		string msg = "";
        
		pflv = me->query("purefamily/level");
		if (pflv>0 && me->query("purefamily/family_name") != "桃花岛") 
			pflv=0;
		
        if ( userp(me) && (pflv<3) )
          return notify_fail("以你现在的能力，无法通过这种方式演奏「碧海潮生曲」。\n");        
		if (pflv>5) pflv=5;
		
          if (me->query_skill_mapped("force") != "bihai-shengong"
			|| me->query_skill("force",1)/2 + me->query_skill("bihai-shengong",1) < 150 )
                return notify_fail("你瞎吹了一通，自己倒搞得头晕脑胀。\n");
		if (me->query_skill("music",1)<100 )
          return notify_fail("你的音律水平还没到家，无法吹奏「碧海潮生曲」。\n");
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的内力不够。\n");

        if( environment(me)->query("no_fight") )//防止玩家利用ask huang about bhcs来达到NK的目的---vast注
                return notify_fail("你怎么好意思在如此清静之处吹～箫～呢？\n");
        if (!objectp(me->query_temp("weapon"))
        || (string)me->query_temp("weapon")->query("music") != "shaw")
          return notify_fail("你必须使用箫才能吹奏「碧海潮生曲」。\n");
		  
		if (userp(me) && time()<(int)me->query_temp("next_bihai_chaosheng"))
			return notify_fail("你才刚吹奏过「碧海潮生曲」，还要休息一会儿才能再次施展。\n");
		
        skill = me->query_skill("force",1)+me->query_skill("music",1);
        me->add("neili", -100);
        me->start_busy(1 + random(4));
		tell_object(me, "你提起玉箫，开始演奏「碧海潮生曲」。\n");
        message_vision(HIC "突然之间，半空中如鸣琴、如击玉，接着悠悠扬扬，飘下一阵清亮柔和的洞箫声来。\n" NOR, me);
		if ( userp(me) ) // 玩家纯门派版
		{
			ob = me->query_enemy();
			if (sizeof(ob)<=0)
			{
				tell_object(me, "你吹奏了一会儿，忽然发现没有听众，只好悻悻然地停了下来。\n");
				me->set_temp("next_bihai_chaosheng", time() + 10-pflv);
				return 1;
			}
			if ( me->query("env/bihai_chaosheng") == "chaos" )
			{
				exob = ({ });
				for(i=0; i<sizeof(ob); i++) {
					if (userp(ob[i])) 
						exob += ({ ob[i] });
				}
				ob -= exob;
				exob = ({ });
				exob += ob;
				if (sizeof(ob)<=0) {
					tell_object(me, "你吹奏了一会儿，忽然发现没有听众，只好悻悻然地停了下来。\n");
					me->set_temp("next_bihai_chaosheng", time() + 10-pflv);
					return 1;
				}
				if (sizeof(ob)==1) exob += ({ me });
				for(i=0; i<sizeof(ob); i++) {
					if (ob[i]->query_temp("bihai_chaosheng_eff/chaos")) continue;
					if( (skill/2 + random(skill/2))/(10-pflv/2) < random((int)ob[i]->query_con() * 2) ) 
						{
							message_vision( HIY + "$n" + HIY"抱元守一，静心凝志，似乎没有受到什么影响。\n" NOR, me, ob[i]);
							continue;
						}
					ob[i]->set_temp("no_perform",1);
					ob[i]->set_temp("no_exert",1);
					ob[i]->set_temp("bihai_chaosheng_eff/chaos", 1);
					if (ob[i]->is_killing(me->query("id")))
						ob[i]->set_temp("bihai_chaosheng_eff/kill", 1);
					tar = exob[random(sizeof(exob))];
					while ( tar == ob[i] )
						tar = exob[random(sizeof(exob))];
					message_vision( MAG + "$n" + MAG "像是喝醉了酒，摇摇晃晃、迷迷糊糊，胡乱发起了攻击。\n" NOR, me, ob[i]);
					COMBAT_D->do_attack(ob[i], tar, ob[i]->query_temp("weapon"), TYPE_REGULAR, 0);
					ob[i]->set_temp("focus_target", tar);
					ob[i]->kill_ob(tar);
				}				
				call_out("end_chaos", 10 + pflv * 2, me, ob);
				me->set_temp("next_bihai_chaosheng", time() + 15 + pflv*2);
			}
			else
			{
				me->start_busy(200);
				damage = (skill + me->query_skill("bihai-shengong",1))/3;		
				message_vision( tune(0), me );
				for(i=0; i<sizeof(ob); i++) {
					if (ob[i]->query_temp("bihai_chaosheng_eff/slow")) continue;
					if( (skill/2 + random(skill/2))/(10-pflv/2) < random((int)ob[i]->query_con() * 2) ) 
						{
							message_vision( HIY + "$n" + HIY"抱元守一，静心凝志，似乎没有受到什么影响。\n" NOR, me, ob[i]);
							continue;
						}
					apply_slow_eff(ob[i], pflv);
					message_vision( HIM + "$n" + HIM "面红耳赤，百脉贲张，忍不住随着箫声手舞足蹈起来。\n" NOR, me, ob[i]);
					ob[i]->receive_damage("qi", damage+random(damage/4), me);
					ob[i]->receive_damage("jing", damage/2+random(damage/6), me);
					COMBAT_D->report_status(ob[i]);
				}
				call_out("continue_damage", 1, me, ob, damage, 1, pflv);
				me->set_temp("next_bihai_chaosheng", time() + 10 - pflv);
			}
		}
		else // 原有的保留给 NPC 使用
		{  
			ob = all_inventory(environment(me));
			for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                  if(!me->visible(ob[i])) continue;
                 if( (skill/2 + random(skill/2))/8 < random((int)ob[i]->query_con() * 2)||random(ob[i]->query("combat_exp"))/3>random(me->query("combat_exp")) ) continue;
                damage = skill+me->query_skill("bihai-shengong",1);
                        ob[i]->receive_wound("qi", damage/3, me);
                        ob[i]->receive_damage("qi", damage, me);
                        ob[i]->receive_damage("jing", damage/2, me);
                        ob[i]->receive_wound("jing", damage/6, me);
                        ob[i]->start_busy(random(me->query_skill("music",1)/80));
                        tell_object(ob[i], "你心头一荡，脸上不自禁的露出微笑，只感全身热血沸腾，就只想手舞足蹈的乱动一番，方才舒服。\n");
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me->query("id")) ) ob[i]->kill_ob(me);
        }

			if(target && target->query_temp("zyhb/bhcs0"))
			{
			//target->set_temp("zyhb/bhcs", 1);//此mark在黄药师身上给出，修正新人直接上去解互搏的情况。Zine
				target->delete_temp("zyhb/bhcs0");
				tell_object(target, CYN"这套曲子模拟大海浩淼，万里无波，远处潮水缓缓推近，渐近渐快，其后洪涛汹涌，白浪
连山，而潮水中鱼跃鲸浮，海面上风啸鸥飞，再加上水妖海怪，群魔弄潮，忽而冰山飘至
，忽而热海如沸，极尽变幻之能事，而潮退后水平如镜，海底却又是暗流湍急，于无声处
隐伏凶险，更令聆曲者不知不觉而入伏，尤为防不胜防。其声由“宫”音起，转而为“角、
羽”之音，最后以“徵”音结尾，你仔细聆听心中暗暗记住了音律的变化。\n\n"NOR);
			}
		}
        return 1;
}

void continue_damage(object me, object *ob, int damage, int step, int pflv)
{
	object *ex = ({ });
	int i;
	string song;
	if (!objectp(me)) return;
	if ( sizeof(ob)<=0 )
	{
		tell_object(me, HIW"你停止了演奏「碧海潮生曲」。\n"NOR);
		me->start_busy(0);
		return;
	}
	if (!objectp(me->query_temp("weapon"))
        || (string)me->query_temp("weapon")->query("music") != "shaw")
		{
			tell_object(me, HIW"你停止了演奏「碧海潮生曲」。\n"NOR);
			for(i=0; i<sizeof(ob); i++)
			{
				if (objectp(ob[i])) remove_slow_eff(ob[i]);
			}
			me->start_busy(0);
			return;
		}
	song = tune(step);
	if (!me->is_busy() || me->query("neili")<400
		|| step > (pflv*5) || strwidth(song)<=0  ) 
		{
		message_vision(HIW"$N一曲余音袅袅，散入四下里，忽地曲终音歇。\n"NOR, me);
		for(i=0; i<sizeof(ob); i++)
		{
			if (objectp(ob[i])) remove_slow_eff(ob[i]);
		}
		if (me->is_busy()) me->start_busy(0);
		return;
	}
	message_vision( song, me );				
	for(i=0; i<sizeof(ob); i++) {
		if (!objectp(ob[i]) || !ob[i]->query_temp("bihai_chaosheng_eff/slow"))
		{
			ex += ({ ob[i] });
			continue;
		}
		if (!living(ob[i])) {
			remove_slow_eff(ob[i]);
			ex += ({ ob[i] });
			continue;
		}
		if (environment(ob[i]) != environment(me)) {
			remove_slow_eff(ob[i]);
			ex += ({ ob[i] });
			continue;
		}
		apply_slow_eff(ob[i], pflv);
		ob[i]->receive_damage("qi", damage+random(damage/4), me);
		ob[i]->receive_damage("jing", damage/2+random(damage/6), me);
		COMBAT_D->report_status(ob[i]);
		if (!ob[i]->is_fighting(me))
			ob[i]->fight_ob(me);
	}
	ob -= ex;
	me->add("neili", -50);
	call_out("continue_damage", 1, me, ob, damage, step+1, pflv);
}

void end_chaos(object me, object *ob)
{
	for(int i=0; i<sizeof(ob); i++) {
		if (!objectp(ob[i])) continue;
		if (!ob[i]->query_temp("bihai_chaosheng_eff/chaos")) continue;
		ob[i]->delete_temp("no_perform");
		ob[i]->delete_temp("no_exert");
		ob[i]->remove_all_killer();
		ob[i]->delete_temp("focus_target");
		message("vision", HIW + ob[i]->query("name") + HIW "清醒了过来，停下手一脸茫然地望着四周，似乎还没弄明白发生了什么事。\n"NOR, 
			environment(me), ({ob[i]}) );
		tell_object(ob[i], HIW"你用力拍了拍脑袋，清醒了过来，停下手一脸茫然地望着四周。\n"NOR);
		if (!living(ob[i]) || !ob[i]->is_fighting())
		{
			ob[i]->delete_temp("bihai_chaosheng_eff");
			continue;
		}
		if (objectp(me) && ob[i]->query_temp("bihai_chaosheng_eff/kill"))
			ob[i]->kill_ob(me);
		ob[i]->delete_temp("bihai_chaosheng_eff");
	}
}


//modify by gudu
/*
这套曲子模拟大海浩淼，万里无波，远处潮水缓缓推近，渐近渐快，其后洪涛汹涌，白浪
连山，而潮水中鱼跃鲸浮，海面上风啸鸥飞，再加上水妖海怪，群魔弄潮，忽而冰山飘至
，忽而热海如沸，极尽变幻之能事，而潮退后水平如镜，海底却又是暗流湍急，于无声处
隐伏凶险，更令聆曲者不知不觉而入伏，尤为防不胜防。
*/

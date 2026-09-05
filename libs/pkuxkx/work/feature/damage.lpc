// damage.c
// Modified by iszt@pkuxkx, 2007-01-17
// added hungry/thirsty and damage type: jingli
// Modified by iszt@pkuxkx, 2007-03-12, changed hungry/thirsty msg to write()
// Modified by iszt@pkuxkx, 2007-03-20, we don't allow wizards to be unconcious
// Modified by iszt@pkuxkx, 2007-03-21, changed killer from string to mixed
// 对heal_up函数中关于恢复治疗部分采用/feature/attribute.c里面的标准恢复治疗函数。
// by seagate@pkuxkx 2012/03/22
// by zine 2012/7/26 增加特殊房间处理程序中断die()
// 加入全真先天神罡效果 by yhzzyahoo @2015.4.21

#define DIE_NOTIFY_NO_CONTINUE 486 //在有listen_to_die()的room里，die_notify()程序return 486将中断die()，不制造尸体，不清楚状态，不送白无常。应对某些特殊需求，比如不死的比武,pk等等

#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>
#include <condition.h>

void remove_sg_effect(object me);

int ghost = 0;
int medical;
string use_skill;

//死亡事件的监听对象
nosave object* dielisteners= ({});

int is_ghost() { return ghost; }


//挽救新手，增加mud粘性
void save_newbie(string type,mixed who)
{
	object me;
    string enemy;
    string* saver_desc = ({"身穿白衣","消瘦清冷","飘逸俊朗","壮如高塔","面如重枣","面如冠玉","短小精悍","白发苍苍","蓑衣斗笠"});
    if(objectp(who)) enemy = who->name();
    else if(stringp(who)) enemy = who;
    else return;

	me = this_object();
	
    if(!userp(me)) return;

    if(!me->is_fighting() && !wizardp(me)) return;

    if((query(type) < query("max_"+type)/80 || query("eff_"+type) < query("max_"+type)/80) && query("mud_age") < 86400 && random(query("kar")) >= 15 )
    {
        tell_object(me,HIY"突然你听到一声暴喝：不要欺人太甚！\n"NOR);
        tell_object(me,HIB"只见一个"+saver_desc[random(sizeof(saver_desc))]+"的人从旁闪出，一掌击退"+enemy+"\n"NOR);
        tell_object(me,HIG"他盘膝坐下，一只手掌抵在你胸前给你运气疗伤，另一只手上下翻飞，也不看"+enemy+"，就把"+enemy+"的攻势全部化于无形。\n"NOR);
        tell_object(me,HIR"你吐出一口淤血，伤势已然痊愈，他又弹指将一粒药丸送入你口中。你觉得浑身说不出的舒畅。\n"NOR);
        tell_object(me,HIY"他也不言语，电一般的闪身离去，你才发现自己连他姓甚名谁都不知晓。也未曾道谢。\n"NOR);
        me->fullme();
        me->start_busy(0);
    }
}

int isvalid_death_reason()
{
    int t1, t2, t3;
    t1 = query_temp("last_damage_time");
    t2 = query_temp("death_msg_time");
    t3 = (t1>=t2)?t1:t2;
    if (!t3 || (time()-t3 > 15)) return 0; // 暂设15秒之后无关联
    if (t3 == t1) return 1; // "last_damage_from"
    else return 2; // "death_msg"
}

mixed get_damage_origin_object()
{
    int result;
    object who;

    result=isvalid_death_reason();
    if (result==0) return 0;
    if (result==1) who=query_temp("last_damage_from");
    if (result==2 && query_temp("death_cond_id") && strsrch(query_temp("death_msg"), cond_def[query_temp("death_cond_id")]["name"])!=-1)
    {
        who=query_temp("death_cond_origin/"+query_temp("death_cond_id"));
    }

    if (objectp(who) && objectp(who->query_temp("do_attack_from")))
    {
        return who->query_temp("do_attack_from");
    }
    else if (objectp(who) && objectp(who->query("master_user/user")))
    {
        return who->query("master_user/user");
    }
    else if (objectp(who))
    {
        return who;
    }
    else
    {
        return 0;
    }
}

varargs int receive_damage(string type, int damage, mixed who)
{
    int dur;
	int val,tmp;
	object me = this_object();

	if( damage < 0 )
		error("F_DAMAGE: 伤害值为负值。\n");
	if( type!="jing" && type!="qi" && type!="jingli")
		error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi, jingli 其中之一 )。\n");

    if(query_temp("tianmo-jieti"))
    {
        dur = me->query_skill("tianmo-jieti",1) * 2;
        if(dur < 5) dur = 5;
        if(dur > 60) dur = 60;

        if(time() - query_temp("tianmo-jieti") < dur)
        {
            tell_room(environment(me),query("name")+"发动了天魔解体大法，刀枪不入，百毒不侵！\n");
            return 0;
        }
        else
        {
            delete_temp("tianmo-jieti");
            tell_object(me,"你的天魔解体大法已经收功了。\n");
        }

    }
	if (query_temp("xiantian_sg"))
	{
            tell_room(environment(me),query("name")+"先天神罡护体，镇定自若，游刃有余！\n");
            return 0;
	}
	if (living(me)&&type=="qi"&&query("level")>=101&&query("born/Gangspirit")&&(query("env/gangqi")<=0||(query("env/gangqi")>0&&query("qi")<query("max_qi")/100*query("env/gangqi"))))
	{
		tell_room(environment(me),WHT+query("name")+WHT+"的先天罡气涌出，抵挡了");
		if (damage>=query("born/Gangspirit"))
		{
			damage-=query("born/Gangspirit");
			set("born/Gangspirit",0);
			tell_room(environment(me),"部分伤害！\n"+NOR);
		}
		else
		{
			add("born/Gangspirit",-damage);
			damage=0;
			tell_room(environment(me),"全部伤害！\n"+NOR);
		}
		if (wizardp(me))
		tell_object(me,"剩余罡气"+query("born/Gangspirit")+"\n");
	}
	val = (int)query(type) - damage;
    if (who)
    {
        if (who == query_temp("combat/damage_from"))
        {
            if (query_temp("combat/"+type+"_damage")) add_temp("combat/"+type+"_damage", damage);
            else set_temp("combat/"+type+"_damage", damage );
        }
        else
        {
            set_temp("combat/damage_from", who );
            set_temp("combat/"+type+"_damage", damage );
        }
    }

    if( objectp(who) )
    {
        set_temp("last_damage_from", who);
        set_temp("last_damage_time", time());
    }

    if( stringp(who) )
    {
        delete_temp("last_damage_time");
        set_temp("death_msg", who);
        set_temp("death_msg_time", time());
    }

	if( val >= 0 )
		set(type, val);
	else
    {
        set( type, -1 );
    }

	set_heart_beat(1);

	// me->damage_received(who,type);

    save_newbie(type,who);

	return damage;
}

varargs int receive_wound(string type, int damage, mixed who)
{
	int val,tmp;
    int dur;
	object me = this_object();

	if( damage < 0 ) error("F_DAMAGE: 伤害值为负值。\n");
	if( type!="jing" && type!="qi" && type!="jingli")
		error("F_DAMAGE: 伤害种类错误( 只能是 jing, qi, jingli 其中之一 )。\n");
    if(query_temp("tianmo-jieti"))
    {
        dur = me->query_skill("tianmo-jieti",1) * 2;
        if(dur < 5) dur = 5;
        if(dur > 60) dur = 60;

        if(time() - query_temp("tianmo-jieti") < dur)
        {
            tell_room(environment(me),query("name")+"发动了天魔解体大法，刀枪不入，百毒不侵！\n");
            return 0;
        }
        else
        {
            delete_temp("tianmo-jieti");
            tell_object(me,"你的天魔解体大法已经收功了。\n");
        }
    }
	if (query_temp("xiantian_sg"))
	{
            tell_room(environment(me),query("name")+"先天神罡护体，镇定自若，游刃有余！\n");
            return 0;
	}

	if (living(me)&&type=="qi"&&query("level")>=101&&query("born/Gangspirit")&&(query("env/gangqi")<=0||(query("env/gangqi")>0&&query("qi")<query("max_qi")/100*query("env/gangqi"))))
	{
		tell_room(environment(me),WHT+query("name")+WHT+"的先天罡气涌出，抵挡了");
		if (damage>=query("born/Gangspirit"))
		{
			damage-=query("born/Gangspirit");
			set("born/Gangspirit",0);
			tell_room(environment(me),"部分伤害！\n"+NOR);
		}
		else
		{
			add("born/Gangspirit",-damage);
			damage=0;
			tell_room(environment(me),"全部伤害！\n"+NOR);
		}
		if (wizardp(me))
		tell_object(me,"剩余罡气"+query("born/Gangspirit")+"\n");
	}
	val = (int)query("eff_" + type) - damage;
    if (who)
    {
        if (who == query_temp("combat/damage_from"))
        {
            if (query_temp("combat/"+type+"_wound")) add_temp("combat/"+type+"_wound", damage);
            else set_temp("combat/"+type+"_wound", damage);
        }
        else
        {
            set_temp("combat/damage_from", who);
            set_temp("combat/"+type+"_wound", damage);
        }
    }

    if( objectp(who) )
    {
        set_temp("last_damage_from", who);
        set_temp("last_damage_time", time());
    }

    if( stringp(who) )
    {
        delete_temp("last_damage_time");
        set_temp("death_msg", who);
        set_temp("death_msg_time", time());
    }

	if( val >= 0 )
		set("eff_" + type, val);
	else
	{
		set( "eff_" + type, -1 );
		val = -1;
	}

	if( (int)query(type) > val )
		set(type, val);

	set_heart_beat(1);

    // me->wound_received(who,type);

    save_newbie(type,who);

	return damage;
}

int receive_heal(string type, int heal)
{
	int val;

	if( heal < 0 )
		error("F_DAMAGE: 恢复值为负值。\n");
	if( type!="jing" && type!="qi" && type!="jingli")
		error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi, jingli 其中之一 )。\n");

	val = (int)query(type) + heal;

	if( val > (int)query("eff_" + type) )
		set(type, (int)query("eff_" + type));
	else
		set( type, val );

    // me->heal_received();
	return heal;
}

int receive_curing(string type, int heal)
{
	int max, val;

	if( heal < 0 )
		error("F_DAMAGE: 恢复值为负值。\n");
	if( type!="jing" && type!="qi" && type!="jingli")
		error("F_DAMAGE: 恢复种类错误( 只能是 jing, qi, jingli 其中之一 )。\n");

	val = (int)query("eff_" + type);
	max = (int)query("max_" + type);

	if( val + heal > max )
	{
		set("eff_" + type, max);
		// me->curing_received();
		return max - val;
	} else {
		set( "eff_" + type, val + heal);
		// me->curing_received();
		return heal;
	}
}

void unconcious()
{
	object defeater,room,*inv;
	int i;
	object where;
    object suicong;
	object me = this_object();
	where=environment(me);
	if (environment() && environment()->query("alternative_die")) {
	  environment()->alternative_die(me);
	  return;
	}
	// 让定义了prevent_unconcious()并返回非零值的房间，可以阻止晕迷
	if (environment(me) && environment(me)->prevent_unconcious(me))
		return;

	if( !living(me) ) return;

	if( wizardp(me) && query("env/immortal") ) return;
//	if( wizardp(me) )
	//added by iszt@pkuxkx, 2007-03-20, we don't allow wizards to be unconcious
	{
//                message_vision(HIC"突然天空中一道闪电，正好劈在垂死的$N头上！\n"NOR, me)

//                me->die();
//		return;
	}


	if( objectp(defeater = get_damage_origin_object()) )
	COMBAT_D->winner_reward(defeater, me);

	me->remove_all_enemy();

    if (!userp(me) && COMBAT_D->check_victim_value(me))
    {
        me->set_temp("is_rich",1);
    }

    if (me->query("eff_qi")>=0 && me->query("eff_jing")>=0)
    {
        if (userp(me))
        {
            delete_temp("last_damage_time");
            delete_temp("death_msg_time");
        }
    }

	message("system", HIR "\n你的眼前一黑，接著什么也不知道了....\n\n" NOR,
	  me);

	set("jing", 0);
	set("qi", 0);


	me->disable_player("<昏迷不醒>");

	if( userp(me) &&
		  time() - me->query("killer/time") < 15*60)
	{
        receive_damage("qi", 0, "昏迷不醒时被蒙面人刺中心脏");
        message_vision( HIR "一个蒙面人向$N走来，趁着$P昏迷不醒，对着$P的心脏刺出一刀。\n\n" NOR, me);
		me->die();
		return;
	}

    if(objectp(suicong = query("suicongdizi/npc")))
    {
        if(environment(suicong) == where)
        {
            suicong->special_function(me,"firstaid","");
        }
    }

	COMBAT_D->announce(me, "unconcious");
	call_out("revive", random(100 - query("con")) + 30);
}

varargs void revive(int quiet)
{
	object room,obj,*inv;
	object tempenv;
	int sign=0;
	int i;
	object me = this_object();
	
	remove_call_out("revive");
	// here is for put in horse bug
	// debug by akuma
	tempenv=environment();

	while(sign==0) {
        if (tempenv && environment(tempenv))
        {
            tempenv=environment(tempenv);
        }
        else
        {
            sign=1;

        }
	}

	me->move(tempenv);

	me->enable_player();

	if( !quiet )
	{
	if (userp(me))
	{
		COMBAT_D->announce(me, "revive");
		me -> set_temp("block_msg/all", 0);
                me ->start_busy(1);
//add by whuan，醒来之后busy 1，然后解除busy
		message("system", HIY "\n慢慢地你终于又有了知觉....\n\n" NOR,me);
	}
	else
		set_temp("block_msg/all", 0);
	}

	me->got_revived();
}

void die()
{
    int dur;
	int sk_level,dur_time;
	int panshi1=0;
	int chushi1=0;
	int i_temp,i_temp0,i_temp1,i_temp2,i_temp3;
	object rubbish;
	object* armors;

	object corpse, room, obj, *inv;
	mixed killer; //iszt@pkuxkx, 2007-03-20, killer might be a string
	object qiankunniuzhuan;
	object cloth, me;
	//object thekiller;
	int i;
	object rum_ob = load_object("/d/huashan/npc/referee");
	me = this_object();

	if (environment(me) && environment(me)->query("alternative_die")) {
	  environment(me)->alternative_die(me);
	}

	// 添加具备prevent_die()函数且返回值为1的特殊房间可以阻止丧命的功能。by lordstar 2017/9/19
	if (environment(me) && environment(me)->prevent_die(me))
		return;

	//绝对不死的房间，连鬼门关都不进。no_die只是没损失。这个标志目前用在鬼门关
	if (environment(me) && environment(me)->query("abs_no_die")) {
		return;
	}

	if( !living(me) ) revive(1);
    set_temp("block_msg/all", 0);

	//只有试剑山庄用no_death参数，其他地方一定不要用！
	if (environment(me)->query("no_death") && userp(me))
	{
		killer = get_damage_origin_object();

                if ( killer && objectp(killer) )
			CHANNEL_D->do_channel(rum_ob, "rumor",
				sprintf("%s被" + killer->name() + "干掉了。", me->name(1)));
		else
			CHANNEL_D->do_channel(rum_ob, "rumor",
				sprintf("%s被干掉了。", me->name(1)));
			COMBAT_D->announce(me, "dead");
		if( me->query("sjsz/entrance")=="east" )
			me->move("/d/bwdh/sjsz/east_xiangfang");
		else
			me->move("/d/bwdh/sjsz/west_xiangfang");
        me->fullme();
		remove_call_out("revive");
		return;
	}

	if (me->query("id") == "pal" && me->is_character() ) return;
	//
	if( wizardp(me) && query("env/immortal") ) return;

    qiankunniuzhuan = present("qiankun niuzhuan",me);
    if(objectp(qiankunniuzhuan) && qiankunniuzhuan->query("true") == 1)
    {
        message_vision("$N眼看垂死之际，吞下一颗乾坤扭转丹，硬是从鬼门关回来了。\n",me);
        me->fullme();
        destruct(qiankunniuzhuan);
        return;
    }

    if(me->query_skill("tianmo-jieti",1) > 0 && me->query("env/tianmo-jieti"))
    {
        message_vision(HIR"$N全身经脉尽断，鲜血如注，原来是发动了天魔解体大法！\n"NOR,me);
        set_temp("tianmo-jieti",time());
        if(me->query_skill("tianmo-jieti",1) > 1)
        {
            me->set_skill("tianmo-jieti",me->query_skill("tianmo-jieti",1) - 1);
        }
        else
        {
            me->delete_skill("tianmo-jieti");
        }
        dur = me->query_skill("tianmo-jieti",1) * 2;
        if(dur < 5) dur = 5;
        if(dur > 60) dur = 60;

        tell_object(me,"你发动了天魔解体大法，"+chinese_number(dur)+"秒内不受任何伤害。\n");
        if(me->is_busy())
        {
            tell_object(me,"你发动了天魔解体大法，你的busy状态解除了。\n");
            me->start_busy(0);
        }
        set("jing",1);
        set("qi",1);
        set("eff_jing",1);
        set("eff_qi",1);
        return;
    }
    if((me->query("family/family_name")=="全真派") && (me->query("safari_skill/qz2")) && (me->query("env/qz_shengang")))
	{

		if ((time() - me->query("xiantian_sg_time")) > 7200)//cd 2小时
			{

			sk_level=(int)me->query_skill("xiantian-gong", 1);
			if ((me->query("chushi/done")) || (me->query("betrayer")))
			{
				i_temp = 1001;
				dur_time = 3;
				chushi1 = 1;
				panshi1 = me->query("betrayer");
			}
			else
			{
				i_temp = 801;
				dur_time = 10;
			}
			i_temp0=2;

			if (sk_level > i_temp)
			{
				message_vision(HIG"$N在垂死之际，突然面色由白转红，发髻飘散，丹田中一股先天真气猛然爆发，内家真气充斥四肢百骸，正是先天功最高境界之先天神罡！！\n"NOR,me);
				set_temp("xiantian_sg",1);
				me->set("xiantian_sg_time",time());
				//计算掉级几率
				 if (me->query_skill_mapped("force") == "xiantian-gong")
				 {
					 i_temp0=1;
				 }
				if ((chushi1) || (panshi1))
				{
					me->set_skill("xiantian-gong",me->query_skill("xiantian-gong",1) - i_temp0);
					tell_object(me,HIR"先天神罡真力凶猛霸道，一时间对你的经脉造成了巨大损害，你的先天功等级降低了。\n"NOR);

				}
				else
				{
					if (!(random(4-i_temp0)))
					{
					me->set_skill("xiantian-gong",me->query_skill("xiantian-gong",1) - 1);
					tell_object(me,HIR"先天神罡真力凶猛霸道，一时间对你的经脉造成了巨大损害，你的先天功等级降低了。\n"NOR);
					}
				}
				i_temp0 = sk_level-i_temp;
				i_temp0 = (int)i_temp0/100;
				i_temp1 = i_temp0*i_temp0*i_temp0+1;
				i_temp0 = me->query_skill_limit();//最高支持等级
				panshi1 = panshi1 * 2;
				panshi1 = panshi1 * panshi1 + 1;
				chushi1 = chushi1 + 1;
				i_temp2 = me->query("max_jing");
				i_temp3 = me->query("max_qi");
				if (random((int)(i_temp1+10*(me->query("level"))))> random((int)(i_temp0*panshi1*chushi1)))
					{
					tell_object(me,"先天神罡遍布你的全身，你在"+chinese_number(dur_time)+"秒内不受任何伤害。\n");
					if(me->is_busy())
					{
						tell_object(me,"你发动了先天神罡，你的busy状态解除了。\n");
						me->start_busy(0);
					}
					set("jing",i_temp2);
					set("qi",i_temp3);
					set("eff_jing",i_temp2);
					set("eff_qi",i_temp3);
				    me->set_temp("active_force_buffer/xiantian-gong.sg/name", "先天神罡");   //buff名称
					me->set_temp("active_force_buffer/xiantian-gong.sg/last_time", time() + dur_time );   //持续时间
					}
				else
				{
					set("jing",(int)(i_temp2/3));
					set("qi",(int)(i_temp3/3));
					set("eff_jing",(int)(i_temp2/3));
					set("eff_qi",(int)(i_temp3/3));
				}
			call_out("remove_sg_effect",dur_time,me);
			return;
			}
		}
	}

	//call the die listener objects
	//added by jason
	//任何想要拦截某些对象死亡信息者可以通过注册这个回调来获得死亡前的通知。
	//在回调里可以做任何事情，但不能改变死亡的结果。
	//用例：剿匪任务里，当玩家在任务房间内死亡时，他的功勋减半
	//这样可以避免在本函数里不断的增加新东西。
	for(i =0;i < sizeof(dielisteners);i++)
	{
	    if(objectp(dielisteners[i]))
	    {
			if(dielisteners[i]->die_notify(me)==DIE_NOTIFY_NO_CONTINUE)
			return;
	    }
	}
	// Clear all the conditions by death.
	me->clear_condition();
	// 放到reward中去判断和处理 me->delete("shaqi");
	me->delete_temp("jingji_exp");
	me->delete_temp("last_exp");
	me->delete_temp("jingji_potential");
	me->delete_temp("xiangbo_level");
//	me->delete_temp("last_damage_from");
	if( me->query("max_neili")<0 ) me->set("max_neili",0);
// start whuan：此处不加判断 2008-12-30
//	if (me->query("max_neili") > (int)me->query_skill("force") * 10)
//			me->set("max_neili",(int)me->query_skill("force") * 10);
// end
	if( me->query("max_jingli")<0 ) me->set("max_jingli",0);
	if( me->query("eff_qi")<0 ) me->set("eff_qi",0);
	if( me->query("eff_jing")<0 ) me->set("eff_jing",0);
	COMBAT_D->announce(me, "dead");
//身上的固定装备消失by whuan===--start===
	inv = all_inventory(me);
	for(int k=0; k<sizeof(inv); k++)
	{
		if( inv[k]->query("owner_id") == getuid(me) )
		{
        tell_object(me, HIB+"你看到" + inv[k]->query("name") +
                        HIB + "竟然化作微尘，慢慢消失在风中．．．\n"+NOR);
            destruct( inv[k] );
         }
    }
//身上的固定装备消失by whuan===---end----

    if(isvalid_death_reason()==0) killer=0;
    if(isvalid_death_reason()==1)
    {
        if(objectp(killer=get_damage_origin_object()))
        {
            set_temp("my_killer", killer->query("id"));
        }
    }
    if(isvalid_death_reason()==2)
    {
        if(objectp(killer=get_damage_origin_object()))
        {
            set_temp("my_killer", killer->query("id"));
        }
        else killer=query_temp("death_msg");
    }
    if(objectp(killer) && userp(killer) && userp(me) && objectp(environment()) && !environment()->query("no_die")) //pk
    {
        killer->start_busy(15);
        if (isvalid_death_reason()==2)
        {
            shout(HIR""+me->name(1)+"在"+environment()->query("short")+"被"+killer->name()+"害死了"+"\n"NOR);
        }
        else
        {
            shout(HIR""+killer->name()+"在"+environment()->query("short")+"杀死了"+me->name(1)+"\n"NOR);
        }
    }
	COMBAT_D->killer_reward(killer, me);

	//销毁任务npc身上的武器的装备 ，否则系统最后垃圾太多，卡死
	if(query("uni_target"))
	{
		rubbish = me->query_temp("weapon");
		if(objectp(rubbish)) destruct(rubbish);
		rubbish = me->query_temp("secondary_weapon");
		if(objectp(rubbish)) destruct(rubbish);
		if(me->query_temp("armor"))
		{
			armors = values(me->query_temp("armor"));
			for(i=0;i<sizeof(armors);i++)
			{
				if(objectp(armors[i])) destruct(armors[i]);
			}
		}

	}


	if( objectp(corpse = CHAR_D->make_corpse(me, killer)) )
		corpse->move(environment());

	me->remove_all_killer();
	all_inventory(environment())->remove_killer(me);

	me->dismiss_team();

	if( userp(me) )
	{
		if (me->is_busy())
			me->interrupt_me();
		//icer added for maybe cause bug
		//	set("jing", 1);	set("eff_jing", 1);
		//	set("qi", 1);	set("eff_qi", 1);
		if(!query("newbie_village/done") && objectp(environment()) && strsrch(file_name(environment()),"/d/newbie_lxsz",1) == 0)
		{
			me->move("/d/newbie_lxsz/weiminggu");
			tell_object(me,"你感到一阵恍惚，发现自己又来到了未明谷。那只蝴蝶还在你面前飞舞。\n");
			cloth = new("/clone/misc/cloth");
			cloth->move(me);
			cloth->wear();

		}
		else
		{
			ghost = 1;
			if ( wizardp(me) )
				ghost = 0;
			me->move(DEATH_ROOM);
			// ghost标识应该统一在reward中处理  me->add("ghost",1);
			DEATH_ROOM->start_death(me);
			me->save();
		}

	}
	else
		destruct(me);
}

void reincarnate()
{
	ghost = 0;
	set("eff_jing", query("max_jing"));
	set("eff_qi", query("max_qi"));
}

/*
int max_food_capacity() { return query_weight() / 200; }

int max_water_capacity() { return query_weight() / 200; }
*/
int max_food_capacity()
{
        int final;
        final=(int)query("str")*10+100;
        if (final < 100 ){
                final=100;
        }
        if(query("special_skill/greedy")&&query("age")>=18)
          final = final * 3;
        return final;
}

int max_water_capacity()
{
        int final;
        final=(int)query("str")*10+100;
        if (final < 100 ){
                final=100;
        }
        if(query("special_skill/greedy")&&query("age")>=18)
          final = final * 3;
        return final;
}

//将气血和精神的自然恢复从heal_up中剥离
int heal_up(int base)
{
	int update_flag, i;
	object me = this_object();
	mapping my;

	update_flag = base;

	//if( me->is_fighting() ) return -1;
  if (!me || !objectp(me)) return 0; //whuan，判断object是否存在
	update_flag = 0;
	my = query_entire_dbase();

  me->set_temp("recover/qi_recover", me->query_qi_recover());
  me->set_temp("recover/jing_recover", me->query_jing_recover());

	if( my["water"] > 0 ) { my["water"] -= 1; update_flag++; }
	if( my["food"] > 0 ) { my["food"] -= 1; update_flag++; }

	if (userp(me) && !wizardp(me)) {
		if( my["water"] < 1 ) {
			if (random(100)==1)
			write("你渴得眼冒金星，全身无力。\n");
			return update_flag;
		}
		switch(my["water"]){
			case 50:
			case 40:
			case 30:
			case 20:
			case 10:
		  message_vision(HIY"$N舔了舔干裂的嘴唇，看来是很久没有喝水了。\n"NOR, me);
		}
	}

	if( my["jing"] >= my["eff_jing"] ) {
	  my["jing"] = my["eff_jing"];
	  if( my["eff_jing"] < my["max_jing"] ) {
	  	my["eff_jing"] += me->query_jing_cure();
	  	update_flag++;
	  }
	}
	else
		update_flag++;

	if( my["qi"] >= my["eff_qi"] ) {
	  my["qi"] = my["eff_qi"];
	  if( my["eff_qi"] < my["max_qi"] ) {
	  	my["eff_qi"] += me->query_qi_cure();
	  	update_flag++;
	  }
	}
	else
		update_flag++;

	if (userp(me) && !wizardp(me)) {
		if( my["food"] < 1 ) {
			if (random(100) == 1)
			write("你饿得头昏眼花，直冒冷汗。\n");
			return update_flag;
		}
		switch(my["food"]){
			case 50:
			case 40:
			case 30:
			case 20:
			case 10:
				message_vision(HIY"突然一阵“咕咕”声传来，原来是$N的肚子在叫了。\n"NOR, me);
		}
	}

	if( my["max_jingli"] && my["jingli"] < my["max_jingli"] ) {
		if ( intp(me->query_jingli_heal()) )
		  my["jingli"] += me->query_jingli_heal();
	  if( my["jingli"] > my["max_jingli"] )
	  	my["jingli"] = my["max_jingli"];
	  update_flag++;
	}

	if( my["max_neili"] && my["neili"] < my["max_neili"] ) {
		if ( intp(me->query_neili_heal()) )
		  my["neili"] += me->query_neili_heal();
	  if( my["neili"] > my["max_neili"] )
	  	my["neili"] = my["max_neili"];
	  update_flag++;
	}

  if ( to_int(me->query("shaqi"))>0 &&
  	   (int)me->query("special_skill/greedy") ) {
    me->add("shaqi",-1);

    if (to_int(me->query("shaqi"))<=0)
    	me->set("shaqi",0);

    update_flag++;
  }
	return update_flag;
}

//气血和精神的自然恢复
void nature_recover()
{
	object me = this_object();
	int recv_qi, recv_jing, spd_qi, spd_jing;

	if (!me || !objectp(me))
		return;

	me->update_irregular_condition();

	if ( userp(me) && (me->query("water")<1 || me->query("food")<1) )
		return;

	if ( !me->query_temp("recover/qi_recover") )
		me->set_temp("recover/qi_recover", me->query_qi_recover());

	if ( !me->query_temp("recover/jing_recover") )
		me->set_temp("recover/jing_recover", me->query_jing_recover());

	spd_qi=me->query_temp("recover/qi_recover");
	spd_jing=me->query_temp("recover/jing_recover");

	recv_qi =spd_qi*100/95+me->query_temp("recover/qi_rem");
	recv_jing = spd_jing*100/95+me->query_temp("recover/jing_rem");
	if ( recv_qi-(recv_qi/10)*10>0 )
		me->set_temp("recover/qi_rem",  recv_qi-(recv_qi/10)*10 );
	else
		me->delete_temp("recover/qi_rem");

	if ( recv_jing-(recv_jing/10)*10>0 )
		me->set_temp("recover/jing_rem",  recv_jing-(recv_jing/10)*10 );
	else
		me->delete_temp("recover/jing_rem");

	me->add("jing", recv_jing/10);
	if( me->query("jing") >= me->query("eff_jing") ) {
	  me->set("jing", me->query("eff_jing"));
	}

	me->add("qi", recv_qi/10);
	if( me->query("qi") >= me->query("eff_qi") ) {
	  me->set("qi", me->query("eff_qi"));
	}
// 定义在 /feature/condition	
}

void listen_to_die(object listener)
{
    //printf("listen_to_die\n");
    if(!objectp(listener) || function_exists("die_notify",listener,0) == 0 || member_array(listener,dielisteners) != -1) return;
    dielisteners += ({listener});
}

void remove_listen_to_die(object listener)
{
    //printf("remove_listen_to_die\n");
    if(!objectp(listener) || function_exists("die_notify",listener,0) == 0 || member_array(listener,dielisteners) == -1) return;
    dielisteners -= ({listener});
}

void Negative_Impact(object me)//处理各种负面属性
{
	if (me&&userp(me)&&environment(me)&&living(me)&&me->query("env/shiye")&&me->query("level")>=101&&me->query("neili")>=1000)//101+的视野爆发
	{
		if (stringp(me->query("env/shiye")))
		me->add("neili",-to_int(to_float(20+random(10))*(1-me->pure_degree("exercised_neili"))));
		else
		me->add("neili",-to_int(to_float(35+random(10))*(1-me->pure_degree("exercised_neili"))));
	}
}

void remove_sg_effect(object me)
{
       if (!me) return;
       tell_object(me, HIY"\n你长长深呼一口气，先天神罡再难维持。\n"NOR); 
       me->delete_temp("xiantian_sg");
       me->delete_temp("active_force_buffer/xiantian-gong.sg");
}

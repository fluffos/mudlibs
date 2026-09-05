#include <ansi.h>

inherit ITEM;
inherit F_SSERVER;
int do_attack(string arg);
int do_hold(string arg);
int do_pullback(string arg);

void create()
{
	set_name( HIR"蛇阵"NOR, ({ "she zhen" }));
	set("short", HIR"蛇阵"NOR);
	set("env/invisibility",1);
	set("no_get",1);
	set("no_magic", 1);
	set("no_fight", 1);
	set("no_get_from",1);
	set("value", 1);
	set("baituo_shezhen", 1);
	set_temp("seeme", 1);
	setup();
}

void init()
{
	add_action("do_attack", "attack");
	add_action("do_pullback", "pullback");
	add_action("do_hold", "hold");
}

int do_attack(string arg)
{
	object ob = this_object();
	object me = this_player();
	object tar, env;
	object* allobj;
	if ( !objectp(ob) ) return 0;
	if ( !ob->query("owner") || ob->query("owner") != me ) return 0;
	if (!present("she di",me))
		return notify_fail("你身上没带蛇笛，无法操控蛇群。\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢，腾不出手来掏蛇笛。\n");
	if (!arg)
	{
		tell_object(me, CYN"你驱使蛇阵自由攻击。\n"NOR);
		ob->delete("target");
		ob->delete("hold_attack");
	}
	else
	{
		if ( !objectp(tar = present(arg, environment(ob))))
			tell_object(me, "这里没有 "+arg+" 这样的目标。\n");
		else {
			if (tar == me)
				tell_object(me, "攻击你自己？用刀子会比较快……\n");
			else {
				if ( !tar->is_character() || tar->is_corpse() ) 
					tell_object(me, "你确定这个目标需要蛇群去攻击？\n");
				else if ( userp(tar) && (me->query("xiuxian_player") || tar->query("xiuxian_player")) ) 
					tell_object(me, "无法驱动蛇群攻击这个目标。\n");
				else if ( tar->query("no_fight") ) 
					tell_object(me, "无法驱动蛇群攻击这个目标。\n");
				else if (!me->is_fighting(tar))
					tell_object(me, "你只能驱动蛇群攻击你的战斗目标。\n");
				else {
					tell_object(me, CYN"你驱使蛇阵攻击"+tar->query("name")+CYN"。\n"NOR);
					ob->set("target", tar);
					ob->delete("hold_attack");
					env = environment(ob);
					allobj = env->query("sieges/baituo_shezhen/siege_target");
					if (sizeof(allobj)<=0 || member_array(tar,allobj)<0 )
					{
						allobj += ({ tar });
						env->set("sieges/baituo_shezhen/siege_msg", "眼前遍地毒蛇，成千成万，哪有落脚的地方？闯不过去蛇阵，你哪儿也去不了！\n");
						env->set("sieges/baituo_shezhen/siege_target", allobj);
						message_vision(HIR"蛇群一拥而上，将$n团团围困在中央。\n"NOR, me, tar);
					}
				}
			}
		}
	}
	return 1;
}

int do_hold(string arg)
{
	object ob = this_object();
	object me = this_player();
	if ( !objectp(ob) ) return 0;
	if ( !ob->query("owner") || ob->query("owner") != me ) return 0;
	if (!present("she di",me))
		return notify_fail("你身上没带蛇笛，无法操控蛇群。\n");
	tell_object(me, CYN"你驱使蛇阵停止攻击。\n"NOR);
	ob->set("hold_attack", 1);
	return 1;
}

int do_pullback(string arg)
{
	object ob = this_object();
	object me = this_player();
	if ( !objectp(ob) ) return 0;
	if ( !ob->query("owner") || ob->query("owner") != me ) return 0;
	if (!present("she di",me))
		return notify_fail("你身上没带蛇笛，无法操控蛇群。\n");
	if (me->is_busy())
		return notify_fail("你正忙着呢，腾不出手来掏蛇笛。\n");
	message_vision(CYN"$N从怀里取出蛇笛，吹奏出一个古怪的音节。\n"NOR, me);
	ob->set("times", 100);
	me->start_busy(1);
	return 1;
}

void show_effect()
{
	object env = environment(this_object());
	object me = this_object()->query("owner");
	object focus;
	object* allobj;
	int i;
	if (!env->isroom()) return;
	env->set("additions/baituo_snake", HIM"只见脚下遍地全都是毒蛇，四下里蠕动游走，蛇声嗤嗤不绝，一股腥臭迎面扑来。\n"NOR);
	if (objectp(me))
	{
		if (me->is_fighting())
			allobj = me->query_enemy();
		else
		{
			focus = me->query_temp("focus_target");
			if ( focus && objectp(focus) && environment(focus) == environment(me) )
				allobj = ({ focus });
			else
			{
				allobj = all_inventory(env);
				allobj -= ({ me });
				for (i=0;i<sizeof(allobj);i++)
				{
					if (!me->visible(allobj[i]))
						allobj[i] = 0;
				}
				allobj -= ({ 0 });
			}
		}
	}
	else
	{
		allobj = all_inventory(env);
	}
	env->set("sieges/baituo_shezhen/siege_msg", "眼前遍地毒蛇，成千成万，哪有落脚的地方？闯不过去蛇阵，你哪儿也去不了！\n");
	env->set("sieges/baituo_shezhen/siege_target", allobj);
}

int remove_effect()
{
	object env = environment(this_object());
	object me;
	string msg;
	if (env->isroom())
	{
		env->delete("additions/baituo_snake");
		me = this_object()->query("owner");
		msg = HIY"远处传来一阵木笛响鞭声，蛇群顿如潮水般向着声响方向退走，不多时就都消失无踪。\n"NOR;
		if (objectp(me) && environment(me)==env)
			message_vision(msg, me);
		else
			tell_room(env, msg);
		env->delete("sieges/baituo_shezhen");
	}
	destruct(this_object());
	return 1;
}

void heal_ob(object me, int pflv)
{
	int point,mxqi,mxnl;
	point = me->query_skill("hamagong", 1);
	if (pflv>=4 && point>100 && me->query_skill_mapped("force") == "hamagong" && !random(7-pflv))
	{
		message_vision(HIG"\n$N瞥见一条通体朱红的大蛇从眼前游过，顺手一把抓住，张口往蛇颈咬下，大口吮吸着蛇血。\n"
				+ HIR "不多时，$P脸上涌起一片红潮，一股热力从腹中直透上来，浑身似有使不完的劲力。\n\n"NOR, me);
		me->set_temp("baituo_redsnake/time", time() + pflv*pflv);
		mxqi = me->query("max_qi");
		mxnl = 2 * me->query("max_neili");
		if ( me->query("qi") < mxqi || me->query("neili") < mxnl )
		{
			if (me->query("eff_qi") < (mxqi-point))
				me->add("eff_qi", point);
			else 
				me->set("eff_qi", mxqi);
			if (me->query("qi") < (me->query("eff_qi")-2*point))
				me->add("qi", 2*point);
			else 
				me->set("qi", me->query("eff_qi"));
			if (me->query("neili") < (mxnl-2*point))
				me->add("neili", 2*point);
			else
				me->set("neili", mxnl);
		}
	}
}

void do_bite(object me, object target, int pflv)
{
	string msg, dgmsg, poison, limb;
	string* poisons = ({ "snake_poison", "bt_poison", "btgs_poison" });
	string* names = ({HIG"竹叶青", HIY"金环蛇", HIW"银环蛇", WHT"白眉蝮蛇", YEL"圆斑蝰蛇", CYN"尖吻蝮蛇", RED"眼镜王蛇", });
	int i,lv,ap,sp;
	string* limbs;
	object ob = this_object();
	if (pflv<=0) return;
	lv = me->query_skill("poison",1);
	msg = HIM"蛇群如潮水般涌了上来，一条" NOR + names[random(sizeof(names))] + HIM"如簧般弹起，向$n一口直咬下去！\n"NOR;
	dgmsg = HIC"$n闪电般地向后一闪，堪堪躲了过去。\n"NOR;
	ap = me->query_skill("zhaosheshu",1) + lv + me->query_skill("force", "hamagong");
	limbs = target->query("limbs");
	for (i=0;i<pflv;i++)
	{
		if (!target) return;
		sp = target->query_skill("zhaosheshu",1) + target->query_skill("poison",1) + target->query_skill("dodge");
		if (!living(target) || F_KUNGFU->hit_rate(ap + ap*i/10, sp, 6, me, target))
		{
			limb = limbs[random(sizeof(limbs))];
			poison = (pflv>=3)?poisons[random(3)]:poisons[random(2)];
			if (poison == "btgs_poison")
			{
				if (i==0)
					msg = HIM "蛇群如潮水般涌了上来，一条" HIR + "西域怪蛇" + HIM"如簧般弹起，向$N一口直咬下去！\n"NOR;
				else
					msg = HIM "紧接着又是一条" HIR + "西域怪蛇" + HIM"从蛇潮中弹起，向$N一口咬来！\n" NOR;
				target->set_temp("btgs_poison/pflv", pflv);
			}
			if (!living(target))
				message_vision(msg + HIW"$n躺在地上一动不动，毒蛇狠狠地咬在$n的"+limb+"上。\n"NOR, me, target);
			else
				message_vision(msg + HIY"$n躲闪不及，感觉"+limb+"上微微一麻，像是被蚊子叮了一口，居然没有什么痛觉。\n"NOR, me, target);
			F_POISON->poison_attack(me, target, poison, (random(lv/20)+lv/100)*(10+pflv)/10 + target->query_condition(poison));
		}
		else
			message_vision(msg + dgmsg, me, target);
		msg = HIM "紧接着又是一条" NOR + names[random(sizeof(names))] + HIM"从蛇潮中弹起，向$n一口咬来！\n" NOR;
		if (!target->is_fighting(me))
			target->fight_ob(me);
		if (!ob->query("target"))
			target = offensive_target(me);
	}
}

void try_bite(object me, int pflv)
{
	object target, *allob;
	if (!me) return;
	if (!me->is_fighting() && pflv<=2 && !random(3) ) // 2级以下可能控制不住蛇阵，随机攻击其他目标
	{
		allob = all_inventory(environment(me));
		target = allob[random(sizeof(allob))];
		if ( target==me || !target->is_character() || target->is_corpse() ) return;
		if ( userp(target) || target->query("no_fight") ) return;
		do_bite(me, target, pflv);
		return;
	}
	if (this_object()->query("hold_attack")) return;
	target = this_object()->query("target");
	if (!target || environment(target)!=environment(me)) target = offensive_target(me);
	if (!target) return;
	do_bite(me, target, pflv);
}

int check_user()
{
	object ob = this_object();
	object env = environment(ob);
	object user;
	int pflv,zss;
	if ( !objectp(ob) ) return 0;
	if ( !objectp(user = ob->query("owner")) || environment(user)!= env ) 
	{
		remove_effect();		
		return 1;
	}
	pflv = (int)user->query("purefamily/level");
	if (pflv>0 && user->query("purefamily/family_name") != "白驼山") 
		pflv=0;
	ob->add("times", 1);
	zss = (int)ob->query("exp") / 50;
	if ((int)ob->query("times")>(1+zss+pflv*5))
		remove_effect();
	else {
		message_vision( MAG"无数的毒蛇在四下里不断地蠕动游走，耳中满是嗤嗤嘘嘘的蛇声不绝。\n"NOR, user);
		try_bite(user, pflv);
		heal_ob(user, pflv);
		call_out("check_user", 3);
	}
}
// tan.c
// notme 2004-05-25 
// 参照暗器类perform使得可以使用各种暗器
// modified by iszt@pkuxkx, 2007-02-08
// 暗器类perform支持amount类型的暗器并且会根据特定暗器类型进行优先级寻找，采用了/feature/kungfu下的find_throwing函数来寻找暗器
// by seagate@pkuxkx 2013-07-28
// 加强点dmg by yhzzyahoo@2015.11.16

#include <ansi.h>
inherit F_SSERVER;

string* valid_weapon() 
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" || target=="self" ;
}

protected void show_message(object me, object target);

protected void attack_more(object me, object target, object anqi, int rate, int ap, int damage, int pflv, int times);
protected void attack_again(object me, object target, int rate, int ap, int dp);

int perform(object me, object target)
{	   
	int ap, dp, pflv, busy_time = 0;
	int damage, skilllevel, throws, throwing_wield = 0;
	int i,p,rate_fix,k,kf_fix;
	object obj, *inv, weapon, *eny, right_weapon, left_weapon;
	string msg, dodge_skill, anqi;

	if( !target ) target = offensive_target(me);

	if( !objectp(target) || !target->is_character() )
		return notify_fail("暗器射敌只能对同地方的对手使用。\n");

	if ( me == target )
	{
        me->start_busy(1);
		me->set("qi", -1);
		return notify_fail("你在自己脑袋上狠狠弹了一下，顿时天旋地转........\n");
	}

    right_weapon = me->query_temp("weapon");
    left_weapon = me->query_temp("secondary_weapon");

    if ( (objectp(right_weapon) && right_weapon->query("skill_type")=="throwing") ||
         (objectp(left_weapon) && left_weapon->query("skill_type")=="throwing") )
        throwing_wield = 1;

    if ( !throwing_wield && me->check_hand() >= 2 )
        return notify_fail("你必须空出一只手才能发射暗器。\n");

    if( skilllevel = (int)me->query_skill("tanzhi-shengong", 1) < 120 )
		return notify_fail("你的弹指神通不够娴熟。\n");

	if( (int)me->query_skill("force", "bihai-shengong") < 180 )
		return notify_fail("你的碧海神功不够高，不能用内力发射暗器。\n");

	if( (int)me->query_skill("bihai-shengong", 1) < 100 )
		return notify_fail("你的碧海神功不够高，不能用内力发射暗器。\n");

	if( (int)me->query("max_neili", 1) < 500 )
		return notify_fail("你现在内力太弱，不能发射暗器。\n");

	if( (int)me->query("neili", 1) < 100 )
		return notify_fail("你现在内力太弱，不能发射暗器。\n");

/*	if ( me->query_skill_prepared("finger") != "tanzhi-shengong"
		|| me->query_skill_mapped("finger") != "tanzhi-shengong")
		return notify_fail("你必须使用弹指神通，才能发射暗器。\n");			*/		 
		
	pflv = (int)me->query("purefamily/level");
	if (pflv>0 && me->query("purefamily/family_name") != "桃花岛")
		pflv = 0;

    eny=me->query_enemy();
 	throws=sizeof(eny);
    if (throws>=5)
        throws=5;

	ap = me->query_skill("force", "bihai-shengong") + me->query_skill("finger", "tanzhi-shengong") + me->query_skill("throwing", 1);
	dp = target->query_skill("dodge") + target->query_skill("parry") + target->query_skill("throwing");

	if (!anqi = me->query_temp("perform_use_anqi"))
		anqi="shi zi";
    obj=F_KUNGFU->find_throwing(me, anqi);//身上可以shizi带了用别的，一个小bug

	if (!obj)
	  return notify_fail("你身上没有暗器，无法使出弹指绝技！\n");

	busy_time = 2;
	me->add("neili", -100);

	show_message(me, target);
	    //命中加强1个小等级

	rate_fix=8;
	k=me->query_temp("active_buff/qimen-baguazhen.buzhen/cengshu");
	if (k>0)
	{
		if (me->query("safari_skill/thd_shangshen"))
		{
			if (!me->query_temp("qmbgz.shangshen_done"))
			{
				kf_fix=(int)(k*4)+8;
				me->add_temp("apply/kf_wound",kf_fix);
				me->set_temp("qmbgz.shangshen_done",1);
		        message_vision(HIG"\n$N在奇门八卦阵的影响下，越战越勇！\n"NOR,me,target);
			}
		}
		if (me->query("safari_skill/thd_huoxin"))
		{	
			if (!me->query_temp("qmbgz.huoxin_done"))
			{
				if (k<16)
				{
					rate_fix -= (int)(k>>1);
				}
		        message_vision(HIG"\n$N在奇门八卦阵的影响下，越战越有灵性！\n"NOR,me,target);
				me->set_temp("qmbgz.huoxin_done",1);
			}
		}
	}
	
	if (pflv>=4 && rate_fix>7)
		rate_fix -= 1;

    if ( throws<=1 && 
  	   ( F_KUNGFU->hit_rate( ap, dp, rate_fix, me, target) || 
  	     !living(target)) )
    {
        damage = (int)(me->query_skill("finger", "tanzhi-shengong") * 2);
		damage += (int)me->query_skill("bihai-shengong");
        damage += obj->query("weapon_prop/damage") * 5;
        if(obj->query("id")=="shi zi")
		{
			damage*=5;
			damage>>=2;
		}
		if (pflv>=3)
			damage += damage*(pflv-2)/10;

        //弹指的damage在暗器perform里最大
        F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
        msg = HIR"$n"HIR"只觉得手臂一麻，已被$N"HIR"的"+obj->name()+HIR+"打中了穴道";
        if(objectp( weapon = target->query_temp("weapon")))
        {
            weapon->unequip();
            if(!target->is_busy())
                target->start_busy(2);
            msg += "，不由自主的放开了兵器";
        }
        msg += "！\n"NOR;

//        msg = replace_string(msg, "$N", me->name());
//       msg = replace_string(msg, "$n", target->name());
        message_vision( msg, me,target);

        //	tell_object(me, replace_string(msg, me->name(), "你"));
//        msg = replace_string(msg, me->name()+HIR"的"+obj->name(), "");
//        msg = replace_string(msg, target->name(), "你");
//        tell_object(target, msg);

        if(obj->query("id")=="shi zi")
        {
            busy_time = random(3);
            tell_object(target, HIR"你仔细一看，发现是东邪黄药师的成名暗器"HIW"玉石子"HIR"！\n"NOR);
            F_KUNGFU->hit_wound("qi", 100 + random(400), 0, me, target);
        }
        msg = COMBAT_D->damage_msg(me->query_skill("finger", "tanzhi-shengong")/6, "内伤");
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        obj->move(environment(target));
		if (pflv>=5 && me->check_hand()==0 && (me->query("zyhb") || !random(4)))
			attack_again(me, target, rate_fix, ap, dp);
    }
    else if ( throws>1 )
	{
		for(i=0;i<throws;i++)
        {
            if ( i>0 )
                obj=F_KUNGFU->find_throwing(me, anqi);
      
            if ( !obj )
                break;
			if (i>0)
				message_vision(HIW"$N双手连弹，嗤的一声，又是一"+(obj->query("base_unit")?obj->query("base_unit"):"枚")+obj->query("name")+ HIW"激射而出！\n"NOR, me);
     
            ap = me->query_skill("force", "bihai-shengong") + me->query_skill("finger", "tanzhi-shengong") + me->query_skill("throwing", 1);
            dp = eny[i]->query_skill("dodge") + eny[i]->query_skill("parry") + eny[i]->query_skill("throwing");
            if ( F_KUNGFU->hit_rate( ap, dp, rate_fix, me, eny[i]) || !living(eny[i]) )
            {
                damage = (int)(me->query_skill("finger", "tanzhi-shengong") * 2);
				damage += (int)me->query_skill("bihai-shengong");
                damage += obj->query("weapon_prop/damage") * 5;
                if(obj->query("id")=="shi zi")
					{
						damage*=5;
						damage>>=2;
					}
				if (pflv>=3)
					damage += damage*(pflv-2)/10;
				obj->move(environment(eny[i]));
                //弹指的damage在暗器perform里最大
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, eny[i]);
                msg = HIR"$n"HIR"只觉得手臂一麻，已被$N"HIR"的"+obj->name()+HIR+"打中了穴道";
                if(objectp( weapon = eny[i]->query_temp("weapon")) &&
                   random(10)<3 )
                {
                    weapon->unequip();
                    if(!eny[i]->is_busy())
                        eny[i]->start_busy(2);
                    msg += "，不由自主的放开了兵器";
                }
                msg += "！\n"NOR;
        
//                msg = replace_string(msg, "$N", me->name());
//                msg = replace_string(msg, "$n", eny[i]->name());
                message_vision( msg, me, eny[i]);
        
                //	    tell_object(me, replace_string(msg, me->name(), "你"));
//                msg = replace_string(msg, me->name()+HIR"的"+obj->name(), "");
//                msg = replace_string(msg, eny[i]->name(), "你");
//                tell_object(eny[i], msg);
        
                if(obj->query("id")=="shi zi")
                {
                    busy_time = random(3);
                    tell_object(eny[i], HIR"你仔细一看，发现是东邪黄药师的成名暗器"HIW"玉石子"HIR"！\n"NOR);
                    F_KUNGFU->hit_wound("qi", 100 + random(400), 0, me, eny[i]);
                }
                msg = COMBAT_D->damage_msg(me->query_skill("finger", "tanzhi-shengong")/6, "内伤");
                message_vision(msg, me, eny[i]);
                COMBAT_D->report_status(eny[i]);
                if( (int)me->query("neili") < 150 )
                    break;
                me->add("neili", -150);
				if (pflv>=3)
					attack_more(me, eny[i], obj, rate_fix, ap, damage, pflv, 1);
           }
            else
            {
                destruct(obj);
                busy_time = 2;
                dodge_skill = eny[i]->query_skill_mapped("dodge");
                if( !dodge_skill ) 
                    dodge_skill = "dodge";
                msg = "\n"+SKILL_D(dodge_skill)->query_dodge_msg(eny[i], 1);
                msg = replace_string(msg, "$N", "发射暗器那人");
                message_vision(msg, me, eny[i]);
                if( (int)me->query("neili") < 150 )
                    break;
                me->add("neili", -150);
            }
        }
	}
	else
	{
		destruct(obj);
		busy_time = 2;
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg = "\n"+SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		msg = replace_string(msg, "$N", "发射暗器那人");
		message_vision(msg, me, target);
		if (pflv>=5 && me->check_hand()==0 && (me->query("zyhb") || !random(5)))
			attack_again(me, target, rate_fix, ap, dp);
	}

	if( F_KUNGFU->hit_rate( me->query("combat_exp"), target->query("combat_exp"), 6, me, target) && 
		  !me->is_fighting(target))
	{
		inv = all_inventory(environment(target));
		while(!objectp(obj) || obj == target || !living(obj))
			obj = inv[random(sizeof(inv))];
		tell_object(target, HIC "你却不知是谁发射的暗器，只看到"+obj->query("name")+HIC"似乎动了动。\n\n" NOR);
	}
	else
	{
		tell_object(target, HIR "你看到发射暗器的"+me->name()+HIR"负手而立，好像什么也没发生过。\n\n" NOR);
		if (pflv<3)
			target->kill_ob(me);
	}
	if (k>0 && me->query("safari_skill/thd_shangshen"))
	{
		me->add_temp("apply/kf_wound",-kf_fix);
	}
	
	if (busy_time>0)
		me->start_busy(busy_time);

	return 1;
}

protected void show_message(object me, object target)
{
    string msg;
  
	msg = HIW"\n只见$N"HIW"双肩微晃，右手中指曲起，扣在拇指之下弹出，将一件物事化作一道闪光而去！\n"NOR;
	msg += HIY"从$N"HIY"手中射出的这件物事射程极远，速度劲急之极，力道强劲异常，破空之声异常响亮！\n"NOR;
//	msg = replace_string(msg, "$N", me->name());
//	msg = replace_string(msg, "$n", target->name());
//	msg = replace_string(msg, "$P", gender_pronoun(me->query("gender")));
	message_vision(msg, me, target);
//	msg = replace_string(msg, me->name(), "你");
//	msg = replace_string(msg, gender_pronoun(me->query("gender")), "你");
	msg = HIW"\n你眼前只见一道闪光，一件物事夹着异常响亮的破空之声直向你打来！\n"NOR;
	tell_object(target, msg);
}

protected void attack_more(object me, object target, object anqi, int rate, int ap, int damage, int pflv, int times)
{
	object *eny, tar;
	int i, dp;
	string msg, dodge_skill;
    eny = me->query_enemy();
	eny -= ({ target });
	i = sizeof(eny);
	if (i<=0 || !objectp(anqi)) return;
	tar = eny[random(i)];
	msg = HIM + anqi->query("name") + HIM "的射力极强，去势不衰，又弹向$n" HIM "！\n"NOR;
	dp = tar->query_skill("dodge") + tar->query_skill("parry") + tar->query_skill("throwing");
    dodge_skill = tar->query_skill_mapped("dodge");
    if( !dodge_skill ) dodge_skill = "dodge";
	if ( F_KUNGFU->hit_rate( ap, dp, rate, me, tar) || !living(tar) )
	{
		msg += HIR"$n"HIR"闪避不及，只觉身上一痛，已被"+ anqi->query("name") + HIR"狠狠打中！\n"NOR;
		message_vision(msg, me, tar);
		if (pflv>=4)
			damage -= damage/3;
		else 
			damage /= 2;
		F_KUNGFU->hit_wound("qi", damage, damage/3, me, tar);
		COMBAT_D->report_status(tar);
		anqi->move(environment(tar));
		if (pflv>=5 && times<2)
			attack_more(me, tar, anqi, rate, ap, damage, pflv, times+1);
	}
	else
	{
		msg += SKILL_D(dodge_skill)->query_dodge_msg(tar, 1);
		destruct(anqi);
		message_vision(msg, me, tar);
	}
}

protected void attack_again(object me, object target, int rate, int ap, int dp)
{
	object obj;
	string msg, anqi, dodge_skill;
	int damage;
	if (!living(target)) return;
	if (!anqi = me->query_temp("perform_use_anqi"))
		anqi="shi zi";
    obj=F_KUNGFU->find_throwing(me, anqi);
	if (!obj)
	{
		tell_object(me, HIY"你正待连发一记暗器，伸手却摸了个空，原来是身上的暗器用光了。\n"NOR);
		return;
	}
	msg = HIW"$N紧随着伸左指一弹，嗤的一声，又是一"+(obj->query("base_unit")?obj->query("base_unit"):"枚")+obj->query("name")+ HIW"激射而出！\n"NOR;
	if ( F_KUNGFU->hit_rate( ap, dp, rate, me, target) )
	{
		msg += HIR"$n"HIR"闪避不及，只觉身上一痛，已被"+ obj->query("name") + HIR"狠狠打中！\n"NOR;
		message_vision(msg, me, target);
        damage = (int)(me->query_skill("finger", "tanzhi-shengong") * 2);
		damage += (int)me->query_skill("bihai-shengong");
        damage += obj->query("weapon_prop/damage") * 5;
        if(obj->query("id")=="shi zi")
		{
			damage*=5;
			damage>>=2;
		}
		damage += damage*3/10;
		F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
		COMBAT_D->report_status(target);
		obj->move(environment(target));
	}
	else
	{
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
		destruct(obj);
		message_vision(msg, me, target);
	}
}

int help(object me)
//added by iszt@pkuxkx, 2007-02-08
{
	write(HIY"\n弹指神通之「弹指绝技」\n\n"NOR);
	write(@HELP
	「东邪」黄药师的绝学，能于不动声色间将暗器扣在拇指之下弹出，手
	法精微奥妙，弹射暗器时，射程极远，速度劲急之极，力道强劲异常，
	破空之声异常响亮。若用玉石子作为暗器，则威力更为惊人。

	要求：	弹指神通等级 120 以上；
		碧海神功等级 100 以上；
		有效内功等级 180 以上；
		最大内力 500 以上；
		内力 100 以上；
		随身带有暗器；
		激发指法为弹指神通；
		且使用弹指神通。
HELP
	);
	return 1;
}

//催命鬼手
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object *enemy,weapon,*inv,enem;
	int sign,level,sign_neili,limit_number,number,sign_skill,damage,practise;
	string msg,enemy_name;
	level=me->query_skill("guishoushe",1);
	if(me->is_busy()) return notify_fail("你正忙着呢！\n");
	if(!me->is_fighting()) return notify_fail("催命鬼手只能在战斗中使用！\n");
	if(me->query("neili")<100) return notify_fail("你的内力不够，不足以使出催命鬼手！\n");
	if(level<100) return notify_fail("你的鬼手射等级不够，不能领悟催命鬼手！\n");
	//对所有敌人
	enemy=me->query_enemy();
	if(sizeof(enemy)<1) return notify_fail("你没有敌人？\n");
	sign=0;
	sign_neili=0;
	number=0;
	practise=0;
	limit_number=me->query_skill("guishoushe",1)/2;
	sign_skill=0;
	inv=all_inventory(me);
	if(me->query("guishoushe/limit")<10) me->set("guishoushe/limit",10);
	for(int i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("skill_type")!="throwing") continue;
		weapon=inv[i];
		if(weapon==me->query_temp("weapon")||
			 weapon==me->query_temp("secondary_weapon") ) continue;//不要用手上拿的兵器
		sign=1;//有暗器
		number++;
		if(number>me->query("guishoushe/limit"))//一次能发出的暗器个数有一定个数限制．
		{
			sign_skill=1;
			number--;
			break;
		}
		if (me->query("neili")<100) 
		{
			sign_neili=1;
			number--;
			break;
		}
                me->add("neili",-10);
		enem=enemy[random(sizeof(enemy))];
		if (!enem->query_temp("guishoushe/shoot"))
			enem->set_temp("guishoushe/shoot",1);//被射了，但不一定射中
		if(random(me->query_skill("guishoushe",1)*2)>random(enem->query_skill("dodge",1))
            &&random(me->query("combat_exp")*2)>enem->query("combat_exp"))
		{//射中
			if(!enem->query_temp("guishoushe/damage"))
			{
				//基本伤害
				enem->set_temp("guishoushe/damage",me->query_skill("guishoushe",1)/4+me->query_skill("throwing",1)/4);
			}
                        enem->add_temp("guishoushe/damage",weapon->query("weapon_prop/damage"));
                        
			enem->add_temp("guishoushe/number",1);
			if (enem->query_temp("guishoushe/damage") > 800)
				enem->set_temp("guishoushe/damage",800);
			weapon->move(enem);
		}
		else
		{
			destruct(weapon);
		}
	}
	if (!sign) return notify_fail("你身上都没有暗器，怎能使用鬼手射的绝技？\n");
     me->start_busy(1);
	msg=HIW"$N"+HIW"使出鬼手射惊天绝技－催命鬼手!\n......\n....\n...\n只见$N"+HIW"在打斗间，双手在身前突然加速，只舞得若现若隐!\n\n"NOR;
	msg+=HIY"正让人纳闷之际，"+chinese_number(number)+"枚暗器已从$N"HIY"的手中铺天盖地般的飞了出来!\n\n\n"NOR;
	msg+=HIR"发出的暗器直奔";
	sign=0;
	for(int i=0;i<sizeof(enemy);i++)
	{
		enem=enemy[i];
		if(!enem->query_temp("guishoushe/shoot")) continue;
		if (environment(enem) != environment(me)) continue;
		if(enem->query("name")==enemy_name) continue;
		enemy_name=enem->query("name");
		if(sign)
			msg+="、"+enemy_name+HIR;
		else
			msg+=enemy_name+HIR;
		sign=1;
	}
	msg+="的周身大穴而去!\n\n"NOR;
	message_vision(msg,me);
	for(int i=0;i<sizeof(enemy);i++)
	{
		enem=enemy[i];
		if(!enem->query_temp("guishoushe/shoot")) continue;
		damage=enem->query_temp("guishoushe/damage");
		if(!damage)
		{
			message_vision(MAG"$N"+MAG"眼疾手快，在暗器近身之前，已看准暗器来路，一个鹞子翻身躲开来袭的暗器!\n"NOR,enem);
		}
		else
		{
			message_vision(HIB"只听一声惨叫,"+chinese_number(enem->query_temp("guishoushe/number"))+"枚暗器已经同时击中$N"+HIB"身上各处大穴!\n"NOR,enem);
			practise+=enem->query_temp("guishoushe/number");
            enem->receive_damage("qi", damage, me);
            enem->receive_wound("qi", damage/3, me);
		}
		enem->delete_temp("guishoushe");
		if(enem->query("qi")<1) enem->die();
	}
	if(sign_neili) tell_object(me,HIG"你觉得由于你内力不支，无法将鬼手射的绝技完全发挥出来!\n"NOR);
	if(sign_skill) tell_object(me,HIG"你觉得由于你对催命鬼手掌握不够，无法射完手中所有的暗器!\n"NOR);
	if(practise)
	{
		me->add("guishoushe/practise",practise);
		practise=me->query("guishoushe/limit");
		if(practise*practise*5<me->query("guishoushe/practise"))
		{
			if(practise+1>limit_number)
			{
				tell_object(me,HIY"看来你鬼手射等级不够，无法继续提高催命鬼手!("+me->query("guishoushe/practise")*20/practise/practise+"%)\n"NOR);
				return 1;
			}
			me->add("guishoushe/limit",1);
			me->set("guishoushe/practise",0);
			tell_object(me,HIR"你的催命鬼手在你努力的练习下升级了!\n"+HIC"你现在可以一次发出"+chinese_number(me->query("guishoushe/limit"))+"枚暗器了!\n"NOR);
		}
		else
		{
			tell_object(me,HIM"你觉得你对催命鬼手的发射暗器方法，又有所领悟!("+me->query("guishoushe/practise")*20/practise/practise+"%)\n"NOR);
		}
	}


	return 1;
}

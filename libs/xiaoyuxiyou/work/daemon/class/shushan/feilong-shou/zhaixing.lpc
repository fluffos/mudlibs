//凌空摘星	偷取敌人东西或金钱 敌方单人 绝 	
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,k,damage,p,steal=1;
	object ob,*inv,*obj;
	string msg,succ_msg;
	
	if( me->query_level()<20 )
    		return notify_fail("你的人物等级不够。\n");
	if((int)me->query_skill("feilong-shou",1) < 200
	 || me->query_skill_mapped("unarmed") != "feilong-shou" )
        	return notify_fail("你的『飞龙探云手』还不纯熟！\n");
	if((int)me->query("force") < 200 )
        	return notify_fail("你体内的内力不足。\n");
	if((int)me->query_skill("dodge")<350 )
        	return notify_fail("你的身法还不纯熟！\n");
        	
	if( !target ) target = offensive_target(me);
        if( !target || !target->is_character()
         || target->is_corpse()
         || target==me
         || !me->is_fighting(target) )
        	return notify_fail("你要对谁施展这一招『铜钱镖』？\n");

	inv = all_inventory(target);
	obj = ({});
	for(i=0;i<sizeof(inv);i++)
	{
		if( !inv[i] || inv[i]->is_character()
		 || inv[i]->query("no_get")
		 || inv[i]->query("no_stealing") )
			continue;
		obj+= ({inv[i]});			 
	}
	obj-=({0});
	if( sizeof(obj)<1
	 && !target->check_pay(1) )
		steal = 0;
	
	msg = HIB"$N"HIB"嘿嘿一笑，足下加快，身形乱转，双手舞动如飞，带起片片掌影掠向$n"HIY"！\n"NOR;
	succ_msg = HIR"结果$n"HIR"一个不防，被$N"HIR"擦身而过，隐约间感觉有些不对劲。\n"NOR;
	p = me->query_skill("dodge")/10;
	p+= me->query_skill("stealing",1)/10;
	me->add_temp("apply/attack",p);
	me->set_temp("pfm_msg",1);
	me->add("force",-150);
	damage = COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_PERFORM,msg,succ_msg);
	me->add_temp("apply/attack",-p);
	me->delete_temp("pfm_msg");
	if( damage<1 )
		message_combatd(HIW"结果被$n"HIW"闪了开来，$N"HIW"怏怏而回。\n"NOR,me,target);
	else if( steal==1 )
	{
		k = 1+random(me->query_skill("feilong-shou",1));
		if( !target->check_pay(k) )
		{
			ob = obj[random(sizeof(obj))];
			if( present(ob,target) )
			{
				if( ob->move(me) )
				{
					tell_object(me,HIY"哈哈，得手！你成功从"+target->name()+HIY"身上盗得"+ob->short()+HIY"。\n"NOR);
					message("vision","只见"+me->name()+"顺手从"+target->name()+"身上偷取了"+ob->short()+"。\n",environment(me),({me,target}));
				}
			}
		}
		else
		{
			target->money_add(-k);
			me->money_add(k);
			me->save(1);
			target->save(1);
			tell_object(me,HIY"哈哈，得手！你成功从"+target->name()+HIY"身上盗得"+MONEY_D->money_str(k)+HIY"。\n"NOR);
			message("vision","只见"+me->name()+"顺手从"+target->name()+"身上偷取了"+MONEY_D->money_str(k)+"。\n",environment(me),({me,target}));
		}		
	}
	me->start_busy(3);	
	return 1;		
}

int help(object me)
{
string str;     
if ( !me )      return 0;
str = @LONG
        外功名称：凌空摘星
        外功所属：飞龙探云手
        外功效果：攻击对方，命中则能从敌方身上偷取钱财或物品
		  自身busy 3 秒	
        外功条件：
        	  人物等级20级	
                  内力200点，消耗150点
                  飞龙探云手200级并激发
                  轻功有效等级350级
LONG;
me->start_more(str);
return 1;
} 

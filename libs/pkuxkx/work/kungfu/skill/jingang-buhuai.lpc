// jingang-buhai.c
// whuan,iron-cloth的特殊工夫
#include <ansi.h>
inherit SKILL;

string *absorb_msg = ({
	      YEL"$n的金刚不坏神功自然激发而出，$N的攻击犹如击中败絮。\n"NOR,
        YEL"$N的攻击甫及$N三尺之内犹如遇上了一层坚硬之极的屏障，确是$n的金刚不坏神功。\n"NOR,
        YEL"$N击中了$n，却觉得似乎击中了铜墙铁壁，真震得肩膀发麻！\n"NOR,
        YEL"$n的金刚不坏神功自然激发而出，直觉得全身肌肤硬如钢戟！\n"NOR,
});

string query_absorb_msg()
{
	return absorb_msg[random(sizeof(absorb_msg))];
}

int valid_enable(string usage)
{
        return usage == "iron-cloth" ;
}

int valid_learn(object me)
{
        if ((string)me->query("family/family_name") != "少林派" 
        && (string)me->query("chushi/last_family") != "少林派")
                return notify_fail("只有少林弟子方可修习「金刚不坏神功」!\n");
        if ((string)me->query("class") != "bonze" )
                return notify_fail("只有佛门弟子方可修习「金刚不坏神功」!\n");
        if ((int)me->query_skill("yijin-jing",1)<300)
                return notify_fail("你的易筋经火候尚不到家，不可强行修习「金刚不坏神功」!\n");
        return 1;       
}
int practice_skill(object me)
{
        return 0;
}

//吸收attacker的伤害
//absorb函数的返回值：整数：大于零表示吸收掉的伤害，等于小于零表示吸收失败
//字符串，输出信息
//数组({吸收的伤害,输出信息})

mixed absorb(int ap,int pp,object attacker,object defender,int damage,object weapon)
{
	int qdamage,sdamage, abs_lv,randnum;
	float ratio;
	string result = "";

  if(!objectp(attacker) || !objectp(defender)) return 0;
  
	abs_lv=(int)defender->query_skill("jingang-buhuai",1);
  randnum = (int)random(ap/2 + pp/2);
  if ( abs_lv<=400 )
  {
    ratio=ap*1.0/pp/800*abs_lv;
    if ( ratio>0.5 )
     	ratio=0.5;
  }
  else if ( abs_lv<=800 )
  {
    ratio=ap*0.5/pp+ap*0.5/pp/1600*abs_lv;
    if ( ratio>0.75 )
    	ratio=0.75;
  }
  else 
  {
   	ratio=ap*0.75/pp+ap*0.75/pp/6000*abs_lv;
   	if ( ratio>0.9 )
   		ratio=0.9;
  }
  
	result +=query_absorb_msg();
	qdamage=to_int(ceil(damage*ratio));
//放开金刚不坏的反弹伤害限制
	if ( qdamage>=2000+abs_lv*3/2 )
		qdamage=2000+abs_lv*3/2;

//基本硬功效果说明，假设ap=pp
//400级 25%几率反弹伤害 反弹50%伤害，封顶2000 吸收83.5%伤害
//      40%几率大幅吸收伤害 吸收75%伤害
//      75%几率小幅吸收伤害 吸收33%伤害
//800级 37.5%几率反弹伤害 反弹75%伤害，封顶2000 吸收75%伤害
//      52.5%几率大幅吸收伤害 吸收90%伤害
//      87.5%几率小幅吸收伤害 吸收50%伤害
//无穷级 45%几率反弹伤害 反弹90%伤害，封顶2000 吸收70%伤害
//       60%几率大幅吸收伤害 吸收90%伤害
//       95%几率小幅吸收伤害 吸收60%伤害
//by seagate@pkuxkx
	if ( randnum < to_int(ceil(pp/2*ratio)) &&
		   defender->query("neili") > qdamage/15 )
	{
		if ( qdamage<0 ) error(sprintf("伤害负值尽快报告巫师！关键信息：伤害：%d, 几率：%.2lf，命中率：%d %d", qdamage, ratio, ap, pp));
		attacker->receive_damage("qi", qdamage, defender );
		result += COMBAT_D->damage_msg(damage, "反弹伤");
		defender->set_temp("反震成功",1);
		sdamage=damage*(1-ratio/3);
		defender->add("neili",-qdamage/15);
	}
	else if ( randnum < to_int(ceil(pp/2*(0.3+ratio))) &&
		   defender->query("neili") > qdamage/25 )
	{
		sdamage=damage*ratio*3/2;
		if ( sdamage > damage*9/10 )
			sdamage=damage*9/10;
		defender->add("neili",-qdamage/25);
	}
	else if ( randnum < to_int(ceil(pp/2*(1+ratio))) &&
		   defender->query("neili") > qdamage/40 )
	{
		sdamage=damage*ratio*2/3;
		defender->add("neili",-qdamage/40);
	}
	else 
		return -1;

	if ( !attacker->query_temp("jingang-buhuai/dodge") )
	{
	  attacker->add_temp("apply/dodge", -abs_lv/5);
	  attacker->add_temp("apply/dexerity", -abs_lv/100);
	  attacker->set_temp("jingang-buhuai/dodge", abs_lv/5);
    attacker->set_temp("active_debuff/jingang-buhuai/name", "金刚不坏神功");                       //buff名称
    attacker->set_temp("active_debuff/jingang-buhuai/last_time", time() + 2 );                     //持续时间
    attacker->set_temp("active_debuff/jingang-buhuai/effect1", "轻功技能-"+(abs_lv/5)+"级");       //效果描述1
    attacker->set_temp("active_debuff/jingang-buhuai/effect2", "后天身法-"+(abs_lv/100)+"级");     //效果描述1
	  call_out("remove_iron_eff", 2, attacker, abs_lv);
	}	
	return ({sdamage, result});
}

void remove_iron_eff(object me, int debuf)
{
	if (me)
	{
		me->delete_temp("jingang-buhuai/dodge");
		me->add_temp("apply/dodge",debuf/5);
		me->add_temp("apply/dexerity",debuf/100);
		me->delete_temp("active_debuff/jingang-buhuai");
	}
}
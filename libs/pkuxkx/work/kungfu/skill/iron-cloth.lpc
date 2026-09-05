// iron-cloth.c

inherit SKILL;

string *absorb_msg = ({
	"$n已有准备，不慌不忙的运起铁布衫。\n",
        "$n闭目凝神，气走全身，护体硬功达到巅峰状态。\n",
        "$n「嘿」的一声，不躲不闪，运起铁布衫迎向$N！\n",
});

string query_absorb_msg()
{
	return absorb_msg[random(sizeof(absorb_msg))];
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
  
	abs_lv=(int)defender->query_skill("iron-cloth",1);
  randnum = (int)random(ap/2 + pp/2);
  if ( abs_lv<=400 )
  {
    ratio=ap*1.0/pp/1200*abs_lv;
    if ( ratio>0.33 )
     	ratio=0.33;
  }
  else if ( abs_lv<=800 )
  {
    ratio=ap*0.33/pp+ap*0.33/pp/2400*abs_lv;
    if ( ratio>0.44 )
    	ratio=0.44;
  }
  else 
  {
   	ratio=ap*0.44/pp+ap*0.44/pp/4800*abs_lv;
   	if ( ratio>0.6 )
   		ratio=0.6;
  }
  
	result +=query_absorb_msg();
	qdamage=to_int(ceil(damage*ratio*2/3));
	if ( qdamage>=4000 )
		qdamage=4000;

//基本硬功效果说明，假设ap=pp
//400级 8%几率反弹伤害 反弹22%伤害，封顶2000 吸收83.5%伤害
//      31%几率大幅吸收伤害 吸收49.5%伤害
//      66%几率小幅吸收伤害 吸收22%伤害
//800级 11%几率反弹伤害 反弹29%伤害，封顶2000 吸收78%伤害
//      37%几率大幅吸收伤害 吸收66%伤害
//      77%几率小幅吸收伤害 吸收29%伤害
//无穷级 15%几率反弹伤害 反弹40%伤害，封顶2000 吸收70%伤害
//       45%几率大幅吸收伤害 吸收90%伤害
//       80%几率小幅吸收伤害 吸收40%伤害
//by seagate@pkuxkx  
	if ( randnum < to_int(ceil(pp/2*ratio/2)) &&
		   defender->query("neili") > qdamage/20 )
	{
		attacker->receive_damage("qi", qdamage, defender );
		result += COMBAT_D->damage_msg(damage, "反弹伤");
		defender->set_temp("反震成功",1);
		sdamage=damage*(1-ratio/2);
		defender->add("neili",-qdamage/20);
	}
	else if ( randnum < to_int(ceil(pp/2*(0.3+ratio))) &&
		   defender->query("neili") > qdamage/25 )
	{
		sdamage=damage*ratio*3/2;
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
	
	if ( !attacker->query_temp("iron-cloth/dodge") )
	{
	  attacker->add_temp("apply/dodge", -abs_lv/2);
	  attacker->add_temp("apply/dexerity", -abs_lv/50);
	  attacker->set_temp("iron-cloth/dodge", abs_lv/2);
    attacker->set_temp("active_debuff/iron-cloth/name", "铁布衫");                       //buff名称
    attacker->set_temp("active_debuff/iron-cloth/last_time", time() + 2 );               //持续时间
    attacker->set_temp("active_debuff/iron-cloth/effect1", "轻功技能-"+(abs_lv/2)+"级"); //效果描述1
    attacker->set_temp("active_debuff/iron-cloth/effect2", "后天身法-"+(abs_lv/50)+"级");//效果描述1
	  call_out("remove_iron_eff", 2, attacker, abs_lv);
	}
	return ({sdamage, result});
}

void remove_iron_eff(object me, int debuf)
{
	if (me)
	{
		me->delete_temp("iron-cloth/dodge");
		me->add_temp("apply/dodge",debuf/2);
		me->add_temp("apply/dexerity",debuf/50);
		me->delete_temp("active_debuff/iron-cloth");
	}
}
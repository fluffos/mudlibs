//kungfu.c
//主要存放exert/perform效果的公共函数库
#include <ansi.h>
float kungfu_wrongpct(object ob);

//命中率函数(满足random(A)=random(B)*q的命中率公式)
//命中率rate_level数值范围是0到18，一共19个级别，效果从命中率95%到5%
//提供了命中率级别接口，对于攻击方提供apply/kf_hit_rate属性来上调命中率级别，最多三级
//                      对于防御方提供apply/kf_anti_hr属性来下调命中率级别，最多5级
//描述级别：S级别95%，A级别85%，B级别70%，C级别55%，D级别40%，E级别25%，F级别10%，F-级别是最低级5%，除了S级每个级别有+-修正级别，分别修正+-5%
int hit_rate(int owner_data, int target_data, int rate_level, object owner, object target)
{
  int *rate_coef=({1000, 500, 333, 250, 200, 167, 143,   //S到B-
                         125, 111, 100, 90,  80,  70,    //C+到D-
                         60,  50,  40,  30,  20,  10});  //E+到F-
  int idata1, idata2;
  int owner_hr, target_hr;
//数据初始化，保证数据足够大，使得概率更准确一点  
  if ( owner_data<1000 && target_data<1000 )
  {
    idata1=owner_data*100;
    idata2=target_data*100;
  }
  else if ( owner_data>=100000000 || target_data>=100000000 )
  {
    idata1=owner_data/1000;
    idata2=target_data/1000;
  }
  else if ( owner_data>=10000000 || target_data>=10000000 )
  {
    idata1=owner_data/100;
    idata2=target_data/100;
  }
  else if ( owner_data>=1000000 || target_data>=1000000 )
  {
    idata1=owner_data/10;
    idata2=target_data/10;
  }
  else
  {
    idata1=owner_data;
    idata2=target_data;
  }
  
  //命中率受到发起方先天身法的影响，调整几率范围大致在-10%到+10%区间内
  idata1=idata1*(owner->query("dex")+150)/180;
//如果是负数或者0，则置最小值1  
  if ( idata1<=0 )
    idata1=5;
  
  if ( idata2<=0 )
    idata2=5;

//命中率级别调整检查，对于攻击方提供kf_hit_rate属性来上调命中率级别
//                    对于防御方提供kf_anti_hr属性来下调命中率级别
  if ( objectp(owner) && ( owner_hr=owner->query_enhance("HitRate") ) )
  {
    //攻击者只能最多上调命中率级别三级
    if ( owner_hr>3 )
      owner_hr=3;
    if ( owner_hr<-5 )
      owner_hr=-5;
      
    rate_level-=owner_hr;
  }
  
  if ( objectp(target) && ( target_hr=target->query_proof("AntiHitRate") ) )
  {
    //防御者只能最多下调命中率级别5级
    if ( target_hr>5 )
      target_hr=5;//修改by yhzzyahoo
    if ( target_hr<0 )
      target_hr=0;
    
    rate_level+=target_hr;
  }

//削减命中率，在高命中率级别idata2/idata1比值过大区间命中率下跌速度不够快速  
  if ( idata2>=idata1*2 && rate_level<=11 && rate_level>6 )
    rate_level++;
  else if ( idata2>=idata1*2 && rate_level<=6 && rate_level>3 )
    rate_level+=2;
  else if ( idata2>=idata1*2 && rate_level<=3 )
    rate_level+=3;
    
//提升命中率，在低命中率级别idata1/idata2过大区间命中率上升速率不够快速
  if ( idata1>=idata2*2 && rate_level<15 && rate_level>=12 )
    rate_level--;
  else if ( idata1>=idata2*2 && rate_level>=15 )
    rate_level-=2;
  
  if ( rate_level<0 )
    rate_level=0;
  
  if ( rate_level>18 )
    rate_level=18;
  
  if ( random(idata1)>random(idata2)*100/rate_coef[rate_level] )
    return 1;
  else
    return 0;
}

//一个简化版的命中函数，这个函数基本只在100-10000之间的数进行比较用，一般是sk判定
//为降低计算量做的努力by yhzzyahoo
int hit_rate_sk(int owner_data, int target_data, int rate_level, object owner, object target)
{
  int *rate_coef=({1000, 500, 333, 250, 200, 167, 143,   //S到B-
                         125, 111, 100, 90,  80,  70,    //C+到D-
                         60,  50,  40,  30,  20,  10});  //E+到F-
  int *dex_tz=({-3,-3,-3,-3,-3,-3,-3,-3,-3,-2,
				-2,-2,-2,-2,-2,-2,-2,-2,-1,-1,
				-1,-1,-1,-1,-1,-1,0,0,0,0,
				0,0,0,0,1,1,1,1,1,1,
				1,1,2,2,2,2,2,2,2,3,
				3});
  int idata1, idata2;
  int owner_hr, target_hr;
  int t=owner->query("dex")-1;
  //命中率受到发起方先天身法的影响，调整几率范围大致在-10%到+10%区间内
//  idata1=idata1*(owner->query("dex")+150)/180;
  if (t>50)
	t=50;
  //去掉除法算法，只用查表
  rate_level-=dex_tz[t];

  idata1=owner_data;
  idata2=target_data;
//如果是负数或者0，则置最小值1  
//小心，不做负判断，要在用这个函数的时候小心 by yhzzyahoo
  /*if ( idata1<=0 )
    idata1=5;
  
  if ( idata2<=0 )
    idata2=5;
*/

//命中率级别调整检查，对于攻击方提供kf_hit_rate属性来上调命中率级别
//                    对于防御方提供kf_anti_hr属性来下调命中率级别
  if ( objectp(owner) && ( owner_hr=owner->query_enhance("HitRate") ) )
  {
    //攻击者只能最多上调命中率级别三级
    if ( owner_hr>3 )
      owner_hr=3;
    if ( owner_hr<-5 )
      owner_hr=-5;
      
    rate_level-=owner_hr;
  }
  
  if ( objectp(target) && ( target_hr=target->query_proof("AntiHitRate") ) )
  {
    //防御者只能最多下调命中率级别5级
    if ( target_hr>5 )
      target_hr=5;//修改by yhzzyahoo
    if ( target_hr<0 )
      target_hr=0;
    
    rate_level+=target_hr;
  }
//削减命中率，在高命中率级别idata2/idata1比值过大区间命中率下跌速度不够快速  
if ( idata2>=idata1*2 )
	rate_level+=2;
 
//提升命中率，在低命中率级别idata1/idata2过大区间命中率上升速率不够快速
  if ( idata1>=idata2*2 )
    rate_level--;

  if ( rate_level<0 )
    rate_level=0;
  
  if ( rate_level>18 )
    rate_level=18;

   if ( random(idata1)*rate_coef[rate_level]>random(idata2)*100)
	//  message_vision("pfm1成功",owner,target);
		return 1;
  else
	 // message_vision("pfm1失败",owner,target);
	  return 0;

/*  if ( random(idata1)>random(idata2)*100/rate_coef[rate_level] )
	{
	  message_vision("pfm2成功",owner,target);
    return 1;
	}
  else
	{
	  message_vision("pfm2失败",owner,target);
    return 0;
	}*/
}

//命中率函数(满足random(A)=random(B)*q+p的命中率公式)
//命中率rate_level数值范围是0到18，一共19个级别，效果从命中率95%到5%
//提供了命中率级别接口，对于攻击方提供apply/kf_hit_rate属性来上调命中率级别，最多三级
//                      对于防御方提供apply/kf_anti_hr属性来下调命中率级别，最多三级
//描述级别：S级别95%，A级别85%，B级别70%，C级别55%，D级别40%，E级别25%，F级别10%，F-级别是最低级5%，除了S级每个级别有+-修正级别，分别修正+-5%
// adjust_par数据取值最好能等于或者小于A/B数据一个量级，否则动态调整数值的时候有可能会造成溢出，或者影响因子过于小
int hit_rate2(int owner_data, int target_data, int adjust_par, int rate_level, object owner, object target)
{
  int *rate_coef=({1000, 500, 333, 250, 200, 167, 143,   //S到B-
                         125, 111, 100, 90,  80,  70,    //C+到D-
                         60,  50,  40,  30,  20,  10});  //E+到F-
  int idata1, idata2, apar;
  int owner_hr, target_hr;
//数据初始化，保证数据足够大，使得概率更准确一点  
  if ( owner_data<1000 && target_data<1000 )
  {
    idata1=owner_data*100;
    idata2=target_data*100;
    apar=adjust_par*100;
  }
  else if ( owner_data>=100000000 || target_data>=100000000 )
  {
    idata1=owner_data/1000;
    idata2=target_data/1000;
    apar=adjust_par/1000;
  }
  else if ( owner_data>=10000000 || target_data>=10000000 )
  {
    idata1=owner_data/100;
    idata2=target_data/100;
    apar=adjust_par/100;
  }
  else if ( owner_data>=1000000 || target_data>=1000000 )
  {
    idata1=owner_data/10;
    idata2=target_data/10;
    apar=adjust_par/10;
  }
  else
  {
    idata1=owner_data;
    idata2=target_data;
    apar=adjust_par;
  }
  
  //命中率受到发起方先天身法的影响，调整几率范围大致在-10%到+10%区间内
  idata1=idata1*(owner->query("dex")+150)/180;
//如果是负数或者0，则置最小值1  
  if ( idata1<=0 )
    idata1=1;
  
  if ( idata2<=0 )
    idata2=1;

//命中率级别调整检查，对于攻击方提供kf_hit_rate属性来上调命中率级别
//                    对于防御方提供kf_anti_hr属性来下调命中率级别
  if ( objectp(owner) && ( owner_hr=owner->query_enhance("HitRate") ) )
  {
    //攻击者只能最多上调命中率级别三级
    if ( owner_hr>3 )
      owner_hr=3;
    if ( owner_hr<-5 )
      owner_hr=-5;
      
    rate_level-=owner_hr;
  }
  
  if ( objectp(target) && ( target_hr=target->query_proof("AntiHitRate") ) )
  {
    //防御者只能最多下调命中率级别5级
    if ( target_hr>5 )
      target_hr=5;//fix by yhzzyahoo
    if ( target_hr<0 )
      target_hr=0;
    
    rate_level+=target_hr;
  }

//削减命中率，在高命中率级别idata2/idata1比值过大区间命中率下跌速度不够快速  
  if ( idata2>=idata1*2 && rate_level<=11 && rate_level>6 )
    rate_level++;
  else if ( idata2>=idata1*2 && rate_level<=6 && rate_level>3 )
    rate_level+=2;
  else if ( idata2>=idata1*2 && rate_level<=3 )
    rate_level+=3;
    
//提升命中率，在低命中率级别idata1/idata2过大区间命中率上升速率不够快速
  if ( idata1>=idata2*2 && rate_level<15 && rate_level>=12 )
    rate_level--;
  else if ( idata1>=idata2*2 && rate_level>=15 )
    rate_level-=2;
  
  if ( rate_level<0 )
    rate_level=0;
  
  if ( rate_level>18 )
    rate_level=18;
  
//  printf("A=%d,B=%d, 1/q=%d,p=%d,level=%d\n", idata1, idata2, rate_coef[rate_level], apar, rate_level);  
  if ( random(idata1)>random(idata2)*100/rate_coef[rate_level]+apar )
    return 1;
  else
    return 0;
}


//化学伤害封装函数
//type就是receive_damage和receive_wound里面的伤害类型，damage不为0调用receive_damage函数，
//wound不为0调用receive_wound函数
//提供属性apply/kf_def_wound 体现对化学伤害的抗性
//提供属性apply/kf_wound 体现对化学伤害的增益
//提供属性apply/kf_abs_def 体现对化学伤害的绝对抗性，绝对抗性最高提供25%的抗性。 
void hit_wound(string type, int damage, int wound, object owner, object target)
{
  int h_damage, h_wound, def_pc, inc_pc, sum_pc, abs_def;
  string skill;
  mapping force_effect;

//缺少攻击者或者防御者将不会调用伤害函数  
  if ( !objectp(owner) || !objectp(target) )
    return;
  //真斗转星移，反击效果
  // 添加一个参数：某些情况下也可能使真斗转星移失效 by lordstar 20180515
  if (target->query_temp("zhen-douzhuan")
		&& !owner->query_temp("apply/cannot_be_absorbed"))
  {
	  int i = random(target->query_temp("zhen-douzhuan")+1);
	  if (i > 2 && target->query("neili")>3000)
	  {	  
		  message_vision("$N"+HIR"轻移身形,早展开慕容家成名绝技--斗转星移，将$n的攻击反击了回来！ \n"NOR,target, owner);
		  def_pc=owner->query_proof("AntiChem");  //目标的技能伤害抗性
		  inc_pc=target->query_enhance("Chem");     //攻击者的技能伤害增益
		  abs_def=owner->query_temp("apply/kf_abs_def");   //目标的技能伤害绝对抗性

		  if ( abs_def <=0 )
			abs_def=0;
		  if ( abs_def > 25 )
			abs_def=25;
			
		  if ( def_pc > 100 )
			def_pc=100;
		  if ( def_pc < -400 )              //对于增益部分放开到400%
			def_pc=-400;
		  if ( inc_pc > 400 )
			inc_pc=400;
		  if ( inc_pc < -100 )
			inc_pc=-100;
		  
		  //综合增益在-75%到+100%之间
		  sum_pc=inc_pc-def_pc;
		  if ( sum_pc>400 )                 //对于增益部分放开到400%
			sum_pc=400;
		  if ( sum_pc<-50 )
			sum_pc=-50;
		  
		  sum_pc=sum_pc-abs_def;            //绝对抗性产生作用
			
		  h_damage=damage*(100+sum_pc)/100;
		  h_wound=wound*(100+sum_pc)/100;
		  
		  if ( h_damage )
		  {
			owner->receive_damage(type, h_damage, owner);
		  }
		  
		  if ( h_wound )
		  {
			owner->receive_wound(type, h_wound, owner);
		  }
		  target->add("neili",-400);
		COMBAT_D->report_status(owner);
	  return;

	  }
	  else if (i>0 && target->query("neili")>2000)
	  {
		  message_vision("$N"+HIR"轻移身形，展开慕容家成名绝技「斗转星移」，将$n的攻击移转开去！ \n"NOR,target, owner);
		  target->add("neili",-200);
		  return;
	  }
  }
  
  def_pc=target->query_proof("AntiChem");  //目标的技能伤害抗性
  inc_pc=owner->query_enhance("Chem");     //攻击者的技能伤害增益
  abs_def=target->query_temp("apply/kf_abs_def");   //目标的技能伤害绝对抗性

  if ( abs_def <=0 )
    abs_def=0;
  if ( abs_def > 25 )
    abs_def=25;
    
  if ( def_pc > 100 )
    def_pc=100;
  if ( def_pc < -400 )              //对于增益部分放开到400%
    def_pc=-400;
  if ( inc_pc > 400 )
    inc_pc=400;
  if ( inc_pc < -100 )
    inc_pc=-100;
  
  //综合增益在-75%到+100%之间
  sum_pc=inc_pc-def_pc;
  if ( sum_pc>400 )                 //对于增益部分放开到400%
    sum_pc=400;
  if ( sum_pc<-50 )
    sum_pc=-50;
  
  sum_pc=sum_pc-abs_def;            //绝对抗性产生作用
    
  h_damage=damage*(100+sum_pc)/100;
  h_wound=wound*(100+sum_pc)/100;
  
  // 增加一个内功吸收化学伤害的接口。by lordstar 20171121
  if (skill = target->query_skill_mapped("force"))
  {
	if (mapp(force_effect = SKILL_D(skill)->absorb(target, owner, type, h_damage, h_wound, "Chem") ))
	{
		if (force_effect["damage"]>0)
		{
			if (h_damage>force_effect["damage"])
				h_damage -= force_effect["damage"];
			else 
				h_damage = 0;
		}
		if (force_effect["wound"]>0)
		{
			if (h_damage>force_effect["wound"])
				h_wound -= force_effect["wound"];
			else 
				h_wound = 0;
		}
		if (force_effect["eff_msg"])
			message_vision( force_effect["eff_msg"], target, owner);
	}
  }
  if ( h_damage )
    target->receive_damage(type, h_damage, owner);
  
  if ( h_wound )
    target->receive_wound(type, h_wound, owner);
}

//busy封装函数
//type是busy类型，分为点穴（dianxue）、截脉（jiemai）、分筋错骨（fenjin）、压制（confuse）、缠绕（body）
//                    五种busy类型
//提供了cant_all_busy(apply/cant_all_busy)、"cant_busy_"+type("apply/cant_busy_"+type)属性表示免疫所有busy类型
//      和免疫某一种具体busy类型
//提供了max_all_busy(apply/max_all_busy)、"max_busy_"+type("apply/max_busy_"+type)属性表示所有busy类型最多只能
//      busy多少秒，或者某一种busy类型最多只能busy多少秒。
void hit_busy(string type, int busy_time, object target)
{
  int b_time, max_bt;
  int at_all, at_type;
  
  if ( !objectp(target) )
    return;
 //  write("斗转测试：发动busy斗转\n");
 
  if (target->query_temp("zhen-douzhuan"))
  {
	  if (random(target->query_temp("zhen-douzhuan")+1) > 1 && target->query("neili")>2000)
	  {
		  message_vision("$N"+HIR"轻移身形,施展慕容家成名绝技--斗转星移，将攻击化解为无形！ \n"NOR,target);
		  target->add("neili",-300);
		  return;
	  }
  }
  b_time=target->query_busy();
  if ( !busy_time )
    return;
  if (busy_time>120)
  {
	  busy_time=120;
  }
  if ( target->query("cant_all_busy") ||
       target->query_temp("apply/cant_all_busy") )
    return;
  
  if ( target->query("cant_busy_"+type) ||
       target->query_temp("apply/cant_busy_"+type) )
    return;
  
  if ( type!="dianxue" &&
       type!="jiemai" &&
       type!="fenjin" &&
       type!="confuse" &&
       type!="body" )
    error("错误的busy类型，目前仅支持点穴、截脉、分筋错骨、压制、缠绕五种类型。");
	
  at_type = (int)target->query_temp("apply/anti_busy_"+type);
  at_all = at_type + (int)target->query_temp("apply/anti_all_busy");
  
  if (userp(target))
  {
	  if (at_all>75) at_all = 75;
	  if (at_all<-300) at_all = -300;
  }
  else
  {
	  if (at_all>99) at_all = 99;
	  if (at_all<-500) at_all = -500;
  }
  if (at_all!=0 && busy_time>0)
	  busy_time += -1*busy_time*at_all/100;
  
  max_bt=target->query("max_all_busy");
  if ( !max_bt )
  {
    max_bt=target->query_temp("apply/max_all_busy");
    if ( !max_bt )
    {
      max_bt=target->query("max_busy_"+type);
      if ( !max_bt )
        max_bt=target->query("apply/max_busy_"+type);
    }
  }
  
  if ( max_bt &&
       busy_time>max_bt )
    busy_time=max_bt;
    
  if ( b_time>busy_time )
    return;
  
  target->start_busy(busy_time);
  target->set_temp("busy_stat/type", type);
  target->set_temp("busy_stat/time", time()+busy_time);
  return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//修炼内功的公共函数 by seagate@pkuxkx                                                      ///////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//是否能够修炼内功检查，并且返回潜能消耗系数，<0表示不能修炼该内功
int valid_xiulian(object me, string skill)
{
  mapping family_force=       //门派和内功映射关系，只能修炼本门内功或者公共武学的内功，无门派的可以修炼百姓内功
  ([
    "武当派":({"taiji-shengong"}),
    "少林派":({"hunyuan-yiqi","yijin-jing"}),
    "峨嵋派":({"linji-zhuang"}),
    "丐帮":({"huntian-qigong"}),
    "华山派":({"huashan-neigong","zixia-shengong","hunyuan-gong"}),
    "雪山派":({"xueshan-neigong"}),
    "全真派":({"xiantian-gong"}),
    "天地会":({"cangming-gong"}),
    "天龙寺":({"beiming-shengong","kurong-shengong","shanjue"}),
    "白驼山":({"hamagong"}),
    "大轮寺":({"longxiang-boruo"}),
    "日月神教":({"riyue-shengong","kuihua-shengong"}),
    "神龙教":({"shenlong-xinfa"}),
    "星宿派":({"huagong-dafa","beiming-shengong","xiaowuxiang-gong"}),
    "朝廷":({"bixue-xinfa"}),
    "古墓派":({"yunu-xinfa"}),
    "灵鹫宫":({"bahuang-gong","beiming-shengong","xiaowuxiang-gong"}),
    "明教":({"guangming-shenghuogong"}),
    "姑苏慕容":({"shenyuan-gong"}),
    "桃花岛":({"bihai-shengong"}),
    "百姓":({"taiyi-shengong"}),
    "侠客岛":({"xiake-shengong"}),
    "公共武学":({"jiuyin-shengong","chuforce","xixing-dafa"}) ]);
    string fname,sname1,sname2,sname3;
    int expm, outpar;

    if ( time()-me->query("wrong_status")<0 )
  {
    tell_object(me, "你体力真气混乱，短时间内无法再修炼内功。\n");
    return -1;
  }

  fname=me->query("family/family_name");
  outpar=0;
  if ( fname && 
       member_array(skill,family_force[fname])<0 &&
       member_array(skill,family_force["公共武学"])<0 )
  {
    fname=me->query("chushi/last_family");
	sname1=me->query("tqt/old_family1");
	sname2=me->query("tqt/old_family2");
	sname3=me->query("tqt/old_family3");
    expm=me->query("combat_exp")/1000000;
   		 if ( fname &&  member_array(skill, family_force[fname])>=0 && 
		 	expm>=250 && me->query_skill(skill, 1)<800+((expm-200)/50)*100)
   		 	{
      			outpar=(expm-200)/50;
   		 	}
    		else
    			{    
    			if ( sname1 && member_array(skill, family_force[sname1])>=0 && 
		 	expm>=250 && me->query_skill(skill, 1)<800+((expm-200)/50)*100)
    				{
      				outpar=(expm-200)/50;
				return outpar;					
    				}
    			if ( sname2 && member_array(skill, family_force[sname2])>=0 && 
		 	expm>=250 && me->query_skill(skill, 1)<800+((expm-200)/50)*100)
    				{
      				outpar=(expm-200)/50;
				return outpar;
    				}
    			if ( sname3 && member_array(skill, family_force[sname3])>=0 && 
		 	expm>=250 && me->query_skill(skill, 1)<800+((expm-200)/50)*100)
    				{
      				outpar=(expm-200)/50;
				return outpar;					
    				}
			tell_object(me, "只能修炼本门内功或者公共内功，要么你功夫未到，不能兼修其他门派内功。\n");
	  		return -1;
			
    			}
		
	
  }
  
  if ( !fname &&
       member_array(skill,family_force["百姓"])<0 &&
       member_array(skill,family_force["公共武学"])<0 )
  {
    fname=me->query("chushi/last_family");
	sname1=me->query("tqt/old_family1");
	sname2=me->query("tqt/old_family2");
	sname3=me->query("tqt/old_family3");
    expm=me->query("combat_exp")/1000000;
   		 if ( fname &&  member_array(skill, family_force[fname])>=0 && 
		 	expm>=250 && me->query_skill(skill, 1)<800+((expm-200)/50)*100)
   		 	{
      			outpar=(expm-200)/50;
   		 	}
    		else
    			{    
    			if ( sname1 && member_array(skill, family_force[sname1])>=0 && 
		 	expm>=250 && me->query_skill(skill, 1)<800+((expm-200)/50)*100)
    				{
      				outpar=(expm-200)/50;
				return outpar;					
    				}
    			if ( sname2 && member_array(skill, family_force[sname2])>=0 && 
		 	expm>=250 && me->query_skill(skill, 1)<800+((expm-200)/50)*100)
    				{
      				outpar=(expm-200)/50;
				return outpar;					
    				}
    			if ( sname3 && member_array(skill, family_force[sname3])>=0 && 
		 	expm>=250 && me->query_skill(skill, 1)<800+((expm-200)/50)*100)
    				{
      				outpar=(expm-200)/50;
				return outpar;					
    				}
			tell_object(me, "只能修炼本门内功或者公共内功，要么你功夫未到，不能兼修其他门派内功。\n");
		  	return -1;
    			}
		
    }
  
  
  return outpar;
}

//计算修炼所需的潜能，aux_coef表示额外消耗潜能的百分比
//    aux_coef上不封顶，最小值-50%。
int xiulian_pot(int my_skill, int aux_coef)
{
  if ( aux_coef < -50 )
    aux_coef=-50;
  
  return my_skill*2*(100+aux_coef)/100;
}

//xl_con就是修炼用的折算跟骨值， factor是额外的递增系数，采用百分制，例如105表示增加5%速度，0和不递增同义
//算法：skill点潜能换skill*(3+random(con^0.5))点
void xiulian_improve(object me, int xl_con, int factor)
{
  string skill;
  int my_skill;
  int imp_skill;
  int wrpct, level;

  skill = me->query_temp("xiulian_skill");
  my_skill = me->query_skill(skill,1);
  if ( !factor ) 
    factor=100;

 // 把等级计算统一整合到special文件里去，便于修改和调整  by lordstar 20180328 
  level = SPECIAL_D("corporeity")->active_level(me);
  if (level>=2) 
  {
	if (me->query("con")>40)  factor+=35;
    else  factor+=30;
  }
  else if (level==1)
    factor+=20;
/*
  if (me->query("special_skill/corporeity"))
	{
	  if ((me->query("special_level/corporeity")>1)&& me->query("special_skill/constitution"))
	  {
		  if (me->query("con")>40)
		  {
			  factor+=35;
		  }
		  else
		  {
			  factor+=30;
		  }
	  }
	  else
		{
		factor+=20;
		}
	}
*/  
  imp_skill = my_skill * 2 * (30+random(pow((xl_con-4)*100.0,0.5)));
  imp_skill = imp_skill * SPEWEEK_D->query_xiulian_bonus()/100;//special week effect
  imp_skill = imp_skill * factor/100; 
  //全局控制的因子。用于超级狂欢周等。
  imp_skill = to_int(imp_skill*REWARD_D->get_global_factor("xiulian"));
  imp_skill = to_int(imp_skill*REWARD_D->get_special_user_factor(me));
  
  //增加对走火入魔的控制，存在走火入魔概率的时候会随时出现修为降低并且1分钟内无法运转真气
  wrpct=to_int(ceil(kungfu_wrongpct(me)*10000));
  if ( wrpct>0 && random(10000)<wrpct ) 
  {
    me->improve_skill(skill, -imp_skill/10);
    me->set("wrong_status",time()+60);
    message_vision( HIG"突然之间$N失去了对真气的控制，看来短时间内再也无法运转真气了。\n"NOR, me );
  }
  else
  {
    me->improve_skill(skill, imp_skill/10);
    message_vision( HIG"$N从玄幻之境回过神来，顿觉内功修为增进不小。\n"NOR, me );
  }
}

//寻找特定暗器，该暗器不限制必须已装备或者未装备，但是如果该暗器为amount类物件，装备手上的暗器为优先处理
//否则优先处理身上的暗器。
//输入参数：me为扔暗器的对象，此为必输项，thid为寻找特定暗器的暗器ID，此非必输项，并且如果不存在特殊ID的暗器
//会自动寻找其他暗器。
varargs object find_throwing(object me, string thid)
{
  object wp, wp2, tho, tp, aqn, *inv;
  int amt;
  mapping aqnbox;
  int slot, weight;
  string *aqkeys;
  
  if ( !objectp(me) )
    return 0;
  
  wp=me->query_temp("weapon");
  wp2=me->query_temp("secondary_weapon");
  aqn=present("anqi dai", me);  // 身上没有暗器时，从暗器袋里支出
  
  if( thid )
  {
    tp=present(thid, me);
    if ( objectp(tp) &&
         tp->query("skill_type")=="throwing" )
    {
      amt=tp->query_amount();
      if ( amt>1 )
      {
        tp->add_amount(-1);
        tho=new(base_name(tp));
        tho->set_amount(1);
        return tho;
      }
      else if ( tp->query("equipped") &&
        amt>0 )
      {
        tp->unequip();
        return tp;
      }
      else if ( !tp->query("equipped") )
        return tp;
    }
  
	if ( objectp(aqn) 
	   && aqn->query("anqi_package")=="throwing"
	   && me->query("anqi_package_count")>0 )
	{
		aqnbox = me->query("anqi_package_number");
		if (mapp(aqnbox) && sizeof(aqnbox))
		{
			if ( me->query("anqi_package_number/"+ thid )>0)
			{	
				me->add("anqi_package_number/"+ thid, -1);
				tho=new(me->query("anqi_package_slot/"+ thid));
				tho->set_amount(1);
				weight=tho->query("base_weight");
				if (weight>0) aqn->set_weight(aqn->query_weight()-weight);
				me->add("anqi_package_count",-1);
				if (me->query("anqi_package_count") <= 0)
				me->delete("anqi_package_count");
				if (!me->query("anqi_package_number/" + thid))
				{
					me->delete("anqi_package_number/" + thid);
					me->delete("anqi_package_slot/" + thid);
					me->delete("anqi_package_name/" + thid);
				}
				tell_object(me, HIC "你探手往" + aqn->query("name") + HIC + "中轻轻一摸，把" + tho->name() + HIC + "捏在手中！\n" NOR);
				message("vision", HIC "只见" + me->name() + HIC + "伸手在" + aqn->query("name") + HIC + "中一摸，把一件东西捏在了手中！\n" NOR, environment(me), ({ me }));
				tho->move(me);
				return tho;
			}
		}
	}   
  }
  
  if ( objectp(wp) && 
       wp->query("skill_type")=="throwing" )
  {
    amt=wp->query_amount();
    if ( amt>1 )
    {
      wp->add_amount(-1);
      tho=new(base_name(wp));
      tho->set_amount(1);
      return tho;
    }
    else if ( amt>0 )
    {
      wp->unequip();
      return wp;
    }
  }
  else if ( objectp(wp2) &&
            wp2->query("skill_type")=="throwing" )
  {
    amt=wp2->query_amount();
    if ( amt>1 )
    {
      wp2->add_amount(-1);
      tho=new(base_name(wp2));
      tho->set_amount(1);
      return tho;
    }
    else if ( amt>0 )
    {
      wp2->unequip();
      return wp2;
    }
  }
  

  inv=all_inventory(me);
  for(int lp=0;lp<sizeof(inv);lp++)
  {
    amt=inv[lp]->query_amount();
    if(inv[lp]->query("skill_type")!="throwing") 
      continue;
    if(inv[lp]->query("equipped")  )
      continue;
    if ( amt>1 )
    {
      inv[lp]->add_amount(-1);
      tho=new(base_name(inv[lp]));
      tho->set_amount(1);
      return tho;
    }
    else 
      return inv[lp];
  }
  
  if ( objectp(aqn) 
	   && aqn->query("anqi_package")=="throwing"
	   && me->query("anqi_package_count")>0 )
  {
    aqnbox = me->query("anqi_package_number");
	if (mapp(aqnbox) && sizeof(aqnbox))
	{
		if (sizeof(aqnbox)>0)
		{
			slot = 0;
		}
		else 
		{
			slot = random(sizeof(aqnbox));
		}
		aqkeys=keys(aqnbox);
		thid=aqkeys[slot];
		me->add("anqi_package_number/"+ thid, -1);
		tho=new(me->query("anqi_package_slot/"+ thid));
		tho->set_amount(1);
		weight=tho->query("base_weight");
		if (weight>0) aqn->set_weight(aqn->query_weight()-weight);
		me->add("anqi_package_count",-1);
		if (me->query("anqi_package_count") <= 0)
		me->delete("anqi_package_count");
		if (!me->query("anqi_package_number/" + thid))
		{
			me->delete("anqi_package_number/" + thid);
			me->delete("anqi_package_slot/" + thid);
			me->delete("anqi_package_name/" + thid);
		}
		tell_object(me, HIC "你探手往" + aqn->query("name") + HIC + "中轻轻一摸，把" + tho->name() + HIC + "捏在手中！\n" NOR);
		message("vision", HIC "只见" + me->name() + HIC + "伸手在" + aqn->query("name") + HIC + "中一摸，把一件东西捏在了手中！\n" NOR, environment(me), ({ me }));
		tho->move(me);
		return tho;
	}
  }		 
    
  
  return 0;
}

//返回自身内功走火入魔的几率
float kungfu_wrongpct(object ob)
{
  float pct, lmt;
  string force, tforce, *kf, tpf;
  mapping bforce;
  int sneili, tneili, lneili, suck, ftms, ltms, con, ext;
  
  force=ob->query_skill_mapped("force");
  if ( !stringp(force) )
  {
    tforce="force";
    FORCE->backup_neili(ob, "force");
  }
  else
  {
    tforce=force;
    if ( !stringp(tforce=SKILL_D(force)->translate(force)) )
      tforce=force;
    SKILL_D(force)->backup_neili(ob, force);
  }
  
  bforce=ob->query("backup_neili");
  if ( mapp(bforce) )
  {
    kf=keys(bforce);
    if ( !stringp(force) )
      suck=0;
    else
      suck=SKILL_D(force)->force_character("TYPE_SUCK_EFF");
    sneili=bforce[tforce]["max_neili"];
    tneili=0;
    ftms=0;
    ltms=0;
    for(int lp=0;lp<sizeof(kf);lp++)
    {
      if ( bforce[kf[lp]]["max_neili"]>sneili )
      {
        sneili=bforce[kf[lp]]["max_neili"];
        if ( bforce[kf[lp]]["force"] )
          suck=SKILL_D(bforce[kf[lp]]["force"])->force_character("TYPE_SUCK_EFF");
        else if ( kf[lp]!="force" )
          suck=SKILL_D(kf[lp])->force_character("TYPE_SUCK_EFF");
        else
          suck=0;
      }
      if ( kf[lp]!="force" && 
           bforce[kf[lp]]["max_neili"]>0 )
        ftms++;
      else 
        continue;
      tneili+=bforce[kf[lp]]["max_neili"];
      if ( bforce[kf[lp]]["max_neili"]>0 )
        lneili+=bforce[kf[lp]]["limit_neili"];
      if ( bforce[kf[lp]]["max_neili"]<=bforce[kf[lp]]["limit_neili"]/2 &&
           bforce[kf[lp]]["max_neili"]>0 )
        ltms++;
    }
    
    if ( !ftms )
      return 0.0;
    
    lneili=lneili-(ftms-1)*ob->query_skill("force",1)*5;
    if ( tneili<=lneili*3/4 &&
         ftms>1 &&
         ltms>=ftms-1 )
      lmt=0.6;
    else if ( tneili>lneili &&
         ftms>1 )
      lmt=1.25;
    else if ( bforce["xiaoyao-neigong"] &&
              bforce["xiaoyao-neigong"]["max_neili"]>0 &&
              bforce["xiaoyao-neigong"]["force"]=="xiaowuxiang-gong" )
      lmt=0.9;
    else
      lmt=1.0;
    
    //当内力中包含易筋经，并且易筋经大于500级，禅宗心法大于1000级则杂质含量减半
    if ( bforce["shaolin-neigong"] &&
         bforce["shaolin-neigong"]["max_neili"]>0 &&
         bforce["shaolin-neigong"]["force"]=="yijin-jing" &&
         ob->query_skill("yijin-jing",1)>=500 &&
         ob->query_skill("buddhism",1)>=1000 )
      suck=suck/2;
    
    sneili=sneili*(100-suck)/100;
    con=ob->query("con");
    if ( con>34 )
      ext=(con-34)/8;
    else
      ext=0;
    
    //当内力中包含小无相功，则兼容性+1，走火入魔概率-10%
    if ( bforce["xiaoyao-neigong"] &&
         bforce["xiaoyao-neigong"]["max_neili"]>0 &&
         bforce["xiaoyao-neigong"]["force"]=="xiaowuxiang-gong" )
      ext++;
    
    if ( ftms<=2+ext )
      return 1.0*lmt-sneili*1.0/tneili-0.3-(con-10)*0.005;
    else
      return 1.0*lmt*(10+ftms-2-ext)/10-sneili*1.0/tneili-0.3-(con-10)*0.005;
  }
  else
    return 0.0;
}

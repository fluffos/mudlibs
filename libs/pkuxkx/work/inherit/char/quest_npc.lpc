//quest_npc.c 
//主要用来统一任务npc的复制问题，仅解决基于family_npc的复制问题
//复制分为两种模式：
//模式一：基于玩家经验的复制模式。技能等级由经验计算出来
//模式二：基于玩家技能等级的复制模式。经验由技能等级计算出来

inherit FAMILY_NPC;

//自动装载武器
varargs void wield_weapon(string weapon)
{
        if(!weapon && query("use_weapon1"))
                wield_weapon(query("use_weapon1"));
        if(!weapon && query("use_weapon2"))
                wield_weapon(query("use_weapon2"));
        if(!weapon)
                return;
        switch(weapon)
        {
        case "sword":
                carry_object("/clone/weapon/changjian")->wield();
                break;
        case "blade":
                carry_object("/clone/weapon/gangdao")->wield();
                break;
        case "staff":
                carry_object("/clone/weapon/gangzhang")->wield();
                break;
        case "whip":
                carry_object("/clone/weapon/changbian")->wield();
                break;
        case "zhen":
                set("gender", "无性");
                carry_object("/d/city/obj/flower_shoe")->wear();
                carry_object("/d/city/obj/pink_cloth")->wear();
                carry_object("/d/city/obj/goldring")->wear();
                carry_object("/d/city/obj/necklace")->wear();
                carry_object("/d/quanzhou/obj/xiuhua")->wield();
                carry_object("/d/riyuejiao/obj/xiuhuajia");
                break;
        case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
                break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
        case "hammer":
                carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
                break;
        default:
        }
        return;
}

//基于模式一的经验和技能级别复制
//导入参数：
//    sk_mod：family_skill函数所需的门派信息
//    exp_fact：经验复制的系数，单位是百分制，也就是说输入80就是80%的意思
//    sk_fact：技能复制的系数，单位是百分制，也就是说输入80就是80%的意思
//    jl_fact：加力系数，单位是百分比，是技能等级的百分比值作为加力值
int es_copy1(object ob, string sk_mod, int exp_fact, int sk_fact, int jl_fact)
{
  object me=this_object();
  int level, adv, expf, skf, jlf;
  int rnd, advrt;
  string *bs_mod=({"dianxue", "jiemai", "fenjin", "confuse", "body"});

  rnd=random(10000)%100;
  advrt=ob->query("env/adv_quest");
  if ( advrt<10 )
    advrt=10;
  if ( advrt>50 )
    advrt=50;
  
  if ( wizardp(ob) )
    tell_object(ob, sprintf("困难模式：%d, 随机概率：%d， 困难几率：%d\n", ob->query("env/adv_quest"), rnd, advrt));
    
  if ( ob->query("env/adv_quest") &&
       rnd < advrt )
  {
    me->set_temp("advanced_quest", 1 );
    adv=1;
  }
  else 
  {
    me->set_temp("advanced_quest", 0 );
    adv=0;
  }
  
  if ( adv )
  {
    expf=exp_fact+25+random(25);
    skf=sk_fact+10+random(10);         //由于技能系数在经验复制的时候是expf系数立方根再乘上技能系数，所以这里少加点
    jlf=jl_fact+15+random(15);
    me->set("cant_busy_"+bs_mod[random(sizeof(bs_mod))],1);
    me->set_temp("apply/kf_def_wound", 20+random(20));
    me->set_temp("apply/week_injure", 20+random(20));
  }
  else
  {
    expf=exp_fact;
    skf=sk_fact;
    jlf=jl_fact;
  }
  
  me->set("combat_exp", ob->query("combat_exp")*expf/100);
  level=pow(ob->query("combat_exp")*expf/10000.0,1.0/3)*skf*10/100;
  me->set("jiali", level*jlf/100 );  
  
  //困难模式增加 jiali/10的基础伤害
  if ( adv )
    me->add_temp("apply/damage", level*jlf/1000 );
  
  family_skill(me, sk_mod, level, 1);
  return adv;
}

//基于模式二的经验和技能级别复制
//导入参数：
//    sk_mod：family_skill函数所需的门派信息
//    exp_fact：经验复制的系数，单位是百分制，也就是说输入80就是80%的意思
//    sk_fact：技能复制的系数，单位是百分制，也就是说输入80就是80%的意思
//    jl_fact：加力系数，单位是百分比，是技能等级的百分比值作为加力值
int es_copy2(object ob, string sk_mod, int exp_fact, int sk_fact, int jl_fact)
{
  object me=this_object();
  int exp, level, adv, lp, expf, skf, jlf;
  int rnd, advrt;
	mapping skl;
	string *sname;
  string *bs_mod=({"dianxue", "jiemai", "fenjin", "confuse", "body"});
  
  rnd=random(10000)%100;
  advrt=ob->query("env/adv_quest");
  if ( advrt<10 )
    advrt=10;
  if ( advrt>50 )
    advrt=50;
  if ( wizardp(ob) )
    tell_object(ob, sprintf("困难模式：%d, 随机概率：%d， 困难几率：%d\n", ob->query("env/adv_quest"), rnd, advrt));
  
  if ( ob->query("env/adv_quest") &&
       rnd < advrt )
  {
    me->set_temp("advanced_quest", 1 );
    adv=1;
  }
  else 
  {
    me->set_temp("advanced_quest", 0 );
    adv=0;
  }
  
  if ( adv )
  {
    expf=exp_fact+8+random(8);
    skf=sk_fact+20+random(10);        //技能有立方效应，系数少加点，经验系数随着技能系数立方乘积，也要少加
    jlf=jl_fact+15+random(15);
    me->set("cant_busy_"+bs_mod[random(sizeof(bs_mod))],1);
    me->set_temp("apply/kf_def_wound", 20+random(20));
    me->set_temp("apply/week_injure", 20+random(20));
  }
  else
  {
    expf=exp_fact;
    skf=sk_fact;
    jlf=jl_fact;
  }
  
	skl = ob->query_skills();
	if ( !skl ) {
		level=10;
	}
	else 
	{
	  level=10;
	  sname  = sort_array( keys(skl), (: strcmp :) );
	  for(lp=0; lp<sizeof(skl); lp++)
		  if ( intp(skl[sname[lp]]) && 
		       skl[sname[lp]] >= level && 
		       SKILL_D(sname[lp])->type() != "knowledge" )
			  level = skl[sname[lp]];
	}
	
  me->set("combat_exp", to_int(ceil(pow(level*skf/1000.0,3)*expf)));
  level=level*skf/100;
  me->set("jiali", level*jlf/100 ); 

  //困难模式增加 jiali/10的基础伤害
  if ( adv )
    me->add_temp("apply/damage", level*jlf/1000 );
  
  family_skill(me, sk_mod, level, 1);
  return adv;
}

//气血复制模式1（直接复制被复制者的气血，精神，内力）
//qx_fact: 气血和精神的复制系数，采用百分比为单位
//nl_fact: 内力的复制系数，采用百分比为单位
void qx_copy1(object ob, int qx_fact, int nl_fact)
{
  object me=this_object();
  
  if ( me->query_temp("advanced_quest") )
  {
    qx_fact=qx_fact+50;
    nl_fact=nl_fact+50;
  }
  
  me->set("max_qi", ob->query("max_qi")*qx_fact/100 );
  me->set("eff_qi", ob->query("max_qi")*qx_fact/100 );
  me->set("qi", ob->query("max_qi")*qx_fact/100 );
  me->set("max_jing", ob->query("max_jing")*qx_fact/100 );
  me->set("eff_jing", ob->query("max_jing")*qx_fact/100 );
  me->set("jing", ob->query("max_jing")*qx_fact/100 );
  me->set("max_neili", ob->query("max_neili")*nl_fact/100 );
  me->set("neili", ob->query("max_neili")*nl_fact/100 );
  me->set("max_jingli", ob->query("max_jingli")*nl_fact/100 );
  me->set("jingli", ob->query("max_jingli")*nl_fact/100 );
}

//气血复制模式2（固定基数）
//qx_fact: 气血和精神的复制系数，单位是倍数，比如100就是固定基数的100倍
//nl_fact: 内力的复制系数，单位是倍数
void qx_copy2(int base, int qx_fact, int nl_fact)
{
  object me=this_object();
  
  if ( me->query_temp("advanced_quest") )
  {
    qx_fact=qx_fact*150/100;
    nl_fact=nl_fact*150/100;
  }
  
  me->set("max_qi", base*qx_fact );
  me->set("eff_qi", base*qx_fact );
  me->set("qi", base*qx_fact );
  me->set("max_jing", base*qx_fact );
  me->set("eff_jing", base*qx_fact );
  me->set("jing", base*qx_fact );
  me->set("max_neili", base*nl_fact );
  me->set("neili", base*nl_fact );
  me->set("max_jingli", base*nl_fact );
  me->set("jingli", base*nl_fact );
}

//先天天赋设定，min是随机天赋的最小值，max是随机天赋的最大值。
void tf_set(int min, int max)
{
  object me=this_object();
  int mi, ma;
  
  mi=min;
  ma=max;
  
  if ( me->query_temp("advanced_quest") )
  {
    mi=mi+5;
    ma=ma+5;
  }
  
  if ( mi<10 ) mi=10;
  if ( mi>30 ) mi=30;
  if ( ma<mi ) ma=mi+10;
  if ( ma>50 ) ma=50;
  
  set("str", mi+random(ma-mi+1) );
  set("dex", mi+random(ma-mi+1) );
  set("int", mi+random(ma-mi+1) );
  set("con", mi+random(ma-mi+1) );
}
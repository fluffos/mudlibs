// attribute.c
// From ES2
// Modified by Xiang for XKX (12/15/95)
// 标准化对象和hp相关的属性：包括最大气血、最大精神、最大内力、最大精力
// 气血相关的自然恢复（治疗）、精神相关的自然恢复（治疗）、内力的自然恢复、精力的自然恢复
// by seagate@pkuxkx 2012/03/22
// 把kungfu.c 的 query_temp("apply/kf_hit_rate"),放在这里，用query_kf_hitrate()表示，
// 把kungfu.c 的 query_temp("apply/kf_anti_hr") 也放在这里，用query_kf_antirate()表示，上下调最多3级的限制仍然在kungfu.c实现
// 这里只是用函数返回结果，实现方式灵活一点 zine 2014/4/1

#include <dbase.h>
#include <skill.h>
#include <ansi.h>
#include <title.h>
#define VEIN3 10//第三层经脉最快和最早完成对临时四维的增加，全服一共就8个人。 Zine
#define VEIN3gift 2//第四层经脉通脉后增加的先天四维上线。 Zine
#define VEIN4gift 3//第四层经脉通脉后增加的先天四维上线。 Zine

//返回attribute文件的修改版本，主要用途是版本上线时候的无缝对接，避免由于版本上线而需要全服重启
int query_attr_version()
{
//版本返回值是更新版本的6位日期yymmdd，有需要的根据这个进行版本判定。
//140913版本主要用于内功被动特效设定上
//141125版本主要是调整了query_enhance函数和query_proof函数中对化学攻击的描述
//          kf_def_wound调整到query_proof，增加kf_wound到query_enhance
  return 141125;
}

//取得攻击增益函数
//Chem是化学攻击
//HitRate是技能命中
//PoisonRate是中毒
int query_enhance(string EnhanceType)
{
	int result;
	switch(EnhanceType)
	{
		case "Chem":
		result=to_int(query_temp("apply/kf_wound"));
		break;
		case "HitRate":
		result=to_int(query_temp("apply/kf_hit_rate"));
		break;
		case "PoisonRate":
		{
			result=to_int(query_temp("apply/poison_hit_rate"));
			result+=to_int(query("PoisonEnhance/Source/"+query_temp("tmp_calc/source")));
			result+=to_int(query_temp("apply/PoisonEnhance/Effect/"+query_temp("tmp_calc/eff_type")));
		}
		break;
		default:
		result=0;
	}
	return result;
}

//取得攻击抗性函数
//AntiChem是化学攻击
//AntiHitRate是技能命中
//AntiPoisonRate是中毒抗性
int query_proof(string DamageType)
{
	int result;
	string p_skill;
	switch(DamageType)
	{
		case "AntiChem":
			result=to_int(query_temp("apply/kf_def_wound"));
		break;
		case "AntiBusy":
			result=to_int(query_temp("apply/kf_anti_busy"));
		break;
		case "AntiHitRate":
		{
			result=to_int(query_temp("apply/kf_anti_hr"));
			p_skill=query_skill_mapped("parry");
			if(p_skill ) result+=SKILL_D(p_skill)->kf_antirate(this_object());
		}
		break;
		case "AntiPoisonRate":
		{
			result=to_int(query_temp("apply/poison_anti_hr"));
			result+=to_int(query("PoisonProof/Source/"+query_temp("tmp_calc/source")));
			result+=to_int(query_temp("apply/PoisonProof/Effect/"+query_temp("tmp_calc/eff_type")));
			p_skill=query_skill_mapped("force");
			if(p_skill ) result+=SKILL_D(p_skill)->poison_antirate(this_object());
		}
		break;
		default:
		result=0;
	}
	return result;
}
int query_str()
{
        int improve = 0, str;

        if ( query_skill("unarmed",1) ||
        	   query_skill("cuff", 1) ||
        	   query_skill("hand",1) || 
        	   query_skill("strike", 1) ||
        	   query_skill("finger",1) || 
        	   query_skill("claw", 1)||
               query_skill("leg",1))
        {
                if ( query_skill("cuff", 1) >= query_skill("unarmed", 1) && 
                	   query_skill("cuff", 1) >= query_skill("hand", 1) && 
                	   query_skill("cuff", 1) >= query_skill("strike", 1) && 
                	   query_skill("cuff", 1) >= query_skill("finger", 1) && 
                	   query_skill("cuff", 1) >= query_skill("claw", 1)&&
                       query_skill("cuff", 1) >= query_skill("leg", 1))
                        improve = (int)query_skill("cuff", 1) / 10;
                else if ( query_skill("unarmed", 1) >= query_skill("hand", 1) && 
                	        query_skill("unarmed", 1) >= query_skill("strike", 1) && 
                	        query_skill("unarmed", 1) >= query_skill("finger", 1) && 
                	        query_skill("unarmed", 1) >= query_skill("claw", 1)&&
                            query_skill("unarmed", 1) >= query_skill("leg", 1))
                        improve = (int)query_skill("unarmed", 1) / 10;
                else if ( query_skill("hand", 1) >= query_skill("strike", 1) && 
                	        query_skill("hand", 1) >= query_skill("finger", 1) && 
                	        query_skill("hand", 1) >= query_skill("claw", 1)&&
                            query_skill("hand", 1) >= query_skill("leg", 1))
                        improve = (int)query_skill("hand", 1) / 10;
                else if ( query_skill("strike", 1) >= query_skill("finger", 1) && 
                	        query_skill("strike", 1) >= query_skill("claw", 1)&&
                            query_skill("strike", 1) >= query_skill("leg", 1))
                        improve = (int)query_skill("strike", 1) / 10;
                else if ( query_skill("finger", 1) >= query_skill("claw", 1)&&
                        query_skill("finger", 1) >= query_skill("leg", 1))
                        improve = (int)query_skill("finger", 1) / 10;
                else if (query_skill("claw", 1) >= query_skill("leg", 1))
                        improve = (int)query_skill("claw", 1) / 10;
                else
                        improve = (int)query_skill("leg", 1) / 10;
        }
        
        str = (int)query("str") +  query_temp("apply/strength") + improve;
		str +=F_VEIN->AttrBonus(this_object(),"str");
        if ( str < 10 )
        	return 10;
        else
          return str;
}
int query_int()
{
  int final,tmp;
  final =(int)query("int") + query_temp("apply/intelligence")+(int)query_skill("literate", 1) / 10;
  if(query("special_skill/intellect")&&query("age")>=18)
    final += 10; //intellect加10点后天悟性,by whuan
  final +=F_VEIN->AttrBonus(this_object(),"int");
  if ( final < 10 )
  	return 10;
  else
    return final;
}

int query_con()
{
	int final;
	final=(int)query("con") + query_temp("apply/constitution") +
                (int)query_skill("force", 1) / 10;
	final +=F_VEIN->AttrBonus(this_object(),"con");
  if ( final < 10 )
  	return 10;
  else
    return final;
}

int query_dex()
{
	int final,tmp;
	final=(int)query("dex") + query_temp("apply/dexerity") +
                (int)query_skill("dodge", 1) / 10;
	final +=F_VEIN->AttrBonus(this_object(),"dex");
  if ( final < 10 )
  	return 10;
  else
    return final;
}

int query_kar()
{
  if ( query("kar") < 10 )
  	return 10;
  else
    return (int)query("kar");
}

int query_per()
{
	int final;
	final=(int)query("per")+ query_temp("apply/personality") +
                (int)query_skill("beauty", 1) / 20;
  if ( final < 10 )
  	return 10;
  else
    return final;
}

int query_spi()
{
  int final;
  final =(int)query("spi")+query_temp("apply/spirituality")+30;//先天默认30
  if(query("special_skill/spirituality")&&query("age")>=18)
  final += 10; //intellect加10点后天灵性性,by whuan       
  return final;  
}

//计算适用于战斗情况的后天臂力计算值
int combat_str()
{
	int xstr=query("str");
	int hstr=query_str(), cstr=0;
	
	if ( xstr< 10 )
		xstr=10;

	if ( hstr<=xstr*2 )
		cstr=hstr;
	else if ( hstr>xstr*2 &&
		        hstr<=xstr*4 )
		cstr=xstr*2+(hstr-xstr*2)/2;
  else if ( hstr>xstr*4 &&
  	        hstr<=xstr*8 )
  	cstr=xstr*3+(hstr-xstr*4)/4;
  else if ( hstr>xstr*8 &&
  	        hstr<=xstr*14 )
  	cstr=xstr*4+(hstr-xstr*8)/6;
  else if ( hstr>xstr*14 &&
  	        hstr<=xstr*22 )
  	cstr=xstr*5+(hstr-xstr*14)/8;
  else
  	cstr=xstr*6;
  
  return cstr;
}

//计算适用于战斗情况的后天身法计算值
int combat_dex()
{
	int xdex=query("dex");
	int hdex=query_dex(), cdex=0;
	
	if ( xdex< 10 )
		xdex=10;

	if ( hdex<=xdex*2 )
		cdex=hdex;
	else if ( hdex>xdex*2 &&
		        hdex<=xdex*4 )
		cdex=xdex*2+(hdex-xdex*2)/2;
  else if ( hdex>xdex*4 &&
  	        hdex<=xdex*8 )
  	cdex=xdex*3+(hdex-xdex*4)/4;
  else if ( hdex>xdex*8 &&
  	        hdex<=xdex*14 )
  	cdex=xdex*4+(hdex-xdex*8)/6;
  else if ( hdex>xdex*14 &&
  	        hdex<=xdex*22 )
  	cdex=xdex*5+(hdex-xdex*14)/8;
  else
  	cdex=xdex*6;
  
  return cdex;
}

//计算角色的最大气血，当角色为player的时候源于adm/daemons/race/humen.c算法
//当角色为npc的时候算法重新设置，大体是依赖于age和内力
int query_max_qi()
{
        mapping my;
        int xism_age, maxhp, addhp, lvc, lp;
        int tai_skill,huashan_skill,sep_force;
        string force;
        object ob=this_object();
        
        my = ob->query_entire_dbase();
        addhp=0;
        
        if(stringp(force = ob->query_skill_mapped("force")))
		      sep_force = (int)ob->query_skill(force, 1);
		    else
			    sep_force = (int)ob->query_skill(force, 1);
			  
			  if ( userp(ob) )  //玩家的气血认定
			  {
          if( my["age"] <= 14 ) 
          	maxhp = 100+sep_force*2;
          else if( my["age"] <= 30 ) 
          	maxhp = 100 + (my["age"] - 14) * my["con"]+sep_force*2;
          else if( my["age"] > 60 )
          {
//身负九阳神功、道家养生术、禅宗心法、大乘涅磐功的弟子不受岁月增加递减气血
//九阳神功变更为光明圣火功，玩家福利不变。by Zine
          	if ( ob->query_skill("guangming-shenghuogong", 1)>=120 ||
          		   ob->query_skill("taoism", 1)>=120 ||
          		   ob->query_skill("buddhism", 1)>=120 ||
          		   ob->query_skill("mahayana", 1)>=120 )
          	  maxhp = my["con"] * 16 + 100 + sep_force*2; 
          	else
          	  maxhp = my["con"] * 16 + 100 - (my["age"] - 60) * (6+(my["age"] - 60)/7) + sep_force*2;
          }
          else 
          	maxhp = my["con"] * 16 + 100 + sep_force*2;

          if( my["max_neili"] > 0 ) 
          	maxhp += my["max_neili"] / 4;

          my["base_hp"]=maxhp;
          
          tai_skill = (int)ob->query_skill("taiji-shengong", 1)/30;
    		  huashan_skill =(int)ob->query_skill("yangwu-jian", 1);

// 道家练气：３０岁前补气，３０岁后长气
          if( (xism_age=(int)ob->query_skill("taoism", 1)) > 39 )
          {
             xism_age = xism_age/2;
             if (my["age"] <= 30) 
             	xism_age -= my["age"];
             else 
             	xism_age -= 30;
             
             if ( xism_age > 0 && 
             	    xism_age * tai_skill > addhp )
             {
             	 maxhp = maxhp - addhp + xism_age * tai_skill;
             	 addhp = xism_age * tai_skill;
             }
          }
          
          if( my["level"] > 0 && my["level"]<=40 )
          { 
           	my["level_hp"]=to_int(my["level"]*my["con"]*pow(my["level"]*1.0,0.2)*pow(my["level"]/60.0,0.5));
          }
          else if ( my["level"]>40 )
          {
           	my["level_hp"]=to_int(my["level"]*my["con"]*pow(my["level"]*my["level"]*0.5/my["con"],(0.2+(my["level"]-20.0)/1000)));
          }
          else
            my["level_hp"]=0;

          my["level_ext_hp"]=0;
          if( my["level"] > 100 )
          {
            lvc=(my["level"]-100)/5;
            if ( lvc >0 )
            {
              for(lp=0;lp<lvc;lp++)
                my["level_ext_hp"]+=to_int(5*my["con"]*pow(my["level"]*1.0,0.5))*(lp+2)/2;
            }
           	my["level_ext_hp"]+=to_int((my["level"]-100-lvc*5)*my["con"]*pow(my["level"]*1.0,0.5))*(lvc+2)/2;
          };
          
          maxhp = maxhp+my["level_hp"]+my["level_ext_hp"];
        }
        else  //npc如果没有定义hp，则简化处理npc的气血问题，有需要再根据race进一步复杂化
        {
        	if( my["age"] <= 14 ) 
            maxhp = 1000 + sep_force*5;
          else 
            maxhp = 1000+ (my["age"] - 14) * my["con"]*2+sep_force*5;
        }
		//增加华山气宗养吾剑法最高加气7%.
		if (huashan_skill>1200&&ob->query("huashan_newskills/qizong"))
		{
			xism_age = pow(ob->query("combat_exp")/100.0,1.0/3)*10;
			if (huashan_skill>xism_age*4/5)
			{
				huashan_skill=7*(huashan_skill-1200)/(xism_age-1200);
				if (huashan_skill>7) huashan_skill=7;
				maxhp+=maxhp*huashan_skill/100;
			}
		}
//气血不超过30w阈值
		if (maxhp>300000&&my["id"]!="yhzzyahoo")
		{
			maxhp=300000;
		}
//如果query_temp定义了临时增加的hp，则临时增加角色气血        
        if ( ob->query_temp("apply/max_qi") )
        	maxhp+=query_temp("apply/max_qi");
        
        return maxhp;
}

//计算角色的最大精神，当角色为player的时候源于adm/daemons/race/humen.c算法
//当角色为npc的时候算法重新设置，大体是依赖于age
int query_max_jing()
{
        mapping my;
        int xism_age, maxmp, addmp, lvc;
        int hun_skill, lp;
        object ob=this_object();
        
        my = ob->query_entire_dbase();
        addmp=0;
		  
			  if ( userp(ob) )  //玩家的气血认定
			  {
          if( my["age"] <= 14 ) 
          	maxmp = 100;
          else if( my["age"] <= 30 ) 
          	maxmp = 100 + (my["age"] - 14) * my["int"];
          else if( my["age"] > 60 )
          { 
//身负九阳神功、道家养生术、禅宗心法、大乘涅磐功的弟子不受岁月增加递减精神          	
          	if ( ob->query_skill("guangming-shenghuogong", 1)>=120 ||
          		   ob->query_skill("taoism", 1)>=120 ||
          		   ob->query_skill("buddhism", 1)>=120 ||
          		   ob->query_skill("mahayana", 1)>=120 )
          	  maxmp = my["int"] * 16 + 100;
          	else
          		maxmp = my["int"] * 16 + 100 - (my["age"] - 60) * (6+(my["age"] - 60)/7);
          }
          else 
          	maxmp = my["int"] * 16 + 100;
          	
          if( my["max_jingli"] > 0 ) 
          	maxmp += my["max_jingli"] / 4;
          
          my["base_mp"]=maxmp;
          
          hun_skill = (int)ob->query_skill("hunyuan-yiqi", 1)/45;

// 佛家养精：３０岁前补精，３０岁后长精
          if( (xism_age=(int)ob->query_skill("buddhism", 1)) > 39 )
          {
            xism_age = xism_age/2;
            if (my["age"] <= 30) 
            	xism_age -= my["age"];
            else 
            	xism_age -= 30;
            
            if ( xism_age > 0 &&
            	   xism_age * hun_skill * 2 > addmp )
            {
            	maxmp = maxmp - addmp + xism_age * hun_skill * 2;
            	addmp = xism_age * hun_skill * 2;
            }
          }
          
          if((xism_age=(int)ob->query_skill("mahayana", 1)) > 39)
          {
            xism_age = xism_age/2;
            if (my["age"] <= 30) 
            	xism_age -= my["age"];
            else 
            	xism_age -= 30;
            
            if ( xism_age > 0 &&
            	   xism_age * ((int)ob->query_skill("linji-zhuang", 1)/30) > addmp )
            { 
            	maxmp = maxmp - addmp + xism_age *((int)ob->query_skill("linji-zhuang", 1)/30);
            	addmp = xism_age *((int)ob->query_skill("linji-zhuang", 1)/30);
            }
          }                
         	
          if( my["level"] > 0 && my["level"]<=40 ) 
          {
            my["level_mp"]=to_int(my["level"]*my["int"]*pow(my["level"]*1.0,0.17)*pow(my["level"]/60.0,0.5));
          }
          else if ( my["level"]>40 )
          {
            my["level_mp"]=to_int(my["level"]*my["int"]*pow(my["level"]*my["level"]*0.5/my["int"],(0.17+(my["level"]-20.0)/1000)));
          }
          else
            my["level_mp"]=0;

          my["level_ext_mp"]=0;
          if( my["level"] > 100 )
          {
            lvc=(my["level"]-100)/5;
            if ( lvc >0 )
            {
              for(lp=0;lp<lvc;lp++)
                my["level_ext_mp"]+=to_int(5*my["int"]*pow(my["level"]*1.0,0.4))*(lp*3+4)/4;
            }
            my["level_ext_mp"]+=to_int((my["level"]-100-lvc*5)*my["int"]*pow(my["level"]*1.0,0.4))*(lvc*3+4)/4;
          };
          
          maxmp=maxmp+my["level_mp"]+my["level_ext_mp"];
        }
        else
        {
        	if( my["age"] <= 14 ) 
            maxmp = 1000;
          else 
            maxmp = 1000+ (my["age"] - 14) * my["int"]*4;
        }
//最大精力限定        
		if (maxmp>300000&&my["id"]!="yhzzyahoo")
		{
			maxmp=300000;
		}

//如果query_temp定义了临时增加的精神，则临时增加角色精神
        if ( ob->query_temp("apply/max_jing") )
        	maxmp+=query_temp("apply/max_jing");
        
        return maxmp;
}

//增加特技对内力最大值的影响 by lordstar 20180327
protected int max_neili_buff(int max_neili, string force)
{
	int eff, buf, level;
	float pot;
	level = SPECIAL_D("corporeity")->active_level(this_object());
	if (level>1)
	{
		if ( stringp(force) )
			eff = SKILL_D(force)->force_character("TYPE_SPECIAL_NEILI_EFF");
		else 
			eff = 100;
		if (eff<=0) return max_neili;
		if (eff>200) eff = 200;
		switch (level)
		{
			case 2: buf = SPECIAL_D("corporeity")->maxneili_level2(); break;
			case 3: buf = SPECIAL_D("corporeity")->maxneili_level3(); break;
			default: buf = SPECIAL_D("corporeity")->maxneili_level4(); break;
		}
		pot = to_float(max_neili) * (100.0 + to_float(buf) * to_float(eff) / 100.0) / 100.0; 
		return to_int(pot);
	}
	return max_neili;
}
//计算角色的最大内力，当角色为player的时候源于adm/daemons/chard.c算法
//本算法实际上仅限于player。
//增加标志flag，当flag>0表示显示极限内力，否则显示最大内力
varargs int query_max_neili(int flag)
{
        mapping my;
        int maxneili, nlimit, neili_times, pot;
        object ob=this_object();
			  string force;
        
        my = ob->query_entire_dbase();
	      force=ob->query_skill_mapped("force");
	      if ( stringp(force) )
	      {
	        //如果内功中设置了特殊的计算最大内力方式，则以该内功的计算方式为主。
	        //主要目的是调整北冥的最大内力计算方式，把suck内力上限认定为最大内
	        //力上限，特设置特殊的内力调整入口
	        //by seagate
	        if ( maxneili=SKILL_D(force)->query_max_neili(ob) )
	        {
				maxneili = max_neili_buff(maxneili, force); 
	          if ( my["max_neili"]<maxneili &&
	               !flag )
	            return my["max_neili"];
	          else
	            return maxneili;
	        }
	        
		      neili_times=SKILL_D(force)->force_character("TYPE_NEILI");
		    }
		    else
		      neili_times=10;
		      
				nlimit=ob->query_skill("force");
				
				pot = nlimit * neili_times;
				pot = max_neili_buff(pot, force); 
				
				if ( flag>0 )
				  return pot;
				
			  if ( my["max_neili"] > pot &&
			  	   my["max_neili"] > 100)
				  maxneili = pot;
				else
			  	maxneili = my["max_neili"];
			  
			  return maxneili;
}

//内力以及其他一些东西的精纯度
//修改了精纯度的一些计算，避免了一些错误 by seagate@pkuxkx
int effective(string arg)
{
	int result, extra;
	if (arg=="neili")
	{
	  if ( userp(this_object()) )
	  {
	    if ( query("sucked_neili")>query_max_neili()-query("exercised_neili") )
	      set("sucked_neili", query_max_neili()-query("exercised_neili"));
	    if ( query("sucked_neili")<0 )
	      set("sucked_neili", 0);
	    
	    extra=query_max_neili()-query("exercised_neili")-query("sucked_neili");
	    if ( extra<0 )
	      extra=0;
	  
		  result=to_int(to_float(query("exercised_neili"))*1.0+to_float(query("sucked_neili"))*0.75+to_float(extra)*0.5);
		  return (result>query_max_neili())?query_max_neili():result;
		}
		else 
		{
		  if ( query("exercised_neili") || query("sucked_neili") )
		  {
	      extra=query_max_neili()-query("exercised_neili")-query("sucked_neili");
	      if ( extra<0 )
	        extra=0;
		    result=to_int(to_float(query("exercised_neili"))*1.0+to_float(query("sucked_neili"))*0.75+to_float(extra)*0.5);
		    return (result>query("max_neili"))?query("max_neili"):result;
		  }
		  else
		    return query("max_neili");
		}
	}
	return 0;
}

float pure_degree(string arg)
{
	float result;
	if (arg=="neili")
	{
	  if ( userp(this_object()) )
	  {
	    if ( !query_max_neili() )
	      return 0.0;
		  result=to_float(effective(arg))/to_float(query_max_neili());
		  return (result>1.0)?1.0:result;
		}
		else
		{
	    if ( !query("max_neili") )
	      return 0.0;
		  result=to_float(effective(arg))/to_float(query("max_neili"));
		  return (result>1.0)?1.0:result;
		}
	}
	if (arg=="exercised_neili")
	{
	  if ( userp(this_object()) )
	  {
	    if ( !query_max_neili() )
	      return 0.0;
		  result=to_float(query("exercised_neili"))/to_float(query_max_neili());
		  return (result>1.0)?1.0:result;
		}
		else
		{
	    if ( !query("max_neili") )
	      return 0.0;
	    if ( query("exercised_neili") )
	    {
	      result=to_float(query("exercised_neili"))/to_float(query_max_neili());
	      return (result>1.0)?1.0:result;
	    }
	    else
		    return 1.0;       //对于npc，默认值为100%
		}
	}
	return 0.0;
}
//计算角色的最大精力，当角色为player的时候源于adm/daemons/chard.c算法
//本算法实际上仅限于player。
int query_max_jingli()
{
        mapping my;
        int maxjingli, nlimit, jingli_times;
        object ob=this_object();
			  string force;
        
        my = ob->query_entire_dbase();
	      force=ob->query_skill_mapped("force");
	      if ( stringp(force) )
		      jingli_times=SKILL_D(force)->force_character("TYPE_JINGLI");
		    else
		      jingli_times=10;
		      
				nlimit=ob->query_skill("force");
			  if ( my["max_jingli"] > nlimit * jingli_times &&
			  	   my["max_jingli"] > 100)
				  maxjingli = nlimit * jingli_times;
				else
			  	maxjingli = my["max_jingli"];
			  
			  return maxjingli;
}

//计算角色的气血自然恢复速度
//每次heal_up()的平均时间间隔是9.5秒，用heal_up()原始恢复数据/9.5就是正常的平均每秒自然恢复速度
//9.5源于heart_beat()函数的tick=5+random(10)
int query_qi_recover()
{
	int greedy_flag = 0; //判断是否有greedy，whuan
  int medical, recv=0, recv_speed;
  mixed t_recv;
	object me = this_object();
	mapping my;
	
	medical = (int)me->query_skill("medical-skill", 1)/10; // 医术效果从/3变成/10
	if( (int)me->query("special_skill/greedy") && 
		  (int)me->query("age")>=18 )
    greedy_flag = 1; //有greedy特技，恢复速度加倍
	my = query_entire_dbase();
  
  recv_speed=me->query_temp("apply/qi_recover_speed");       //气血加速恢复倍率系数
  if ( !recv_speed )
  	recv_speed=100;
  
  if ( my["neili"]>my["max_neili"] * 2 || recv_speed>100 )
  {
    recv = my["con"] / 3 + my["max_neili"] / 10 * recv_speed/100 + medical;  // 最大内力影响的恢复从/5变成/10
    if (greedy_flag) 
  	  recv += my["con"] / 3 + my["max_neili"] / 5; //greedy的玩家额外恢复
  }
  else 
  {
    recv = my["con"] / 3 + my["neili"] / 20 * recv_speed/100 + medical;     //内力的影响从/10变成/20
    if (greedy_flag) 
  	  recv += my["con"] / 3 + my["neili"] / 10; //greedy的玩家额外恢复
  }
  
//qi_recover属性记录的是每秒恢复气血的数量，换算到recv要×9.5秒
  if ( (t_recv=me->query_temp("apply/qi_recover")) )
  {
  	if ( intp(t_recv) )
  	  recv+=t_recv*95/10;
  	else if ( floatp(t_recv) )
  		recv+=to_int(ceil(t_recv*9.5));
  }
  
  if ( recv<3 )
  	return 3;
  else
    return recv;
}

//计算角色的气血自然疗伤速度
int query_qi_cure()
{
	int greedy_flag = 0; //判断是否有greedy，whuan
  int medical, recv=0;
  mixed t_recv;
	object me = this_object();
	mapping my;
	
	medical = (int)me->query_skill("medical-skill", 1)/10;  // 医术效果从/3变成/10
	if( (int)me->query("special_skill/greedy") && 
		  (int)me->query("age")>=18 )
    greedy_flag = 1; //有greedy特技，恢复速度加倍
	my = query_entire_dbase();
  
	recv = medical/5;
  if (greedy_flag) 
  	recv += my["con"]/2;
  
//qi_cure属性记录的是每秒治疗气血的数量，换算到recv要×9.5秒
  if ( (t_recv=me->query_temp("apply/qi_cure")) )
  {
  	if ( intp(t_recv) )
  	  recv+=t_recv*95/10;
  	else if ( floatp(t_recv) )
  		recv+=to_int(ceil(t_recv*9.5));
  }
  
  if ( recv<1 )
  	return 1;
  else
    return recv;
}

//计算角色的精神自然恢复速度
int query_jing_recover()
{
	int greedy_flag = 0; //判断是否有greedy，whuan
  int medical, recv=0, recv_speed;
  mixed t_recv;
	object me = this_object();
	mapping my;
	
	medical = (int)me->query_skill("medical-skill", 1)/10;       // 医术效果从/3变成/10
	if( (int)me->query("special_skill/greedy") && 
		  (int)me->query("age")>=18 )
    greedy_flag = 1; //有greedy特技，恢复速度加倍
	my = query_entire_dbase();

  recv_speed=me->query_temp("apply/jing_recover_speed");       //气血加速恢复倍率系数
  if ( !recv_speed )
  	recv_speed=100;
  
  if ( my["jingli"] > my["max_jingli"] * 2 || recv_speed>100 )
  {
    recv = my["con"] / 3 + my["max_jingli"] / 10 * recv_speed/100 + medical;   // 最大精力的效果从/5 变成/10
    if (greedy_flag) 
  	  recv += my["con"] / 3 + my["max_jingli"] / 5; //greedy的玩家额外恢复
  }
  else
  {
    recv = my["con"] / 3 + my["jingli"] / 20 * recv_speed/100 + medical;       // 精力的效果从/10 变成/20
    if (greedy_flag) 
  	  recv += my["con"] / 3 + my["jingli"] / 10; //greedy的玩家额外恢复
  }
  
//jing_recover属性记录的是每秒恢复精神的数量，换算到recv要×9.5秒
  if ( (t_recv=me->query_temp("apply/jing_recover")) )
  {
  	if ( intp(t_recv) )
  	  recv+=t_recv*95/10;
  	else if ( floatp(t_recv) )
  		recv+=to_int(ceil(t_recv*9.5));
  }
  
  if ( recv<3 )
  	return 3;
  else
    return recv;
}

//计算角色的精神自然疗伤速度
int query_jing_cure()
{
	int greedy_flag = 0; //判断是否有greedy，whuan
  int medical, recv=0;
  mixed t_recv;
	object me = this_object();
	mapping my;
	
	medical = (int)me->query_skill("medical-skill", 1)/10;    // 医术效果从/3变成/10
	if( (int)me->query("special_skill/greedy") && 
		  (int)me->query("age")>=18 )
    greedy_flag = 1; //有greedy特技，恢复速度加倍
	my = query_entire_dbase();
  
	recv = medical/5;
  if (greedy_flag) 
  	recv += my["con"]/2;
  
//jing_cure属性记录的是每秒治疗精神的数量，换算到recv要×9.5秒
  if ( (t_recv=me->query_temp("apply/jing_cure")) )
  {
  	if ( intp(t_recv) )
  	  recv+=t_recv*95/10;
  	else if ( floatp(t_recv) )
  		recv+=to_int(ceil(t_recv*9.5));
  }
  
  if ( recv<1 )
  	return 1;
  else
    return recv;
}

//增加特技对内力恢复的影响 by lordstar 20180327
protected int neili_heal_buff()
{
	int level = SPECIAL_D("constitution")->active_level(this_object());
	if (level>1)
	{
		switch (level)
		{
			case 2: return SPECIAL_D("constitution")->neili_heal_level2();
			case 3: return SPECIAL_D("constitution")->neili_heal_level3();
			default: return SPECIAL_D("constitution")->neili_heal_level4();
		}
	}
	return 0;
}

//计算角色的内力自然恢复速度
int query_neili_heal()
{
	object me=this_object();
	int recv=0, recv_spd=0,dec;
	mixed t_recv;
	string force;
	
	force=me->query_skill_mapped("force");
	if ( stringp(force) )
		recv_spd=SKILL_D(force)->force_character("TYPE_FORCE");
  
  dec=me->query_temp("apply/neili_decrease");         //内力恢复抑制系数，当运气等过程中会产生抑制系数，导致一段时间内内力恢复效率降低
  if ( !dec )
  	dec=100;
  
	if ( recv_spd )                                      //有特殊内功的时候，恢复效率跟着特殊内功本身内功特征走
	  recv=(int)me->query_skill("force") * dec / recv_spd;
	else                                                 //无特殊内功的时候，恢复效率是基本内功等级/10
		recv=(int)me->query_skill("force",1) * dec /1000;
	
//neili_recover属性记录的是每秒恢复内力的数量，换算到recv要×9.5秒
  if ( (t_recv=me->query_temp("apply/neili_recover")) )
  {
  	if ( intp(t_recv) )
  	  recv+=t_recv*95/10;
  	else if ( floatp(t_recv) )
  		recv+=to_int(ceil(t_recv*9.5));
  }
//增加内力精纯度对恢复的影响
  recv=to_int(recv*pure_degree("neili")/0.75);  
  
  recv+= neili_heal_buff();
  if ( recv<=0 )
  	return 0;
  else
    return recv;
}

//计算角色的精力自然恢复速度
int query_jingli_heal()
{
	object me=this_object();
	int recv=0;
	mixed t_recv;
	
  if( (int)me->query("special_skill/intellect") && 
  	  (int)me->query("age")>=18 )
    recv = (int)me->query_int();
	
//jingli_recover属性记录的是每秒恢复精力的数量，换算到recv要×9.5秒
  if ( (t_recv=me->query_temp("apply/jingli_recover")) )
  {
  	if ( intp(t_recv) )
  	  recv+=t_recv*95/10;
  	else if ( floatp(t_recv) )
  		recv+=to_int(ceil(t_recv*9.5));
  }
  
  if ( recv<=0 )
  	return 0;
  else
    return recv;
}

//计算经验的大等级，小等级，小等级分，小等级总分
//增加对入口参数combatexp的支持，存在入口参数的时候通过入口参数作为经验进行计算
varargs int *query_combatexp(int combatexp)
{
//level表示年，jieji是每年有五种颜色，exp是具体颜色下剩余的经验
	int level, jieji, exp;
//levelexp决定每10年功力的每年经验值，单位万
	int *levelexp=
	({1,5,10,20,30,40,60,80,100,120,140,160,     //2甲子
	  200,240,280,320,360,400,480,560,640,720,800,880,  //4甲子
	  1000,1120,1250,1400,1580,1800,2000,2200,2400,2600,2800,3000, //6甲子
	  3500,4000,4500,5000,5500,6000,6500,7000,7500,8000,8500,9000, //8甲子
	  10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,21000, //10甲子
		23000,25000,27000,29000,31000,33000,35000,37000,39000,41000,43000,45000, //12甲子
		50000,55000,60000,65000,70000,75000,80000,85000,90000,95000,100000,110000, //14甲子
		120000,130000,140000,150000,160000,170000,180000,190000,200000,210000,220000,//16甲子
		240000,260000,280000,300000,320000,340000,360000,380000,400000,420000,440000}); //18甲子
	int *factexp=({});
	int index=0;
	
	if ( !combatexp )
	  exp=query("combat_exp");
	else 
		exp=combatexp;
	level=0;
	while(exp>=levelexp[index]*10000)
	{
		exp-=levelexp[index]*10000;
		level++;
		index=level/10;
	}
	jieji=0;
	jieji=exp/(levelexp[index]*2000);
	exp=exp-levelexp[index]*2000*jieji;
	factexp=({level,jieji,exp,levelexp[index]*2000});
	return factexp;
}

//返回经验评价值，分为三种模式，默认模式返回大等级（功力）
// level=1返回是小等级的总等级数
// level=2返回是小等级的总等级数×100+下一个小等级的经验百分比
varargs int query_combatgrade(int level)
{
  int *exp;
  exp=query_combatexp();
  if ( !level )
    return exp[0];
  else if ( level==1 )
  	return exp[0]*5+exp[1];
  else if ( level==2 )
  	return exp[0]*500+exp[1]*100+exp[2]*100/exp[3];
}
//返回0.1-2.0之间的浮点数，将影响rewardd add_exp()以及练功领悟的效率
float query_rewardcoe()
{
	float result=1.0,*coe=({1.15,1.1,1.07}),*coe2=({1.2,1.15,1.1});
	string bang;
	int tmp_bonus;
	if (query("ProfessionalClass"))
	result=0.5;//选择非武者职业，exp，练功等效率减到0.5
	if (mapp(query_temp("apply/gainexp")))
	{
		if (query_temp("apply/gainexp")["due"]<time()) delete_temp("apply/gainexp");
		else
		{
			tmp_bonus=query_temp("apply/gainexp")["bonus"];
			if (tmp_bonus<-50) 
			{
				tmp_bonus=-50;
				set_temp("apply/gainexp",(["bonus":tmp_bonus,"due":query_temp("apply/gainexp")["due"]]));
			}
			if (tmp_bonus>50)
			{
				tmp_bonus=50;
				set_temp("apply/gainexp",(["bonus":tmp_bonus,"due":query_temp("apply/gainexp")["due"]]));
			}
		}
	}
	result+=to_float(tmp_bonus)/100.0;
	bang=this_object()->get_title(TITLE_BANG);
	if (bang&&(strsrch(bang,"龙虎") ||strsrch( bang, "六合")))
	{
		for (int i=0;i<2;i++)
		if (this_object()->query("id")==STATISTIC_D->ret_list(0)[i]["id"])
		{
			result*=coe[i];
			break;
		}
		for (int i=0;i<2;i++)
		if (this_object()->query("id")==STATISTIC_D->ret_list(1)[i]["id"])
		{
			result*=coe2[i];
			break;
		}
	}
	return result;
}
//通脉对于四维上限的提升
int MaxGift(string gift)
{
	int base=50;
	return base+F_VEIN->MaxGift(this_object(),gift);
}
//通脉对于战斗的增益
int query_veinbuff()
{
	int coe=query("myVeins/level"),*buff=({0,10,15,25,35,50,55});
	if (coe>6)
	coe=6;
	if (coe<0)
	coe=0;
	return buff[coe];
}
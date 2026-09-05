// by bugbug & alading 
// cmd.c
// written by mon 3/8/98
// by all on Mon 16/07/2012, only check the status of the player
inherit F_CLEAN_UP;
#include <combat.h>
#include <ansi.h>
#include <condition.h>
#include "/d/yingtianfu/neicheng/adv_weapon/query.h"


string user_stat(object ob);
protected string perform_stat(mapping buf, string color, int time_flag);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        
	string skill_type, msg, wtype;
        
	int threshold, flag, ind, spdamage;
        
	object ob, weapon;
        
	float attack_points, parry_points, dodge_points, opp_attack, opp_dodge, opp_parry, attack_speed;
       
	mapping flag_conv=(["-a":1,"-g":2,"-s":3,"-h":4,"-b":5,"-o":6]);
        
	string *skills=({"dodge","parry","force","cuff","strike","claw","finger",
                         "hand","sword","blade","staff","whip","hammer","spear",
                         "dagger","throwing"});
        string *chars=({"strength","intelligence","constitution","dexerity"});
        string *chn_chars=({"后天膂力","后天悟性","后天根骨","后天身法"});

        if (stringp(arg) && member_array(arg, keys(flag_conv))>=0 )
        	flag=flag_conv[arg];
        else
        {
            if (wizardp(me) && arg)
            {
                ob=find_player(arg);
            }
            flag=0;
        }

        if (!ob) ob=me;

        if ( time()-me->query_temp("scan_time") < 15 && !wizardp(me) )
          return notify_fail("等等，系统喘气中......\n");
        if ( !flag )
          me->set_temp("scan_time",time());
        else 
        	me->set_temp("scan_time",time()-14);
                
        printf(HIG"≡━◎个人状态◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR);
        printf(HIW"姓名:%-20s       ID:%-12s\n", ob->query("name"), capitalize(ob->query("id")));
		if (arg=="-qw")
		return do_queryweapon();
        if ( !flag || flag==1 )
        {
 
			attack_speed=COMBAT_D->attack_speed(ob, ob->query_temp("weapon"), COMBAT_D->is_hubo(ob), COMBAT_D->is_hubei(ob) );
          printf(HIG"≡━◎战斗属性◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR);
  
			if ( mapp(ob->query_temp("apply/dmg_map")) )
     
			{
 
			weapon=ob->query_temp("weapon");
          
			if ( objectp(weapon) )
          
				wtype=weapon->query("skill_type");
      
			else
    
				wtype="unarmed";
    
			    spdamage=ob->query_temp("apply/dmg_map/"+wtype);
     
			}
    
			if ( spdamage )

				printf(RED"伤害：%-6d(+%-6d)      防御：%-6d      攻击命中：%-6d级  防御命中：%-6d级\n"NOR, 
                 ob->query_temp("apply/damage")+spdamage, spdamage,  ob->query_temp("apply/armor"), ob->query_temp("apply/attack"), ob->query_temp("apply/defense"));

			else

				printf(RED"伤害：%-6d      防御：%-6d      攻击命中：%-6d级  防御命中：%-6d级\n"NOR, 
                 ob->query_temp("apply/damage"), ob->query_temp("apply/armor"), ob->query_temp("apply/attack"), ob->query_temp("apply/defense"));
			if (wizardp(me))
				printf(MAG"%-6s    %-6s     %-6s      %-6s\n"NOR, 	"(apply/damage)", "(apply/armor)", "(apply/attack)", "(apply/defense)");

			printf(RED"战斗膂力：%-6d  战斗身法：%-6d  攻击速度：%.2f\n"NOR,ob->combat_str(), ob->combat_dex(), attack_speed*1.0/100 );
 			if (wizardp(me))
				printf(MAG"%-6s    %-6s    %-6s\n"NOR, 	"(combat_str())", "(combat_dex())", "(attack_speed())");
 
			printf(RED"攻击命中：%-5d%%  招架命中：%-5d%%  躲闪命中：%-5d%%\n"NOR,ob->query_temp("apply/attack_factor"),ob->query_temp("apply/parry_factor"), ob->query_temp("apply/dodge_factor") );
			if (wizardp(me))
				printf(MAG"%-6s %-6s %-6s\n"NOR, 	"(apply/attack_factor)", "(apply/parry_factor)", "(apply/dodge_factor)");

			printf(YEL"[抗性]"RED"普通伤害：%-3d%%(+%-2d%%)  技能伤害：%-3d%%(+%-2d%%)  技能命中：%2d级\n"NOR,
                 (ob->query_temp("apply/week_injure")>75?75:ob->query_temp("apply/week_injure")), 
                 (ob->query_temp("apply/abs_week_injure")>25?25:ob->query_temp("apply/abs_week_injure")), 
                 (ob->query_temp("apply/kf_def_wound")>75?75:ob->query_temp("apply/kf_def_wound")), 
                 (ob->query_temp("apply/kf_abs_def")>25?25:ob->query_temp("apply/kf_abs_def")), 
                 ob->query_temp("apply/kf_anti_hr"));
			if (wizardp(me)){
				printf(MAG"      %-6s   %-6s  %-6s\n", 	"(apply/week_injure)", "(apply/kf_def_wound)", "(apply/kf_anti_hr)");
				printf("      %-6s %-6s \n"NOR, 	"+(apply/abs_week_injure)", "+(apply/kf_abs_def)");
			}
			printf(YEL"      内力吸收伤害：%-d%%  毒攻击抗性：%-3d%%\n"NOR, ob->query_temp("apply/armor_effect_armor_vs_force"),
				 ob->query_temp("apply/AllPoisonsImmune") );
			if (wizardp(me))
				printf(MAG"      %-6s %-6s\n"NOR, 	"(apply/armor_effect_armor_vs_force)", "(apply/AllPoisonsImmune)");
			
			
          if ( ob->query("last_attack_info") )
          {
        	  skill_type=COMBAT_D->choose_attack_skill(ob,ob->query_temp("weapon"));
	          attack_points = (float)COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK)*1.0+0.001;
	          parry_points = (float)COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE)*1.0+0.001;
	          dodge_points = (float)COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE)*1.0+0.001;
	          opp_attack=(float)ob->query("last_attack_info/attack")*1.0+0.001;
	          opp_dodge=(float)ob->query("last_attack_info/dodge")*1.0+0.001;
	          opp_parry=(float)ob->query("last_attack_info/parry")*1.0+0.001;
	          printf(HIC"你攻击对手%s(%s)"HIC"，有%.2f%%几率被对手躲闪，%.2f%%几率被对手招架。\n"NOR,
	            ob->query("last_attack_info/name"), ob->query("last_attack_info/id"), 
	            opp_dodge/(attack_points+opp_dodge)*100, opp_parry/(attack_points+opp_parry)*100);
	          printf(HIC"对手%s(%s)"HIC"攻击你，有%.2f%%几率被你躲闪，%.2f%%几率被你招架。\n"NOR,
              ob->query("last_attack_info/name"), ob->query("last_attack_info/id"), 
	            dodge_points/(opp_attack+dodge_points)*100, parry_points/(opp_attack+parry_points)*100);
          }
        }
        if ( !flag || flag==2 )
        {
        	ind=0;
        	for(int lp=0;lp<sizeof(chars);lp++)
        	{
        		if ( ob->query_temp("apply/"+chars[lp]) )
        		{
        			ind++;
        			if ( ind==1 )
        				msg=HIG"≡━◎天赋加成◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"YEL;
        			
        			msg+=sprintf("%s: %-6s ", chn_chars[lp], sprintf("%+d点",ob->query_temp("apply/"+chars[lp])) );
        			if ( !(ind%4) )
        				msg+="\n";
        		}
        	}
        	
        	if ( msg )
        	{
        		if ( !(ind%4) )
        		  msg=msg+"\n"NOR;
        		else
        			msg=msg+"\n\n"NOR;
        			
        		printf(msg);
        	}
/*          printf(HIG"≡━◎天赋加成◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR);
          printf(YEL"后天膂力：%+-6d  后天悟性：%+-6d  后天根骨：%+-6d  后天身法：%+-6d\n"NOR, 
                 me->query_temp("apply/strength"), me->query_temp("apply/intelligence"), me->query_temp("apply/constitution"), me->query_temp("apply/dexerity"));*/
        }
        if ( !flag || flag==3 )
        {
        	msg=0;
        	ind=0;
        	for(int lp=0;lp<sizeof(skills);lp++)
        	{
        		if ( ob->query_temp("apply/"+skills[lp]) )
        		{
        			ind++;
        			if ( ind==1 )
        				msg=HIG"≡━◎技能加成◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"HIM;
        			
        			msg+=sprintf("%s: %-6s ", to_chinese(skills[lp]), sprintf("%+d级",ob->query_temp("apply/"+skills[lp])) );
        			if ( !(ind%4) )
        				msg+="\n";
        		}
        	}
        	
        	if ( msg )
        	{
        		if ( !(ind%4) )
        		  msg=msg+"\n"NOR;
        		else
        			msg=msg+"\n\n"NOR;
        		
        		printf(msg);
        	}
/*        	
          printf(HIG"≡━◎技能加成◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR);
          printf(HIM"轻功：%-6d      招架：%-6d      内功：%-6d      \n", 
               me->query_temp("apply/dodge"), me->query_temp("apply/parry"), me->query_temp("apply/force"));
          printf("基本拳法：%-6d  基本掌法：%-6d  基本爪法：%-6d  基本指法：%-6d  基本手法：%-6d\n", 
               me->query_temp("apply/cuff"), me->query_temp("apply/strike"), me->query_temp("apply/claw"), me->query_temp("apply/finger"), me->query_temp("apply/hand"));
          printf("基本剑法：%-6d  基本刀法：%-6d  基本杖法：%-6d  基本鞭法：%-6d\n", 
               me->query_temp("apply/sword"), me->query_temp("apply/blade"), me->query_temp("apply/staff"), me->query_temp("apply/whip"));
          printf("基本锤法：%-6d  基本枪法：%-6d  基本匕法：%-6d  基本暗器：%-6d\n"NOR, 
               me->query_temp("apply/hammer"), me->query_temp("apply/spear"), me->query_temp("apply/dagger"), me->query_temp("apply/throwing"));*/
        }
        if ( !flag || flag==4 )
        {
          printf(HIG"≡━◎恢复状态◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR);
          ob->set_temp("recover/qi_recover", ob->query_qi_recover());
          ob->set_temp("recover/jing_recover", ob->query_jing_recover());
          printf(HIR"[气血]"GRN"基础：%-5d 等级：%+-10d  高等级：%+-9d 其他：%+-6d\n", 
               ob->query("base_hp"), ob->query("level_hp"), ob->query("level_ext_hp"), ob->query("max_qi")-ob->query("base_hp")-ob->query("level_hp")-ob->query("level_ext_hp"));
          printf(HIB"[精神]"GRN"基础：%-5d 等级：%+-10d  高等级：%+-9d 其他：%+-6d\n", 
               ob->query("base_mp"), ob->query("level_mp"), ob->query("level_ext_mp"), ob->query("max_jing")-ob->query("base_mp")-ob->query("level_mp")-ob->query("level_ext_mp"));
          printf(GRN"气血加成：%+-6d  精神加成：%+-6d  内力恢复：%+-7.2f 精力恢复：%+-7.2f\n", 
               ob->query_temp("apply/max_qi"), ob->query_temp("apply/max_jing"), ob->query_neili_heal()/9.5, ob->query_jingli_heal()/9.5);
          printf("气血恢复：%+-7.2f 气血治疗：%+-7.2f 精神恢复：%+-7.2f 精神治疗：%+-7.2f\n", 
               ob->query_qi_recover()/9.5, ob->query_qi_cure()/9.5, ob->query_jing_recover()/9.5, ob->query_jing_cure()/9.5);
          printf("内力精纯度：%+-7.2f%%\n"NOR, ob->pure_degree("neili")*100);
        }
        if ( !flag || flag==5 )
        {
          printf(HIG"≡━◎健康状态◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR);
          write(sprintf(WHT"    %s\n"NOR, user_stat(ob)));
        }
        if ( !flag || flag==6 )
        {
          printf(HIG"≡━◎其他属性◎━━━━━━━━━━━━━━━━━━━━━━━━━≡\n"NOR);
          printf(MAG"幸运值：%-6d\n"NOR, ob->query_temp("apply/magic"));
		  if (mapp(ob->query_temp("apply/gainexp"))&&ob->query_temp("apply/gainexp")["due"]>=time())
		  write(sprintf("%-20s",HIG+"奖励加成："+ob->query_temp("apply/gainexp")["bonus"]+"%\n"+NOR));
        }
        printf(HIG"≡━━━━━━━━━━━━━━━━━━━━━━━◎北大侠客行◎━━≡\n"NOR);
        return 1;
}

//健康状态检查
string user_stat(object ob)
{
	int qipct, lp;
	string status, *cond, injure_stat, disease_stat, poison_stat, bufprt;
	mapping busy_stat=(["dianxue":"点穴", "jiemai":"截脉", "fenjin":"分筋错骨",
	                    "confuse":"压制", "body":"缠绕"]);
	
	qipct=to_int(ob->query("eff_qi"))*100/to_int(ob->query("max_qi"));
//基本健康状态
	if ( qipct>=95 )
		status=HIW"健康"NOR;
	else if ( qipct>=80 )
		status=CYN"受伤"NOR;
	else if ( qipct>=50 )
		status=YEL"轻伤"NOR;
	else if ( qipct>=20 )
		status=RED"重伤"NOR;
	else
		status=HIR"濒危"NOR;
//禁止特殊攻击提示
	if ( ob->query_temp("no_exert") )
		status+="、"+YEL"闭气"NOR;
	if ( ob->query_temp("no_perform") )
		status+="、"+YEL"疯魔"NOR;
  if ( ob->query("wrong_status") - time() >0 )
    status+=sprintf("、"HIR"走火入魔"HIY"(%d秒)"NOR, ob->query("wrong_status") - time() );
  
  if ( time()-ob->query("enable_cd")<=(70-ob->query("con")) )
    status+=sprintf("、"HIR"内功切换"HIY"(%d秒)"NOR, (70-ob->query("con"))-(time()-ob->query("enable_cd")) );
  
//中毒，病痛等持续状态提示
	cond=keys(cond_def);
	for(lp=0;lp<sizeof(cond);lp++)
	{
		if ( ob->query_condition(cond[lp])>0 )
		{
			if ( cond_def[cond[lp]]["type"]=="poison" )
			{
				if ( !poison_stat )
					poison_stat=GRN+cond_def[cond[lp]]["name"]+NOR;
				else
					poison_stat+="、"+GRN+cond_def[cond[lp]]["name"]+NOR;
			}
			
      if ( cond_def[cond[lp]]["type"]=="injure" )
			{
				if ( !injure_stat )
					injure_stat=RED+cond_def[cond[lp]]["name"]+NOR;
				else
					injure_stat+="、"+RED+cond_def[cond[lp]]["name"]+NOR;
			}
			
      if ( cond_def[cond[lp]]["type"]=="disease" )
			{
				if ( !disease_stat )
					disease_stat=YEL+cond_def[cond[lp]]["name"]+NOR;
				else
					disease_stat+="、"+YEL+cond_def[cond[lp]]["name"]+NOR;
			}
		}
	}
	
	if ( injure_stat )
		status+="、"+injure_stat;
	if ( disease_stat )
		status+="、"+disease_stat;
	if ( poison_stat )
		status+="、"+poison_stat;
	if ( ob->query_temp("busy_stat/type") &&
		   ob->query_temp("busy_stat/time")-time() > 0 )
	{
	  status+="、"+CYN+busy_stat[ob->query_temp("busy_stat/type")]+"(持续时间"+(ob->query_temp("busy_stat/time")-time())+"秒)"NOR;
	}
	
  status+="\n";
//perform的buffer效果显示	
	if ( bufprt=perform_stat(ob->query_temp("active_buffer"), HIY, 1) )
		status+=bufprt;
//debuffer的效果显示	
	if ( bufprt=perform_stat(ob->query_temp("active_debuff"), HIR, 1) )
		status+=bufprt;
//内功的buffer效果显示
	if ( bufprt=perform_stat(ob->query_temp("active_force_buffer"), HIC, 1) )
		status+=bufprt;
//音攻效果显示
	if ( bufprt=perform_stat(ob->query_temp("music_status"), HIM, 0) )
		status+=bufprt;
  return status;
}

//处理buff/debuff等的效果显示处理，其中time_flag是表示是否显示持续时间，
//color是效果的颜色处理
protected string perform_stat(mapping buf, string color, int time_flag)
{
  string *bufkey, bufprt, effkey;
  int lp, frst;
  
  if ( !mapp(buf) )
  	return 0;
  
	bufkey=keys(buf);
	bufprt="";
	for(lp=0;lp<sizeof(bufkey);lp++)
	{
		if ( bufkey[lp]=="family" )
			continue;
	  if ( !mapp(buf[bufkey[lp]]) )
	  	continue;
	  bufprt+=sprintf(WHT"    "CYN"%s："NOR, buf[bufkey[lp]]["name"]);
	  if ( time_flag )
	  {
	    if ( !buf[bufkey[lp]]["last_time"] )
	  	  bufprt+=HIG"永久"NOR;
	    else
	  	  bufprt+=sprintf(HIG"持续时间%d秒"NOR, buf[bufkey[lp]]["last_time"]-time());
	  }
	  frst=0;
	  foreach(effkey in keys(buf[bufkey[lp]]) )
	  {
	  	if ( strsrch(effkey,"effect")!=0 )
	  		continue;
	  	if ( !stringp(buf[bufkey[lp]][effkey]) )
	  		continue;
	  	if ( frst>=4 )
	  	{
	  		bufprt+="\n            ";
	  		time_flag=0;
	  		frst=0;
	  	}
	  	if ( !time_flag && !frst )
	  		bufprt+=color+buf[bufkey[lp]][effkey];
	  	else
	  	  bufprt+=color+"，"+buf[bufkey[lp]][effkey];
	  	frst++;
	  }
	  bufprt+="。\n";
	}
	return bufprt;
}

int help(object me)
{
write(@HELP
指令格式 : status_me [-a|-g|-s|-h|-b|-o|-qw]
查询玩家不常用的属性或者增益加成数值，其中参数-a|-g|-s|-h|-b|-o
指的是仅查看战斗|天赋|技能|恢复|健康|其他状态或者加成情况。
-qw是查询自己高级兵器技能的状态。
HELP
    );
    return 1;
}

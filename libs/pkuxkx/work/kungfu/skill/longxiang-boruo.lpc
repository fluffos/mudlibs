// longxiang-boruo.c 龙相般若功
// by iceland
// modefied by emnil@sj 2/2/2000

inherit FORCE;
//inherit F_DBASE;

#include <ansi.h>
#include "/kungfu/skill/force.h"

int query_level(object me);

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
        int i = (int)me->query_skill("longxiang-boruo", 1);

        if (((string)me->query("class") != "huanxi") && i > 100 && me->query("chushi/last_family")!="大轮寺") 
                return notify_fail("你没有出家，不能领会更高深的龙象般若功，只能修炼到第一层。\n");     
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("要学龙象般若功先打打基本内功根基吧。\n");
/*
        if ( me->query("gender") == "无性" && i > 40)
                return notify_fail("龙象般若功深奥复杂，你达不到至阳或至阴，还是放弃修炼吧。\n");
*/
        if ((int)me->query_con() < 30 && i > 120 )
                return notify_fail("你的根骨不够，再修炼龙象般若功恐怕会走火入魔。\n");
        if ((int)me->query_skill("huanxi-chan",1)<120 && (int)me->query_skill("huanxi-chan",1)<i)
                return notify_fail("你对欢喜禅的理解不够，阻碍了你的龙象般若功的修炼。\n");
        return valid_public(me);        
}

int practice_skill(object me)
{
        if((int)me->query_skill("longxiang-boruo", 1) >= 200 ) {
                if( (int)me->query("potential", 1) > 5 && (int)me->query("neili", 1) > 200) {
                        me->improve_skill("longxiang-boruo", (int)me->query_int());
                        me->add("neili", -100); 
                        me->add("potential", -1*(1+random(3)));
                        return 1;
                }
                else return notify_fail("你现在的修为不足以提高龙象般若功了。\n");   
        }
        else return notify_fail("龙象般若功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"longxiang-boruo/" + func;
}

void skill_improved(object me)
{
        int i = query_level(me);   

        if ( i != 10 && i != 13)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第"+chinese_number(i)+"层了。\n"NOR);

        if (i == 10)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了第十层了，已经具备了十龙十象的大力。\n"NOR);

        if (i == 13)
                tell_object(me,HIW"龙象般若功十三层你已经修炼到了融会贯通的境界，只怕天下已无人是你的对手了。\n"NOR);
}
mapping exercise_msg(object me)
{
        if (me->query("gender")=="男性")
        {
  return ([
    "status_msg" : CYN + me->name()+"脸上神色平和，身形凝重，稳如山岳。"NOR,
    "start_my_msg" : CYN"你抉弃杂念盘膝坐定，手捏气诀，脑中一片空明，渐入无我境界，一道炽热的内息在任督二脉之间游走。\n"NOR,
    "start_other_msg" : CYN + me->name() +"盘膝坐定，左手阴，右手阳虚拢胸前，脸上神色平和，一丝红潮若隐若现，身形凝重，稳如山岳。\n"NOR,
    "halt_msg" : CYN"$N感到烦躁难耐，只得懈了内息，轻吁口气，身上涔涔透出层冷汗。\n"NOR,
    "end_my_msg" : CYN"你只觉神元归一，全身精力弥漫，无以复加，忍不住长啸一声，徐徐站了起来。
\n"NOR,
    "end_other_msg" : CYN + me->name()+"一声清啸，双手两下一分，徐徐站了起来，眼中神光闪烁，令人不可逼视。\n"NOR
                    ]);
        }
        else {
  return ([
    "status_msg" : MAG + me->name()+"脸上神色娇艳，安定祥和，静若止水。"NOR,
    "start_my_msg" : MAG"你收敛心神闭目打坐，手搭气诀，调匀呼吸，感受天地之深邃，自然之精华，渐入无我境界。\n"NOR,
    "start_other_msg" : MAG + me->name() +"闭目盘膝打坐，双手十指如兰搭于胸前，呼吸渐渐悠长，脸上涌起一层红晕，安定祥和，静若止水。\n"NOR,
    "halt_msg" : MAG"$N感到呼吸紊乱，全身燥热，只好收功站了起来。\n"NOR,
    "end_my_msg" : MAG"你感到自己和天地融为一体，全身清爽如浴春风，忍不住舒畅的呻吟了一声，缓缓睁开了眼睛。\n"NOR,
    "end_other_msg" : MAG + me->name()+"鼻中发出一阵舒畅的呻吟，睁眼缓缓站了起来，伸衣袖擦了擦额头的汗水。\n"NOR
                    ]);
        }
}

int ob_hit(object ob, object me, int damage)
{
        int skill = me->query_skill("force");
        int skill2= ob->query_skill("force");
        int neili = me->query_skill("neili");
        int neili2= ob->query_skill("neili");
        int i = 1,j;
        string msg;

        if(!me->query_temp("xs/shield"))
                return 1;

        if ( random(skill) > (skill2*14/10/2-1) ) {
                if(me->query_busy()<2 || random(3)==1 ) {
                        msg = MAG"$N"+MAG+"默运龙象般若护体大法，化去了$n"MAG;
                        if(neili > neili2*2) {
                                msg += "大部分的攻击！\n"NOR;
                                i = -(damage/2 + random(damage));
                        }
                        else {
                                if(neili < neili2/4) {
                                        msg += "很少的一点攻击！\n"NOR;
                                        i = -random(damage/4);
                                }
                                else {
                                        msg += "一部分的攻击！\n"NOR;
                                        i = -(damage/3+random(damage/2));
                                }
                        }
                        if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("ob_hit: %d  ",i));
                        if( objectp(me) && objectp(ob) )
                                message_vision(msg, me, ob);            

                }
                else {
                        j = me->query_busy() / 2;
                        j = j/2 + random(j);
                        if(j<3) j = 3;
                        if(j>10) j = 10;
                        if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("busy:%d , dec busy:%d  ",me->query_busy(),j));
                        me->start_busy(me->query_busy() - j);
                        msg = MAG"$N"MAG"试图摆脱困境，虽然没有成功，但手脚似乎灵活了不少！\n"NOR;
                        
                        if( objectp(me) && objectp(ob) )
                                message_vision(msg, me, ob);            
                }
        }

        if(random(4)!=1) {
                if( ((damage+i) > 500) && (me->query("jing")>200) ) {
                        j = (damage+i)/2;
                        if( j > me->query("jing")) 
                                j = me->query("jing") - 100;
                        i = i -j ;
                        me->add("jing", -j);
                        if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("jing:%d ",j));
                        message_vision(MAG"$N"MAG"眉头紧锁，努力以自己的精神念力化解$n"MAG"的攻势！\n"NOR, me, ob);             
                }
        }

        return i;
} 

int force_character(string char_type)
{
	int recv;
	recv=::force_character(char_type);
	switch(char_type)
	{
		case "TYPE_RECOVER":          //TYPE_RECOVER
			return 200;
	  case "TYPE_REC_CD":          //TYPE_REC_CD
	  	return 12;
	  case "TYPE_MIN_SPD":          //TYPE_MIN_SPD
	  	return 150;
	  case "TYPE_MAX_SPD":          //TYPE_MAX_SPD
	  	return 350;
	  case "TYPE_SPEED":          //TYPE_SPEED
	  	return 2;
	  case "TYPE_DEC_SPD":          //TYPE_DEC_SPD
	  	return 50;
	  case "TYPE_FORCE":     //TYPE_FORCE
	  	return 500;
    case "TYPE_ENFORCE":
      return 12;
	  default:
	  	return recv;
	}
}

//查询龙象般若功所处的层级
//非大轮寺弟子最高只能到达第七层
//第九层开始要求提高，第九层是1000级，第十层是1200级，第十一层是1600级，第十二层是2000级，第十三层是2800级
//恢复到原来的设定 8层以后 150级加一层by huacuoh 2015/2/14
int query_level(object me)
{
  int level;
  
  level=me->query_skill("longxiang-boruo",1)/100;
 /* if ( level>7 &&
       me->query("family/family_name")!="大轮寺" )
    return 7;
 //去除门派限制
 */
  if ( level>8 )
    level=8+(me->query_skill("longxiang-boruo",1)-800)/150;
  
 /* if ( level>10 )
    level=10+(level-10)/2;
  
  if ( level>12 )
    level=12+(level-12)/2;
 */ 
  if ( level>13 )
    level=13;
  
/*  if ( level>9 &&
       ( me->query("chushi/done")||
         me->query("betrayer") ) )
    return 9;
*/  
  return level;
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int skill,my_jiali,my_neili;
        int i = 1,j;
	//	mapping my;
        object weapon;    

        if(!me->query_temp("xs/longxiang"))
                return ::hit_ob(me, victim, damage_bonus, factor);
		
	//	my = me->query_entire_dbase();
        skill = me->query_skill("force");

        i = damage_bonus * (skill+1) / 1000;
        i = i/2+ random(i);
//修改算法，对于高攻武器抑制伤害，对于空手攻击提高伤害
        if( !(weapon=me->query_temp("weapon")) )
                i = i*3/2;
        if( objectp(weapon) &&
            weapon->query("weapon_prop/damage")>=200 )
                i = i*2/3;
		my_jiali = me->query("jiali");
		my_neili = me->query("neili");
	    if( my_jiali && (my_neili > my_jiali) )
		{
			if (my_jiali < 1500)
			{
				i += my_jiali*2;
			}
			else
			{
				if (my_jiali < 2500)
				{
					i += my_jiali*3/2+500;
				}
				else
				{
					i += my_jiali+1000; 
				}
			}
		}
		
        if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("hit_ob: %d  ",i));
        j = query_level(me);    
        if (j > 13) j = 13;
		//附加伤害与层数挂挂勾
        i += j*10;
        if ( me->query("family/family_name")=="大轮寺" && j>0 )
        	me->add("neili", -factor/j );
        else
        	me->add("neili", -factor);
        message_vision(MAG"$N"+MAG+"陡然大喝一声，以"+CHINESE_D->chinese_number(j)+"龙"
                +CHINESE_D->chinese_number(j)+"象之力攻向$n！\n" NOR, me,victim);

        return i;
}

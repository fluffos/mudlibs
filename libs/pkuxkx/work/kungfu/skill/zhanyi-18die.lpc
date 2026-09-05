#include <ansi.h>
inherit SKILL;

string type() { return "knowledge"; }
/*
int valid_enable(string usage)
{
    return (usage == "parry"); 
}
*/
int valid_learn(object me)
{
    write("沾衣十八跌无法通过简单的学习来提高。\n");
    return 0;
}

int practice_skill(object me)
{
    write("沾衣十八跌无法通过简单的练习来提高。\n");
    return 0;
}

string *parry_msg = ({
        GRN"$n"GRN"使出一招『玉女穿梭』右手上前格挡住"GRN"$N"GRN"的攻击，左手攻其不备，\n"GRN"$N"GRN"一阵慌乱，被"GRN"$n"GRN"乘机出左脚绊倒在地。\n"NOR,
        GRN"$n"GRN"使出一招『晾翅弹肘』闪过"GRN"$N"GRN"的攻击，趁敌不备用左脚逼住"GRN"$N"GRN"的右脚，\n"GRN"$N"GRN"顿时重心不稳，被"GRN"$n"GRN"一个肘击击倒在地。\n"NOR,
        });
string *unarmed_parry_msg = ({
        GRN"$n"GRN"使出一招『玉女穿梭』右手上前格挡住"GRN"$N"GRN"的攻击，左手攻其不备，\n"GRN"$N"GRN"一阵慌乱，被"GRN"$n"GRN"乘机出左脚绊倒在地。\n"NOR,
        GRN"$n"GRN"使出一招『晾翅弹肘』闪过"GRN"$N"GRN"的攻击，趁敌不备用左脚逼住"GRN"$N"GRN"的右脚，\n"GRN"$N"GRN"顿时重心不稳，被"GRN"$n"GRN"一个肘击击倒在地。\n"NOR,
        });

string query_parry_msg(object weapon)
{   
    if( weapon )
        return parry_msg[random(sizeof(parry_msg))];
    else
        return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
/*  迁移去太极拳
mapping buffer_applied(object ob)
{
    mapping buf, tbuf;
    int level;
    
    if ( ob->query("family/family_name") != "武当派" )
    {
      buf=([]);
      ob->delete_temp("zhanyi-18die");
      return buf;
    }
    
    if ( mapp(ob->query_temp("zhanyi-18die")) )
      return buf;
    
    level=ob->query_skill("zhanyi-18die",1);
    buf=([]);
    buf["parry_factor"]=1+level/150;
    if ( buf["parry_factor"]>16 )
      buf["parry_factor"]=16;
    buf["dodge_factor"]=-1-level/200;
    if ( buf["dodge_factor"]<-11 )
      buf["dodge_factor"]=-11;
    buf["week_injure"]=1+level/300;
    if ( buf["week_injure"]>8 )
      buf["week_injure"]=8;
    //防止buffer跨门派叠加，增加门派限制
    if ( mapp(tbuf=ob->query_temp("active_buffer")) &&
         sizeof(tbuf)>1 &&
         stringp(tbuf["family"]) &&
         tbuf["family"]!="武当派" &&
         tbuf["family"]!="公共武学" )
    {
      buf=([]);
      ob->delete_temp("zhanyi-18die");
      return buf;
    }
    ob->set_temp("zhanyi-18die", buf);
    ob->set_temp("active_buffer/family","武当派");
    ob->set_temp("active_buffer/zhanyi-18die/name", "沾衣十八跌");                       //buff名称
    ob->set_temp("active_buffer/zhanyi-18die/effect1", "招架命中+"+(buf["parry_factor"])+"%");     //效果描述1
    ob->set_temp("active_buffer/zhanyi-18die/effect2", "躲闪命中"+(buf["dodge_factor"])+"%");     //效果描述2
    ob->set_temp("active_buffer/zhanyi-18die/effect3", "削弱所受普通攻击伤害+"+(buf["week_injure"])+"%");     //效果描述3
    return buf;
}

mapping buffer_removed(object ob)
{
    mapping buf;
    
    buf=ob->query_temp("zhanyi-18die");
    if ( mapp(buf) )
    {
      buf["parry_factor"]=buf["parry_factor"]*(-1);
      buf["dodge_factor"]=buf["dodge_factor"]*(-1);
      buf["week_injure"]=buf["week_injure"]*(-1);
    }
    else
      buf=([]);
    ob->delete_temp("zhanyi-18die");
    ob->delete_temp("active_buffer/zhanyi-18die");
    return buf;
}
*/

void skill_deleted(object ob)
{
    mapping buf;
	int i;
    string *apply;
	
    buf=ob->query_temp("zhanyi-18die");
    if ( mapp(buf) )
	{
		apply=keys(buf);
		for(i=0;i<sizeof(apply);i++)
		{
			if ( intp(buf[apply[i]]) )
			ob->add_temp("apply/"+apply[i], -1*buf[apply[i]]);
		}
		ob->delete_temp("zhanyi-18die");
 	}
    ob->delete_temp("active_buffer/zhanyi-18die");
}
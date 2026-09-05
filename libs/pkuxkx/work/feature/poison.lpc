//存放各种类型的毒，标准化。 zine 2014/4/3
//source：1矿物类2植物类3动物类
//玩家强化有永久性query("PoisonEnhance/Source/#"),临时性增强query_temp("apply/PoisonEnhance/Source/#") #可为1，2，3
//玩家抗性永久query("PoisonProof/Source/#"),临时性增强query_temp("apply/PoisonProof/Source/#") #可为1，2，3
//eff_type：1致幻2减血3减精4减内力5四肢无力(臂力，身法下降)6特殊效果（比如哑巴了，半小时无法chat,tell,ask job等等）
//玩家强化有永久性query("PoisonEnhance/Effect/#"),临时性增强query_temp("apply/PoisonEnhance/Effect/#") #可为1，2，3
//玩家抗性永久query("PoisonProof/Effect/#"),临时性增强query_temp("apply/PoisonProof/Effect/#") #可为1，2，3
//usage_enable：1武功2涂毒3食物下毒4特殊方式
#define Poison_Limit 700
#define PoisonDurLit 10 //普通攻击带毒的发作时间上限
#include <ansi.h>
int LvLimit()
{
	return Poison_Limit;
}
nosave mapping poisons=
([
	"anran_poison":(["name":"情毒","source":2,"eff_type":({2,3}),"usage_enable":({1,3}),]),
	"rose_poison":(["name":"火玫瑰毒","source":2,"eff_type":({2,3}),"usage_enable":({1}),]),
	"s-poison":(["name":"断肠散毒","source":2,"eff_type":({2,3}),"usage_enable":({1}),]),
	"san-poison":(["name":"断肠散毒","source":2,"eff_type":({2,3}),"usage_enable":({1}),]),//has not been used in PKUXKX
	"bee_poison":(["name":"蜂毒","source":3,"eff_type":({2,3}),"usage_enable":({1,}),]),
	"chanchu_poison":(["name":"蟾蜍毒","source":3,"eff_type":({2,3}),"usage_enable":({1,2}),]),
	"scorpion_poison":(["name":"蝎毒","source":3,"eff_type":({2,3}),"usage_enable":({1}),]),//above this line has relief medicine
	"bing_poison":(["name":"冰魄银针毒","source":1,"eff_type":({2,3}),"usage_enable":({1,}),]),
	"bt_poison":(["name":"白驼蛇毒","source":3,"eff_type":({3}),"usage_enable":({1,2}),]),
	"btgs_poison":(["name":"西域怪蛇毒","source":3,"eff_type":({3}),"usage_enable":({1,2}),]),
	"chuanxin":(["name":"穿心钉","source":3,"eff_type":({2}),"usage_enable":({1}),]),
	"dsy_poison":(["name":"密宗大手印毒","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"emerald_poison":(["name":"玄冰毒","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"fs_poison":(["name":"腐尸毒","source":3,"eff_type":({2,3}),"usage_enable":({1}),]),
	"insect_poison":(["name":"蜂毒","source":3,"eff_type":({2,3}),"usage_enable":({1}),]),
	"ningxue":(["name":"凝血毒","source":3,"eff_type":({1}),"usage_enable":({1}),]),
	"nx_zhua":(["name":"凝血神爪毒","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"qianzhu":(["name":"千蛛万毒","source":3,"eff_type":({2,3,4}),"usage_enable":({1}),]),
	"qishang":(["name":"七伤拳伤心脉","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"sanxiao_poison":(["name":"三笑逍遥散","source":2,"eff_type":({2,3}),"usage_enable":({1}),]),
	"sha_poison":(["name":"铁砂掌毒","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"shuoxin":(["name":"烁心弹焚伤","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"slumber_drug":(["name":"蒙汗药","source":1,"eff_type":({1}),"usage_enable":({3}),]),
	"snake_poison":(["name":"蛇毒","source":3,"eff_type":({2,3}),"usage_enable":({1}),]),
	"ss_poison":(["name":"生死符","source":2,"eff_type":({2,3}),"usage_enable":({1}),]),
	"wudu_poison":(["name":"五毒神掌毒","source":3,"eff_type":({2,3}),"usage_enable":({1}),]),
	"wugong_poison":(["name":"蜈蚣毒","source":3,"eff_type":({2,3}),"usage_enable":({1}),]),
	"xx_poison":(["name":"星宿毒掌毒","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"xx_poison2":(["name":"星宿毒神","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),//毒神附体状态下打出来的
	"xxfog-poison":(["name":"星宿毒雾","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"xx-poison-hocus":(["name":"星宿麻痹","source":1,"eff_type":({5}),"usage_enable":({1}),]),
	"xx-poison-palsy":(["name":"星宿麻痹","source":1,"eff_type":({5}),"usage_enable":({1}),]),
	"xx-poison-palsy2":(["name":"星宿麻痹","source":1,"eff_type":({5}),"usage_enable":({1}),]),
	"xxx_poison":(["name":"冰魄寒毒","source":1,"eff_type":({2,3}),"usage_enable":({1}),]),
	"xx_disorder":(["name":"星宿碧磷毒","source":3,"eff_type":({6}),"usage_enable":({1}),]),
	"yf_condition":(["name":"玉蜂针毒","source":3,"eff_type":({2,3}),"usage_enable":({1}),]),
	"zhizhu_poison":(["name":"冰魄寒毒","source":3,"eff_type":({2,3}),"usage_enable":({1}),]),
]);
string * all_poisons=keys(poisons);

int AdjustCoefficient(int parameter)
{
	if (parameter<0)
	parameter=0;
	if (parameter>99)
	parameter=99;
	return parameter;
}
int ObtainProof(object target,string poison_id)
{
	int result;
	target->set_temp("tmp_calc/source",poisons[poison_id]["source"]);
	target->set_temp("tmp_calc/eff_type",poisons[poison_id]["eff_type"][random(sizeof(poisons[poison_id]["eff_type"]))]);
	result=AdjustCoefficient(target->query_proof("AntiPoisonRate"));
	target->delete_temp("tmp_calc");
	return result;
}
int ObtainEnhance(object me,string poison_id)
{
	int result;
	me->set_temp("tmp_calc/source",poisons[poison_id]["source"]);
	me->set_temp("tmp_calc/eff_type",poisons[poison_id]["eff_type"][random(sizeof(poisons[poison_id]["eff_type"]))]);
	result=AdjustCoefficient(me->query_enhance("PoisonRate"));
	me->delete_temp("tmp_calc");
	return result;
}
void poison_eff(object victim,string poison_id,mapping eff,int times)//case 0receive_damage 1调用receive_wound 2 add(-),3 add_temp(apply) times指发作次数
{
	object attacker;
	string * list;
	int PoisonProof,finalResult,report=0;
	if (member_array(poison_id,all_poisons)==-1)
	return;
	list=keys(eff);
	PoisonProof=ObtainProof(victim,poison_id);
	if ((victim->query_temp("apply/PoisonExpert")||victim->query("PoisonExpert")||wizardp(victim))&&PoisonProof)
	tell_object(victim,"你对"+poisons[poison_id]["name"]+"的抗性抵御了"+PoisonProof+"%的伤害。\n");
	attacker=victim->query_temp("death_cond_origin/"+poison_id);
	for (int i=0;i<sizeof(list);i++)
	{
		finalResult=eff[list[i]][1]*(100-PoisonProof)/100;
		if (objectp(attacker))
		finalResult=finalResult*(ObtainEnhance(attacker,poison_id)+100)/100;
		else if (!userp(victim)) 
		finalResult=finalResult*(victim->query_temp("PoisonAddition")+100)/100;
		if (finalResult<0)
		log_file("user/poison_error",sprintf("%s%d%s%d%s%d%s%d%s%d%s%s\n","PoisonError:Result=",finalResult,"BaseValue",eff[list[i]][1],"PoisonProof",
		PoisonProof,"Enhance:",objectp(attacker)?ObtainEnhance(attacker,poison_id):0,"Addition",victim->query_temp("PoisonAddition"),"Poison:",poison_id));
		if (times<1) times=1;
		for (int j=0;j<times;j++)
		{
			switch (eff[list[i]][0])
			{
				case 0:
					{
						if (objectp(attacker))
						victim->receive_damage(list[i],finalResult,attacker);
						else
						victim->receive_damage(list[i],finalResult,"中"+poisons[poison_id]["name"]);
					}
				case 1:
					{
						if (objectp(attacker))
						victim->receive_wound(list[i],finalResult,attacker);
						else
						victim->receive_wound(list[i],finalResult,"中"+poisons[poison_id]["name"]);
						if (userp(victim))
						report=1;
					}
					break;
				case 2:
					victim->add(list[i],finalResult);
					break;
				case 3:
					victim->add_temp("apply/"+list[i],finalResult);
					break;
				case 4:
					victim->add_busy(finalResult);
					break;
				default:
					return;
			}
		}
		if (report) COMBAT_D->report_status(victim);
	}
}
void detoxicate(object me,string poison_id)//彻底解读
{
	if (poison_id=="all_poisons")
	{
		for (int i=0;i<sizeof(all_poisons);i++)
		{
			if (me->query_condition(all_poisons[i]))
			{
				me->apply_condition(all_poisons[i],0);
				me->delete_temp("death_cond_origin/"+all_poisons[i]);
			}
		}
	}
	else
	{
		if (member_array(poison_id,all_poisons)==-1)
		return;
		if (me->query_condition(poison_id))
		me->apply_condition(poison_id,0);
		tell_object(me,"你身上的"+poisons[poison_id]["name"]+"被解除了。\n");
	}
}
void relief(object me,string poison_id,int reduce)//缓解毒性，降低发作时间
{
	if (member_array(poison_id,all_poisons)==-1)
	return;
	if (!me->query_condition(poison_id))
	{
		tell_object(me,"你并没有身中"+poisons[poison_id]["name"]+"。\n");
		return;
	}
	reduce=me->query_condition(poison_id)-reduce;
	if (reduce<0) reduce=0;
	me->apply_condition(poison_id,reduce);
	if (reduce==0)
	tell_object(me,"你身上的"+poisons[poison_id]["name"]+"被彻底解除了。\n");
	else
	tell_object(me,"你身上的"+poisons[poison_id]["name"]+"被缓解了些许。\n");
}
void depoison(object me)
{
	if (me) 
	{
		me->delete_temp("apply/PoisonAttack");
		me->delete_temp("active_force_buffer/poison_attack");
	}
}
void empoison(object me,string poison_id,int dur,string type)//普通攻击带毒
{
	mapping poison=([]),types=(["weapon":"武器","unarmed":"空手","all":""]);
	if (!poison_id||!stringp(poison_id)) return;
	if (member_array(poison_id,all_poisons)==-1) return;
	if (!dur) dur=1;
	if (dur>PoisonDurLit) dur=PoisonDurLit;
	if (!type||member_array(type,({"weapon","unarmed","all"}))==-1) type="unarmed";
	poison=(["id":poison_id,"dur":dur,"type":type]);
	me->set_temp("apply/PoisonAttack",poison);
	me->set_temp("active_force_buffer/poison_attack/name", "带毒攻击");
	me->set_temp("active_force_buffer/poison_attack/effect1", "所有"+types[type]+"带"+poisons[poison_id]["name"]);  
}
void poison_attack(object me,object target,string poison_id,int duration)
{
	int anti_poison,enhance_poison;
	float durAdjust;
	//被击中以后的抗毒性计算
	enhance_poison=ObtainEnhance(me,poison_id);
	anti_poison=ObtainProof(target,poison_id);
	if ((arrayp(target->query("PoisonImmune"))&&member_array(poison_id,target->query("PoisonImmune"))!=-1)||
	(arrayp(target->query_temp("PoisonImmune"))&&member_array(poison_id,target->query_temp("PoisonImmune"))!=-1)||
	target->query_temp("apply/AllPoisonsImmune")>random(100))
	{
		message_vision(poisons[poison_id]["name"]+"对$N完全没有任何作用。\n",target);
	}
	else if (enhance_poison+1+random(100)>anti_poison)//中毒
	{
		if (!enhance_poison)
		anti_poison*=2;//对手没有毒属性强化时，抗毒属性减发作时间加倍
		durAdjust=(to_float(enhance_poison-anti_poison)+100.0)/100.0; //比如20点抗毒属性，对手无毒属性 发作时间为原来的60%
		target->set_temp("death_cond_id", poison_id);
		target->set_temp("death_cond_origin/"+poison_id, me);
		target->set_temp("last_damage_from",me);//为玩家用毒做任务考虑。
		target->apply_condition(poison_id, to_int(to_float(duration)*durAdjust));
		if (!userp(target)) target->set_temp("PoisonAddition",enhance_poison); //对非玩家使用可能伤害更大
	}
	else //不中
	{
		message_vision("$N森然一笑，"+poisons[poison_id]["name"]+"似乎对$N全无作用。\n",target);
	}
}
void ObtainImmune(object me,string poison_id,string type)//某种毒的临时、终身免疫
{
	string * immune;
	if (type=="temp")
	{
		if (arrayp(me->query_temp("PoisonImmune")))
		immune=me->query_temp("PoisonImmune");
		if (member_array(poison_id,immune)==-1)
		immune+=({poison_id});
		me->set_temp("PoisonImmune",immune);
	}
	if (type=="permanent")
	{
		if (arrayp(me->query("PoisonImmune")))
		immune=me->query("PoisonImmune");
		if (member_array(poison_id,immune)==-1)
		immune+=({poison_id});
		me->set("PoisonImmune",immune);
	}
}


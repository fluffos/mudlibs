#include <ansi.h>
#define LINE "-------------------------------------------------------------------\n"
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int flag=0;
	string msg=HIW"\t\t    【北侠职业相关信息】\n"+NOR+LINE,pro,*sks,*other_pros;
	mapping pros=(["fighter":"武者","alchemy":"药师","herbalism":"采药师","smithing":"锻造师","mining":"采矿师"]);
	mapping pro_skills=(["alchemy":({"alchemy","herbalism"}),"herbalism":({"alchemy","herbalism"}),"smithing":({"smithing","mining"}),"mining":({"smithing","mining"})]);
	sks=keys(pros);
	if (!arg)
	{
		pro=F_PRO->pro_class(me);
		msg+="你是一名["+HIC+pros[pro]+NOR+"]";
		if (pro!="fighter")
		{
			msg+="，你还可以从事专职";
			other_pros=pro_skills[pro];
			for (int i=0;i<sizeof(other_pros);i++)
			if (other_pros[i]!=pro)
			msg+=pros[other_pros[i]];
		}
		msg+="。\n";
		msg+="你的职业技能：\n";
		sks-=({"fighter"});
		if (pro!="fighter")
		{
			for (int i=0;i<sizeof(sks);i++)
			{
				if (me->query_skill(sks[i],1)&&member_array(sks[i],pro_skills[pro]))
				{
					msg+=to_chinese(sks[i])+"级别："+me->query_skill(sks[i],1)+"\n";
					flag=1;
				}
			}
		}
		else
		{
			for (int i=0;i<sizeof(sks);i++)
			{
				if (me->query_skill(sks[i],1))
				{
					msg+=to_chinese(sks[i])+"级别："+me->query_skill(sks[i],1)+"\n";
					flag=1;
				}
			}
		}
		if (!flag)
		msg+="【无】\n";
		msg+=LINE+"pro 命令可加的参数有alchemy，herbalism，smithing，mining和fighter\n";
		msg+=HBBLU+HIR+"所有非fighter以外职业，转为专职之后，常规经验经验获取速度减半。\n"+NOR;
		write(msg);
	}
	else if (member_array(arg,sks)==-1)
	{
		write(arg+"并不是一个北侠的职业，目前没有相关的信息。\n");
	}
	else
	{
		if (arg=="fighter")
		{	
			msg+=HBBLU+HIW+"武者"+NOR+"就是北侠世界的默认职业，以战斗和做战斗型的任务，提升自己战斗为\n";
			msg+="目的。\n";
		}
		if (arg=="alchemy")
		{
			msg+=HBBLU+HIW+"药师"+NOR+"是以炼出各种神奇药物为目的。职业药师条件：50级炼丹术(alchemy)。\n";
			msg+="只有药师可以练习五禽戏。药师相关命令："+U+"formula"+NOR+"。\n";
		}
		if (arg=="herbalism")
		{
			msg+=HBBLU+HIW+"采药师"+NOR+"是药师一个分支职业，获取最初级的药材，供药师制作药物。药师后\n";
			msg+="期很多药物只有通过采药获得。\n";
			msg+="职业采药师条件：30级采药术(herbalism)，完成大石谷青囊残篇与五禽戏\nquest。\n";
			msg+="采药师相关命令：gather(采集),lookfor(搜寻)。\n";
		}
		if (arg=="smithing")
		{
			msg+=HBBLU+HIW+"锻造师"+NOR+"可以制造各种金属类装备，高等级的锻造师可以制造出比系统随机装\n";
			msg+="备更高性能的装备。\n";
			msg+="职业锻造师条件：50级锻造术(smithing)。\n";
			msg+="锻造师相关命令："+U+"smith"+NOR+"，"+U+"repair"+NOR+"，"+U+"disassemble"+NOR+"，"+U+"refine"+NOR+"。\n";
		}
		if (arg=="mining")
		{
			msg+=HBBLU+HIW+"采矿师"+NOR+"可以帮锻造师提供高级的材料，用以制造装备。\n";
			msg+="职业采矿师条件：50级采矿术(mining)。\n";
			msg+="采矿师相关命令：shift，excavate，"+U+"unite"+NOR+"。\n";
		}
		msg+=LINE+HBWHT+HIR+"含下划线的命令可以help，如"+U+"smith"+NOR+HBWHT+HIR+"。\n"+NOR;
		write(msg);
	}
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式：pro 提供你可用的职业相关信息。
pro <职业名> 提供某种职业的相关信息。
HELP
    );
    return 1;
}

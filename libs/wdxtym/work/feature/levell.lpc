// level.c
#pragma save_binary
#include <dbase.h>
#include <ansi.h>;

//计算升级需要最大的修为
int levell_max_exp(object me)
{
	int max_exp,lvl;
	lvl=(int)me->query("yuanshen/level");
	if(lvl<5)
		max_exp=lvl*1000+10000;
	if(lvl<10 && lvl>4)
		max_exp=lvl*5000+100000;
	if(lvl<15 && lvl>9)
		max_exp=lvl*10000+500000;
	if(lvl<20 && lvl>14)
		max_exp=lvl*50000+1000000;
	if(lvl<25 && lvl>19)
		max_exp=lvl*60000+1000000;
	if(lvl<30 && lvl>24)
		max_exp=lvl*100000+1500000;
	if(lvl<35 && lvl>29)
		max_exp=lvl*200000+2000000;
	if(lvl<40 && lvl>34)
		max_exp=lvl*500000+5000000;
	if(lvl<45 && lvl>39)
		max_exp=lvl*800000+8000000;
	if(lvl<50 && lvl>44)
		max_exp=lvl*1000000+10000000;
	if(lvl<55 && lvl>49)
		max_exp=lvl*1500000+15000000;
	if(lvl>=60)
		max_exp=lvl*500000000+5000000000;
	return max_exp;
}

varargs void improve_levell(object me)
{
	int exp_num, lev_num;
	exp_num=me->query("yuanshen/exp");
	lev_num = (int)me->query("yuanshen/level");
	if(lev_num == 100)
	{
		write(HIR"你的元神已达最高等级!"NOR"\n");
		return 0;
	}
	if(exp_num >= levell_max_exp(me))
	{
		tell_object(me, HIG"丹田气海得到了扩充  "NOR"\n");
		tell_object(me, HIR" 恭喜:"+NOR" 你的 "+YEL+"元神"HIY" 提升了一级 \n");
		if(exp_num >= levell_max_exp(me))
		{
			me->add("yuanshen/level",1);
		}
	}
	else
	{
		write(HIR"你的元神修为不足以提升等级!"NOR"\n");
	}
}

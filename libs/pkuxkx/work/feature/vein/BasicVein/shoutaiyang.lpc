//手太阳小肠经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "手太阳小肠经";
}
string VeinTitle()
{
	return "手太陽小腸經";
}
string benefit()
{
	return "增加临时身法。\n";//tuna,dazuo效率增加。
}
int *bene_families()
{
	return ({5,15,16,18});
}
int benefit_effect(object me)
{
	if (me->query("myVeins/"+ThisVein()+"/completed")>=3)
	return 3;
	else if (me->query("myVeins/"+ThisVein()+"/completed")==2)
	return 2;
	else if (me->query("myVeins/"+ThisVein()+"/completed")==1)
	return 1;
	else
	return 0;
}
/*float benefit_times(object me) //or related thing
{   
	if (me->query("myVeins/"+ThisVein()+"/completed")>=3)
	return 1.5;
	else if (me->query("myVeins/"+ThisVein()+"/completed")==2)
	return 1.2;
	else
	return 1.0;
}*/
int DailyLimit(object me)//一天限制次数
{
	if (F_VEIN->family_id(me)>0&&member_array(F_VEIN->family_id(me),bene_families())!=-1)
	return 1000;
	else
	return 1100;
}
int Period(object me)//每次消耗时间
{
	if (F_VEIN->family_id(me)>0&&member_array(F_VEIN->family_id(me),bene_families())!=-1)
	return 8-random(2);
	else
	return 8;
}
int recover_require()
{
	return 6;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 3;
}
string *AcuPoint_list()//穴位列表
{
	return ({"少泽","前谷","后溪","腕骨","阳谷","养老","支正","小海","肩贞","臑俞","天宗","秉风","曲垣","肩外俞","肩中俞","天窗","天容","颧髎","听宫"});
}

string vein()
{
	return "
			"+CYN+"手太陽小腸經\n"+NOR+F_VEIN->DIVIDE()+"
								听宫
								         颧髎
										 
								天容
							 天窗
						肩中俞
					      肩外俞  秉风
						       曲垣
							        臑俞
								  天宗
								  
								   肩贞
								   
								   
								   
								 小海
								 
								 
								    支正
									
									  养老
									  阳谷
									 腕骨
									后溪
									 前谷
									 
									 少泽
";
}

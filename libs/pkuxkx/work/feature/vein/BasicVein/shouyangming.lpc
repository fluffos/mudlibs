//手阳明大肠经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "手阳明大肠经";
}
string VeinTitle()
{
	return "手陽明大腸經";
}
string benefit()
{
	return "能更好的将食物的营养转化。\n";//食用食物后，可少量持续增加内力，精力。
}
int benefit_effect(object me)
{
	int benefit,max_neili=me->query("max_neili"),neili=me->query("neili");
	if (max_neili>50000) max_neili=50000;
	if (neili>50000) neili=50000;
	benefit=max_neili/100+neili/200;
	if (me->query("myVeins/"+ThisVein()+"/completed")>=3)
	benefit=benefit*3;
	benefit=benefit*4/5+random(benefit/5);
	return benefit;
}
int benefit_times(object me) //or related thing
{
	if (me->query("myVeins/"+ThisVein()+"/completed")>=3)
	return 10+random(3);
	if (me->query("myVeins/"+ThisVein()+"/completed")==2)
	return 6+random(5);
	if (me->query("myVeins/"+ThisVein()+"/completed")==1)
	return 3+random(3);
}
int DailyLimit(object me)//一天限制次数
{
	return 720;
}
int Period(object me)//每次消耗时间
{
	return 4;
}
int recover_require()
{
	return 2;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 1;
}
string *AcuPoint_list()//穴位列表
{
	return ({"商阳","二间","三间","合谷","阳谿","偏历","温溜",
			"下廉","上廉","手三里","曲池","肘髎","手五里",
			"臂臑","肩髃","巨骨","天鼎","扶突","禾髎","迎香"});
}

string vein()
{
	return "
			"+HIC+"手陽明大腸經\n"+NOR+F_VEIN->DIVIDE()+"
             迎香
		    禾髎        
				  
				    扶突  
				     天鼎                     
					 
						    巨骨   
						  肩髃     
							 
							   臂臑   
								  手五里      
									    肘髎
									  曲池
								    手三里
								   上廉
								   下廉
								   温溜
								  偏历
							    阳谿
							
							  合谷 
							   三间
                               二间

                               商阳
";
}

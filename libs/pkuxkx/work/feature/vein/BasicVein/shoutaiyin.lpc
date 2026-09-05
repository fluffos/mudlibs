//手太阴肺经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "手太阴肺经";
}
string VeinTitle()
{
	return "手太陰肺經";
}
string benefit()
{
	return "增加吐故纳新的效率。\n";//tuna,dazuo效率增加。
}
int benefit_effect(object me)
{
	if (me->query("myVeins/"+ThisVein()+"/completed")>=3)
	return 0.33;
	else if (me->query("myVeins/"+ThisVein()+"/completed")==2)
	return 0.2;
	else if (me->query("myVeins/"+ThisVein()+"/completed")==1)
	return 0.1;
	else
	return 0.0;
}
float benefit_times(object me) //or related thing
{   
	if (me->query("myVeins/"+ThisVein()+"/completed")>=3)
	return 1.5;
	else if (me->query("myVeins/"+ThisVein()+"/completed")==2)
	return 1.2;
	else
	return 1.0;
}
int DailyLimit(object me)//一天限制次数
{
	return 600;
}
int Period(object me)//每次消耗时间
{
	return 5;
}
int recover_require()
{
	return 1;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 1;
}
string *AcuPoint_list()//穴位列表
{
	return ({"云门","中府","天府","侠白","尺泽","孔最",
"列缺","经渠","太渊","鱼际","少商"});
}

string vein()
{
	return "
			"+CYN+"手太陰肺經\n"+NOR+F_VEIN->DIVIDE()+"
             云门
		    中府        
				  
				    天府  
				     侠白                     
					 
						   尺泽   
						
							 孔最
							 
							   列缺   
							  经渠     
								太渊
								
								   
								   
									鱼际

									
									  少商 
";
}

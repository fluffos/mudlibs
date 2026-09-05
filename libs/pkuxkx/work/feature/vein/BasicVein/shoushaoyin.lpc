//手少阴心经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "手少阴心经";
}
string VeinTitle()
{
	return "手少陰心經";
}
string benefit()
{
	return "增加临时悟性。\n";//tuna,dazuo效率增加。
}
int *bene_families()
{
	return ({4,11,17,20});
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
	return 800;
	else
	return 1000;
}
int Period(object me)//每次消耗时间
{
	if (F_VEIN->family_id(me)>0&&member_array(F_VEIN->family_id(me),bene_families())!=-1)
	return 10-random(2);
	else
	return 10;
}
int recover_require()
{
	return 5;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 3;
}
string *AcuPoint_list()//穴位列表
{
	return ({"极泉","青灵","少海","灵道","通里","阴郄","神门","少府","少冲"});
}

string vein()
{
	return "
			"+CYN+"手少陰心經\n"+NOR+F_VEIN->DIVIDE()+"
             极泉

			 
			    青灵
			   
			   少海
			
			
		 灵道
		通里
	   阴郄
	  神门
	  
  少府
     少冲
";
}

//手厥阴心包经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "手厥阴心包经";
}
string VeinTitle()
{
	return "手厥阴心包经";
}
string benefit()
{
	return "无。\n";
}
int benefit_effect(object me)
{
	return -1;
}
int benefit_times(object me) //or related thing
{
	return -1;
}
int DailyLimit(object me)//一天限制次数
{
	return 150;
}
int Period(object me)//每次消耗时间
{
	return 15;
}
int recover_require()
{
	return 9;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 5;
}
int ExpConsume()
{
	return 60+random(40); 
}
int PureNeili()//每次冲穴加的纯净内力，不宜太大，对于穴道比较多的脉
{
	return 0;
}
int Purify()//每次冲穴转化的纯净内力
{
	return 2;
}
int Difficulty()
{
	return 4;
}
int ExpBonus()//全部贯通以后一段时间的经验加成%
{
	return 0;
}
int BonusPeriod()//持续多少小时
{
	return 0;
}
string *AcuPoint_list()//穴位列表
{
	return ({"天池","天泉","曲泽","郄门","间使","内关","大陵","劳宫","中冲"});
}

string vein()
{
	return "
			"+WHT+"手厥阴心包经\n"+NOR+F_VEIN->DIVIDE()+"
				天池
						天泉
						
						
						 曲泽
						 
						 
						  郄门
							间使
							 内关
								大陵
								
								 劳宫
								 
								 
									中冲	  		  
";
}

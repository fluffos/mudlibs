//手厥阴心包经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "手少阳三焦经";
}
string VeinTitle()
{
	return "手少阳三焦经";
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
	return 10;//修复走火入魔需要的物品编号。物品在/obj/vein下
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
	return ({"关冲","液门","中渚","阳池","外关","支沟","会宗","三阳络","四渎","天井","清冷渊",
	"消泺","臑会","肩髎","天髎","天牖","翳风","瘛脉","颅息","角孙","耳门","耳和髎","丝竹空"});
}

string vein()
{
	return "
			"+WHT+"手少阳三焦经\n"+NOR+F_VEIN->DIVIDE()+"
			丝竹空	
					耳和髎	角孙
					 耳门	 颅息
							 瘛脉
							翳风
						   天牖
						   
								天髎
									肩髎
										臑会
										
											消泺
											
											  清冷渊
											   天井
											   
											   
											四渎
											
										三阳络
								支沟   会宗
								 外关
							   阳池
							   
								  中渚
								    液门
									
										关冲
";
}

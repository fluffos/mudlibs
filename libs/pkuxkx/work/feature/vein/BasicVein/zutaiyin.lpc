//足太阴脾经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "足太阴脾经";
}
string VeinTitle()
{
	return "足太陰脾經";
}
string benefit()
{
	return "提升闪躲效率。\n";
}
int benefit_effect(object me)
{
	if (me->query("myVeins/"+ThisVein()+"/completed")>=3)
	return 10+random(3);
	if (me->query("myVeins/"+ThisVein()+"/completed")==2)
	return 6+random(5);
	if (me->query("myVeins/"+ThisVein()+"/completed")==1)
	return 3+random(3);
}
int benefit_times(object me) //or related thing
{
	return -1;
}
int DailyLimit(object me)//一天限制次数
{
	return 520;
}
int Period(object me)//每次消耗时间
{
	return 7;
}
int recover_require()
{
	return 4;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 2;
}
int ExpConsume()
{
	return 20+random(10); 
}
int PureNeili()//每次冲穴加的纯净内力，不宜太大，对于穴道比较多的脉
{
	return random(2);
}
int Purify()//每次冲穴转化的纯净内力
{
	return 8+random(5);
}
string *AcuPoint_list()//穴位列表
{
	return ({"隐白","大都","太白","公孙","商丘","三阴交","漏谷","地机","阴陵泉","血海","箕门","冲门","府舍","腹结","大横","腹哀","食窦","天溪","胸乡","周荣","大包"});
}

string vein()
{
	return "
			"+HIB+"足太陰脾經\n"+NOR+F_VEIN->DIVIDE()+"
			周荣
		   胸乡
		   天溪
			
				食窦
	大包
				 腹哀
				 
				 
			   大横
			  腹结
			 
			 府舍
			    冲门
				
				 箕门
				 
				 
				  血海
				   阴陵泉
				   地机
				  漏谷 
				  三阴交
				
			  商丘
		   公孙
		太白
隐白 大都
	
";
}

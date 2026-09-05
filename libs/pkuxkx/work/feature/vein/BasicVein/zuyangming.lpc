//足阳明胃经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "足阳明胃经";
}
string VeinTitle()
{
	return "足陽明胃經";
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
	return 140;
}
int Period(object me)//每次消耗时间
{
	return 20;
}
int recover_require()
{
	return 3;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 2;
}
int ExpConsume()
{
	return 100+random(20); 
}
int PureNeili()//每次冲穴加的纯净内力，不宜太大，对于穴道比较多的脉
{
	return 7+random(6);
}
int Purify()//每次冲穴转化的纯净内力
{
	return 0;
}
string *AcuPoint_list()//穴位列表
{
	return ({"承泣","四白","巨髎","地仓","大迎","颊车","下关","头维","人迎","水突","气舍","缺盆","气户","库房","屋翳","膺窗","乳中",
"乳根","不容","承满","梁门","关门","太乙","滑肉门","天枢","外陵","大巨","水道","归来","气冲","髀关","伏兔","阴市","梁丘","犊鼻",
"足三里","上巨虚","条口","下巨虚","丰隆","解谿","冲阳","陷谷","内庭","厉兑"});
}

string vein()
{
	return "
			"+BLU+"足陽明胃經\n"+NOR+F_VEIN->DIVIDE()+"
			头维									人迎						髀关
												   水突 
										   缺盆	  气舍
							 承泣		  气户									 伏兔
		   下关				四白		 库房
							巨髎		屋翳									  阴市
		  颊车						  膺窗										   梁丘
						 地仓		  乳中 
			   大迎																   犊鼻
									 乳根										  足三里
											不容
											承满									上巨虚
											 梁门
											 关门										条口
											  太乙									丰隆 下巨虚
											  滑肉门
											   天枢
											   外陵											解谿
											    大巨									  冲阳
												 水道									陷谷
												  归来								  内庭
												   气冲								 厉兑
";
}

//足少阴肾经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "足少阴肾经";
}
string VeinTitle()
{
	return "足少陰腎經";
}
string benefit()
{
	return "升级经验折扣。\n";
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
	return 320;
}
int Period(object me)//每次消耗时间
{
	return 8;
}
int recover_require()
{
	return 8;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 4;
}
int ExpConsume()
{
	return 75+random(75); 
}
int PureNeili()//每次冲穴加的纯净内力，不宜太大，对于穴道比较多的脉
{
	return 4+random(2);
}
int Purify()//每次冲穴转化的纯净内力
{
	return 0;
}
int ExpBonus()//全部贯通以后一段时间的经验加成%
{
	return 20;
}
int BonusPeriod()//持续多少小时
{
	return 2;
}
string *AcuPoint_list()//穴位列表
{
	return ({"涌泉","然谷","太溪","大钟","水泉","照海","复溜","交信","筑宾","阴谷","横骨","大赫",
	"气穴","四满","中注","肓俞","商曲","石关","阴都","通谷","幽门","步廊","神封","灵墟","神藏",
	"彧中","俞府"});
}

string vein()
{
	return "
			"+WHT+"足少陰腎經\n"+NOR+F_VEIN->DIVIDE()+"
                       俞府                                   阴谷
                      彧中
                     神藏
                     灵墟                                       筑宾
					神封
                   步廊                                        复溜
                                                                 太溪
                        幽门
                       通谷                                     交信
                       阴都	  石关                         照海    大钟            
                      商曲                               然谷    水泉
                    肓俞	                                 涌泉
                    中注
                   四满
                  气穴
                
                大赫
                横骨				
";
}

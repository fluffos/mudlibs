//足太阳膀胱经
#include <ansi.h>
inherit F_CLEAN_UP;
string ThisVein()//经脉名称
{
	return "足太阳膀胱经";
}
string VeinTitle()
{
	return "足太陽膀胱經";
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
	return 150;
}
int Period(object me)//每次消耗时间
{
	return 15;
}
int recover_require()
{
	return 7;//修复走火入魔需要的物品编号。物品在/feature/vein/obj/下
}
int Level()
{
	return 4;
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
	return 3;
}
int ExpBonus()//全部贯通以后一段时间的经验加成%
{
	return 30;
}
int BonusPeriod()//持续多少小时
{
	return 4;
}
string *AcuPoint_list()//穴位列表
{
	return ({"睛明","攒竹","眉冲","曲差","五处","承光","通天","络却","玉枕","天柱","大杼","风门","肺俞","厥阴俞",
	"心俞","督俞","膈俞","肝俞","胆俞","脾俞","胃俞","三焦俞","肾俞","气海俞","大肠俞","关元俞","小肠俞","膀胱俞",
	"中膂俞","白环俞","上髎","次髎","中髎","下髎","会阳","承扶","殷门","浮郄","委阳","委中","附分","魄户","膏肓",
	"神堂","譩譆","膈关","魂门","阳纲","意舍","胃仓","肓门","志室","胞肓","秩边","合阳","承筋","承山","飞扬","跗阳",
	"昆仑","仆参","申脉","金门","京骨","束骨","足通谷","至阴"});
}

string vein()
{
	return "
			"+WHT+"足太陽膀胱經\n"+NOR+F_VEIN->DIVIDE()+"
					                               承光
					通天                           五处
					络却                         眉冲  曲差
					玉枕                           攒竹
				    天柱                             睛明
					 
					  大杼
				  附分    风门
                 魄户	  肺俞	
                 膏肓     厥阴俞
				 神堂     心俞                                        会阳
				  譩譆     督俞
				 膈关      膈俞                                  承扶 
				 魂门      肝俞
				 阳纲      胆俞                                  殷门
				 意舍      脾俞                           浮郄
				胃仓      胃俞                           委阳 委中
				肓门                                           合阳 
				 志室      三焦俞                             承筋
                          肾俞                               承山
                          气海俞                           飞扬
                 大肠俞               
                          关元俞  上髎                    跗阳
                  胞肓			  次髎                   昆仑
                          小肠俞   中髎           金门  申脉  仆参
                  秩边	  膀胱俞   下髎	    束骨  京骨    
                          中膂俞          至阴  足通谷
						 白环俞	   
							   会阳       		  		  
";
}

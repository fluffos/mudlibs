//Cracked by Kafei
//default data set

static int OPPOSE_DROP_EXP=200;//200;



static int MASTER_CALL_IN_EXP=300;
static int FINISH_JOB_EXP=100;//100;

static int MASTER_CALL_IN_CON=10;
static int OPPOSE_DROP_CON=5;
static int FINISH_JOB_CON=2;

//When assess meeting start, will dealy ASSESS_DELAY time do it.
static int ASSESS_DELAY=300;
int ASSESS_NUM=10000;
//门派评定的基数
//
int assess_wd=ASSESS_NUM*7/10;
int assess_xx=ASSESS_NUM*5/10;
int assess_hs=ASSESS_NUM*8/10;
int assess_th=ASSESS_NUM*7/10;
int assess_gb=ASSESS_NUM*8/10;
int assess_em=ASSESS_NUM*5/10;
int assess_bt=ASSESS_NUM*6/10;
int assess_qz=ASSESS_NUM*8/10;
int assess_xs=ASSESS_NUM*5/10;
int assess_dl=ASSESS_NUM*5/10;
int assess_sl=ASSESS_NUM*5/10;


//武林各门派缺省参数设计

//int add_orgdata(string family_name,mapping strategy,int luck,int money,mapping power)
/************************************************************************************/
//各门派策略最大为100,表示%100，最小为0,表示%0.
//oppose_pker:反pk,维护江湖正义，产生杀pker任务
//support_pker:支持PK策略，产生Pk任务

//protect:保护策略，用来产生保护性质的任务
//plunder:抢夺策略，用来产生抢夺性质的任务

//destroy：破坏策略，用来产生破坏性质的任务
//develop:发展策略，用来产生发展性质的任务

//business:商业发展策略
//generally：一般策略
//总体策略的和最大为100,各种策略的数值表示相对的比率。

//武当派
mapping strategy_wd=([
				   //竞争性参数
				   "oppose_pker"		:30,
				   "support_pker"		:0,
				   
				   "protect"			:30,
				   "plunder"			:0,
				   
//     		       "develop"			:20,
//				   "destroy"			:-50,
			  
				   //传统性参数
				   "business"			:0,
				   "generally"			:40,

]);
//星宿派
mapping strategy_xx=([
				   //竞争性参数
				   "oppose_pker"		:0,
				   "support_pker"		:30,
				   
				   "protect"			:0,
				   "plunder"			:30,
				   
				   //传统性参数
				   "business"			:0,
				   "generally"			:40,

]);
//华山派
mapping strategy_hs=([
				   //竞争性参数
				   "oppose_pker"		:40,
				   "support_pker"		:0,
				   
				   "protect"			:20,
				   "plunder"			:0,
				   
			  
				   //传统性参数
				   "business"			:10,
				   "generally"			:30,

]);
//桃花岛
mapping strategy_th=([
				   //竞争性参数
				   "oppose_pker"		:15,
				   "support_pker"		:15,
				   
				   "protect"			:15,
				   "plunder"			:15,
				   
			  
				   //传统性参数
				   "business"			:15,
				   "generally"			:25,

]);
//丐帮
mapping strategy_gb=([
				   //竞争性参数
				   "oppose_pker"		:20,
				   "support_pker"		:20,
				   
				   "protect"			:20,
				   "plunder"			:20,
				   
			  
				   //传统性参数
				   "business"			:0,
				   "generally"			:20,

]);
//峨嵋派
mapping strategy_em=([
				   //竞争性参数
				   "oppose_pker"		:50,
				   "support_pker"		:0,
				   
				   "protect"			:10,
				   "plunder"			:0,
				   
			  
				   //传统性参数
				   "business"			:0,
				   "generally"			:40,

]);
//白驼山
mapping strategy_bt=([
				   //竞争性参数
				   "oppose_pker"		:0,
				   "support_pker"		:30,
				   
				   "protect"			:0,
				   "plunder"			:30,
				   
			  
				   //传统性参数
				   "business"			:20,
				   "generally"			:20,

]);
//全真教
mapping strategy_qz=([
				   //竞争性参数
				   "oppose_pker"		:30,
				   "support_pker"		:0,
				   
				   "protect"			:50,
				   "plunder"			:0,
				   
			  
				   //传统性参数
				   "business"			:0,
				   "generally"			:20,

]);
//雪山派
mapping strategy_xs=([
				   //竞争性参数
				   "oppose_pker"		:0,
				   "support_pker"		:20,
				   
				   "protect"			:15,
				   "plunder"			:15,
				   
			  
				   //传统性参数
				   "business"			:0,
				   "generally"			:50,

]);
//大理
mapping strategy_dl=([
				   //竞争性参数
				   "oppose_pker"		:10,
				   "support_pker"		:0,
				   
				   "protect"			:15,
				   "plunder"			:0,
				   
			  
				   //传统性参数
				   "business"			:40,
				   "generally"			:35,

]);
//少林派
mapping strategy_sl=([
				   //竞争性参数
				   "oppose_pker"		:0,
				   "support_pker"		:0,
				   
				   "protect"			:70,
				   "plunder"			:0,
				   
			  
				   //传统性参数
				   "business"			:0,
				   "generally"			:30,

]);








/***********************************************************************************/
//各个门派的运气参数设计
int luck_wd=1+random(3);
int luck_xx=2+random(3);
int luck_hs=1+random(1);
int luck_th=3+random(3);
int luck_gb=2+random(3);
int luck_em=1+random(3);
int luck_bt=1+random(3);
int luck_qz=1+random(3);
int luck_xs=2+random(3);
int luck_dl=1+random(1);
int luck_sl=1+random(2);
/***********************************************************************************/
//各个门派产生任务的比率初始设定
int luck_wdrate=30;
int luck_xxrate=20;
int luck_hsrate=30;
int luck_gbrate=40;
int luck_thrate=15;
int luck_qzrate=35;
int luck_dlrate=10;
int luck_slrate=40;
int luck_btrate=20;
int luck_emrate=10;
int luck_xsrate=5;

//门派经济
//将全部江湖的money设置成100，每个门派按照比率拥有。
int money_wd=5;
int money_xx=15;
int money_hs=10;
int money_th=15;
int money_gb=5;
int money_em=5;
int money_bt=10;
int money_qz=5;
int money_xs=15;
int money_dl=10;
int money_sl=5;
/***********************************************************************************/
//门派势力
//将全部江湖的势力按地域划分，最高100，每个门派按照比率拥有。
/*　中原
　　主要城市：襄阳。
　　所含区域：山东、山西、陕西、河南、湖北、湖南。
　　现有地方：嵩山少林、湖北武当山、终南山、山东泰山、黄河边、洞庭湖。

　江南
　　主要城市：扬州。
　　所含区域：安徽、江苏、浙江、江西、福建。
　　现有地方：杭州、太湖、福建泉州、嘉兴、安徽黄山。

　南疆
　　主要城市：大理。
　　所含区域：四川、贵州、云南、广东、广西。
　　现有地方：四川峨嵋、云南苗疆。

　西域
　　主要城市：灵州。
　　所含区域：宁夏、甘肃、青海、新疆、西藏。
　　现有地方：天山、昆仑山、祁连山、藏边大雪山、西域。
  东北
　　主要城市：北京。
　　所含区域：河北、辽宁、吉林、黑龙江、内蒙古。
　　现有地方：长白山、辽东神龙岛。
*/
//wudang
mapping power_wd=([
				   //竞争性参数
				   "中原"		:20,
				   "江南"		:10,
				   "南疆"		:5,
				   "西域"		:0,
				   "东北"		:5,
				   

]);
//xingxiu
mapping power_xx=([
				   //竞争性参数
				   "中原"		:0,
				   "江南"		:5,
				   "南疆"		:0,
				   "西域"		:30,
				   "东北"		:5,
				   

]);
//huashan
mapping power_hs=([
				   //竞争性参数
				   "中原"		:10,
				   "江南"		:10,
				   "南疆"		:5,
				   "西域"		:0,
				   "东北"		:5,
				   

]);

//taohuadao
mapping power_th=([
				   //竞争性参数
				   "中原"		:5,
				   "江南"		:10,
				   "南疆"		:0,
				   "西域"		:0,
				   "东北"		:5,
				   

]);

//gaibang
mapping power_gb=([
				   //竞争性参数
				   "中原"		:20,
				   "江南"		:20,
				   "南疆"		:20,
				   "西域"		:10,
				   "东北"		:20,
]);

//emei
mapping power_em=([
				   //竞争性参数
				   "中原"		:10,
				   "江南"		:10,
				   "南疆"		:0,
				   "西域"		:0,
				   "东北"		:5,
]);
//baituo
mapping power_bt=([
				   //竞争性参数
				   "中原"		:5,
				   "江南"		:5,
				   "南疆"		:5,
				   "西域"		:30,
				   "东北"		:5,
]);
//quanzhen
mapping power_qz=([
				   //竞争性参数
				   "中原"		:5,
				   "江南"		:10,
				   "南疆"		:5,
				   "西域"		:0,
				   "东北"		:5,
]);

//xueshan
mapping power_xs=([
				   //竞争性参数
				   "中原"		:0,
				   "江南"		:5,
				   "南疆"		:5,
				   "西域"		:30,
				   "东北"		:5,
]);

//dali
mapping power_dl=([
				   //竞争性参数
				   "中原"		:5,
				   "江南"		:5,
				   "南疆"		:50,
				   "西域"		:0,
				   "东北"		:5,
]);
//shaolin
mapping power_sl=([
				   //竞争性参数
				   "中原"		:20,
				   "江南"		:10,
				   "南疆"		:5,
				   "西域"		:0,
				   "东北"		:5,
]);








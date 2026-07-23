// Purpose : Spy job
// Creator : Numa@Sj 2000.4.29

mapping *spy = ({
	(["family":	"华山派",				  // Which Party
	"item":		HIM"紫霞秘籍"NOR,			  // What Treasure
	"item_desc":	"这是华山派紫霞功的修炼秘籍，书页泛黄。\n", // Treasure's Description
	"generation":	"12",					  // Top Master Generation
	"canask":	"linghu chong,yue buqun,ning zhongze",]),					  // Whom Can Ask

	(["family":	"少林派",
	"item":		HIR"易筋经秘籍"NOR,
	"item_desc":	"这是少林寺武学精华易筋经的修炼总法。\n",	
	"generation":	"34",
	"canask":	"xuanci dashi,xuannan dashi,xuanbei dashi,xuanji dashi,huizhen zunzhe,huixiu zunzhe,du nan,du jie",]),

	(["family":	"明教",
	"item":		HIB"乾坤大挪移秘籍"NOR,
	"item_desc":	"这是明教教主张无忌自行抄录的一簿乾坤大挪移心法秘籍。\n",
	"generation":	"34",
	"canask":	"zhang wuji,yin tianzheng,fan yao,yang xiao,leng qian",]),

	(["family":	"大轮寺",
	"item":		HIC"血刀秘籍"NOR,
	"item_desc":	"这是雪山派血刀老祖的一本练功秘籍，书页泛黄。\n",	
	"generation":	"10",
	"canask":	"jiumo zhi,xuedao laozu,lingzhi shangren,sang jie,wenwo er,mohe basi,hu bayin,",]),

	(["family":	"丐帮",
	"item":		HIW"打狗棒秘籍"NOR,
	"item_desc":	"这是丐帮长老洪七公所写的打狗棒心法及棒诀。\n",
	"generation":	"17",
	"canask":	"hong qigong,lu youjiao,song zhanglao,jiang zhanglao,xi zhanglao,quan guanqing,chen zhanglao",]),

	(["family":	"天龙寺",
	"item":		HIG"六脉神剑剑谱"NOR,
	"item_desc":	"这是大理段氏交由天龙寺守护的六脉神剑剑谱。\n",
	"generation":	"12",
	"canask":	"kurong zhanglao,benyin dashi,benxiang dashi,benguan dashi,duan zhengming,duan zhengchun,",]),

	(["family":	"星宿派",
	"item":		HIM"神木王鼎"NOR,
	"item_desc":	"一只雕琢而成的暗黄色小木鼎, 木理之间隐隐泛出红丝。鼎侧有五个铜钱大的圆孔，木鼎齐颈出有一道细缝，似乎上下分为两截。",
	"generation":	"1",
	"canask":	"ding chunqiu,zhaixing zi,anran zi,tianlang zi,shihou zi,azi,",]),
/*
	(["family":	"",
	"item":		"",
	"item_desc":	"",
	"generation":	"",
	"canask":	"",]),
*/
});

mapping place = ([
	"华山派":	({"/d/huashan/qinshi",
			"/d/huashan/xiaoxi",
			"/d/huashan/siguoya",
			"/d/huashan/wuqiku",
			"/d/huashan/yaofang",}),
	"少林派":	({"/d/shaolin/yaowang",
			"/d/shaolin/luohan9",
			"/d/shaolin/banruo1",
			"/d/shaolin/zdyuan",}),
	"明教":		({"/d/mingjiao/jyt",
			"/d/mingjiao/bishui",
			"/d/mingjiao/shiwang",
			"/d/mingjiao/xting",}),
	"大轮寺":	({"/d/xueshan/dadian",
			"/d/xueshan/zhudubadian",
			"/d/xueshan/yushengdian",
			"/d/xueshan/boluomiyuan",}),
	"丐帮":		({"/d/gb/fenduo2",
			"/d/gb/pomiao",
			"/d/gb/xinglin9",}),
	"天龙寺":	({"/d/tls/baodian",
			"/d/tls/gfd",
			"/d/tls/ta3",
			"/d/tls/ta2",}),
	"星宿派":	({"/d/xingxiu/ryd1",
			"/d/xingxiu/ryd",
			"/d/xingxiu/shanshi",
			"/d/xingxiu/house",}),
]);
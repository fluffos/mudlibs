#include <ansi.h>

#pragma optimize
#pragma save_binary

inherit F_SAVE;
inherit F_DBASE;

// 江湖传言，某某武功被高人破解，威力下降
// 特殊dodge及parry应该在skill本身来处理
// skilllevel - 100;
// (scores / users - score / user) / 10
#define TO_EFFECT(x, y, a, b)      ((y / 20) < 20 ? 20 - b : (y / 20) - b) + (x / y - a / b) / 10

mapping all_record = ([ ]);
mapping all_skills = ([ ]);

nosave mapping skillsetup = ([
	// 宗师武功
	"never-defeated"  : ([ "attack" : 180, "parry"  : 180, "dodge"  : 150, "damage" : 160, "force" : 150 ]), 
	"jiuyin-shengong" : ([ "attack" : 160, "parry"  : 150, "dodge"  : 150, "damage" : 160, "force" : 180 ]), 
	"bluesea-force"   : ([ "attack" : 150, "parry"  : 150, "dodge"  : 150, "damage" : 160, "force" : 180 ]), 
	"kuihua-mogong"   : ([ "attack" : 170, "parry"  : 150, "dodge"  : 180, "damage" : 150, "force" : 140 ]),
	// 公共武功 
	"taixuan-gong"    : ([ "attack" : 150, "parry"  : 150, "dodge"  : 150, "damage" : 150, "force" : 150 ]), 
	"mingyu-gong"     : ([ "attack" : 140, "parry"  : 160, "dodge"  : 160, "damage" : 140, "force" : 150 ]), 
	"jiuyin-baiguzhao": ([ "attack" : 140, "parry"  : 100, "dodge"  : 90, "damage" : 150, "force" : 150 ]), 
	"xuanming-zhang"  : ([ "attack" : 120, "parry"  : 90, "dodge"  : 90, "damage" : 130, "force" : 150 ]), 
	"baihua-cuoquan"  : ([ "attack" : 130, "parry"  : 110, "dodge"  : 110, "damage" : 110, "force" : 150 ]), 
	"jinshe-zhang"    : ([ "attack" : 120, "parry"  : 120, "dodge"  : 120, "damage" : 120, "force" : 110 ]), 
	"bizhen-qingzhang": ([ "attack" : 140, "parry"  : 90, "dodge"  : 100, "damage" : 100, "force" : 140 ]), 
	"tie-zhang"       : ([ "attack" : 160, "parry"  : 100, "dodge"  : 80, "damage" : 150, "force" : 140 ]), 
	"huanyin-zhi"     : ([ "attack" : 120, "parry"  : 100, "dodge"  : 110, "damage" : 110, "force" : 160 ]), 
	"ningxue-shenzhao": ([ "attack" : 130, "parry"  : 100, "dodge"  : 110, "damage" : 130, "force" : 130 ]),	 
	"wuhu-duanmendao" : ([ "attack" : 140, "parry"  : 90, "dodge"  : 90, "damage" : 130 ]),
	"jinshe-jian"     : ([ "attack" : 150, "parry"  : 120, "dodge"  : 120, "damage" : 140 ]),
	"jinshe-zhui"     : ([ "attack" : 140, "parry"  : 110, "dodge"  : 110, "damage" : 130 ]),
	"sanfen-jianshu"  : ([ "attack" : 150, "parry"  : 90, "dodge"  : 140, "damage" : 100 ]),
	"zijinbagua-dao"  : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 150 ]),
	"zigai-jian"      : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 130 ]),
	"zhurong-jian"    : ([ "attack" : 130, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),
	"yuenv-jian"      : ([ "attack" : 150, "parry"  : 120, "dodge"  : 120, "damage" : 140 ]),   
	"yunlong-shenfa"  : ([ "dodge"  : 120 ]),
	"zhuangzi-wu"     : ([ "dodge"  : 120 ]),
	"shenxing-baibian": ([ "dodge"  : 120 ]),
	"shexing-lifan"   : ([ "dodge"  : 135 ]),
	// 少林
	"fengyun-shou"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"qianye-shou"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"jingang-quan"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 90, "force" : 100 ]), 
	"luohan-quan"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 80, "force" : 100 ]), 
	"banruo-zhang"    : ([ "attack" : 100, "parry"  : 90, "dodge"  : 90, "damage" : 100, "force" : 100 ]), 
	"sanhua-zhang"    : ([ "attack" : 90, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 90 ]), 
	"shenzhang-bada"  : ([ "attack" : 90, "parry"  : 90, "dodge"  : 90, "damage" : 100, "force" : 100 ]), 
	"xumishan-zhang"  : ([ "attack" : 110, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 130 ]), 
	"longzhua-gong"   : ([ "attack" : 130, "parry"  : 80, "dodge"  : 100, "damage" : 140, "force" : 100 ]), 
	"yingzhua-gong"   : ([ "attack" : 130, "parry"  : 80, "dodge"  : 80, "damage" : 130, "force" : 100 ]), 
	"nianhua-zhi"     : ([ "attack" : 120, "parry"  : 100, "dodge"  : 130, "damage" : 100, "force" : 100 ]), 
	"yizhi-chan"      : ([ "attack" : 140, "parry"  : 110, "dodge"  : 110, "damage" : 130, "force" : 140 ]), 
	"xiuluo-zhi"      : ([ "attack" : 90, "parry"  : 100, "dodge"  : 100, "damage" : 130, "force" : 130 ]), 
	"wuxiang-zhi"     : ([ "attack" : 130, "parry"  : 110, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"duoluoye-zhi"    : ([ "attack" : 90, "parry"  : 100, "dodge"  : 100, "damage" : 90, "force" : 160 ]), 
	"jingang-zhi"     : ([ "attack" : 100, "parry"  : 90, "dodge"  : 100, "damage" : 110, "force" : 130 ]), 
	"yipai-liangsan"  : ([ "attack" : 150, "parry"  : 130, "dodge"  : 110, "damage" : 140, "force" : 150 ]),	 
	"cibei-dao"       : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"xiuluo-dao"      : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"weituo-gun"      : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"zui-gun"	 : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"wuchang-zhang"   : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"pudu-zhang"      : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"fumo-jian"       : ([ "attack" : 120, "parry"  : 110, "dodge"  : 100, "damage" : 140 ]),
	"damo-jian"       : ([ "attack" : 140, "parry"  : 140, "dodge"  : 130, "damage" : 150 ]),
	"riyue-bian"      : ([ "attack" : 160, "parry"  : 120, "dodge"  : 140, "damage" : 140 ]), 
	"jingang-buhuaiti": ([ "parry"  : 160 ]),	      
	"shaolin-shenfa"  : ([ "dodge"  : 130 ]),
	// 武当
	"paiyun-shou"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"wudang-zhang"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"yitian-zhang"    : ([ "attack" : 120, "parry"  : 90, "dodge"  : 100, "damage" : 120, "force" : 120 ]), 
	"zhenshan-zhang"  : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 90, "force" : 90 ]), 
	"huzhua-shou"     : ([ "attack" : 90, "parry"  : 100, "dodge"  : 80, "damage" : 130, "force" : 110 ]), 
	"taiji-quan"      : ([ "attack" : 140, "parry"  : 160, "dodge"  : 130, "damage" : 140, "force" : 150 ]), 
	"xuanxu-dao"      : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"taiji-dao"       : ([ "attack" : 100, "parry"  : 120, "dodge"  : 100, "damage" : 100 ]),
	"wudang-jian"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"raozhi-roujian"  : ([ "attack" : 120, "parry"  : 120, "dodge"  : 100, "damage" : 120 ]),
	"shenmen-jian"    : ([ "attack" : 130, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),
	"taiji-jian"      : ([ "attack" : 140, "parry"  : 160, "dodge"  : 120, "damage" : 140 ]),	
	"tiyunzong"       : ([ "dodge"  : 130 ]),
	// 娥眉
	"jinding-zhang"   : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"cuixin-zhang"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 130, "force" : 130 ]), 
	"piaoxue-zhang"   : ([ "attack" : 110, "parry"  : 90, "dodge"  : 90, "damage" : 130, "force" : 130 ]), 
	"tiangang-zhi"    : ([ "attack" : 130, "parry"  : 80, "dodge"  : 110, "damage" : 100, "force" : 90 ]), 
	"huifeng-jian"    : ([ "attack" : 140, "parry"  : 140, "dodge"  : 120, "damage" : 160 ]),
	"yitian-jian"     : ([ "attack" : 130, "parry"  : 120, "dodge"  : 120, "damage" : 140 ]),
	"yanxing-dao"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"yinlong-bian"    : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 140 ]),	
	"zhutian-bu"      : ([ "dodge"  : 100 ]),
	// 华山
	"hunyuan-zhang"   : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 110, "force" : 150 ]), 
	"poyu-quan"       : ([ "attack" : 110, "parry"  : 120, "dodge"  : 100, "damage" : 110, "force" : 110 ]), 
	"dugu-jiujian"    : ([ "attack" : 175, "parry"  : 160, "dodge"  : 130, "damage" : 140 ]),
	"chongling-jian"  : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"huashan-jianfa"  : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),
	"kuangfeng-jian"  : ([ "attack" : 130, "parry"  : 110, "dodge"  : 100, "damage" : 130 ]),
	"yunv-sword"      : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),
	"fanliangyi-dao"  : ([ "attack" : 130, "parry"  : 120, "dodge"  : 120, "damage" : 120 ]),	
	"huashan-shenfa"  : ([ "dodge"  : 100 ]),
	"feiyan-huixiang" : ([ "dodge"  : 110 ]),
	// 丐帮
	"dragon-strike"   : ([ "attack" : 150, "parry"  : 110, "dodge"  : 100, "damage" : 200, "force" : 180 ]), 
	"shexing-diaoshou": ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"chansi-shou"     : ([ "attack" : 100, "parry"  : 120, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"jueming-tui"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 140, "damage" : 110, "force" : 90 ]), 
	"changquan"       : ([ "attack" : 80, "parry"  : 100, "dodge"  : 100, "damage" : 80, "force" : 80 ]), 
	"dagou-bang"      : ([ "attack" : 140, "parry"  : 140, "dodge"  : 120, "damage" : 140 ]),
	"fengmo-zhang"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 110 ]),
	"jiaohua-bangfa"  : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"fumo-zhang"      : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 110 ]),
	"liuhe-dao"       : ([ "attack" : 100, "parry"  : 100, "dodge"  : 90,  "damage" : 100 ]),
	"mantianhuayu"    : ([ "attack" : 140, "parry"  : 80,  "dodge"  : 120, "damage" : 120 ]),	
	"feiyan-zoubi"    : ([ "dodge"  : 90 ]),
	"xiaoyaoyou"      : ([ "attack" : 90, "parry"  : 90, "dodge"  : 110, "damage" : 90, "force" : 90 ]),
	// 桃花
	"tanzhi-shentong" : ([ "attack" : 160, "parry"  : 130, "dodge"  : 110, "damage" : 140, "force" : 140 ]), 
	"luoying-shenzhang": ([ "attack" : 130, "parry"  : 100, "dodge"  : 100, "damage" : 120, "force" : 120 ]), 
	"xuanfeng-tui"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]), 
	"lanhua-shou"     : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 90, "force" : 90 ]), 
	"luoying-shenjian": ([ "attack" : 120, "parry"  : 120, "dodge"  : 100, "damage" : 120 ]),
	"yuxiao-jianfa"     : ([ "attack" : 140, "parry"  : 140, "dodge"  : 130, "damage" : 150 ]),
	"canglang-bian"   : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),	
	"luoying-shenfa"  : ([ "dodge"  : 110 ]),
	// 星宿
	"chousui-zhang"   : ([ "attack" : 120, "parry"  : 100, "dodge"  : 80, "damage" : 160, "force" : 160 ]), 
	"sanyin-zhua": ([ "attack" : 130, "parry"  : 100, "dodge"  : 100, "damage" : 140, "force" : 130 ]), 
	"tianshan-zhang" : ([ "attack" : 120, "parry"  : 120, "dodge"  : 100, "damage" : 120 ]),
	"chanhun-suo"    : ([ "attack" : 100, "parry"  : 140, "dodge"  : 100, "damage" : 100 ]),	
	"zhaixing-gong"   : ([ "dodge"  : 100 ]),
	"feixing-shu"     : ([ "attack" : 140, "parry"  : 60, "dodge"  : 90, "damage" : 100 ]),
	// 逍遥
	"zhemei-shou"     : ([ "attack" : 140, "parry"  : 80, "dodge"  : 100, "damage" : 130, "force" : 140 ]), 
	"qingyun-shou"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"ruyi-dao"       : ([ "attack" : 140, "parry"  : 110, "dodge"  : 100, "damage" : 130 ]),
	"liuyue-jian"    : ([ "attack" : 130, "parry"  : 120, "dodge"  : 120, "damage" : 140 ]),	
	"lingbo-weibu"    : ([ "dodge"  : 200 ]),
	// 灵鹫
	"liuyang-zhang"   : ([ "attack" : 140, "parry"  : 120, "dodge"  : 100, "damage" : 140, "force" : 150 ]),
	"youming-guizhao" : ([ "attack" : 110, "parry"  : 110, "dodge"  : 120, "damage" : 150, "force" : 150 ]),
	"tianyu-qijian"  : ([ "attack" : 140, "parry"  : 110, "dodge"  : 100, "damage" : 140 ]),
	"wuliang-jian"   : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),
	"zhougong-jian"  : ([ "attack" : 160, "parry"  : 120, "dodge"  : 100,  "damage" : 120 ]),	
	"yueying-wubu"    : ([ "dodge"  : 100 ]),
	// 古墓
	"meinv-quan"      : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"sad-strike"      : ([ "attack" : 150, "parry"  : 140, "dodge"  : 120, "damage" : 160, "force" : 170 ]),
	"chilian-shenzhang": ([ "attack" : 110, "parry"  : 100, "dodge"  : 100, "damage" : 130, "force" : 130 ]),
	"wudu-shenzhang"  : ([ "attack" : 110, "parry"  : 100, "dodge"  : 100, "damage" : 110, "force" : 110 ]),
	"sanwu-shou"      : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110, "force" : 110 ]),
	"tianluo-diwang"  : ([ "attack" : 110, "parry"  : 100, "dodge"  : 80, "damage" : 100, "force" : 100 ]),   
	"yunv-jian"      : ([ "attack" : 120, "parry"  : 100, "dodge"  : 140, "damage" : 120 ]),
	"xuantie-jian"   : ([ "attack" : 140, "parry"  : 120, "dodge"  : 100, "damage" : 160 ]),
	"yinsuo-jinling" : ([ "attack" : 120, "parry"  : 90,  "dodge"  : 140, "damage" : 120 ]),
	"yunzhou-fufa"   : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),
	"yufeng-zhen"    : ([ "attack" : 120, "parry"  : 90,  "dodge"  : 120, "damage" : 120 ]),
	"bingpo-shenzhen": ([ "attack" : 120, "parry"  : 90,  "dodge"  : 120, "damage" : 140 ]),
	"yunv-shenfa"     : ([ "dodge"  : 100 ]),	
	// 全真
	"xiantian-gong"   : ([ "attack" : 150, "parry"  : 150, "dodge"  : 130, "damage" : 150, "force" : 170 ]),
	"chunyang-quan"   : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"kongming-quan"   : ([ "attack" : 120, "parry"  : 150, "dodge"  : 110, "damage" : 110, "force" : 130 ]),
	"haotian-zhang"   : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"chongyang-shenzhang": ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 90 ]),
	"zhongnan-zhi"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 90, "force" : 100 ]),    
	"quanzhen-jian"  : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),
	"duanyun-bian"   : ([ "attack" : 150, "parry"  : 120, "dodge"  : 140, "damage" : 140 ]),	
	"jinyan-gong"     : ([ "dodge"  : 120 ]),
	// 神龙
	"yingxiong-sanzhao": ([ "attack" : 110, "parry"  : 100, "dodge"  : 100, "damage" : 110, "force" : 100 ]),
	"shenlong-bashi"   : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"huagu-mianzhang"  : ([ "attack" : 140, "parry"  : 130, "dodge"  : 100, "damage" : 130, "force" : 160 ]),
	"shenlong-jian"  : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"shedao-qigong"  : ([ "attack" : 140, "parry"  : 120, "dodge"  : 100, "damage" : 150 ]),
	"yixing-bufa"     : ([ "dodge"  : 100 ]),
	// 明教
	"shenghuo-quan"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"qishang-quan"     : ([ "attack" : 130, "parry"  : 110, "dodge"  : 100, "damage" : 150, "force" : 150 ]),
	"guangming-zhang"  : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"hanbing-mianzhang": ([ "attack" : 110, "parry"  : 100, "dodge"  : 100, "damage" : 90, "force" : 110 ]),
	"yingzhua-shou"    : ([ "attack" : 110, "parry"  : 90, "dodge"  : 90, "damage" : 110, "force" : 110 ]),
	"jiuyang-shengong": ([ "attack" : 150, "parry"  : 140, "dodge"  : 140, "damage" : 160, "force" : 200 ]),	 
	"liehuo-jian"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"shenghuo-ling"  : ([ "attack" : 140, "parry"  : 100, "dodge"  : 100, "damage" : 140 ]),
	"qiankun-danuoyi" : ([ "parry"  : 200 ]),	
	"lingxu-bu"       : ([ "dodge"  : 90 ]),
	"qingfu-shenfa"   : ([ "dodge"  : 130 ]),
	// 密宗
	"shenzhaojing"     : ([ "attack" : 160, "parry"  : 120, "dodge"  : 110, "damage" : 150, "force" : 150 ]),
	"yujiamu-quan"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"dashou-yin"       : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 120, "force" : 120 ]),
	"longxiang-gong"   : ([ "attack" : 140, "parry"  : 120, "dodge"  : 110, "damage" : 130, "force" : 150 ]),
	"huoyan-dao"       : ([ "attack" : 110, "parry"  : 100, "dodge"  : 100, "damage" : 130, "force" : 130 ]),
	"xuedao-daofa"   : ([ "attack" : 160, "parry"  : 120, "dodge"  : 110, "damage" : 160 ]),
	"mingwang-jian"  : ([ "attack" : 140, "parry"  : 100, "dodge"  : 90,  "damage" : 140 ]),
	"liancheng-jianfa" : ([ "attack" : 160, "parry"  : 100, "dodge"  : 100, "damage" : 140 ]),
	"xiangmo-chu"    : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 120 ]),
	"riyue-lun"      : ([ "attack" : 140, "parry"  : 90,  "dodge"  : 130, "damage" : 140 ]),
	"shenkong-xing"   : ([ "dodge"  : 100 ]),
	// 日月
	"tianmo-zhang"     : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110, "force" : 110 ]),
	"shiying-shenzhao" : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110, "force" : 110 ]),
	"xuwu-piaomiao"    : ([ "attack" : 120, "parry"  : 110, "dodge"  : 110, "damage" : 110, "force" : 110 ]),
	"fengyun-bianhuan" : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110, "force" : 110 ]),
	"huanmo-longtianwu": ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110, "force" : 130 ]),
	"tianmo-shou"      : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110, "force" : 110 ]),
	"pixie-jian"      : ([ "attack" : 170, "parry"  : 120, "dodge"  : 180, "damage" : 150, "force" : 140 ]), 
	"riyue-jian"     : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110 ]),
	"tianmo-jian"    : ([ "attack" : 120, "parry"  : 120, "dodge"  : 120, "damage" : 120 ]),
	"tianmo-dao"     : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110 ]),
	"pili-daofa"     : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110 ]),
	"tianmo-gun"     : ([ "attack" : 110, "parry"  : 110, "dodge"  : 110, "damage" : 110 ]),
	"liushui-bian"   : ([ "attack" : 140, "parry"  : 110, "dodge"  : 110, "damage" : 140 ]),
	"xinghui-canlan" : ([ "attack" : 110, "parry"  : 110, "dodge"  : 120, "damage" : 120 ]),
	"piaomiao-shenfa" : ([ "dodge"  : 80 ]),
	// 欧阳
	"hamagong"	 : ([ "attack" : 150, "parry"  : 130, "dodge"  : 120, "damage" : 150, "force" : 160 ]),
	"shentuo-zhang"    : ([ "attack" : 110, "parry"  : 90, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"lingshe-quan"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 110, "force" : 90 ]),
	"shedu-qiqiao"     : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"lingshe-zhangfa": ([ "attack" : 100, "parry"  : 120, "dodge"  : 120, "damage" : 140 ]),
	"baibian-daxue"  : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"chanchu-bufa"    : ([ "dodge"  : 130 ]),
	// 慕容
	"qixing-quan"      : ([ "attack" : 90, "parry"  : 100, "dodge"  : 90, "damage" : 100, "force" : 90 ]),
	"xingyi-zhang"     : ([ "attack" : 100, "parry"  : 90, "dodge"  : 100, "damage" : 110, "force" : 100 ]),
	"canhe-zhi"	: ([ "attack" : 150, "parry"  : 120, "dodge"  : 110, "damage" : 150, "force" : 150 ]),
	"murong-jianfa"  : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"longcheng-shendao" : ([ "attack" : 120, "parry"  : 100, "dodge"  : 100, "damage" : 130 ]),
	"murong-daofa"   : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100 ]),
	"douzhuan-xingyi" : ([ "parry"  : 170 ]),		 
	"beidou-xianzong" : ([ "dodge"  : 110 ]),
	// 段氏
	"six-finger"       : ([ "attack" : 180, "parry"  : 120, "dodge"  : 140, "damage" : 170, "force" : 160 ]),
	"jinyu-quan"       : ([ "attack" : 90, "parry"  : 90, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"wuluo-zhang"      : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"yiyang-zhi"       : ([ "attack" : 140, "parry"  : 110, "dodge"  : 110, "damage" : 140, "force" : 150 ]),
	"qiantian-zhi"     : ([ "attack" : 110, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 110 ]),
	"duanjia-jian"   : ([ "attack" : 120, "parry"  : 120, "dodge"  : 100, "damage" : 120 ]),
	"feifeng-whip"   : ([ "attack" : 130, "parry"  : 90, "dodge"  : 100, "damage" : 120 ]),
	"tiannan-bufa"    : ([ "dodge"  : 100 ]),
	// 胡家
	"hujia-quan"       : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"tianchang-zhang"  : ([ "attack" : 100, "parry"  : 100, "dodge"  : 100, "damage" : 100, "force" : 100 ]),
	"hujia-daofa"    : ([ "attack" : 140, "parry"  : 140, "dodge"  : 120, "damage" : 150 ]),
	"baisheng-daofa" : ([ "attack" : 130, "parry"  : 100, "dodge"  : 90, "damage" : 160 ]),
	"miaojia-jian"   : ([ "attack" : 130, "parry"  : 120, "dodge"  : 140, "damage" : 130 ]),
	"mantian-xing"   : ([ "attack" : 140, "parry"  : 70, "dodge"  : 120, "damage" : 120 ]),
	"daojian-guizhen": ([ "attack" : 180, "parry"  : 170, "dodge"  : 170, "damage" : 180 ]),
	"taxue-wuhen"     : ([ "dodge"  : 100 ]),
	"sixiang-bufa"    : ([ "dodge"  : 110 ]),
	// 唐门
	"boyun-suowu"      : ([ "attack" : 100, "parry"  : 130, "dodge"  : 130, "damage" : 100, "force" : 100 ]),  
	"tangmen-throwing": ([ "attack" : 140, "parry"  : 100, "dodge"  : 140, "damage" : 150 ]),
	"wuzhan-mei"      : ([ "attack" : 120, "parry"  : 120, "dodge"  : 140, "damage" : 120 ]),
	"qiulin-shiye"    : ([ "dodge"  : 120 ]),      
]);

mapping force_lvl = ([
	"yinyang-shiertian"     : 200, 
	"jiuyang-shengong"      : 180,
	"taixuan-gong"	  : 170,
	"mingyu-gong"	   : 170,
	"yijinjing"	     : 170,
	"freezing-force"	: 160,
	"taiji-shengong"	: 160,
	"beiming-shengong"      : 150,
	"bahuang-gong"	  : 150,
	"xiantian-gong"	 : 150,
	"hamagong"	      : 160,
	"pixie-jian"	    : 140,
	"longxiang-gong"	: 150,
	"shenzhaojing"	  : 150,
	"luohan-fumogong"       : 150,
	"huagong-dafa"	  : 140,
	"xixing-dafa"	   : 140,
	"zixia-shengong"	: 140,
	"shenyuan-gong"	 : 140,
	"bibo-shengong"	 : 140,
	"lengyue-shengong"      : 140,
	"kurong-changong"       : 140,
	"huntian-qigong"	: 140,
	"nuhai-kuangtao"	: 140,
	"linji-zhuang"	  : 140,
	"sanku-shengong"	: 140,
	"xuanming-shengong"     : 140,
	"zhanshen-xinjing"      : 140,
	"shenghuo-shengong"     : 130,
	"xiaowuxiang"	   : 130,
	"quanzhen-xinfa"	: 130,
	"zihui-xinfa"	   : 130,
	"yunv-xinfa"	    : 130,
	"shenlong-xinfa"	: 130,
	"hunyuan-yiqi"	  : 130,
	"xuehai-mogong"	 : 130,
	"yinyun-ziqi"	   : 130,
	"biyun-xinfa"	   : 130,
	"yijin-duangu"	  : 120,
	"mizong-neigong"	: 120,
	"huashan-xinfa"	 : 120,
	"emei-xinfa"	    : 120,
	"shaolin-xinfa"	 : 110,
	"guixi-gong"	    : 110,
]);

void create()
{
	seteuid(getuid());
	restore();
		
	if (! mapp(all_skills) || 
	    sizeof(all_skills) < 1)
		all_skills = skillsetup;
		
	set_heart_beat(1800);
}

void remove()
{
	save();
}

public void mud_shutdown()
{
	save();
}

// private 
void heart_beat()
{
	int t, delta;
	int last;	
	int user, users, score, scores, effect;
	mapping skills;
	string *record;
	string *sname, *ids, *var, skl;

	t = time();
	last = query("last_check");
	if ((t / 86400) != (last / 86400))
	{		       
		sname = keys(skillsetup);	
		users = 0;
		scores = 0;
		
		foreach (skl in sname)
		{
			reset_eval_cost(); 
			if (! query(skl))
			{
				if (! undefinedp(all_record[skl]))
					map_delete(all_record, skl);
				continue;
			}
			
			ids = keys(query(skl));
			user = sizeof(ids);
			users += user;
			score = 0;		
			foreach(string id in ids)
				score += query(skl + "/" + id);
			scores += score;

			record = ({ user, score });
		
			all_record[skl] = record;

		}
	
		foreach (skl in sname)
		{
			reset_eval_cost(); 
			if (undefinedp(all_record[skl]))
			{
				all_skills[skl] = skillsetup[skl];
					continue;
			}   
			if (! scores || ! users || ! all_record[skl][1] || ! all_record[skl][0])
				continue;

			effect = TO_EFFECT(scores, users, all_record[skl][1], all_record[skl][0]);
			if (effect > 30) effect = 30;
			if (effect < -30) effect = -30;
				      
			if (query("create/" + skl))
				effect += 5;

			var = keys(skillsetup[skl]);
			skills = ([ ]);
			delta = 0;
			foreach (string vg in var)
			{				
				skills[vg] = skillsetup[skl][vg] + effect;
				delta = skills[vg] - all_skills[skl][vg];
			}				
			
			if (delta < 0)
				CHANNEL_D->do_channel(this_object(), "rumor", 
					"江湖传言，" + to_chinese(skl) + "被高人破解，威力有所下降。");  
			else
			if (delta > 0)
				CHANNEL_D->do_channel(this_object(), "rumor", 
					"江湖传言，" + to_chinese(skl) + "被高人加强，威力有所上升。");  
								
			all_record[skl] += ({ effect });	
			all_skills[skl] = skills;
		} 
	}
	set("last_check", t);
	save();		  
}

int sort_skills(string f1, string f2, mapping fame)
{
	return fame[f2]["attack"] - fame[f1]["attack"];
}

public varargs void show_skills_power_point(object me, string skill)
{
	int i, delta;
	mapping skl;
	string *sname, msg;
	
	msg = WHT "目前江湖上所有武功以攻击力排名状况"NOR"\n";
	msg += "技能名称		      攻击   躲闪   招架   内伤   伤害   变动\n";
	msg += "---------------------------------------------------------------------\n";
	
	if (stringp(skill) && ! undefinedp(all_skills[skill]))
		sname = ({ skill });
	else
		sname = keys(all_skills) - ({ 0 });
	sname = sort_array(sname, (: sort_skills :), all_skills);	
	for (i = 0; i < sizeof(sname); i++)
	{
		skl = ([ ]); 
		skl = all_skills[sname[i]];
		
		if (! undefinedp(all_record[sname[i]]))
			delta = all_record[sname[i]][2];
		else
			delta = 0;
			
		msg += sprintf("%-30s", to_chinese(sname[i]) + "(" + sname[i] + ")");
		if (! undefinedp(skl["attack"]))
			msg += sprintf("%-4d   ", 
				skl["attack"]);
		else
			msg += HIR " x     " NOR;
		if (! undefinedp(skl["dodge"]))
			msg += sprintf("%-4d   ",
				skl["dodge"]);		  
		else
			msg += HIR " x     " NOR;
		if (! undefinedp(skl["parry"]))
			msg += sprintf("%-4d   ",
				skl["parry"]);	       
		else
			msg += HIR " x     " NOR;
		if (! undefinedp(skl["force"]))
			msg += sprintf("%-4d   ",
				skl["force"]);		
		else
			msg += HIR " x     " NOR;
		if (! undefinedp(skl["damage"]))
			msg += sprintf("%-4d   ",
				skl["damage"]);		   
		else
			msg += HIR " x     " NOR;
		
		msg += sprintf("(%s%d%s)\n",
				(delta > 0) ? HIY "+" :
				(delta < 0) ? HIR : WHT,
				 delta, NOR);       
	}
	msg += "---------------------------------------------------------------------\n";
	me->start_more(msg);     
}

public void add_id_into_skills(object me)
{
	mapping skills;
	string id, sname;
	string *sk;

	if (wizardp(me)) return;
			
	id = me->query("id");
	
	if (! mapp(skills = me->query_skills()) || 
		sizeof(skills) < 1)
		return;
	      
	sk = keys(skills);
	
	foreach (sname in sk)
	{
		if (SKILL_D(sname)->type() != "martial")
			continue;

		if (undefinedp(skillsetup[sname]))
			continue;
			     
		if (! query(sname + "/" + id) && skills[sname] < 400)
			continue;
		
		if (query(sname + "/" + id) && skills[sname] < 400)
		{
			delete(sname + "/" + id);
			if (! sizeof(query(sname)))
				delete(sname);
			continue;
		}		       
			       
		set(sname + "/" + id, skills[sname]);
	}
	save();
}

public void remove_id_from_skills(object me)
{
	mapping skills;
	string id, sname;
	string *sk;
 
	if (wizardp(me)) return;       
	
	id = me->query("id");
	
	if (! mapp(skills = me->query_skills()) || 
		sizeof(skills) < 1)
		return;	
	
	sk = keys(skills);
	
	foreach (sname in sk)
	{
		if (SKILL_D(sname)->type() != "martial")
			continue;
			
		/*   
		if (undefinedp(skillsetup[sname])
			continue;
		*/
		
		if (! query(sname + "/" + id))
			continue;

		delete(sname + "/" + id);
		if (! sizeof(query(sname)))
			delete(sname);
	}
	
	save();
}

public void remove_id_from_abandon(object me, string sname)
{
	if (SKILL_D(sname)->type() != "martial")
		return;
	
	if (! query(sname + "/" + me->query("id")))
		return;
		
	delete(sname + "/" + me->query("id"));
	if (! sizeof(query(sname)))
		delete(sname);
	
	save();
}

public mixed skill_query_power_point(string skill)
{
	if (! undefinedp(all_skills[skill]))
		return all_skills[skill];      
	else
		return 0;  
}

public int ap_power(object me, string skill)
{
	int lv, ap_power;
	string attack_skill;
	      
	if (! stringp(attack_skill = me->query_skill_mapped(skill)))
	{
		ap_power = me->query_skill(skill) +
			   me->query("level") * 20 + 
			   me->query_skill("martial-cognize", 1);
		return ap_power;
	}
	
	if (! undefinedp(all_skills[attack_skill]))	
		lv = all_skills[attack_skill]["attack"];
	
	if (! lv) lv = 50;	    
	ap_power = me->query_skill(skill, 1) / 2 + 
		   me->query_skill(attack_skill, 1) * lv / 10 +
		   me->query("level") * 20 + 
		   me->query_skill("martial-cognize", 1);
		   
	if (me->query("jieti/times"))
		ap_power += ap_power * me->query("jieti/times") / 10;

	return ap_power;
}

public int dp_power(object target, string skill)
{
	int lv, dp_power;
	string defend_skill;
	 
	if (! objectp(target)) return 0;
	defend_skill = target->query_skill_mapped(skill); 
	
	if (! stringp(defend_skill = target->query_skill_mapped(skill)))
	{
		dp_power = target->query_skill(skill) +
			   target->query("level") * 20 + 
			   target->query_skill("martial-cognize", 1);
		return dp_power;
	}
	
	if (skill == "parry")
	{	
		if (! undefinedp(all_skills[defend_skill]))	
			lv = all_skills[defend_skill]["parry"];
	} else
	if (skill == "dodge")
	{
		if (! undefinedp(all_skills[defend_skill]))	
			lv = all_skills[defend_skill]["dodge"];		  
	} else
	if (skill == "force")
	{
		if (! undefinedp(force_lvl[defend_skill]))	
			lv = force_lvl[defend_skill];
	}
	
	if (! lv) lv = 50;
		    
	dp_power = target->query_skill(skill, 1) / 2 + 
		   target->query_skill(defend_skill, 1) * lv / 10 +
		   target->query("level") * 20 + 
		   target->query_skill("martial-cognize", 1);
		   
	if (target->query("jieti/times"))
		dp_power += dp_power * target->query("jieti/times") / 10;

	return dp_power;
}


public int da_power(object me, string skill)
{
	int lv, da_power;
	string attack_skill;
	
	      
	if (! stringp(attack_skill = me->query_skill_mapped(skill)))
	{
		da_power = me->query_skill(skill) +
			   me->query("level") * 20 + 
			   me->query_skill("martial-cognize", 1);
		
		da_power = da_power / 2 + random(da_power);
		// da_power /= 3;
		return da_power;
	}
	
	if (! undefinedp(all_skills[attack_skill]))	
		lv = all_skills[attack_skill]["damage"];    
	 
	if (! lv) lv = 50;	   
	da_power = me->query_skill(skill, 1) / 2 + 
		   me->query_skill(attack_skill, 1) * lv / 10 +
		   me->query("level") * 20 + 
		   me->query_skill("martial-cognize", 1);
			  
	da_power = da_power / 2 + random(da_power / 2);
	da_power /= 2;     
	if (me->query("jieti/times"))
		da_power += da_power * me->query("jieti/times") / 10;
	return da_power;
}			

public string query_save_file() { return DATA_DIR "skillsd"; } 

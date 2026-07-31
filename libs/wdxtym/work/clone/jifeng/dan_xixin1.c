#include <ansi.h>
inherit COMBINED_ITEM;


string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}
void create()
{
	set_name(HIW "洗心丹" NOR, ({ "xixin dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一粒晶莹剔透的丹药，服了之后使人强行散去本门武功，从而重新拜师学艺("HIR"注意：一旦使用将清除所有已经请教的绝学"NOR")。\n");
		set("unit", "粒");
		set("value", 50000);
		set("jifeng", 2000);
	    set("no_get", 1);
        set("no_drop", 1);
        set("no_give", 1);
        set("no_sell", 1);		
		set("only_do_effect", 1);
		set("weight", 1);
		set("base_weight", 200);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;
	mapping all_fam = ([
		"武当派":({
				"taiji-quan",
				"taiji-shengong",
				"wudang-xinfa",
				"tiyunzong",
				"wudang-zhang",
				"paiyun-shou",
				"wudang-jian",
				"taiji-jian",
				"taiji-dao",
				"raozhi-roujian",
				"huzhua-shou",
				"zhenshan-zhang",
				"yitian-zhang",
				"shenmen-jian",
				"xuanxu-dao",
				"yitian-zhang",
				"shenmen-jian",
			}),
		"少林派":({
				"jingang-buhuaiti",
				"banruo-zhang",
				"jingang-zhi",
				"jingang-quan",
				"xumishan-zhang",
				"cibei-dao",
				"damo-jian",
				"fengyun-shou",
				"fumo-jian",
				"hunyuan-yiqi",
				"shaolin-xinfa",
				"jingang-quan",
				"longzhua-gong",
				"luohan-quan",
				"nianhua-zhi",
				"pudu-zhang",
				"qianye-shou",
				"sanhua-zhang",
				"riyue-bian",
				"shaolin-shenfa",
				"weituo-gun",
				"wuchang-zhang",
				"xiuluo-dao",
				"yingzhua-gong",
				"yijinjing",//公共到180
				"yizhi-chan",
				"zui-gun",
//以下为少林藏经阁特有武功
				"yipai-liangsan",
				"xiuluo-zhi",
				"duoluoye-zhi",
				"wuxiang-zhi",
			}),
		"天龙寺":({
				"kurong-changong",
				"duanshi-xinfa",
				"tiannan-step",
				"sun-finger",
			}),
		"华山派":({
				"huashan-sword",
				"huashan-xinfa",
				"huashan-quanfa",
				"huashan-shenfa",
				"zixia-shengong",
				"poyu-quan",
				"hunyuan-zhang",
				"feiyan-huixiang",
				"kuangfeng-jian",
				"yunu-sword",
				"fanliangyi-dao",
			//	"lonely-sword",
			}),
		"华山剑宗":({
				"huashan-sword",
				"huashan-xinfa",
				"huashan-quanfa",
				"huashan-shenfa",
				"zixia-shengong",
				"poyu-quan",
				"hunyuan-zhang",
				"feiyan-huixiang",
				"kuangfeng-jian",
				"yunu-sword",
				"fanliangyi-dao",
			}),
		"峨嵋派":({
				"persuading",
				"jinding-zhang",
				"tiangang-zhi",
				"huifeng-jian",
				"yanxing-dao",
				"zhutian-bu",
				"emei-xinfa",
				"linji-zhuang",
				"piaoxue-zhang",
				"jiuyin-baiguzhao",//周芷若，作为公共技能可学到100级
			}),
		"桃花岛":({
				"bibo-shengong",
				"luoying-xinfa",
				"tanzhi-shentong",
				"luoying-shenzhang",
				"xuanfeng-leg",
				"anying-fuxiang",
				"luoying-shenjian",
				"yuxiao-jian",
				"lanhua-shou",
				"bihai-chaosheng",
				//"count",
			}),
		"神龙教":({
				"shenlong-xinfa",
				"yixingbu",
				"shenlong-bashi",
				"huagu-mianzhang",
				"shedao-qigong",
			}),
		"丐帮":({
				"jiaohua-neigong",
				"huntian-qigong",
				"changquan",
				"xiaoyaoyou",
				"feiyan-zoubi",
				"dragon-strike",//公共武学，需炒菜
				"jiaohua-bangfa",
				"dagou-bang",
				"mantianhuayu-zhen",
				"jueming-tui",
				"chansi-shou",//白世镜
				"suohou-gong",//马大元
				"fengmo-zhang",//彭有敬
				"fumo-zhang",//jian
				
			}),
		"古墓派":({
				"yunv-xinfa",
				"surge-force",
				"yunv-jian",
				"quanzhen-jian",
				"xuantie-jian",
				"yunv-shenfa",
				"meinv-quan",
				"sad-strike",//公共
				"fireice-strike",
				"tianluo-diwang",
				"yufeng-zhen",
				"yinsuo-jinling",
				"tianluo-diwang",
				"zuoyou-hubo",
			}),
		"全真教":({
				"quanzhen-xinfa",
				"xiantian-gong",
				"quanzhen-jian",
				"jinyan-gong",
				"jinguan-yusuo",
				"chongyang-shenzhang",
				"haotian-zhang",
				"zhongnan-zhi",
				//"zuoyou-hubo",
				"kongming-quan",
			}),
		"星宿派":({
				"huagong-dafa",
				"freezing-force",
				"guixi-gong",
				"feixing-shu",
				"zhaixinggong",
				"chousui-zhang",
				"sanyin-wugongzhao",
				"chanhun-suo",
				"tianshan-zhang",
			}),
		"逍遥派":({
				"xiaoyao-xinfa",
				"beiming-shengong",
				"xiaowuxiang",
				"lingbo-weibu",
				"feiyan-zoubi",
				"liuyang-zhang",
				"ruyi-dao",
				"zhemei-shou",
			}),
		"雪山寺":({
				"longxiang",
				"mizong-neigong",
				"mingwang-jian",
				"xiangmo-chu",
				"riyue-lun",
				"shenkong-xing",
				"dashou-yin",
				"yujiamu-quan",
				"xiaowuxiang",
				"huoyan-dao",
			}),
		"血刀门":({
				"xue-dao",
				"mingwang-jian",
				"mizong-neigong",
				"xuehai-mogong",
				"shenkong-xing",
				"dashou-yin",
				"yujiamu-quan",
			}),

		"灵鹫宫":({
				"zhemei-shou",
				"liuyang-zhang",
				"yueying-wubu",
				"bahuang-gong",
				"tianyu-qijian",
				"lingjiu-xinfa",
				"zhougong-jian",
			}),
		"慕容世家":({
				"zihui-xinfa",
				"douzhuan-xingyi",
				"beidou-xianzong",
				"canhe-zhi",
				"qixing-quan",
				"murong-sword",
				"longcheng-shendao",
			}),
		"欧阳世家":({
				"shedu-qiqiao",
				"hamagong",
				"chanchu-bufa",
				"lingshe-quan",
				"lingshe-zhangfa",
				"baibian-daxue",
			}),
		"关外胡家":({
				"lengyue-shengong",
				"hujia-daofa",
				"taxue-wuhen",
				"sixiang-bufa",
				"mantian-xing",
				"tianchang-zhang",
				"hujia-quan",
				"baisheng-daofa",
				"miaojia-jian"
			}),
		"段氏皇族":({
				"duanshi-xinfa",
				"tiannan-step",
				"jinyu-quan",
				"duanjia-sword",
				"sun-finger",
				"wuluo-zhang",
				"feifeng-whip",//刀白凤
				"qingliang-daxuefa",//朱丹臣
				"yuezhao-gong",//hua
				"six-finger",
			}),
		"明教":({
				"qiankun-danuoyi",
				"shenghuo-xinfa",
				"shenghuo-quan",
				"guangming-zhang",
				"liehuo-jian",
				"qingfu-shenfa",
				"hannbing-mianzhang",
				"yinfeng-dao",
				"tougu-zhen",
				"sougu-yingzhua",
				"qishang-quan",
				"pili-quan",
				"shenghuo-shengong",
				"taiji-quan",
				"taiji-jian",
				"jiuyang-shengong",
			}),
		"日月神教":({
				"riyue-xinfa",
				"liushui-bian",
				"tianmo-gun",
				"xuwu-piaomiao",
				"tianmo-zhang",
				"tianmo-dao",
				"tianmo-jian",
				"pili-daofa",
				"huanmo-longtianwu",
				"xixing-dafa",
				"riyue-guanghua",
				"kuihua-shengong",
			}),
				"移花宫":({
				"jueqing-zhang",
				"mingyu-shengong",
				"mingyu-gong",
				"yihua-jiemu",
				"yifeng-jian",
				"yifeng-dodge",
				"riyue-xinfa",						
			}),
			"魔教":({
				"moshen-xinfa",
				"moshen-bufa",
				"moshen-quanfa",
				"liuxing-jianfa",
				"moshen-daofa",
				"moshen-zhangfa",
				"moshen-jianfa",
				"yinlong-shou",
				"chiyou-kuangzhanjue",
				"jiutian-xiaoyaobu",
				"mingyue-blade",
				"moon-blade",
				"yanzi-blade",
				"nuquan",
				"longteng-daofa",
				
			}),
			"白云城":({
				"feixian-sword",
				"jingyiforce",
				"feixian-steps",
				"feixian-jian",
										
			}),
			"蜀山派":({
				"shushan-force",
				"zuixian-steps",
				"xianfeng-spells",
				"fumozhang",
				"songhe-sword",
										
			}),
			"绝情谷":({
				"jueqing-xinfa",
				"jueqing-shenfa",
				"guhong-zhang",
				"guxing-jian",
				"luoyun-dao",
				"poshui-zhang",
				"fenxin-jue",
				"pokong-quan",
				"jueqing-zhang",
				"yinyang-ren",
				"zilei-jian",
				"tianjue-dao",
				"poguang-dao",
				"jueqing-jian",
				"tiezhang-xinfa",
				"tianlei-shengong",
				"dengping-dushui",
				"tiexian-quan",
				"chuanxin-zhang",
				"feilong-zhang",
				"tie-zhang",
			}),
			"浣花剑派":({
				"huanhua-jian",
				"guiyuan-dafa",
				"tiexian-quan",
				"feihua-wuping",
			}),
			  "玄冥谷":({
				"xuanming-shengong",
				"lingxu-bu",
				"piaofeng-quan",
				"feihua-zhang",
				"xuanming-zhang",
				"dulong-shenzhua",
				"hexing-bifa",
				"pili-daofa",
            }),		
		"唐门世家":({
				"feixian-sword",
				"jingyiforce",
				"feixian-steps",
				"feixian-jian",
										
			}),
	]);

	if(!me->query("family"))
	{
		tell_object(me,"你还没有师门吧，无需使用"+query("name")+"。\n");
		return 0;
	}
	message_vision(CYN "$N" CYN "小心的服下了一"+query("unit")+"" + name() + CYN "，决定重新做人。"NOR"\n", me);

	family = me->query("family/family_name");
	if(skills=all_fam[family])
	{
		for(i=0;i<sizeof(skills);i++)
		{
			if(skills[i] == "count")
			{
				if(me->query_skill(skills[i],1)>380)
					me->set_skill("count",380);
			}
			else
				me->delete_skill(skills[i]);
		}
	}
	else
	{
		tell_object(me,"门派数据错误，请联系管理员。\n");
		return 0;
	}
	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"服用了一粒"+this_object()->query("name")+""HIM"，获得了一次重新选择师门的机会！");
	me->delete("can_perform");
	me->delete("family");
	me->delete("title");
	me->delete("class");
	//检查技能是否符合要求，不符合的删除
	UPDATE_D->check_skill(me);
	add_amount(-1);

	return 1;
}

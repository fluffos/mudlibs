// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "五绝令牌" NOR, ({ "wujue ling" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "华山之巅，群雄争霸中小有名声之辈才能获得的令牌，凭此令可以学习一项其门派的武学，每人限用一次。\n");
		set("unit", "块");
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_put",1);
        set("no_steal",1);
		set("action_list",([
			"使用":"taojiao",
		]));
		set("no_sell", 1);set("value", 50000);
		set("gongxian", 15000);
		set("weight", 1);
	}
	setup();
}

void init()
{
	add_action("do_taojiao","taojiao");
}

int do_taojiao(string arg)
{
	string str,*fams,family,skill,skill_name,*skills;
	int i;
	object me;
	mapping mskills;
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
				"yijinjing",
				"yizhi-chan",
				"zui-gun",
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
				"jiuyin-baiguzhao",
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
				"dragon-strike",
				"jiaohua-bangfa",
				"dagou-bang",
				"mantianhuayu-zhen",
				"jueming-tui",
				"chansi-shou",
				"suohou-gong",
				"fengmo-zhang",
				"fumo-zhang",
			}),
		"古墓派":({
				"yunv-xinfa",
				"surge-force",
				"yunv-jian",
				"quanzhen-jian",
				"xuantie-jian",
				"yunv-shenfa",
				"meinv-quan",
				"sad-strike",
				"fireice-strike",
				"tianluo-diwang",
				"yufeng-zhen",
				"yinsuo-jinling",
				"tianluo-diwang",
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
				"feifeng-whip",
				"qingliang-daxuefa",
				"yuezhao-gong",
			}),
	]);

	me = this_player();

	if(me->query("wujue_skill"))
	{
		tell_object(me,"你已经使用过一次五绝令牌了，每个人只能使用一次！\n");
		return 1;
	}

	if(me->query("combat_exp")<600000)
	{
		tell_object(me,"修为不足60万，不能使用五绝令牌！\n");
		return 1;
	}

	if(!arg)
	{
		fams = keys(all_fam);
		str = ZJOBLONG"请选择你想喜欢的门派：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		for(i=0;i<sizeof(fams);i++)
		{
			str += fams[i]+":taojiao "+fams[i];
			if(i<(sizeof(fams)-1)) str += ZJSEP;
		}
		tell_object(me,str + "\n");
		return 1;
	}

	if(sscanf(arg,"%s %s",family,skill)!=2)
	{
		if(!all_fam[arg])
		{
			tell_object(me,"没有这个门派！\n");
			return 1;
		}

		if(me->query("family/family_name") == arg)
		{
			tell_object(me,"你自己的门派，无需这么麻烦！\n");
			return 1;
		}

		skills = all_fam[arg];
		str = ZJOBLONG"请选择你想喜欢的["+arg+"]技能：\n"ZJOBACTS2+ZJMENUF(2,2,10,30);
		for(i=0;i<sizeof(skills);i++)
		{
			str += to_chinese(skills[i])+ZJBR+skills[i]+":taojiao "+arg+" "+skills[i];
			if(i<(sizeof(skills)-1)) str += ZJSEP;
		}
		tell_object(me,str + "\n");
		return 1;
	}

	if(!all_fam[family])
	{
		tell_object(me,"没有这个门派！\n");
		return 1;
	}

	if(member_array(skill,all_fam[family])==-1)
	{
		tell_object(me,family+"没有你要的这个技能！\n");
		return 1;
	}

	if(file_size(SKILL_D(skill)+".c")<0)
	{
		tell_object(me,"没有这个技能！\n");
		return 1;
	}

	if (me->query_skill(skill,1))
	{
		tell_object(me,"你已经掌握这个技能了，无需再次学习！\n");
		return 1;
	}

	if (!SKILL_D(skill)->valid_learn(me))
	{
		tell_object(me,"你目前的能力不足以掌握此项技能！("+skill+")\n");
		return 1;
	}

	mskills = me->query_skills();

	if (SKILL_D(skill)->valid_enable("force") && !SKILL_D(skill)->valid_force("*"))
	foreach (skill_name in keys(mskills))
	{
		if (! SKILL_D(skill_name)->valid_enable("force"))
			continue;

		if (! SKILL_D(skill_name)->valid_force(skill))
		{
			tell_object(me,"你不散了" + to_chinese(skill_name) + "，怎么学习" + to_chinese(skill) + "？\n");
			return 1;
		}
	}

	me->set_skill(skill,180);
	me->set("wujue_skill",skill);
	tell_object(me,"你掌握了180级" + to_chinese(skill) + "。\n");
	log_ufile(me,"wujueling","使用五绝令牌掌握了180级" + to_chinese(skill) + "。\n");

	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }
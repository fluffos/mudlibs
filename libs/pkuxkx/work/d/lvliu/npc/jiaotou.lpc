#include <ansi.h>
inherit NPC;
string ask_skills();
int do_buy(string arg);
int do_list();

mapping *all_skills = ({
([	"name" : "太极神功",
	"id" : "taiji",
	"skill" : "太极剑法、太极神功",
	"skills" : ({ "taiji-jian", "taiji-shengong" }),
	"value" : 10,
]),
([	"name" : "六脉神剑",
	"id" : "liumai",
	"skill" : "六脉神剑",
	"skills" : ({ "liumai-shenjian" }),
	"value" : 15,
]),
([	"name" : "北冥六脉",
	"id" : "beiming",
	"skill" : "六脉神剑、北冥神功",
	"skills" : ({ "liumai-shenjian", "beiming-shengong" }),
	"value" : 18,
]),
([	"name" : "冰蚕毒掌",
	"id" : "bingcan",
	"skill" : "冰蚕毒掌",
	"skills" : ({ "bingcan-duzhang" }),
	"value" : 8,
]),
([	"name" : "碧海弹指",
	"id" : "tanzhi",
	"skill" : "弹指神通、碧海神功",
	"skills" : ({ "tanzhi-shengong", "bihai-shengong" }),
	"value" : 10,
]),	
([	"name" : "龙象降伏",
	"id" : "longxiang",
	"skill" : "降伏轮、龙象般若功",
	"skills" : ({ "xiangfu-lun", "longxiang-boruo" }),
	"value" : 15,
]),
([	"name" : "蛤蟆扑击",
	"id" : "hamagong",
	"skill" : "蛤蟆功",
	"skills" : ({ "hamagong" }),
	"value" : 10,
]),
([	"name" : "灵蛇蛤蟆",
	"id" : "lingshe",
	"skill" : "灵蛇杖法、蛤蟆功",
	"skills" : ({ "lingshe-zhangfa", "hamagong" }),
	"value" : 12,
]),
([	"name" : "混天降龙",
	"id" : "xianglong",
	"skill" : "降龙十八掌、混天气功",
	"skills" : ({ "xianglong-zhang", "huntian-qigong" }),
	"value" : 11,
]),
([	"name" : "打狗棒法",
	"id" : "dagou",
	"skill" : "打狗棒法",
	"skills" : ({ "dagou-bang" }),
	"value" : 9,
]),
([	"name" : "玉女长恨",
	"id" : "changhen",
	"skill" : "长恨鞭法、玉女心法",
	"skills" : ({ "changhen-bian", "yunu-xinfa" }),
	"value" : 10,
]),
([	"name" : "独孤九剑",
	"id" : "dugu",
	"skill" : "独孤九剑",
	"skills" : ({ "dugu-jiujian" }),
	"value" : 10,
]),
([	"name" : "参合点穴",
	"id" : "canhe",
	"skill" : "参合指",
	"skills" : ({ "canhe-zhi" }),
	"value" : 9,
]),
([	"name" : "慕容参合",
	"id" : "murong",
	"skill" : "慕容剑法、参合指、神元功",
	"skills" : ({ "murong-jianfa", "canhe-zhi", "shenyuan-gong" }),
	"value" : 15,
]),
([	"name" : "先天全真",
	"id" : "quanzhen",
	"skill" : "全真剑法、先天功",
	"skills" : ({ "quanzhen-jian", "xiantian-gong" }),
	"value" : 12,
]),
([	"name" : "神龙毒匕",
	"id" : "dulong",
	"skill" : "毒龙匕法、神龙心法",
	"skills" : ({ "dulong-bi", "shenlong-xinfa" }),
	"value" : 10,
]),
([	"name" : "浩气丹心",
	"id" : "danxin",
	"skill" : "碧血丹心剑、浩气苍冥功",
	"skills" : ({ "danxin-jian", "cangming-gong" }),
	"value" : 7,
]),

});


void create()
{
        set_name("教头", ({ "jiao tou", "jiaotou", "tou" }));
		set("title",HIM "无" HIW "所" HIC "不" HIY "知"NOR);
        set("long","一位发须都已花白的教头，负责指点庄里武士的武艺，看起来深不可测的样子。\n");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 80);
		set("combat_exp", 2000000000);
		set("str", 50);
        set("int", 50);
        set("con", 50);
        set("dex", 50);
        set("max_qi", 100000);
        set("max_jing", 100000);
        set("neili", 100000);
        set("max_neili", 50000);
        set("jiali", 1000);
        set("score", 5000000);
		set_skill("force", 5000);
        set_skill("jiuyin-zhengong", 5000);
        set_skill("xuanming-zhangfa", 5000);
        set_skill("dodge", 5000);
        set_skill("jiuyin-shenfa", 5000);
        set_skill("strike", 5000);  
        set_skill("parry", 5000);
        map_skill("force","jiuyin-zhengong");
        map_skill("dodge","jiuyin-shenfa");
        map_skill("strike","xuanming-zhangfa");
        map_skill("parry","xuanming-zhangfa");
		set_temp("apply/armor", 3000);
		set_temp("apply/damage", 1000);
        prepare_skill("strike", "xuanming-zhangfa");
		set("inquiry",([
			"赵敏":"那是我们郡主，她现在就在庄内招待各路英雄。",
			"指点": (: ask_skills :),
			"武功": (: ask_skills :),
			"skills": (: ask_skills :),
			]));
        setup();
}

string sk_list()
{
	mapping sk;
	string msg;
	int i;
	msg = HIC "你可以通过学习，临时获得以下技能：\n" ;
	msg += HIG"◎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◎\n";
	msg += HIG"│   名称   │    I D    │         包含技能          │ 价格参数 │\n";
	msg += HIG"◎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◎\n";
	for (i=0; i<sizeof(all_skills); i++)
	{
		sk = all_skills[i];
		msg += HIG "│" NOR;
		msg += sprintf(" %-9s" HIG "│" NOR " %-10s" HIG "│" NOR " %-26s" HIG "│" NOR "    %2d    " HIG "│\n", 
			sk["name"], sk["id"], sk["skill"], sk["value"]);
	}
	msg += HIG"◎━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━◎\n";
	msg += HIY"学习技能所需银两 ＝ 技能等级 * 价格参数\n";
	msg += HIW"持续时间：15分钟。" HIR "仅在本庄内有效！\n" NOR;
	return msg;
}

string ask_skills()
{
	object me = this_player();
	tell_object(me, sk_list());
	return "尊客如有需要，可以 buy <id> <等级> 来学习一项技能。";	
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int do_list()
{
	object me = this_player();
	tell_object(me, sk_list());
	return 1;
}

int do_buy(string arg)
{
	mapping tsk;
	object me = this_player();
	string sk, msg;
	int c, i, exp_lvl, rlvl, level, value;
	if (!wizardp(me) && me->query_temp("lvliu_last_learn_temp")>time())
		return notify_fail("教头才刚指点过你不久，还要过一段时间才能再来向他请教。\n");
	if (!arg || sscanf(arg, "%s %d", sk, level) !=2)
		return notify_fail("使用 buy <id> <等级> 来学习一项技能，或者用 list 来查看有哪些技能可供学习。\n");
	if (level <100)
		return notify_fail("庄内教头不教毫无诚意的无能之辈，你至少也需要学习 100 级技能。\n");
	exp_lvl = me->query_skill_limit();
	if (level > exp_lvl)
		return notify_fail("凭你的实战经验，你最多只能学习 "+exp_lvl+" 级技能。\n");
	for (i=0; i<sizeof(all_skills); i++)
	{
		if (all_skills[i]["id"] == sk)
		{
			tsk = all_skills[i];
			break;
		}
	}
	if (!mapp(tsk))
		return notify_fail("没有 "+sk+" 这样的技能可学，请向教头先打听清楚。\n");
	value = tsk["value"] * level * 100;
	if (value > (int)me->query("balance"))
		return notify_fail("学习 "+level+" 级" HIC "「"+tsk["name"]+ "」" NOR "需要花费"HIW+chinese_number(value/100)+"两白银"NOR"，你的钱庄账户里没有那么多钱。\n");
	me->add("balance", -value);
	msg = "你听了教头的指导，似乎有些心得。\n";
	c = 0;
	for (i=0;i<sizeof(tsk["skills"]);i++)
	{
		sk = tsk["skills"][i];
		rlvl = me->query_skill(sk, 1);
		if (level > rlvl)
		{
			me->set_temp_skill(sk, level - rlvl, 15*60, "/d/lvliu", 0);
			msg += HIC "你学会了临时技能「"+ to_chinese(sk) + "」！\n";
			c++;
		}
	}
	if (c<=0)
		msg += HIY"但是教头指点的东西你都已了然于胸，对你的境界并没有什么太大的提升。\n";
	tell_object(me, msg + NOR);
	me->set_temp("lvliu_last_learn_temp", time() + 60*15); //15分钟CD
	return 1;
}


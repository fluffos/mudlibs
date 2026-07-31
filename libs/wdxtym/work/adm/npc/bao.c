// bao.c 包打听

#include <ansi.h>

inherit NPC;
int ask_baowu();
int ask_gushi();

mapping list = ([
	"少林武技一":"/clone/book/wuji1",
	"少林武技二":"/clone/book/wuji2",
	"少林武极三":"/clone/book/wuji3",
	"少林武极四":"/clone/book/wuji4",
	"乾坤大挪移":"/clone/book/qiankun_book",
	"六脉神剑谱":"/clone/book/six_book",
	"易筋经":"/clone/book/yijinjing",
	"论语":"/clone/book/lbook4",
	"九阴真经·上册":"/clone/book/jiuyin1",
	"九阴真经·全":"/d/tulong/obj/zhenjing",
	"圣火令1":"/clone/book/ling1",
	"圣火令2":"/clone/book/ling2",
	"圣火令3":"/clone/book/ling3",
	"屠龙刀":"/d/tulong/obj/tulongdao",
	"倚天剑":"/d/tulong/obj/yitianjian",
	"真武剑":"/clone/weapon/zhenwu",
	"孟子":"/clone/book/mengzi",
	"玄铁令":"/d/tulong/tulong/obj/xuantie-ling",
	"鬼谷神算":"/clone/book/guigu",
	"神木王鼎":"/clone/misc/swmuding",
	
]);

void create()
{
	object book;

	set_name("包打听", ({"bao dating", "dating"}));
	set("gender", "男性");
	set("age", 62);
	set("long", "他看上去深色淡然，好像天下事尽在心中的样子。\n");
	set("attitude", "peaceful");
	set("shen_type",1);
	set("str", 31);
	set("int", 36);
	set("con", 32);
	set("dex", 29);

	set("qi", 6200);
	set("max_qi", 6200);
	set("jing", 3100);
	set("max_jing", 3100);
	set("neili", 6500);
	set("max_neili", 6500);
	set("jiali", 50);

	set("combat_exp", 2800000);

	set_skill("force", 280);
	set_skill("dodge", 260);
	set_skill("parry", 270);
	set_skill("unarmed", 270);
	set_skill("literate", 120);

	set("title", "无所不知");

	set("inquiry", ([
		"江湖宝物" : (: ask_baowu :),
		"故事信息" : (: ask_gushi :),
	]));

	set_temp("apply/attack", 50);
	set_temp("apply/dodge", 80);
	set_temp("apply/parry", 80);
	set_temp("apply/unarmed_damage", 30);
	set_temp("apply/damage", 30);

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("show_baowu","chabw");
}

int ask_gushi()
{
	string str,*sss;
	int i;
	mapping smp;
	object me = this_player();

	smp = ([
		"anthem":"义勇军进行曲[技能]",
		"baguadao":"紫金八卦刀[技能]",
		"beihai":"北海传说[boss北海龙王]",
		"bizhen":"玄铁令[碧真清掌技能]",
		"caishen":"大小财神[丢金钱]",
		"donghai":"东海传说[boss龙王三太子]",
		"guanzhang":"张飞戏关羽[丹药神力丸]",
		"huanyin":"幻阴指法[技能]",
		"hyshan":"火焰山传说[boss牛头怪]",
		"jindouyun":"斗战胜佛[boss孙悟空]",
		"jiuyang":"九阳神功[技能]",
		"jiuzhuan":"九转金丹[丹药]",
		"laojun":"醍醐仙丹[丹药]",
		"liandan":"火红仙丹[丹药]",
		"lighting":"天灾人祸[几率加根骨]",
		"master":"玄黄紫清丹[丹药]",
		"mengzi":"孟子[读书]",
		"nanhai":"南海传说[boss南海恶蛟]",
		"nanji":"洗髓丹[丹药]",
		"pangtong":"鬼谷神算[秘籍]",
		"sanfenjian":"三分剑术[技能]",
		"shenzhao":"凝血神爪[技能]",
		"xiyou":"西天取经[黄金]",
	]);
	STORY_D->save();
	str = ZJOBLONG+STORY_D->query_info();
	str = replace_string(str,"\n",ZJBR);
	str += "目前仍有概率刷新的故事有："ZJBR;
	sss = STORY_D->query_all_story();
	for(i=0;i<sizeof(sss);i++)
	{
		if(smp[sss[i]])
			str += smp[sss[i]]+ZJBR;
		else
			str += sss[i]+ZJBR;
	}
	tell_object(me,str+"\n");
	return 1;
}

int ask_baowu()
{
	string str,*items;
	int i;

	object me = this_player();
	str = ZJOBLONG"你想打听什么江湖宝物的下落：\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
	items = keys(list);
	for(i=0;i<sizeof(items);i++)
	{
		str += items[i]+":chabw "+items[i];
		if(i<(sizeof(items)-1)) str += ZJSEP;
	}
	tell_object(me,str+"\n");
	return 1;
}

int show_baowu(string arg)
{
	object me,ob,*objs;
	int i;
	string str,*names;

	names = ({});
	me = this_player();
	if(!arg||!list[arg])
	{
		tell_object(me,"你要打听什么宝物？\n");
		return 1;
	}

	objs = children(list[arg]);

	if(sizeof(objs))
	{
		for(i=0;i<sizeof(objs);i++)
		{
			if(ob=environment(objs[i]))
			{
				if(playerp(ob))
					names += ({ ob->query("name") });
			}
		}
	}
	if(sizeof(names))
	{
		if(sizeof(names)==1)
			say("包打听说：目前江湖中持有"+arg+"的玩家有："+names[0]+"。\n");
		else
			say("包打听说：目前江湖中持有"+arg+"的玩家有："+implode(names,"、")+"。\n");
	}
	else
	{
		say("包打听说：目前江湖中没有玩家持有"+arg+"！\n");
		return 1;
	}


	return 1;
}


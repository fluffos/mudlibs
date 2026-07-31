// kezhene.c
#include <ansi.h>;
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("柯镇恶", ({ "ke zhene", "ke" }));
	set("title", "江南七侠");
	set("nickname", HIM"飞天蝙蝠"NOR);
	set("long", "他是一个衣衫褴褛的瞎子，右手握着一根粗大的铁杖。只见他
尖嘴削腮，脸色灰扑扑地，颇有凶恶之态。\n");
	set("gender", "男性");
	set("age", 44);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 12);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	
	set("max_qi", 2500);
	set("max_jing", 1500);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiali", 50);
	set("combat_exp", 800000);
	set("score", 12000);

	set_skill("force", 180);
	set_skill("taixuan-gong", 180);
	set_skill("dodge", 180);
	set_skill("lingxu-bu", 180);
	set_skill("unarmed", 180);
	set_skill("changquan", 180);
	set_skill("staff", 180);
	set_skill("xiangmo-zhangfa", 180);
	set_skill("parry", 180);
	set_skill("throwing", 180);
	set_skill("feixing-shu", 180);

	map_skill("force", "taixuan-gong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu-bu");
	map_skill("staff", "xiangmo-zhangfa");
	map_skill("parry", "xiangmo-zhangfa");
	map_skill("blade", "feixing-shu");

	set("inquiry", ([
		"郭靖" : "靖儿是我们的乖徒儿！\n",
		"江南七侠" : "七侠可不敢当，我们七兄妹江湖上有个匪号叫江南七怪！\n",
		"江南七怪" : "七怪也是你叫的？！\n",
		"丘处机" : "丘道长豪侠仗义，是条汉子！\n",
		"柯镇恶" : "就是瞎子我，你要怎的？！\n",
		"朱聪"   : "那是我二弟。\n",
		"韩宝驹"   : "那是我三弟。\n",
		"南希仁"   : "那是我四弟。\n",
		"张阿生"   : "那是我五弟。\n",
		"全金发"   : "那是我六弟。\n",
		"韩小莹"   : "那是我七妹。\n",
		"梅超风"   : "这个铁尸害死我大哥，此仇一定要报。\n",
				"降魔杖法" : "嘿嘿，这是我的独门绝招。\n",
	]));

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("character") != "心狠手辣")
	{
		command("say 大丈夫做事必须心狠手辣，我看你不是这种人。");
		return -1;
	}

	if (me->query("weiwang") < 100000)
	{
		command("say 你是从哪里来的？在江湖上没有威望的人，我怎会传授你武功？");
		return -1;
	}

	if (skill != "xiangmo-zhangfa")
	{
		command("say 这些我可不知清，回去问一下你师傅吧。");
		return -1;
	}

	return 1;
}

void unconcious()
{
	die();
}


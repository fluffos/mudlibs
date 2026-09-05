// File		: setdizi.h
// Created By	: iszt@pkuxkx, 2006-08-14

#include <ansi.h>
#include "name.h"

inherit F_MASTER;
inherit NPC;

void setcreate(int level)
//普通七代弟子：level < 100
//白阿绣和其他原著中提及的七代弟子：level = 100
//有特殊任务的七代弟子：level < 140
//非长门六代弟子：level = 120 ~ 140
//普通长门六代弟子：level = 140 ~ 180
//封万里和非长门五代弟子：level = 240
//白万剑：level = 270
//白自在：level = 350
{
	object me = this_object();
	int exp = 0;

	me->set_name(getname(), ({"xueshan dizi", "dizi"}));
	me->set("gender",random(5)>1 ? ("男性") : ("女性"));
	me->set("age", 20 + 10 * random(2));
	me->set("long","这是一位身着白袍、手执长剑的雪山弟子，");

	me->set("max_qi", level * 8);
	me->set("eff_qi", level * 8);
	me->set("qi", level * 8);
	me->set("max_jing", level * 8);
	me->set("eff_jing", level * 8);
	me->set("jing", level * 8);
	me->set("max_neili", level * 14);
	me->set("neili", level * 14);
	me->set("max_jingli", level * 14);
	me->set("jingli", level * 14);

	me->set("jiali",100);

	exp = pow(level/10, 3) * 100;
	exp += random(exp/2);
	me->set("combat_exp", exp);
	me->set("shen_type", 1);
	me->set("shen", level * 100);

	me->set("attitude", "peaceful");

	set("str", 14+random(14));
	set("dex", 14+random(14));
	set("con", 14+random(14));
	set("int", 14+random(14));
	set("per", 14+random(14));

	me->set_skill("force", level * 3 / 40 * 10);
	me->set_skill("dodge", level * 3 / 40 * 10);
	me->set_skill("parry", level * 4 / 50 * 10);
	me->set_skill("sword", level);
	me->set_skill("unarmed", level * 3 / 40 * 10);
	me->set_skill("literate", level * 2 / 30 * 10);
	me->set_skill("xueshan-neigong", level * 2 / 30 * 10);
	me->set_skill("xueshan-jianfa", level);

	me->map_skill("force", "xueshan-neigong");
	me->map_skill("sword", "xueshan-jianfa");
	me->map_skill("parry", "xueshan-jianfa");

	me->set("inquiry", ([
		"白自在" : "白老爷子的名讳岂是你随便叫得的？！",
		"白老爷子" : "白老爷子是本派第五代掌门人，江湖人称「威德先生」。",
		"威德先生" : "那便是本派第五代掌门人白老爷子了。",
		"掌门人" : "雪山派第五代掌门人白老爷子，江湖人称「威德先生」。",
		"雪山派" : "本派在凌霄城建城开派，已有一百七十余年，剑法精奇，实为海内无双。",
		"雪山剑法" : "雪山剑法变化精微，在下尚未能窥其堂奥，见笑了。",
		"剑法" : "雪山剑法变化精微，在下尚未能窥其堂奥，见笑了。",
		"凌霄城" : "凌霄城所在之地甚为险峻，又有护城冰沟，外人实难攻入。",
		"护城冰沟" : "传说沟底隐藏着什么秘密，不过前后已有十几人或不慎或被逼坠入其中，无一生还。",
		"沟底" : "沟底大概铺满尸骨，难以想象。",
		"秘密" : "秘密？我知道什么秘密？",
		"rumors" : "秘密？我知道什么秘密？",
		"白万剑" : "「气寒西北」的名号其实不虚，剑法凌厉无匹，令人钦服。",
		"十兆" : "十兆是本派的创始人，雪山剑法深不可测。",
		"iszt" : "十兆是本派的创始人，雪山剑法深不可测。",
	]));

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "liuchu" :),
		(: perform_action, "fengjian" :),
	}));
}

void setfamily(int gen)
{
	this_object()->create_family("雪山派", gen, "弟子");
}

void setequip()
{
	object me = this_object();
	me->add_money("coin", 10 + random(6) * 10);
	me->add_money("silver", random(3) * 10);
	me->carry_object(__DIR__"obj/sword.lpc");
	me->carry_object(__DIR__"obj/sword.lpc")->wield();
	me->carry_object(__DIR__"obj/changpao.lpc")->wear();
}

void setinit()
{
	int i;
	string fam = this_player()->query("family/family_name");

	if(fam && fam == "雪山派")
		i = this_object()->query("family/generation")
			- this_player()->query("family/generation");
	if( i == 1 ) {
		message_vision( HIC"$N倒转剑尖，恭恭敬敬地面向$n：「弟子恭迎师叔！」\n" NOR,
		this_object(),this_player() );
		return;
	}
	if( i >= 2 ) {
		message_vision( HIC"$N单膝支地，恭恭敬敬地面向$n：「弟子叩见师叔祖！」\n" NOR,
		this_object(),this_player() );
		return;
	}

	if(!this_object()->query("inquiry/here"))
		this_object()->add("inquiry", ([
			"here" : "这里便是" + environment(this_object())->query("short")+ "。\n",
			]));

}

void setapp(object ob)
{
	command("shake");
	command("say 这位"+RANK_D->query_respect(ob)+"，没有许可我是不收徒的。");
	return;
}
// 樵子 by River@SJ 2002.6.5

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("樵子", ({ "jiao zi", "jiao", "zi" }) );
	set("long", "见他容色豪壮，神态虎虎，举手迈足间似是大将军有八面威风。\n"+
		"若非身穿粗布衣裳而在这山林间樵柴，必当他是个叱咤风云的统兵将帅。\n");
	set("gender", "男性" );
	set("age", 45);
	set("str", 30);
	set("con", 30);
	set("dex", 25);
	set("int", 25);
	set("per", 25);
	set("unique", 1);
	set("attitude", "friendly");

	set("max_qi", 5000);
	set("max_jing", 2800);
	set("eff_jingli", 3600);
	set("neili", 8000);
	set("qi", 5000);
	set("jingli", 3600);
	set("max_neili", 8000);
	set("jiali", 50);

	set("combat_exp", 2300000);
	set("score", 5000);

	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("axe", 280);
	set_skill("literate", 200);
	set_skill("qiantian-yiyang", 280);
	set_skill("pangen-fu", 280);
	set_skill("tianlong-xiang", 280);
	set_skill("finger", 200);
	set_skill("yiyang-zhi", 200);
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "pangen-fu");
	map_skill("force", "qiantian-yiyang");
	map_skill("finger", "yiyang-zhi");
	map_skill("axe","pangen-fu");
	prepare_skill("finger","yiyang-zhi");

	setup();
	carry_object(BINGQI_D("axe"))->wield();
	carry_object(ARMOR_D("b_cloth"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}

void init()
{
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;

	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_answer", "answer");
}

void greeting(object me)
{
	if (! me || me->query_temp("yideng/answer")) return;
	command("say 天津桥上，凭栏遥望，舂陵王气都凋丧。树苍苍，水茫茫，云台\n"+
		"不见中兴将，千古转头归灭亡。功，也不久长！名，也不久长！");
	remove_call_out("greeting1");
	call_out("greeting1", 5, me);
}

void greeting1(object me)
{
	if (! me) return;
	command("say 峰峦如聚，波涛如怒，山河表里潼关路。望西都，意踟蹰。伤心\n"+
		"秦汉经行处，宫阙万间都做了土。兴，百姓苦！亡，百姓苦！");
	me->set_temp("yideng/answer", 1);
}

int do_answer(string arg)
{
	object me = this_player();

	if (! me->query_temp("yideng/answer")) return 0;
	if ( me->query_temp("yideng/jiaozi_pass")) return 0; 

	if ( ! arg ) return 0;

	if ( arg != "青山相待，白云相爱。梦不到紫罗袍共黄金带。一茅斋，野花开，管甚谁家兴废谁成败？陋巷单瓢亦乐哉。贫，气不改！达，志不改！"){
		command("shake");
		return 1;
	}

	message_vision(CYN"\n$N回道：「青山相待，白云相爱。梦不到紫罗袍共黄金带。一茅斋，野花开，\n"+
		"管甚谁家兴废谁成败？陋巷单瓢亦乐哉。贫，气不改！达，志不改！」\n"NOR, me);

	message_vision(CYN"\n$N听得心中大悦，心旷神怡之际，向山边一指，道：上去罢！\n"NOR, this_object());
	me->set_temp("yideng/jiaozi_pass", 1);
	return 1;
}

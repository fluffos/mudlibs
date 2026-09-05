// jiang.c 蒋四根

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("蒋四根", ({ "jiang sigen", "jiang","sigen" }));
	set("title", HIR "红花会"HIG"十三当家" NOR);
	set("nickname", HIY "铜头鳄鱼" NOR);
	set("long", 
"铜头鳄鱼蒋四根在会中坐第十三把交椅，兵器是铁桨。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 21);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1100);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 150000);

	set_skill("literate", 200);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);

	set_skill("bingchuan-xinfa", 180);
	set_skill("zhuangzi-mengwu", 180);
	set_skill("luohua-jian",     180);

	map_skill("dodge", "zhuangzi-mengwu");
	map_skill("force", "bingchuan-xinfa");
	map_skill("sword", "luohua-jian");
	map_skill("parry", "luohua-jian");

	set("env/wimpy", 20);
	create_family("红花会", 3, "弟子");
 	setup();
	set("env/wimpy", 20);

 	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiejiang")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 我不收徒！");
	return;
}

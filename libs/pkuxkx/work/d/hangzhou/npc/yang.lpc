// yang.c 杨成协

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("杨成协", ({ "yang chengxie", "yang","chengxie" }));
	set("title", HIR "红花会"HIG"八当家" NOR);
	set("nickname", CYN "铁塔" NOR);
	set("long", 
"他又肥又高，手执钢鞭，鞭身甚是粗重，看模样少说也有三十来斤。\n");
	set("gender", "男性");
	set("class", "fighter");
	set("age", 26);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1500);
	set("max_jing", 900);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 300000);

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

	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/tiebian")->wield();
}

void attempt_apprentice(object ob)
{
	command("say 我不收徒！");
	return;
}
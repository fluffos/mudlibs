// yang.cg.c
// Rewrote by iszt@pkuxkx, 2007-02-12

#include <ansi.h>
inherit NPC;

void heal();

void create()
{
        set_name("王贵",({"wang gui","wang"}));
        set("long", "这是王员外的独子，跟随周侗读书习武。\n");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 40);
	set("str", 40);
	set("int", 40);
	set("con", 40);
	set("dex", 40);
	set("chat_chance", 100);
	set("chat_msg", ({
		(: heal :),
	}));
	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 40000);
	set("max_neili", 40000);
	set("jiali", 300);
	set("combat_exp", 1200000);
	set("score", 400000);

	set_skill("force",230);
	set_skill("jiuyang-shengong",230);
	set_skill("dodge",230);
	set_skill("datengnuo-bufa", 230);
	set_skill("hanbing-zhang",230);
	set_skill("parry",230);
	set_skill("sword",230);
	set_skill("blade",230);
	set_skill("liuhe-dao",230);
	set_skill("shenghuo-lingfa",230);
	set_skill("qiankun-danuoyi", 530);
	set_skill("strike",230);
	set_skill("spear",230);
	set_skill("yuejia-qiangfa",230);

	map_skill("spear", "yuejia-qiangfa");
	map_skill("strike", "hanbing-zhang");
	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "datengnuo-bufa");
	map_skill("parry", "shenghuo-lingfa");
	map_skill("sword", "shenghuo-lingfa");

	prepare_skill("strike", "hanbing-zhang");

	setup();
	carry_object(__DIR__"obj/changqiang")->wield();
	carry_object("/d/mingjiao/obj/changpao")->wear();
}

void heal()
{
	object ob=this_object();
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 50");
		return;
	}
	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}
	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");
	return;
}
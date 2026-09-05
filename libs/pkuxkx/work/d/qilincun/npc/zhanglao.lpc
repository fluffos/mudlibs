// yang.cg.c
// Rewrote by iszt@pkuxkx, 2007-02-11
#include <ansi.h>

inherit NPC;

void heal();

void create()
{
	set_name("志明长老",({"zhiming zhanglao", "zhiming", "zhanglao"}));
	set("long", "这是一位手执禅杖、身穿布衣的长老，正盘膝坐在云床上打坐。\n");
	set("gender", "男性");
	set("age", 64);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 50);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 100);
	set("chat_msg", ({
		(: heal :),
	}));
	set("max_qi", 4000);
	set("max_jing", 2000);
	set("neili", 4000);
	set("max_neili", 4000);
	set("jiali", 100);
	set("combat_exp", 1200000);
	set("score", 4000);

	set_skill("force", 230);
	set_skill("jiuyang-shengong", 230);
	set_skill("dodge", 230);
	set_skill("datengnuo-bufa", 500);
	set_skill("hanbing-zhang", 230);
	set_skill("parry", 230);
	set_skill("sword", 230);
	set_skill("shenghuo-lingfa", 230);
	set_skill("qiankun-danuoyi", 230);
	set_skill("strike", 230);
	set_skill("spear", 230);
	set_skill("yuejia-qiangfa", 230);

	map_skill("spear", "yuejia-qiangfa");
	map_skill("strike", "hanbing-zhang");
	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "datengnuo-bufa");
	map_skill("parry", "shenghuo-lingfa");
	map_skill("sword", "shenghuo-lingfa");

	prepare_skill("strike", "hanbing-zhang");

	setup();
	carry_object("/clone/weapon/staff/tiezhang")->wield();
	carry_object("/clone/cloth/seng-cloth")->wear();
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
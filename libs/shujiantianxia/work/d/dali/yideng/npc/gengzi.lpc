// 农夫 By River@SJ 2002.6.5

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("农夫", ({ "nong fu", "nong", "fu" }) );
	set("long", "只见他实无惊人之处，双手托着黄牛大石，却又显得并不如何吃力。\n");
	set("gender", "男性" );
	set("age", 45);
	set("str", 30);
	set("con", 30);
	set("dex", 25);
	set("int", 25);
	set("per", 22);
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
	set_skill("literate", 200);
	set_skill("qiantian-yiyang", 280);
	set_skill("tianlong-xiang", 280);
	set_skill("cuff", 280);
	set_skill("duanjia-quan", 280);
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "duanjia-quan");
	map_skill("force", "qiantian-yiyang");
	map_skill("cuff", "duanjia-quan");
	prepare_skill("cuff","duanjia-quan");

	setup();
	carry_object(ARMOR_D("b_cloth"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}

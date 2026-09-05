// Rewrote by iszt@pkuxkx, 2007-02-12

inherit NPC;

void create()
{
	set_name("汤永澄", ({ "tang yongcheng", "tang", "yongcheng" }));
	set("gender", "男性");
	set("nickname", "员外郎");
	set("age", 50);
	set("long", "这是本地有名望的员外之一，出身行伍，人较耿直。\n");

	set("combat_exp", 800000);
	set("shen_type", 1);

	set("attitude", "peaceful");

	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("changquan", 200);

	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");

	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
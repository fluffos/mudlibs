// NPC: /d/meizhuang/npc/shilingwei.c
// By Looklove

inherit NPC;

void create()
{
	set_name("丹青生", ({ "danqing sheng", "sheng" }));
	set("nickname", "梅庄四庄主");

	set("gender", "男性");
	set("age", 46);
	set("no_quest", 1);
	set("no_bark", 1);
	set("long", "他髯长及腹，左手拿着一只酒杯，脸上醺醺然大有醉意。\n");

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("jingli", 4000);
	set("max_jingli", 4000);
	set("max_neili", 5000);
	set("neili", 8000);
	set("combat_exp", 2200000);
	set("attitude", "peaceful");

	set_skill("unarmed", 180);
	set_skill("art", 180);
	set_skill("medicine", 180);
	set_skill("literate", 180);
	set_skill("force", 220);
	set_skill("parry", 180);
	set_skill("tiyunzong", 180);
	set_skill("sword", 180);
	set_skill("xuantian-wuji", 180);
	set_skill("hengshan-jian", 180);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "tiyunzong");
	map_skill("sword", "hengshan-jian");
	map_skill("parry", "hengshan-jian");

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
        carry_object(BINGQI_D("changjian"))->wield();
}
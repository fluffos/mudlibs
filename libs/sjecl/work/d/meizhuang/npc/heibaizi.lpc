// NPC: /d/meizhuang/npc/huangzhonggong.c
// By Looklove

inherit NPC;

void create()
{
	set_name("黑白子", ({ "heibai zi", "zi" }));
	set("nickname", "梅庄二庄主");

	set("gender", "男性");
	set("age", 54);
	set("no_quest", 1);
	set("no_bark", 1);
	set("long", "他头发极黑而皮肤极白，果然是黑白分明。\n");

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

	set_temp("apply/damage", 40);

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
        carry_object(BINGQI_D("changjian"))->wield();
}
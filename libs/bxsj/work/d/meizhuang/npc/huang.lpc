// NPC: /d/meizhuang/npc/huang.c
// By Looklove 2001.9.11

inherit NPC;

void create()
{
	object ob;

	set_name("黄钟公", ({ "huangzhong gong", "huang", "gong" }));
	set("nickname", "梅庄大庄主");

	set("gender", "男性");
	set("age", 65);
	set("no_quest", 1);
	set("no_bark", 1);
	set("long", "他骨瘦如柴，脸上肌肉都凹了进去，直如一具骷髅，双目却炯炯有神。\n");

	set("qi", 4000);
	set("max_qi", 4000);
	set("jing", 4000);
	set("max_jing", 4000);
	set("jingli", 4000);
	set("max_jingli", 4000);
	set("max_neili", 5000);
	set("neili", 8000);
	set("combat_exp", 3200000);
	set("attitude", "peaceful");

	set_skill("unarmed", 180);
	set_skill("art", 180);
	set_skill("medicine", 120);
	set_skill("literate", 160);
	set_skill("force", 220);
	set_skill("parry", 240);
	set_skill("tiyunzong", 200);
	set_skill("sword", 280);
	set_skill("xuantian-wuji", 280);
	set_skill("hengshan-jian", 280);
	set_skill("claw", 240);
	set_skill("longzhua-gong", 240);

	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "tiyunzong");
	map_skill("sword", "hengshan-jian");
	map_skill("parry", "hengshan-jian");
	map_skill("claw", "longzhua-gong");

	set_temp("apply/damage", 260);

	setup();
        if (clonep()) {
                ob = unew(BINGQI_D("sword/yaoqin"));
                if (!ob) ob = unew(BINGQI_D("yuxiao2"));
                ob->move(this_object());
                ob->wield();
                carry_object(ARMOR_D("cloth"))->wear();
        }
}

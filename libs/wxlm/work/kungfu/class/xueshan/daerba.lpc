// /kungfu/class/xueshan/daerba.c  达而巴
// by secret

inherit NPC;
inherit F_MASTER;



void create()
{
	set_name("达而巴", ({ "daerba huofo", "huofo" }));
	set("long",@LONG
他是金轮上师座下的大弟子。深得法王的真传。
身穿一件黄色袈裟，头带僧帽。
LONG
	);
	set("title", HIY "活佛" NOR);
	set("gender", "男性");
	set("age", 45);
	set("attitude", "heroism");
	set("shen_type", -1);
	set("str", 26);
	set("int", 19);
	set("con", 22);
	set("dex", 21);
	set("max_qi", 3200);
	set("max_jing", 1600);
	set("neili", 3400);
	set("max_neili", 3400);
	set("jiali", 50);
	set("combat_exp", 270000);

	set_skill("lamaism", 80);
	set_skill("literate", 80);
	set_skill("force", 150);
	set_skill("mizong-neigong", 150);
	set_skill("dodge", 100);
	set_skill("shenkong-xing", 100);
	set_skill("cuff", 140);
	set_skill("yujiamu-quan", 140);
	set_skill("parry", 140);
	set_skill("staff", 120);
	set_skill("xiangmo-chu", 120);

	map_skill("force", "mizong-neigong");
	map_skill("dodge", "shenkong-xing");
	map_skill("cuff", "yujiamu-quan");
	map_skill("parry", "mingwang-jian");
	map_skill("staff", "xiangmo-chu");

	prepare_skill("cuff", "yujiamu-quan");

	create_family("雪山寺", 3, "活佛");
	set("class", "bonze");

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xueshan/obj/sengmao")->wear();
}

void attempt_apprentice(object ob)
{
	command("say 我不收徒的。");
}


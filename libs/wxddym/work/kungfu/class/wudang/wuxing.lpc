// wuxing.c 五行弟子

inherit NPC;

void create()
{
	set_name("五行弟子", ({ "wuxing dizi", "dizi", "wuxing"}));
	set("age", 23);
	set("gender", "男性");
	set("long", "真武剑阵的五行方位弟子。\n");
	set("attitude", "peaceful");
	set("str", 24);
	set("dex", 27);
	set("combat_exp", 420000);
	set("shen_type", 1);

	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("force", 120);
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/damage", 120);
	set_temp("apply/armor", 120);
	set("chat_chance", 2);
	set("chat_msg", ({
		"五行弟子齐声吆喝：真武剑阵，天下第一！\n",
	}));
	create_family("武当派", 3, "弟子");
	setup();
	carry_object("/clone/weapon/changjian");
	carry_object("/d/wudang/obj/wuxingfu")->wear();
}

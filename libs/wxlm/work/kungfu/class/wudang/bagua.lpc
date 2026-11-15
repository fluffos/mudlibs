// bagua.c 八卦弟子

#include <command.h>


inherit NPC;

void create()
{
	set_name("八卦弟子", ( {"bagua dizi","dizi","bagu" }));
	set("age", 23);
	set("gender", "男性");
	set("long", "真武剑阵八卦方位弟子。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 600000);
	set("shen_type", 1);

	set_skill("unarmed", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("force", 150);
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 150);
	set_temp("apply/armor", 150);
	set("chat_chance", 5);
	set("chat_msg", ({
		"八卦弟子齐声吆喝：真武剑阵，天下第一！\n",
	}));
	create_family("武当派", 3, "弟子");

	setup();
	carry_object("/clone/weapon/changjian");
	carry_object("/d/wudang/obj/baguafu")->wear();
}

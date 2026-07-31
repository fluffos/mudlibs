// REN.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("任无月", ({ "Ren wuyue","ren","wuyue" }) );
        set("nickname", RED"斩红郎 无双剑"NOR);        
        set("title",HIY"华山风老前辈爱徒"NOR);         
	set("gender", "男性");
	set("age", 45);
	set("long",
		"他是千古石的守卫，这家伙满脸杀气，一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 120000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set("chat_chance", 5);
	set("chat_msg", ({
		"任无月嘿嘿地冷笑道:竟敢闯进千古石，今天你就别想从这里活着出去了!\n",
	}) );
        set_skill("dugu-jiujian", 80);
	set_skill("sword", 80);
	set_skill("unarmed", 80);
	set_skill("parry", 150);
	set_skill("dodge", 80);
        map_skill("sword", "dugu-jiujian");
        map_skill("parry", "dugu-jiujian");
	setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 50);
}

// smith.c 地下铁铺NPC

inherit NPC;
#include "smith.h"
void create()
{
	set_name("铁铺伙计", ({ "huo ji", "huo" }));
	set("gender", "男性");
	set("age", 25);

	set("combat_exp", 500000);
	set("shen_type", 1);
	set("no_accpet", 1);
	set("boss_id","becool");
	set("boss_name","虫二");

	set_skill("unarmed", 300);
	set_skill("blade", 400);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	set("forging",350);
	
	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 200);
	set("inquiry", ([
                "name" : (: ask_here :),
                "锻造" : (: ask_forge :),
                "forge" : (: ask_forge :),
                "强化" : (: ask_add :),
                "add" : (: ask_add :),
                "定价" : (: ask_adjust :),
                "adjust" : (: ask_adjust :),
                "生意" : (: ask_business :),
                "business" : (: ask_business :),
                "收购" : (: ask_buy :),
                "buy" : (: ask_buy :),
        ]));

	setup();
//	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}
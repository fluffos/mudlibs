// zhelemi.c 者勒米

inherit NPC;
#include <ansi.h>
#include "cike.h";

void create()
{
	set_name("者勒米", ({ "zhe lemi", "zhelemi","zhele","mi"}));
	set("gender", "男性");
        set("title",HIR"神风营千夫长"NOR);
	set("age", 30);
	set("str", 30);
	set("dex", 25);
	set("long", "他个子不高，但肌肉扎结，身体非常强健，颔下留着短须。\n他久经沙场，是蒙古族著名的勇士。");
	set("max_qi",700);
	set("eff_jing",300);
	set("max_jing",300);
	set("combat_exp", 400000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("unique", 1);

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("blade", 120);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_temp("apply/attack", 100);
	set_temp("apply/defense",100);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 100);

	setup();
	carry_object(ARMOR_D("bianfuxuejia"))->wear();
    carry_object(BINGQI_D("wandao"))->wield();
}


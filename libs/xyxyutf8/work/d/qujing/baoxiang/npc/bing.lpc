#include <ansi.h>

inherit NPC;

void create()
{
	int i = 20+random(20);
        set_name("宫兵", ({ "gong bing", "bing" }) );
        set("gender", "男性");
        set("age", 35);
        set_level(i);

        set("attitude", "heroism");

        set("force_factor", random(50)+25);
        set_skill("unarmed",i*10);
        set_skill("parry",i*10);
        set_skill("dodge",i*10);
        set_skill("blade",i*10);

        setup();

        carry_object("/d/qujing/baoxiang/obj/wandao")->wield();
        carry_object("/d/qujing/baoxiang/obj/zhanpao")->wear();
}
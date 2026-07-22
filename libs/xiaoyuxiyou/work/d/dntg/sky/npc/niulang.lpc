//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIG"牛郎"NOR, ({"niu lang", "niulang", "lang"}));
       	set("long","原来是个放牛娃，后与织女相爱，生下一双儿女，后被罚银河永隔，\n只有每年的七月初七才能鹊桥相会。\n");
	set("gender", "男性");
        set_level(39);
       	set("age", 20);
       	set("class", "xian");
        set("title", "");
       	set("attitude", "friendly");
       	set("per", 30);
	set("int", 30);
        set("force_factor", 50);
	set("mana_factor", 0);
	set("daoxing", 80000);

	set_skill("literate", 250);
        set_skill("unarmed", 250);
        set_skill("dodge", 250);
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("blade", 250);
	set_skill("xuanhu-blade", 250);
        set_skill("spells", 250);
        set_skill("moonshentong", 250);
        set_skill("baihua-zhang", 250);
        set_skill("moondance", 250);
        set_skill("moonforce", 250);
        map_skill("spells", "moonshentong");
        map_skill("force", "moonforce");
        map_skill("blade", "xuanhu-blade");
        map_skill("parry", "xuanhu-blade");
        map_skill("unarmed", "baihua-zhang");
        map_skill("dodge", "moondance");

	setup();

        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/blade/yuandao")->wield();
}

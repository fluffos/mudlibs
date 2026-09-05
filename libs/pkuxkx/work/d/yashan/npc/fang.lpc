//方伯谦
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY"方伯谦"NOR, ({ "fang boqian", "fang","boqian" }));
	set("age", 42);
	set("gender", "男性");
	set("long", "他是济远号的管带，牙山的资深官。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 1000000);
	set("shen_type", 1);

	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("blade", 70);
	set_skill("force", 70);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 70);
	set_temp("apply/armor", 70);
    set("random_npc",1);
	if (random(2) == 1) {
		set("chat_chance", 500);
		set("chat_msg", ({
			"唉，弹药不足......\n",
			"大家一定要顶住!\n",
			"要注意救火，火烧长了，会把船烧毁的！\n",
			"一定要瞄准呀！!\n",
		}));
	}

    setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
}

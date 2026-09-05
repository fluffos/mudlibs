//林国祥
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY"林国祥"NOR, ({ "lin guoxiang", "lin","guoxiang" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "他是广乙号的管带。\n");
	set("attitude", "peaceful");

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 1000000);
	set("shen_type", 1);

	set_skill("unarmed", 65);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("blade", 65);
	set_skill("force", 65);
	set_temp("apply/attack", 65);
	set_temp("apply/defense", 65);
	set_temp("apply/damage", 65);
	set_temp("apply/armor", 65);
    set("random_npc",1);
	if (random(2) == 1) {
		set("chat_chance", 500);
		set("chat_msg", ({
			"唉，弹药不足......\n",
			"大家一定要顶住哇!\n",
			"要注意救火....\n",
			"大家一定要瞄准打呀！!\n",
		}));
	}

    setup();
	carry_object(__DIR__"obj/gangdao")->wield();
	carry_object(__DIR__"obj/junfu")->wear();
}

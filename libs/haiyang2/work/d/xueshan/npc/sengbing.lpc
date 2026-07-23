//
// /d/xueshan/npc/seng-bing1.c
//

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("守寺僧兵", ({
		"seng bing",
		"seng",
		"bing",
	}));
	set("long",
                "他是一位身材高大的壮年僧人，两臂粗壮，膀阔腰圆。他手持僧\n"
                "棍，身穿一袭黑色袈裟，似乎怀有一身武艺。\n"
	);

	set("gender", "男性");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", -1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 3500);
	set("max_jing", 3300);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiaji", 50);
	set("combat_exp", 180000);
	set("score", 1);

	set_skill("force", 50);
	set_skill("xiaowuxiang", 150);
	set_skill("dodge", 50);
	set_skill("shenkong-xing", 150);
	set_skill("unarmed", 50);
	set_skill("yujiamu-quan", 250);
	set_skill("parry", 50);
	set_skill("staff", 50);
	set_skill("xiangmo-chu", 250);

	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong-xing");
	map_skill("unarmed", "yujiamu-quan");
	map_skill("parry", "xiangmo-chu");
	map_skill("staff", "xiangmo-chu");

	setup();

    carry_object("/d/xueshan/obj/senggun")->wield();
    carry_object("/d/xueshan/obj/b-jiasha")->wear();
}

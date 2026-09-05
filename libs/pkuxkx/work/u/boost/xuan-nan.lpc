// Npc: /kungfu/class/shaolin/xuan-nan.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("玄难大师", ({
		"xuannan dashi",
		"xuannan",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材极瘦，\n"
		"两手更象鸡爪一样。他双目微闭，一副没精打采的模样。\n"
	);


	set("title", HIR "少林" NOR + MAG "神僧" NOR);
	set("nickname", CYN "般若堂" NOR + RED "首座" NOR);
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 2000);
	set("max_jing", 1000);
	set("neili", 2500);
	set("max_neili", 2500);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 100000);

	set_skill("force", 160);
	set_skill("hunyuan-yiqi", 160);
	set_skill("dodge", 160);
	set_skill("shaolin-shenfa", 160);
	set_skill("parry", 160);
	set_skill("cuff", 160);
	set_skill("club", 160);
	set_skill("finger", 160);
	set_skill("strike", 160);
	set_skill("jingang-quan", 160);
	set_skill("wuchang-zhang", 160);
	set_skill("yizhi-chan", 160);
	set_skill("banruo-zhang", 160);
	set_skill("buddhism", 160);
	set_skill("literate", 160);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "jingang-quan");
	map_skill("finger", "yizhi-chan");
	map_skill("strike", "banruo-zhang");
	map_skill("club", "wuchang-zhang");
	map_skill("parry", "wuchang-zhang");

	prepare_skill("finger", "yizhi-chan");
	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 36, "弟子");

	set("inquiry", ([
		"十八罗汉阵"       : (: ask_me :),
		"罗汉大阵"	   : (: ask_me :)
	]));

	setup();

        carry_object("/d/shaolin/obj/chanzhang")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}


#include "/kungfu/class/shaolin/xuan-nan.h"
#include "/kungfu/class/shaolin/xuan1.h"


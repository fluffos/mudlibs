// Npc: /kungfu/class/shaolin/xuan-nan.c
// Date: YZC 96/01/19

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


	set("nickname", "般若堂首座");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 5500);
	set("max_jing", 5000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("force", 220);
	set_skill("hunyuan-yiqi", 220);
	set_skill("dodge", 220);
	set_skill("shaolin-shenfa", 220);
	set_skill("parry", 220);
	set_skill("cuff", 220);
	set_skill("club", 220);
	set_skill("finger", 220);
	set_skill("strike", 220);
	set_skill("jingang-quan", 220);
	set_skill("wuchang-zhang", 220);
	set_skill("yizhi-chan", 220);
	set_skill("banruo-zhang", 220);
	set_skill("buddhism", 220);
	set_skill("literate", 220);
set_skill("riyue-bian", 150);
set_skill("damo-jian", 250);
set_skill("wuying-jian", 250);
set_skill("weituo-zhang", 250);
set_skill("shaolin-tantui", 250);
set_skill("jingang-zhang", 250);
set_skill("jimie-zhua", 250);
set_skill("duoluoye-zhi", 250);
set_skill("mohe-zhi", 250);
set_skill("boluomi-shou", 250);
set_skill("yijinjing",200);
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


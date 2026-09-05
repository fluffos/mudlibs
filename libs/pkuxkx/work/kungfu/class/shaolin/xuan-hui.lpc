#include <ansi.h>

inherit NPC;
#include "/new_quest/qzhengpai.h"
#include "/new_quest/quest.h"

void create()
{
	set_name("玄惠大师", ({
		"xuanhui dashi",
		"xuanhui",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。\n"
		"他的工作就是给少林弟子布置任务。\n"
	);


//	set("nickname", "达摩院主持");
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

	set_skill("force", 180);
	set_skill("hunyuan-yiqi", 180);
	set_skill("dodge", 180);
	set_skill("shaolin-shenfa", 180);
	set_skill("hand", 180);
	set_skill("claw", 180);
	set_skill("blade", 180);
	set_skill("sword", 180);
	set_skill("parry", 180);
	set_skill("qianye-shou", 180);
	set_skill("longzhua-gong", 180);
	set_skill("cibei-dao", 180);
	set_skill("damo-jian", 180);
	set_skill("buddhism", 180);
	set_skill("literate", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("hand", "qianye-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("blade", "cibei-dao");
	map_skill("sword", "damo-jian");
	map_skill("parry", "cibei-dao");

	prepare_skill("hand", "qianye-shou");
	prepare_skill("claw", "longzhua-gong");
        set("inquiry", ([
        "quest":   (: ask_quest() :),
        "cancelquest":   (: ask_cancel() :),
        "取消任务":   (: ask_cancel() :),
      ]));


	create_family("少林派", 36, "弟子");

	setup();

        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}


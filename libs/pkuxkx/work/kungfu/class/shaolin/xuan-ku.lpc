// Npc: /kungfu/class/shaolin/xuan-ku.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("玄苦大师", ({
		"xuanku dashi",
		"xuanku",
		"dashi",
	}));
	set("long",
		"他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材瘦高，\n"
		"脸上满布皱纹，手臂处青筋绽露，似乎久经风霜。\n"
	);


	set("title", HIR "少林" NOR + MAG "神僧" NOR);
	set("nickname", CYN "罗汉堂" NOR + RED "首座" NOR);
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
	set_skill("staff", 160);
	set_skill("blade", 160);
	set_skill("sword", 160);
	set_skill("luohan-quan", 160);
	set_skill("weituo-gun", 160);
	set_skill("xiuluo-dao", 160);
	set_skill("fumo-jian", 160);
	set_skill("buddhism", 160);
	set_skill("literate", 160);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("parry", "luohan-quan");
	map_skill("cuff", "luohan-quan");
	map_skill("staff", "weituo-gun");
	map_skill("blade", "xiuluo-dao");
	map_skill("sword", "fumo-jian");

	prepare_skill("cuff", "luohan-quan");

	create_family("少林派", 36, "弟子");

	set("inquiry", ([
		"十八罗汉阵"       : (: ask_me :),
		"罗汉大阵"	   : (: ask_me :)
	]));

	setup();

        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

#include "/kungfu/class/shaolin/xuan-ku.h"
#include "/kungfu/class/shaolin/xuan1.h"





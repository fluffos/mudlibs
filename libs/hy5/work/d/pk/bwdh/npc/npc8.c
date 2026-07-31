#include "ansi.h"

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void create()
{
	set_name("小谢逊", ({"xie xun", "xie", "xun", }));
	set("long",
        "他是一位身材魁伟异常的的老者，身穿一件白布长袍。\n"
        "他满头黄发，威风凛凛，真如天神一般，只是两只眼睛并不睁开。\n"
	);

	set("title",HIG "明教" HIY "金毛狮王" NOR);
	set("level",9);
	set("gender", "男性");
	set("attitude", "peaceful");

	set("age", 63);
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("max_qi", 8500);
	set("max_jing", 8500);
	set("neili", 8000);
	set("max_neili", 33000);
	set("jiali", 250);

	set("combat_exp", 1900000);
	set("score", 800000);

    	set_skill("force", 260);
	set_skill("dodge", 240);
	set_skill("sword", 240);
	set_skill("blade", 240);
	set_skill("parry", 240);
	set_skill("cuff", 300);
	set_skill("blade", 220);
	set_skill("jinwu-daofa", 240);
	set_skill("jiuyang-shengong", 260);
	set_skill("lingxu-bu", 240);
    	set_skill("damo-jian", 240);
    	set_skill("qishang-quan", 300);
    	set_skill("hunyuan-zhang", 250);
    	set_skill("literate", 200);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "lingxu-bu");
	map_skill("cuff", "qishang-quan");
    	map_skill("parry", "hunyuan-zhang");
    	map_skill("sword", "damo-jian");
	map_skill("blade", "jinwu-daofa");

	prepare_skill("cuff","qishang-quan");

	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: command("perform hunpofeiyang") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
	}) );
	create_family("明教",34, "法王");
	setup();
    	carry_object("/d/mingjiao/obj/baipao")->wear();
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");

}




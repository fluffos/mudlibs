// NPC: /d/huashan/npc/gao.c
// Date: Look 99/03/25
// Lklv modify 2001.10.18

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("高老者",({"gao laozhe","gao"}));
        set("title","华山派第十二代弟子");
        set("long", "这就是在江湖中隐居的华山派高老者。");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 32);
        set("int", 32);
        set("con", 32);
        set("dex", 32);

        set("max_qi",3500);
        set("qi", 3500);
        set("max_jing", 2500);
        set("jing",2500);
        set("eff_jingli", 3000);
        set("max_neili", 4000);
        set("neili", 4000);
        set("jiali", 50);
        set("combat_exp", 1900000);
        set("score", 30000);

	set_skill("dodge",  190);
	set_skill("force",  190);
	set_skill("cuff", 190);
	set_skill("sword", 190);
        set_skill("parry",  190);
	set_skill("poyu-quan", 190);
	set_skill("literate",190);
	set_skill("zixia-gong", 185);
	set_skill("huashan-jianfa",  190);
	set_skill("huashan-shenfa",  190);
	set_skill("zhengqi-jue", 185);

        map_skill("dodge", "huashan-shenfa");
        map_skill("sword", "huashan-jianfa");
        map_skill("force","zixia-gong");
        map_skill("parry","poyu-quan");
        map_skill("cuff", "poyu-quan");
        prepare_skill("cuff","poyu-quan");
	set("chat_chance_combat",30);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yangwu" :),
		(: perform_action, "sword.feijian" :),
		(: perform_action, "sword.junzi" :),
		(: perform_action, "sword.kuaijian" :),
		(: perform_action, "sword.lianhuan" :),
		(: perform_action, "sword.sanqing" :),
	}));
        create_family("华山派",12,"弟子");

        setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(BINGQI_D("sword"))->wield();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        if ( mapp(fam=ob->query("family"))
         && (string)fam["family_name"] != "华山派"
         && (int)ob->query("is/huashan")==1 ) {
		message_vision(CYN "$N！你这个华山派的叛徒还回来干什么 ？？？\n"NOR, ob );
		command("slap "+ob->query("id"));
		return;
	}
	if ( ob->query("fengset")) {
		command("say 你不是已经拜了风清扬为师了么？");
		return;
	}
	if ((int)ob->query("shen") <= 0) {
		command("say 我华山派乃是堂堂名门正派，对弟子要求极严。");
		command("say 在德行方面，" + RANK_D->query_respect(ob)+"是否还做得不够？");
		return;
        }
        if ((int)ob->query("max_pot") < 200) {
		command("say " + RANK_D->query_respect(ob)+"现在不需要我来指导，回去安心找你师傅学艺去吧。");
		return;
        }
        if( (int)ob->query_skill("zixia-gong", 1) < 100 ) {
		command("say 你的紫霞神功还未到火候,老朽我可不能收你为徒。\n");
		return;
        }
        if( (int)ob->query_skill("force") < 100 ) {
		command("say 你的内功还未到火候,老朽我可不能收你为徒。\n");
		return;
        }
        command("say 好吧，我就收下你了,你可要为我们华山派争口气。");
        command("recruit " + ob->query("id"));
}

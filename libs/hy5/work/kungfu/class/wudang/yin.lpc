// yin.c 殷梨亭
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("殷梨亭", ({ "yin liting","yin"}));
        set("nickname", "武当六侠");
        set("long",
                "他就是张三丰的最软弱的弟子、武当七侠之六的殷梨亭。\n"
                "身穿一件干干净净的青布长衫。\n"
                "他不过二十出头年纪，精明能干，嫉恶如仇，性如烈火，却一直一副不愉快的表情。\n");
        set("gender", "男性");
        set("age", 23);
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("shen_type", 1);
        set("str", 26);
        set("int", 39);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 8000);
        set("max_jing", 8000);
        set("neili", 5000);
        set("max_neili", 1000);
        set("jingli", 1000);
        set("max_jingli", 1000);
        set("jiali", 50);
        set("combat_exp", 250000);
        set("score", 60000);

        set_skill("force", 95);
        set_skill("taiji-shengong", 100);
        set_skill("dodge", 95);
        set_skill("tiyunzong", 100);
        set_skill("unarmed", 100);
        set_skill("taiji-quan", 100);
        set_skill("parry", 100);
        set_skill("sword", 100);
        set_skill("liangyi-jian", 100);
        set_skill("literate", 95);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 180);
	set_skill("shenmen-jian", 180);
	set_skill("yitian-zhang", 180);
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");	
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");

        create_family("武当派", 2, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 3) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
        if ((int)ob->query_skill("taiji-shengong", 1) < 40) {
                command("say 我武当派乃内家武功，最重视内功心法。");
                command("say " + RANK_D->query_respect(ob) +
                        "是否还应该在太极神功上多下点功夫？");
                return;
        }
        if ((int)ob->query("shen") < 1000) {
                command("say 我武当乃是堂堂名门正派，对弟子要求极严。");
                command("say 在德行方面，" + RANK_D->query_respect(ob) +
                        "是否还做得不够？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
}

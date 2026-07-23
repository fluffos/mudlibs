// mo.c 莫声谷

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("莫声谷", ({ "mo shenggu", "mo" }));
        set("nickname", "武当七侠");
        set("long",
                "他就是张三丰的最小弟子、武当七侠之末的莫声谷。\n"
                "身穿一件干干净净的灰色道袍。\n"
                "他不过二十出头年纪，显得稚气未脱，身材瘦长，眉宇飞扬。。\n");
        set("gender", "男性");
        set("age", 21);
        set("attitude", "peaceful");
        set("class", "swordsman");
        set("shen_type", 1);
        set("str", 26);
        set("int", 26);
        set("con", 26);
        set("dex", 26);

        set("max_qi", 8800);
        set("max_jing", 8800);
        set("neili", 8800);
        set("max_neili", 8800);
        set("jingli", 1800);
        set("max_jingli", 1800);
        set("jiali", 50);
        set("combat_exp", 600000);
        set("score", 60000);

        set_skill("force", 80);
        set_skill("taiji-shengong", 190);
        set_skill("dodge", 90);
        set_skill("tiyunzong", 90);
        set_skill("unarmed", 80);
        set_skill("taiji-quan", 185);
        set_skill("parry", 90);
        set_skill("sword", 90);
        set_skill("liangyi-jian", 90);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 180);
	set_skill("shenmen-jian", 180);
	set_skill("yitian-zhang", 180);
        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "liangyi-jian");
        map_skill("sword", "liangyi-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
//prepare_skill("hand", "paiyun-shou");
//prepare_skill("strike", "yitian-zhang");
	set("chat_chance", 20);
        set("chat_msg", ({
            "莫声谷轻声说道：在石柱面壁可以大有收获的。\n",
            "莫声谷斜了你一眼：不过邪魔外道就不能面壁的了。\n",
            "莫声谷偷偷告诉你：面壁是一定要注明技能的。\n",
            "莫声谷自豪地说道：只有我武当才是天下的正宗。\n",
            "莫声谷对张三丰的钦仰溢于言表：如果想成为绝顶高手，一定要学道德经。\n"
        }));

        create_family("武当派", 2, "弟子");

        setup();
        set("inquiry", ([
           "石柱":     "在石柱面壁可以大有收获的。",
           "面壁":     "面壁是一定要注明技能的。",
           "张三丰":   "我恩师学究天人，尤其是他的道学心法。"]) );
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("guarded") < 3) {
                command("say " + RANK_D->query_respect(ob) +
                        "你对我武当派尽了多少心力，有几分忠心呢？");
                return;
        }
        if ((int)ob->query_skill("taiji-shengong", 1) < 30) {
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

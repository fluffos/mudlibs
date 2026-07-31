// Npc: /kungfu/class/shaolin/hui-zhen.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;


void create()
{
	set_name("矮老者", ({
			"ai laozhe",
                "laozhe",
        }));
        set("long",
		"他是一位身材矮小的老者，身穿一件灰布长衫。\n"
                "太阳穴微凸，双目炯炯有神。\n"
        );

        set("gender", "男性");
        set("attitude", "friendly");

        set("age", 50);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_kee", 600);
        set("max_gin", 500);
        set("force", 1000);
        set("max_force", 1000);
        set("force_factor", 100);
        set("combat_exp", 50000);
        set("score", 100);

        set_skill("force", 100);
        set_skill("huashan-neigong", 80);
        set_skill("dodge", 80);
        set_skill("huashan-shenfa", 80);
        set_skill("cuff", 90);
        set_skill("poyu-quan", 90);
        set_skill("strike", 70);
        set_skill("hunyuan-zhang", 70);
        set_skill("sword", 80);
        set_skill("huashan-jianfa", 80);
        set_skill("parry", 80);
        set_skill("literate", 100);

        map_skill("force", "huashan-neigong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("cuff", "poyu-quan");
        map_skill("strike", "hunyuan-zhang");
        map_skill("sword", "huashan-jianfa");
        map_skill("parry", "huashan-jianfa");

        prepare_skill("cuff", "poyu-quan");
        prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派", 17, "弟子");

        setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/huashan/obj/huishan")->wear();
}

// fengbuping.c -封不平
#include <ansi.h>
inherit NPC;
int ask_xueyi();

void create()
{
        set_name("成不优",({"cheng buyou","cheng","buyou"}));
	set("title", GRN "华山" NOR + YEL "剑宗" NOR + CYN "传人" NOR);
        set("long",
                "华山派剑宗传人。\n"
                "他是华山剑宗的第一高手。剑气之争剑宗一败涂地，封不平隐居苦练，。\n");
        set("gender", "男性");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 22);
        set("int", 26);
        set("con", 26);
        set("dex", 26);

        set("max_qi",  2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 50);
        set("combat_exp", 1000000);
        set("score", 10000);

        set_skill("force", 100);
        set_skill("huashan-neigong", 100);
        set_skill("huashan-xinfa", 150);
        set_skill("dodge", 120);
        set_skill("huashan-shenfa", 120);
        set_skill("parry", 120);
        set_skill("sword", 130);
        set_skill("huashan-jianfa", 120);
        set_skill("strike", 100);
        set_skill("hunyuan-zhang", 100);

        map_skill("strike", "hunyuan-zhang");
        map_skill("force", "huashan-neigong");
	map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("strike", "hunyuan-zhang");

        create_family("华山派" , 18, "弟子");

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/huashan/obj/baishan")->wear();
}

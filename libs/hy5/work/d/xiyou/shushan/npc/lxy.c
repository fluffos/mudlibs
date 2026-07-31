// modified by vikee
//【蜀山剑派】dhxy-evil 2000.7.5
inherit NPC;
inherit F_MASTER;
int ask_me();
int recruit_apprentice(object ob);
int attempt_apprentice(object me);
int do_report();

void create()
{
        set_name("李逍遥", ({ "li xiaoyao", "li", "xiaoyao" }));
        set("title","蜀山剑派入门弟子");
        set("long", 
"李逍遥身材较瘦，长的浓眉阔眼，气宇暄昂。\n");
        set("gender", "男性");
        set("age", 18);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 30);
        set("kee", 2800);
        set("max_kee", 2800);
        set("sen", 1600);
        set("max_sen", 1600);
        set("force", 4800);
        set("max_force", 2400);
        set("mana", 4800);
        set("max_mana", 2400);
        set("force_factor", 60);
        set("mana_factor", 60);

        set("combat_exp", 1800000);
        set("daoxing", 2500000);


        set("inquiry", ([
                "赵灵儿" : "你能帮我去救灵儿？我可会报答你的！\n",
                "醉道士" : "好久没见师父了！\n",


        ]));
        setup();
        create_family("蜀山剑派", 5, "未入门弟子");
        carry_object("/clone/misc/cloth")->wear();
         carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}


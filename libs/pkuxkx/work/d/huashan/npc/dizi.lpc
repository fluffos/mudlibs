// dayou.c c
inherit NPC;
void create()
{
        set_name("华山弟子", ({ "dizi" }));
//        set("nickname", "六猴儿");
        set("long",
"华山弟子\n");
        set("gender", "男性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        set("max_qi", 300);
        set("max_jing", 200);
        set("neili", 300);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 2000);
        set("score", 100);
        set_skill("force", 20);
        set_skill("huashan-neigong", 20);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("sword", 20);
//      set_skill("huashan-jianfa", 60);
        map_skill("force", "huashan-neigong");
//      map_skill("parry", "huashan-jianfa");
//      map_skill("sword", "huashan-jianfa");
        create_family("华山派", 20, "弟子");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
}

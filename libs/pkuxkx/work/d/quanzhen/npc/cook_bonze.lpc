
inherit NPC;

void create()
{
     set_name("烧火道士",({"dao shi","dao"}));
     set("gender", "男性");
     set("class", "bonze");
     set("age",35);
     set("long","一位长得肥肥胖胖, 福福泰泰的中年僧人。\n");
     set("combat_exp", 1100);
     set("attitude", "friendly");

     set("max_neili",400);
     set("neili",400);
     set("force", 800);
     set("force_factor", 2);

     set_skill("force",40);
     set_skill("unarmed",40);
     set_skill("blade",45);
     set_skill("dodge",35);


     set("shen_type",1);set("score",200);setup();

     carry_object(__DIR__"obj/cloth")->wear();
}

int accept_fight(object me)
{
     command("say 阿弥陀佛 !! 贫僧的菜刀是用来切菜的, 不是用来砍人的。\n");
     return 0;
}

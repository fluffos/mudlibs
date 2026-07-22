// shatongtian.c 沙通天

inherit NPC;
 
void create()
{
        set_name("沙通天", ({ "sha tongtian", "tongtian", "sha" }));
        set("nickname", "鬼门龙王");
        set("long", 
        "他就是黄河四鬼的杀通天。\n"
        "满脸横肉，眼睛里冒这凶光。\n");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("str", 28);
        set("int", 20);
        set("con", 23);
        set("dex", 24);
        
        set("max_qi", 1000);
        set("max_jing", 800);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 50);
        set("combat_exp", 550000);
        set("shen", -5500);

    set_skill("force", 100);
    set_skill("hunyuan-yiqi", 120);
    set_skill("dodge", 100);

    set_skill("shaolin-shenfa", 120);
    set_skill("cuff", 100);
    set_skill("damo-jian", 100);
    set_skill("parry", 100);
    set_skill("sword", 100);
    set_skill("jingang-quan", 80);
    set_skill("literate", 30);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "jingang-quan");
    map_skill("parry", "damo-jian");
    map_skill("sword", "damo-jian");
    prepare_skill("cuff", "jingang-quan");
 
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
//        add_money("gold", 3);
}
// houtonghai.c 侯通海

inherit NPC;
 
void create()
{
        set_name("侯通海", ({ "hou tonghai", "hou", "tonghai" }));
        set("nickname", "三头蛟");
        set("long", 
        "他就是黄河四鬼的侯通海。\n"
        "尖嘴猴腮，面露邪气，一看就不是好人。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("str", 27);
        set("int", 20);
        set("con", 22);
        set("dex", 22);
        
        set("max_qi", 850);
        set("max_jing", 700);
        set("neili", 1100);
        set("max_neili", 1100);
        set("jiali", 20);
        set("combat_exp", 350000);
        set("shen", 3500);

    set_skill("force", 90);
    set_skill("hunyuan-yiqi", 100);
    set_skill("dodge", 90);
    set_skill("shaolin-shenfa", 100);
    set_skill("cuff", 90);
    set_skill("parry", 90);
    set_skill("taizu-quan", 100);
    set_skill("literate", 20);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "taizu-quan");
    map_skill("parry", "taizu-quan");
    prepare_skill("cuff", "taizu-quan");
 
        setup();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 5);
}
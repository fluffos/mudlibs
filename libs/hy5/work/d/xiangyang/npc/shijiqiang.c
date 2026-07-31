// shijiqiang.c史季强

inherit NPC;
 
void create()
{
        set_name("史季强", ({ "shi jiqiang","shi", "jiqiang" }));
        set("nickname", "大力神");
        set("long", 
        "他就万兽山庄五兄弟的老四，生具异禀,力大无穷。\n");
        set("gender", "男性");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen", 4000);
        set("str", 36);
        set("int", 15);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 50);
        set("combat_exp", 400000);
        
    set_skill("force", 80);
    set_skill("hunyuan-yiqi", 80);
    set_skill("dodge", 90);
    set_skill("club", 80);
    set_skill("weituo-gun", 80);
    set_skill("shaolin-shenfa", 80);
    set_skill("cuff", 100);
    set_skill("jingang-quan", 90);
    set_skill("parry", 80);

        map_skill("force", "hunyuan-yiqi");
        map_skill("club", "weituo-gun");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "weituo-gun");
        prepare_skill("cuff", "jingang-quan");

         set("inquiry", ([
                "神雕侠" : "三哥全仗他老人家的内伤才得以康复。",
                "霍都" : "再要见到那个狗贼，一定要杀了他。",
                "御兽": "此技为我们兄弟祖传之术，武功若无小成，学习甚是危险。",
                
        ]) );
        
        setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 1);
}
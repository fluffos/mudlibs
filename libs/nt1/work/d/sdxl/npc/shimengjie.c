// shimengjie.c史孟捷

inherit NPC;
 
void create()
{
        set_name("史孟捷", ({ "shi mengjie","shi","mengjie" }));
        set("nickname", "八手仙猿");
        set("long", 
        "他就万兽山庄五兄弟的最小一个，可是一身的武艺却非常出色。\n");
        set("gender", "男性");
        set("age", 24);
        set("attitude", "peaceful");
        set("shen", 6500);
        set("str", 25);
        set("int", 20);
        set("con", 25);
        set("dex", 21);
        
        set("max_qi", 1000);
        set("max_jing", 900);
        set("neili", 1100);
        set("max_neili", 1100);
        set("jiali", 50);
        set("combat_exp", 500000);
        
    set_skill("force", 105);
    set_skill("hunyuan-yiqi", 105);
    set_skill("dodge", 90);
    set_skill("blade", 90);
    set_skill("xiuluo-dao", 90);
    set_skill("shaolin-shenfa", 90);
    set_skill("cuff", 90);
    set_skill("jingang-quan", 90);
    set_skill("parry", 90);
    set_skill("literate", 50);

        map_skill("force", "hunyuan-yiqi");
        map_skill("blade", "xiuluo-dao");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("parry", "xiuluo-dao");
        prepare_skill("cuff", "jingang-quan");

         set("inquiry", ([
                "神雕侠" : "三哥全仗他老人家的内伤才得以康复。",
                "霍都" : "再要见到那个狗贼，一定要杀了他。",
                "御兽": "此技为我们兄弟祖传之术，武功若无小成，学习甚是危险。",
                
        ]) );
        
        setup();
        carry_object("/d/city/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 1);
}
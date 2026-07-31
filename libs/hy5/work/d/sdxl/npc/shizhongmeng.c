// shizhongmeng.c史仲猛

inherit NPC;
 
void create()
{
        set_name("史仲猛", ({ "shi zhongmeng","shi","zhongmeng" }));
        set("nickname", "管见子");
        set("long", 
        "他就万兽山庄五兄弟的老二，身体结实，虎背熊腰。\n"
        "擅长驾御野兽。\n");
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen", 4300);
        set("str", 28);
        set("int", 16);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 800);
        set("max_jing", 700);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 50);
        set("combat_exp", 430000);
         
    set_skill("force", 80);
    set_skill("yinyun-ziqi", 80);
    set_skill("dodge", 80);
    set_skill("tiyunzong", 80);
    set_skill("hand", 80);
    set_skill("juehu-shou", 80);
    set_skill("parry", 80);
    set_skill("literate", 50);

    map_skill("force", "yinyun-ziqi");
    map_skill("dodge", "tiyunzong");
    map_skill("hand", "juehu-shou");
    map_skill("parry", "juehu-shou");
    prepare_skill("hand", "juehu-shou");

         set("inquiry", ([
                "神雕侠" : "三弟的病全仗他老人家才得以康复。",
                "霍都" : "再要见到那个狗贼，一定要杀了他。",
                "御兽": "此技为我们兄弟祖传之术，武功若无小成，学习甚是危险。",
                
        ]) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
//        add_money("gold", 1);
}
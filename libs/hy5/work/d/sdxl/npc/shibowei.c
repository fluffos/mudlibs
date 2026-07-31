// shibowei.c 史伯威

inherit NPC;
 
void create()
{
        set_name("史伯威", ({ "shi bowei","shi", "bowei" }));
        set("nickname", "白额山君");
        set("long", 
        "他就万兽山庄五兄弟的大哥，身材魁梧，面色微黑。\n"
        "据说一身御兽本领出神入化。\n");
        set("gender", "男性");
        set("age", 38);
        set("attitude", "peaceful");
        set("shen", 4500);
        set("str", 25);
        set("int", 18);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 800);
        set("max_jing", 600);
        set("neili", 900);
        set("max_neili", 900);
        set("jiali", 50);
        set("combat_exp", 450000);
         
    set_skill("force", 90);
    set_skill("hunyuan-yiqi", 90);
    set_skill("dodge", 90);
    set_skill("shaolin-shenfa", 80);
    set_skill("cuff", 90);
    set_skill("jingang-quan", 80);
    set_skill("parry", 90); 
    set_skill("literate", 20);

    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shnfa");
    map_skill("cuff", "jingang-quan");
    map_skill("parry", "jingang-quan");
    prepare_skill("cuff", "jingang-quan");

         set("inquiry", ([
                "神雕侠" : "三弟的病全仗他老人家才得以康复。",
                "霍都" : "再要见到那个狗贼，一定要杀了他。",
              
                
        ]) );
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        add_money("silver", 50);
}
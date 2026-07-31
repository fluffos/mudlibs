 // TIE@FY3
inherit NPC;
void create()
{
        //string *name = ({"山烟寺","兴国禅寺","塞外","印度","南山寺","无名寺","黄山","泰庙"});
        set_name("无名寺的和尚", ({ "wild monk", "monk"}) );
        set("gender", "男性");
        set("age", random(90)+10);
        set("long",
                "一个到东林的外寺和尚。\n");
        set("combat_exp", 3000000);
        set("neili",1200);
        set("max_neili",1200);
        set("force_factor",50);
        set("cor",40);
        set("cps",40);
        
        set("class","shaolin");
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        
        set("no_busy",2); 
        set_skill("unarmed", 180);
        set_skill("jingang-quan",150);
        set_skill("move",200);
        set_skill("dodge",150);
        set_skill("shaolin-shenfa",150);
        set_skill("force",100); 
        
        map_skill("unarmed", "jingang-quan");
        map_skill("dodge","shaolin-shenfa");
        map_skill("move","shaolin-shenfa");
              
        set("chat_chance", 1);
        set("chat_msg", ({
                name()+"叹道：东林不愧为禅宗大庙呀．．\n",
                name()+"道：我看东林也不乏空有虚名者！\n",
                name()+"对你说道：这位小弟，你意下如何？\n",
        }) ); 
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 

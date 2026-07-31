// NPC :zhong_ling.c 钟灵 
// By River 98/12
inherit NPC;
void create()
{
        set_name("钟灵", ({ "zhong ling", "zhong", "ling"}));
        set("title","万劫谷谷主女儿");        
        set("gender", "女性" );
        set("age", 16);
        set("str", 17);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 28);
   	set("attitude", "friendly");

        set("max_qi", 800);
        set("max_jing", 600);
        set("eff_jingli", 600);
        set("neili", 800);
	set("qi", 800);	
        set("max_neili", 800);      
        set("unique", 1);
        
        set("long","这少女约莫十六七岁年纪，一身青衫，笑靥如花。\n");
        set("combat_exp", 100000);
        set("shen", 500); 

        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("force", 160);
        set_skill("strike", 160);
        set_skill("kurong-changong", 160);        
        set_skill("tiannan-step", 160);
        set_skill("kunlun-zhang", 160);
        map_skill("dodge", "tiannan-step");
        map_skill("parry", "kunlun-zhang");
        map_skill("strike", "kunlun-zhang");
        map_skill("force", "kurong-changong");
        prepare_skill("strike","kunlun-zhang");
        set("inquiry", ([            
//            "段正淳" : (: ask_duan :),
        ]));

        setup();
        carry_object(__DIR__"obj/qingshan")->wear();
}

// NPC :gan_baobao.c ¸Ê±¦±¦ 
// By River 98/12
inherit NPC;
void create()
{
        set_name("¸Ê±¦±¦", ({ "gan baobao", "gan", "baobao"}));
        set("title","Íò½Ù¹È¹ÈÖ÷·òÈË");
        set("nickname","ÇÎÒ¹²æ");        
        set("gender", "Å®ĞÔ" );
        set("age", 36);
        set("str", 17);
        set("con", 23);
        set("dex", 26);
        set("int", 25);
        set("per", 25);
   	set("attitude", "friendly");

        set("max_qi", 1000);
        set("max_jing", 800);
        set("eff_jingli", 800);
        set("neili", 1000);
	set("qi", 1000);	
        set("max_neili", 1000);      
        set("unique", 1);
        
        set("long","Õâ¸¾ÈËÔ¼ÄªÈıÊ®ÁùÆßËê×óÓÒÄê¼Í£¬ÈİÉ«ÇåĞã£¬Ã¼Ä¿¼äÒÀÏ¡ÓëÖÓÁéÉõÊÇÏàËÆ¡£\n");
        set("combat_exp", 200000);
        set("shen", 800); 

        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("kurong-changong", 100);        
        set_skill("tiannan-step", 100);
        set_skill("kunlun-zhang", 100);
        map_skill("dodge", "tiannan-step");
        map_skill("parry", "kunlun-zhang");
        map_skill("strike", "kunlun-zhang");
        map_skill("force", "kurong-changong");
        prepare_skill("strike","kunlun-zhang");

        set("inquiry", ([            
//            "¶ÎÕı´¾" : (: ask_duan :),
        ]));

        setup();
        carry_object(__DIR__"obj/lvshan")->wear();
}

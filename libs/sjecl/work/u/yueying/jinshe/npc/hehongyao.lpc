// hehongyao  何红药

inherit NPC;
void create()
{
       set_name("何红药", ({ "he hongyao", "he", "hongyao" }));
       set("nickname", "老乞婆");
       set("long", 
               "她就是何铁手得力的助手何红药。\n"
               "年纪已有五十开外，一双眼睛透出精光。\n");
        set("gender", "女性");
       set("age", 59);
       set("attitude", "friendly");
       set("shen", -3000);
       set("str", 29);
       set("int", 27);
       set("con", 26);
       set("dex", 26);
       
       set("max_qi", 1200);
       set("max_jing", 1000);
       set("neili", 1800);
       set("max_neili", 1800);
       set("eff_jingli", 1400);
       set("jiali", 70);
       set("combat_exp", 800000);
 
       set_skill("force", 130);
        set_skill("yinyun-ziqi", 130);
       set_skill("dodge", 130);
       set_skill("jinshe-zhangfa", 130);
       set_skill("tiyunzong", 130);
       set_skill("strike", 130);
       set_skill("jinshe-jianfa", 130);
       set_skill("parry", 130);
       set_skill("sword", 130);
       set_skill("poison", 80);
       set_skill("literate", 100);
        map_skill("force", "yinyun-ziqi");
       map_skill("dodge", "tiyunzong");
       map_skill("strike", "jinshe-zhangfa");
       map_skill("parry", "jinshe-jianfa");
       map_skill("sword", "jinshe-jianfa");
       prepare_skill("strike", "jinshe-zhangfa");

       set("inquiry", ([
              
               "袁承志" : "教主非常挂念他。",
               "含沙射影" : "五毒教的独门暗器。",
       ]));
       setup();
     
       carry_object("/clone/armor/cloth")->wear();
}

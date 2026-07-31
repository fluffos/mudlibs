#include <ansi.h>
inherit NPC;
void create()
{
       set_name("神秘镖师", ({ "shenmi biaoshi", "biaoshi" }) );
       set("title", "中原镖师");
       set("gender", "男性" );
       set("age", 45);
       set("str", 20);
       set("con", 20);
       set("int", 20);
       set("dex", 20);
       set("env/wimpy", 60);
       set("long", "他是个来自中原的镖师，但他十年来从没回去过，好象是在找什么东西。\n" );
       set("combat_exp", 25000 + random(3000));
       set("shen", -300); 
       set("attitude", "heroism");
       set("chat_chance", 10);
       set("chat_msg", ({
            "神秘镖师好象在自言自语：在哪呢？在哪呢？ \n",
           (: random_move :)
       }) );          
         set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 13900);
        set("max_qi", 13900);
        set("jing", 13900);
        set("max_jing", 13900);
        set("neili", 21500);
        set("max_neili", 21500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 370);
        set_skill("unarmed", 300);
        set_skill("dodge", 350);
        set_skill("parry", 350);
        set_skill("hand",370);
        set_skill("staff", 370);
        set_skill("taixuan-gong", 350);
set_skill("huanhe-dao", 350);
set_skill("sata-shenfa", 350);
set_skill("sumi-jian", 220);
set_skill("wuyu-quan", 350);
set_skill("xiuli-qiankun", 350);
set_skill("strike", 250);
set_skill("cuff", 250);
set_skill("unarmed", 250);
set_skill("blade", 350);
set_skill("sword", 350);
set_skill("club", 220);
set_skill("bawang-qiang", 220);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 220);
set_skill("bawang-qiang", 220);

    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "sword.dieying" :),
                (: perform_action, "sword.feiwu" :),
                (: perform_action, "sword.jiushi" :),
                (: perform_action, "sword.jiushi" :),                	
                (: perform_action, "sword.ruhe" :),
                (: perform_action, "sword.shenfeng" :),                	
                (: perform_action, "sword.wuyun" :),                	                	                	                	
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
                
        }) );
       setup();       
       carry_object("clone/weapon/gangjian")->wield();
       carry_object("/clone/misc/cloth")->wear();
       add_money("silver", 5);
}
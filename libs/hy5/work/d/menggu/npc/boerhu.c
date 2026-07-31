inherit NPC;
void create()
{
   set_name("博尔术",({"boer shu"}));
   set("gender","男性");
   set("long","铁木真手下四杰之一,勇猛过人!\n");
   set("shen",25000);
   set("combat_exp",120000);
   
set("age",45);

set("food",250);
set("water",250);
set("chat_chance",8);
set("chat_msg",({
"博尔术偷偷告诉你:只有九天浣花神箭才能对付草原上的鹰鹫.\n",
"博尔术叹道:悬崖下的白雕是鹰鹫的天敌.\n",
}));
     set("int", 30);
        set("str", 25);
        set("con", 30);
        set("dex", 25);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 1000);

        set("qi",84000);
        set("max_qi", 84000);
        set("jing", 82000);
        set("max_jing", 82000);
        set("neili", 82000);
        set("max_neili", 82000);
        set("jiali", 150);
        set("combat_exp", 9000000);
        set("score", 250000);

    
        set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 33900);
        set("max_qi", 33900);
        set("jing", 33900);
        set("max_jing", 33900);
        set("neili", 61500);
        set("max_neili", 61500);
        set("jiali", 50);

        set("combat_exp", 8500000);
        set("score", 200000);
        set_skill("force", 570);
        set_skill("unarmed", 500);
        set_skill("dodge", 550);
        set_skill("parry", 550);
        set_skill("hand",570);
        set_skill("staff", 570);
        set_skill("taixuan-gong", 550);
set_skill("huanhe-dao", 550);
set_skill("sata-shenfa", 550);
set_skill("sumi-jian", 580);
set_skill("wuyu-quan", 550);
set_skill("xiuli-qiankun", 550);
set_skill("strike", 550);
set_skill("cuff", 550);
set_skill("unarmed", 550);
set_skill("blade", 550);
set_skill("sword", 550);
set_skill("club", 580);
set_skill("bawang-qiang", 580);
map_skill("sword", "sumi-jian");
//map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
set_skill("club", 580);
set_skill("bawang-qiang", 580);

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


	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1000);
	set_temp("apply/damage", 600);

   setup();
   add_money("silver",20);
carry_object("/clone/weapon/changjian")->wield();
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tieqiang");
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book593",1);
		


	::die();
}
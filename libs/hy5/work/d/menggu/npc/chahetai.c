inherit NPC;
void create()
{
   set_name("察合台",({"cha hetai"}));
   set("gender","男性");
   set("long","铁木真的二儿子,生性粗鲁,两颗獠牙露在嘴唇外!\n");
   set("shen",-15000);
   set("combat_exp",100000);
   
     set("per",14);
   set("age",34);
  set("str", 60);
        set("int", 69);
        set("con", 60);
        set("dex", 68);

        set("qi", 93900);
        set("max_qi", 93900);
        set("jing", 93900);
        set("max_jing", 93900);
        set("neili", 91500);
        set("max_neili", 91500);
        set("jiali", 50);

        set("combat_exp", 9500000);
        set("score", 200000);
        set_skill("force", 570);
        set_skill("unarmed", 500);
        set_skill("dodge", 550);
        set_skill("parry", 550);
        set_skill("hand",570);
        set_skill("staff", 570);
        set_skill("taixuan-gong", 550);

set_skill("huanhe-dao", 580);
set_skill("sata-shenfa", 550);
set_skill("sumi-jian", 550);
set_skill("wuyu-quan", 550);
set_skill("xiuli-qiankun", 550);
set_skill("strike", 550);
set_skill("cuff", 550);
set_skill("unarmed", 550);
set_skill("blade", 550);
set_skill("sword", 550);
set_skill("club", 580);
set_skill("bawang-qiang", 580);
//map_skill("sword", "sumi-jian");
map_skill("blade", "huanhe-dao");
map_skill("strike", "xiuli-qiankun");
map_skill("cuff", "wuyu-quan");
      map_skill("force", "taixuan-gong");
        map_skill("dodge", "sata-shenfa");
        map_skill("parry", "taixuan-gong");
        map_skill("unarmed", "taixuan-gong");
    	prepare_skill("strike", "xiuli-qiankun");
	prepare_skill("cuff", "wuyu-quan");

        
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "blade.huan" :),
                	(: perform_action, "blade.kuang" :),
                		(: perform_action, "blade.leitingpili" :),
                			(: perform_action, "blade.shiwanshenmo" :),
                				(: perform_action, "blade.tiandirenmo" :),
                					(: perform_action, "blade.xueyu" :),
                						(: perform_action, "blade.baoxue" :),
                						(: perform_action, "blade.baoxue" :),                							
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
   
   set("chat_chance",5);
   set("chat_msg",({
  "我总看不顺眼拖雷这小子，老跟我作对。\n",
  "郭靖这傻小子居然还有人喜欢，老子早晚要把他杀了.\n",
  }));




   setup();
   add_money("silver",20);
carry_object("/clone/weapon/gangdao")->wield();
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/yinqiang");
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book592",1);
		


	::die();
}
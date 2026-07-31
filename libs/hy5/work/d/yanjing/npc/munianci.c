inherit NPC;
void create()
{
   set_name("穆念慈",({"mu nianci"}));
	set("gender","女性");
   set("score",25000);
   set("combat_exp",80000);
   
set("per",30);
set("age",19);
   set("qi",28000);
   set("max_qi",28000);
set("food",250);
set("water",250);
   set("neili",50000);
   set("max_neili",50000);
   set("force_factor",30);

  set_skill("taoism", 180);
	set_skill("force", 100);
	set_skill("taiji-shengong", 180);
	set_skill("dodge", 100);
	set_skill("tiyunzong", 180);
	set_skill("unarmed", 100);
	set_skill("taiji-quan", 180);
	set_skill("parry", 100);
	set_skill("sword", 100);
	set_skill("taiji-jian", 180);
	set_skill("wudang-jian", 180);
	set_skill("literate", 50);
	set_skill("raozhi-roujian", 180);
	set_skill("wudang-mianzhang", 280);
set_skill("claw", 150);
set_skill("strike", 150);
	set_skill("hand", 180);
	set_skill("paiyun-shou", 250);
	set_skill("shenmen-jian", 250);
	set_skill("yitian-zhang", 250);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "paiyun-shou");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
			map_skill("strike", "yitian-zhang");
prepare_skill("hand", "paiyun-shou");
prepare_skill("strike", "yitian-zhang");

        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
   
   set("inquiry",([
   "比武招亲":"这个...这个...问我爹爹吧.\n",
   "绣花鞋":"问这个干嘛,流氓.\n",
   ]));

   setup();
   add_money("silver",5);
carry_object(__DIR__"obj/skirt")->wear();
carry_object(__DIR__"obj/xiuhuaxie")->wear();
}

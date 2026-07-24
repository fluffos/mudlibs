inherit NPC;
void create()
{
      set_name("佃户",({"dianhu","man","qiongren"}));
      if (random(2)==1) 
      set("gender","男性");
      else set("gender","女性");
      set("age",15+random(50));
      set("str",10+random(20));
      set("combat_exp",1000+random(1000));
      set("chat_chance",3);
      set("chat_msg",({
            "张财主再这么逼债,可叫我们怎么活啊?\n",
            "我可真不懂,怎么去年的一升米,到了今年就成了一斗呢?\n",
            "梁师爷说去年的一斗米种下地,到了今年都不止一斗呢!\n",
         }));
     set_skill("dodge",20);
     set_skill("parry",20);
     set_skill("unarmed",20);
     setup();
     carry_object("/clone/misc/cloth")->wear();
     add_money("coin",10+random(20));
}
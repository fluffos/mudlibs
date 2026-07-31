inherit NPC;
void create()
{
      set_name("制胎工匠",({"gongjiang","worker"}));
      set("gender","男性");
      set("age",20+random(40));
      set("shen_type",1);
      set("combat_exp",30000+random(40000));
      set("str",40);
      set("per",16);
      set_skill("unarmed",15);
      set_skill("parry",15);
      set_skill("dodge",15);
      set("chat_chance",3);
      set("chat_msg",({
                     "工匠在泥胎上仔细地雕刻着花纹.\n",
                     "工匠用脚踩动转轮，一会儿就作出了一只薄胎碗.\n",
                     "工匠使劲地和着陶土，使其变得适用.\n",
                     "工匠把作好的胎盘放到一个个的铁盒子中.\n"
               }));
      setup();
      carry_object("/clone/misc/cloth")->wear();
      add_money("silver",20);
 }
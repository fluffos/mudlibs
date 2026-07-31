inherit NPC;
void create()
{
     set_name("说书老人",({"oldman","shuoshu"}));
     set("gender","男性");
     set("shen_type",1);
     set("age",70);
     set("combat_exp",300000);
     set("str",34);
     set("per",30);
     set_skill("unarmed",90);
     set_skill("dodge",90);
     set_skill("parry",90);
     set("chat_chance",8);
     set("chat_msg",({
            "说书老人道：水泊梁山聚集了一批英雄好汉，要轰轰烈烈干一番大事!\n",
            "说书老人喝了口茶接着说道：山东有位好汉子，人称[及时雨]的黑面宋三郎就是!\n",
            "说书老人道：八十万禁军教头林冲，受了高俅的陷害，发配沧州!\n",
       }));
     setup();
    carry_object("/clone/misc/cloth")->wear();
    add_money("silver",50);
}

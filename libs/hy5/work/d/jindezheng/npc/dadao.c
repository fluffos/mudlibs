inherit NPC;
void create()
{
     set_name("¶ÀÐÐµÁ",({"duxing dao","dao","qiangdao"}));
     set("shen_type",-1);
     set("gender","ÄÐÐÔ");
     set("age",20+random(30));
     set("str",20+random(20));
     set("max_qi",1700);
     set("qi",1700);
     set("force",1000);
     set("force_factor",80);
     set("combat_exp",500000);
     set_skill("dodge",100);
     set_skill("force",100);
     set_skill("unarmed",100);
     set_skill("blade",100);
     set_skill("parry",100);
     setup();
     carry_object("/clone/misc/cloth")->wear();
     carry_object(__DIR__"obj/blade")->wield();
     add_money("silver",random(30));
}
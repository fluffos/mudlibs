inherit NPC;
void create()
{
	set_name("青衣妇人",({"woman","furen","qingyi"}));
     set("shen_type",-1);
     set("gender","女性");
     set("age",20+random(30));
     set("str",10+random(20));
     set("max_qi",1700);
     set("qi",1700);
     set("force",800);
     set("force_factor",40);
     set("combat_exp",200000+random(300000));
     set_skill("dodge",80);
     set_skill("force",80);
     set_skill("unarmed",80);
     set_skill("parry",80);
     setup();
     carry_object(__DIR__"obj/cloth")->wear();
     add_money("silver",random(30));
}

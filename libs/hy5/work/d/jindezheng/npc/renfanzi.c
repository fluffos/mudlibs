inherit NPC;
void create()
{
     set_name("人贩子",({"ren fanzi","fanzi"}));
     set("shen_type",-1);
     set("age",56);
     set("gender","男性");
     set("combat_exp",200000);
     set("str",21);
     set("per",16);
     set_skill("unarmed",70);
     set_skill("dodge",70);
     set_skill("parry",70);
     set("inquiry",([
            "小孩子":"这是我家老二的孩子，你瞧多可爱!\n",
            "kid":"是我孙子，今年才五岁，就调皮得不行!\n",
            "小孩":"没给他买烤肉串，就哭个不行，唉，真没办法!\n",
             ]));
     setup();
     carry_object("/clone/misc/cloth")->wear();
     add_money("silver",30);
}
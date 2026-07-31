inherit NPC;
void create()
{
      set_name("烧窑工",({"gongren","worker"}));
      set("gender","男性");
      set("age",20+random(40));
      set("shen_type",1);
      set("combat_exp",30000+random(40000));
      set("str",40);
      set("per",16);
      set_skill("unarmed",15);
      set_skill("parry",15);
      set_skill("dodge",15);
      setup();
      carry_object(__DIR__"obj/cloth")->wear();
      add_money("silver",10);
 }

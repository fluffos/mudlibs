//Cracked by Roath
inherit NPC;

string *names = ({
  "[33mÍÃ¾«[m",
  "[34mºü¾«[m",
  "[35mâ¯¹Ö[m",
  "[36mÂ¹¾«[m",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({"yao jing"}));
  set("per",12);
  set("combat_exp", 50000);
  set("combat_exp", 50000);
  set("max_neili",5000);
  set("neili",5000);
  set("max_qi",5000);
  set("max_jing",5000);
  set("force_factor",10);
  set("max_neili",500);
  set("neili",600);
  set_skill("unarmed",50);
  set_skill("dodge",50);
  set_skill("force",50);
  set_skill("parry",50);
  set_skill("spells",50);
  setup();
  carry_object("/d/qujing/huangfeng/obj/cloth")->wear();  
}

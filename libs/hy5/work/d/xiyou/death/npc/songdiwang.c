 //puti.c
//inherit NPC;
inherit NPC;
inherit F_MASTER;

void create()
{
  set_name("ËÎµÛÍõ", ({"songdi wang", "wang", "songdi"}));
  set("title", "Òõ¼äÊ®ÍõÖ®");
  set("gender", "ÄÐÐÔ");
  set("age", 30);
  set("class", "youling");
  set("attitude", "friendly");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30+random(5));
  set("max_kee", 600);
  set("max_gin", 900);
  set("max_sen", 900);
  set("force", 700);
  set("max_force", 1000);
  set("force_factor", 35);
  set("max_mana", 1000);
  set("mana", 1000);
  set("mana_factor", 40);
  set("combat_exp", 600000);
  set("daoxing", 500000);

 
  
  create_family("ÑÖÂÞµØ¸®", 1, "ÄãºÃ");
  setup();
  
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}

ÿ

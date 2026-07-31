// ´óÌÆË«Áú´«
 
// chaer.c ²è²©Ê¿

inherit NPC;

void create()
{
//  reload("gaoli_cha");
  set_name("²è²©Ê¿", ({"cha boshi", "cha", "boshi"}));
  set("gender", "ÄĞĞÔ");
  set("combat_exp", 3000);
  set("age", 38);
  set("per", 29);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
 setup();
  carry_object("/d/gaoli/obj/cloth")->wear();
}


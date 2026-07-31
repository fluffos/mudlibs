// daoshi.c

inherit NPC;

void create()
{
  set_name("µÀÊ¿", ({"daoshi"}));
  set("gender", "ÄÐÐÔ" );
  set("age", 43);
  set("long", "ËûÕýÀÁÑóÑóµØÉ¹Ì«Ñô¡£¼ûÁËÄãÏÔ³öÒ»¸±°®´î²»ÀíµÄÑù×Ó¡£\n");
  set("class","taoist");
  set("combat_exp", 10000);
  set("combat_exp", 20000);

  set("attitude", "peaceful");
  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set("per", 15);
  set("max_qi", 300);
  set("max_jing", 200);
  set("max_jing", 300);
  set("neili", 100);
  set("max_neili", 100);
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}

ÿ
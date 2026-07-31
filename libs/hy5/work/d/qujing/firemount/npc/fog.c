// rewritten by snowcat on 4/12/1997
#include "cloudfog.h"


inherit NPC;
#include "/d/migong/romnpc2.c"

void create()
{
  set_name("ÎíÀïÔÆ", ({"fog cloud", "fog"}));
  set("long", "ºìº¢¶ùÊÖÏÂÁù½¡½«£¬ÆäÖĞÓÖÊÇÔÆÀïÎí"+
              "ºÍÎíÀïÔÆ×îÊÜºìº¢¶ùµÄÏ²°®£¬¶´ÖĞµÄÈºÑı¶¼ÊÜ¹ıËûÁ©µÄÖ¸µ¼¡£\n");
  set("gender", "ÄĞĞÔ");
  set("age", 20);
  set("attitude", "heroism");
  set("shen_type", 1);
  set("con", 30+random(5));
  set("max_qi", 500);
  set("max_jing", 500);
  set("max_jing", 500);
  set("neili", 500);
  set("max_neili", 500);
  set("force_factor", 20);
  set("max_neili", 500);
  set("neili", 500);
  set("combat_exp", 240000);
  set("combat_exp", 200000);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("staff", 50);
  set_skill("spells", 30);
  set_skill("force", 50);
  create_family("´äÔÆÉ½°Å½¶¶´",3,"µÜ×Ó");
  setup();
  initlvl((300+random(300)),24);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}



void init()
{
  ::init();
  set("inquiry", ([
        "princess" :   (: test_player :),
        "ÌúÉÈ¹«Ö÷" :   (: test_player :),
        "¹«Ö÷"     :   (: test_player :),
      ]));
}


ÿ
// created 1/15/1999 by smile
#include <ansi.h>
inherit NPC;

string *prefixs = ({
  "黑脸",
  "青面",
  "白眉",
  "黄牙",
  "紫须",
  "蓝耳",
});


void create()
{
  int i;
  set_name(prefixs[random(sizeof(prefixs))]+"僵尸", ({"jiang shi", "shi"}));
  i = random(5)+30;
  set("gender", "男性");
  set("age", 100);
  set("attitude", "aggressive");
  set_level(i);
  set_skill("dodge",i*10);
  set_skill("parry",i*10);
  set_skill("force",i*10);
  set_skill("spells",i*10);
  set_skill("unarmed",i*10);
  set("per", 20);

  set("eff_dx",-26000);
  set("nkgain",400);

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}

void unconcious()
{
   die();
}

void die()
{
  message_vision ("\n$N浑身一软瘫在地上，散落在地上化做一摊黄水。\n",
                  this_object());
    destruct(this_object());
}


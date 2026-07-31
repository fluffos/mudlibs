//Cracked by Roath


inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
   set_name("水妖", ({ "shui yao", "yao"}));
   set("gender", "男性" );
   set("age", 35);
   set("long","盘踞在水下的老妖怪。\n");
   set("max_qi",1200);
   set("max_neili",1200);
   set("neili",1200);
   set("force_factor", 40);
   set("max_neili",1200);
   set("neili",1200);
   set("combat_exp", 7850000);
   set("attitude","aggressive");
   set_skill("unarmed", 130);
   
   setup();
   initlvl((200+random(100)),6);
   //carry_object("/d/obj/cloth/cloth")->wear();
   //carry_object("/d/qujing/village/obj/hammer")->wield();
}

int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

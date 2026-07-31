// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("±ÙÊî´óÍõ", ({ "pishu dawang", "dawang" }));
  set("title", "ĞşÓ¢¶´");   
  set("long", "Ò»Î»Ñı¹Ö£¬±Ç×ÓÉÏ³¤×ÅÒ»¸ù½Ç¡£");
  set("gender", "ÄĞĞÔ");
  set("age", 50);
  set("attitude", "heroism");
  set("per", 29);
  set("max_qi", 1400);
  set("max_jing", 1400);
  set("max_jing", 1400);
  set("neili", 1400);
  set("max_neili", 1400);
  set("force_factor", 90);
  set("max_neili", 800);
  set("neili", 800);
  set("mana_factor", 80);
  set("combat_exp", 640000);
  set("combat_exp", 65800000);


  set("env/wimpy", 50);
  setup();
   initlvl((800+random(800)),38);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/qinglong/obj/blade")->wield();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
    object prince = new ("/d/qujing/jinping/npc/fuling");
  if (ob)
  {
    ob->set_temp("obstacle/jinping_pi2_killed",1);
  prince->announce_success (ob);
  destruct (prince); 
  }
  message_vision ("\n$NÆËµ¹ÔÚµØ£¬»¹Ô­ÎªÒ»Í·Ï¬Å£¡£\n",me);
  message_vision ("\nÌì¿ÕËÄÄ¾ÇİĞÇÒ»ÉÁ£¬Ï¬Å£±»Ò»µÀ¹â×½ÁËÈ¥£¡\n",me);
::die();
}



void destruct_me(object me)
{
  destruct(me);
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

ÿ
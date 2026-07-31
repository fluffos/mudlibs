// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("½ğÁÛ¹Ö", ({ "jinlin guai", "jinglin", "guai" }));
  set("title", "Í¨ÌìºÓ");   
  set("long", "Ò»Î»Éí×Å½ğ¼×µÄÑı¹Ö¡£\n");
  set("gender", "ÄĞĞÔ");
  set("age", 76);
  set("attitude", "aggressive");
  set("per", 30);
  set("max_qi", 170000);
  set("max_jing", 170000);
  set("max_jing", 170000);
  set("neili", 170000);
  set("max_neili", 170000);
  set("force_factor", 10000);
  set("max_neili", 600);
  set("neili", 600);
  set("mana_factor", 20);
  set("combat_exp", 1500000);
  set("combat_exp", 29000000);

  set_skill("spells", 30);

  set_skill("dodge", 80);
  set_skill("dragonstep", 70);
  set_skill("parry", 85);
  set_skill("force", 70);

  setup();
  initlvl((400+random(400)),10);
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/hammer/bahammer")->wield();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
object chen = new ("/d/qujing/tongtian/npc/chen");
  if (ob)
  {
    ob->set_temp("obstacle/tongtian_killed",1);
  chen->announce_success (ob);
  destruct (chen); 
  }
  message_vision ("\n$NÒ»Ë¦Î²°Í£¬ÏÖ³ö½ğÓãµÄÔ­Éí¡£\n",me);
  message_vision ("\nÌìÉÏÅ­ºÈÒ»Éù£º½ğÓã£¬¹éÎÒÁ«»¨³ØÒ²£¡\n",me);
  message_vision ("½ğÓãÎÅÉù£¬¹Ô¹ÔµØÒ»×İÉíÅ¤×ÅÑüÒ¡»Î×ÅÍ·ÓÎ×ßÁË¡£\n",me);
::die();
}

void chen_appearing (object who)
{
  


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